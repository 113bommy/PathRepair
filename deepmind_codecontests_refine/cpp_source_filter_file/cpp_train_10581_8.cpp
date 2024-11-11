#include <bits/stdc++.h>
using namespace std;
int Ile;
long double IleKilo, IleKoloKopia;
long double Tymczasowa, Wynik;
struct Sklepy {
  int cena;
  int ilosc;
  long double CenaZaIlosc;
} TablicaStruktur[200], Suma;
bool FunkcjaPorownujacaStruktury(Sklepy A, Sklepy B) {
  return (A.CenaZaIlosc < B.CenaZaIlosc);
}
int main() {
  cin >> Ile >> IleKilo;
  IleKoloKopia = IleKilo;
  for (int i = 0; i < Ile; i++) {
    cin >> TablicaStruktur[i].cena >> TablicaStruktur[i].ilosc;
    TablicaStruktur[i].CenaZaIlosc =
        (long double)TablicaStruktur[i].cena / TablicaStruktur[i].ilosc;
  }
  sort(TablicaStruktur, TablicaStruktur + Ile, FunkcjaPorownujacaStruktury);
  Wynik = IleKilo *
          ((long double)TablicaStruktur[0].cena / TablicaStruktur[0].ilosc);
  cout.precision(9);
  cout << Wynik << endl;
  return 0;
}
