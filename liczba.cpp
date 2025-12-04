#include <iostream>
#include <fstream>
using namespace std;

double pierwiastek(double x) {
    double r = x;
    double poprzedni = 0;

    while (r != poprzedni) {
        poprzedni = r;
        r = (r + x / r) / 2;
    }
    return r;
}

int main() {
    ifstream plik("liczby_zadanie.txt");

    if (!plik.good()) {
        cout << "Blad otwarcia pliku!";
        return 0;
    }

    int liczby[2000];
    int n = 0;

    while (plik >> liczby[n]) {
        n++;
    }

    cout << "1. Ilosc liczb: " << n << endl;

    double suma = 0;
    for (int i = 0; i < n; i++) suma += liczby[i];
    double srednia = suma / n;

    cout << "2. Srednia: " << srednia << endl;

    double suma2 = 0;
    for (int i = 0; i < n; i++) {
        double roznica = liczby[i] - srednia;
        suma2 += roznica * roznica;
    }

    double wariancja = suma2 / n;
    double odchylenie = pierwiastek(wariancja);

    cout << "3. Odchylenie standardowe: " << odchylenie << endl;

    int podzielne3 = 0;
    for (int i = 0; i < n; i++)
        if (liczby[i] % 3 == 0)
            podzielne3++;

    cout << "4. Podzielne przez 3: " << podzielne3 << endl;

    int minv = liczby[0];
    int maxv = liczby[0];

    for (int i = 1; i < n; i++) {
        if (liczby[i] < minv) minv = liczby[i];
        if (liczby[i] > maxv) maxv = liczby[i];
    }

    cout << "5. Min: " << minv << "  Max: " << maxv << endl;

    int dwucyfrowe = 0;
    for (int i = 0; i < n; i++)
        if (liczby[i] >= 10 && liczby[i] <= 99)
            dwucyfrowe++;

    cout << "6. Dwucyfrowe: " << dwucyfrowe << endl;

    int czteryKoniec4 = 0;
    for (int i = 0; i < n; i++)
        if (liczby[i] >= 1000 && liczby[i] <= 9999 && liczby[i] % 10 == 4)
            czteryKoniec4++;

    cout << "7. 4 cyfry i koniec 4: " << czteryKoniec4 << endl;

    int palindromy = 0;
    for (int i = 0; i < n; i++) {
        int a = liczby[i];
        int odw = 0;
        int tmp = a;

        while (tmp > 0) {
            odw = odw * 10 + (tmp % 10);
            tmp /= 10;
        }

        if (odw == a) palindromy++;
    }

    cout << "8. Palindromy: " << palindromy << endl;

    int pierwsze = 0;

    for (int i = 0; i < n; i++) {
        int x = liczby[i];

        bool prime = true;

        if (x < 2) prime = false;

        for (int j = 2; j * j <= x; j++) {
            if (x % j == 0) prime = false;
        }

        if (prime) pierwsze++;
    }

    cout << "9. Liczby pierwsze: " << pierwsze << endl;

    return 0;
}
