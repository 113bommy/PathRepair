#include <bits/stdc++.h>
using namespace std;
int tab[20100][20];
int pracownicy[20100] = {0};
int zapytania[20] = {0};
int zlicz_pracownika[20100] = {0};
int main(int argc, char* const argv[]) {
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int wiersz = 0; wiersz < (n); ++wiersz)
    for (int kolumna = 0; kolumna < (m); ++kolumna) cin >> tab[wiersz][kolumna];
  int x, y;
  for (int numer_zapytania = 0; numer_zapytania < (k); ++numer_zapytania) {
    cin >> x >> y;
    x--;
    y--;
    zlicz_pracownika[x]++;
    zapytania[y]++;
  }
  for (int kolumna = 0; kolumna < (m); ++kolumna) {
    if (zapytania[kolumna])
      for (int numer_pracownika = 0; numer_pracownika < (n);
           ++numer_pracownika) {
        if (tab[numer_pracownika][kolumna] == 1)
          pracownicy[numer_pracownika] += zapytania[kolumna];
      }
  }
  for (int numer_pracownika = 0; numer_pracownika < (n); ++numer_pracownika) {
    cout << max(pracownicy[numer_pracownika] -
                    zlicz_pracownika[numer_pracownika],
                0)
         << " ";
  }
  return 0;
}
