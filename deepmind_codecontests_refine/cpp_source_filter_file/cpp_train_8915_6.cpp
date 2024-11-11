#include <bits/stdc++.h>
using namespace std;
int ciag[200000 + 7];
int bezJednegoElementu[200000 + 7];
int wszystkieElementy[200000 + 7];
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  int wynik = -1500000000;
  int dlugosc;
  cin >> n;
  for (int i = 0; i < 200000; i++) {
    bezJednegoElementu[i] = 1500000000;
    wszystkieElementy[i] = 1500000000;
  }
  for (int i = 1; i <= n; i++) {
    cin >> ciag[i];
    ciag[i] -= i;
  }
  for (int i = 2; i <= n; i++) {
    dlugosc = upper_bound(bezJednegoElementu + 1, bezJednegoElementu + n + 1,
                          ciag[i]) -
              bezJednegoElementu;
    bezJednegoElementu[dlugosc] = ciag[i] + 1;
    wynik = max(wynik, dlugosc);
    dlugosc = upper_bound(wszystkieElementy + 1, wszystkieElementy + n + 1,
                          ciag[i - 1]) -
              wszystkieElementy;
    wszystkieElementy[dlugosc] = ciag[i - 1] + 1;
    wynik = max(wynik, dlugosc);
    bezJednegoElementu[dlugosc] =
        min(bezJednegoElementu[dlugosc], wszystkieElementy[dlugosc]);
  }
  cout << max(0, n - wynik - 1);
  return 0;
}
