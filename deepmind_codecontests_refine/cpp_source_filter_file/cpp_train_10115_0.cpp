#include <bits/stdc++.h>
using namespace std;
const long long M = 1000003, M2 = 500002;
int n, m, poz_nr;
long long wynik;
char slowo[100005];
int nr[100005];
int dzialaj() {
  for (int i = 0; i < n; i++) {
    scanf("%s", slowo);
    poz_nr = 0;
    for (int j = 0; j < m; j++) {
      if (slowo[j] != '.') {
        if (slowo[j] == '1' || slowo[j] == '2') {
          if (j % 2 == 0) {
            if (poz_nr == 0)
              poz_nr = 1;
            else if (poz_nr == 2)
              return 0;
          } else {
            if (poz_nr == 0)
              poz_nr = 2;
            else if (poz_nr == 1)
              return 0;
          }
        } else {
          if (j % 2 == 0) {
            if (poz_nr == 0)
              poz_nr = 2;
            else if (poz_nr == 1)
              return 0;
          } else {
            if (poz_nr == 0)
              poz_nr = 1;
            else if (poz_nr == 2)
              return 0;
          }
        }
      }
      if (slowo[j] != '.') {
        if (slowo[j] == '1' || slowo[j] == '4') {
          if (i % 2 == 0) {
            if (nr[j] == 0)
              nr[j] = 1;
            else if (nr[j] == 2)
              return 0;
          } else {
            if (nr[j] == 0)
              nr[j] = 2;
            else if (nr[j] == 1)
              return 0;
          }
        } else {
          if (j % 2 == 0) {
            if (nr[j] == 0)
              nr[j] = 2;
            else if (nr[j] == 1)
              return 0;
          } else {
            if (nr[j] == 0)
              nr[j] = 1;
            else if (nr[j] == 2)
              return 0;
          }
        }
      }
    }
    if (poz_nr == 0) wynik = wynik * 2 % M;
  }
  for (int j = 0; j < m; j++)
    if (nr[j] == 0) wynik = wynik * 2 % M;
  return wynik;
}
int main() {
  wynik = 1;
  scanf("%d %d", &n, &m);
  printf("%d\n", dzialaj());
  return 0;
}
