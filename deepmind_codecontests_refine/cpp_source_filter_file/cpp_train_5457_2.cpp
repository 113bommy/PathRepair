#include <bits/stdc++.h>
using namespace std;
const int MAX = 5050;
int n, m, t[MAX][MAX];
string s[MAX];
void wczytaj_dane() {
  cin >> n >> m;
  for (int i = 0; i < (n); i++) cin >> s[i];
}
void wypelnij_t() {
  for (int j = 0; j < (m); j++) t[j][n] = 0;
  for (int i = 0; i < (n); i++)
    for (int j = (m - 1); j >= (0); j--)
      t[j][i] = (s[i][j] == '1' ? 1 + t[j][i + 1] : 0);
}
int rozwiaz() {
  int wynik = 0;
  for (int j = 0; j < (m); j++) {
    sort(t[j], t[j] + n, greater<int>());
    for (int i = 0; i < (n); i++) wynik = max(wynik, (i + 1) * t[j][i]);
  }
  return wynik;
}
void zrob_test() {
  wczytaj_dane();
  wypelnij_t();
  cout << rozwiaz() << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  zrob_test();
  return 0;
}
