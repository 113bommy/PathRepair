#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &z : v) cin >> z;
  vector<int> l(n), r(n);
  l[0] = (~v[0]);
  for (int i = 1; i < n; i++) {
    l[i] = ~v[i] & l[i - 1];
  }
  r[n - 1] = ~v[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    r[i] = ~v[i] & r[i + 1];
  }
  int najveci = -1;
  int indeks = -1;
  for (int i = 0; i < n; i++) {
    int trenutni = v[i] & ((i - 1 >= 0) ? (l[i - 1]) : (-1)) &
                   ((i + 1 <= n - 1) ? (r[i + 1]) : (-1));
    if (trenutni > najveci) {
      najveci = trenutni;
      indeks = i;
    }
  }
  cout << v[indeks];
  for (int i = 0; i < n; i++) {
    if (i != indeks) cout << ' ' << v[i];
  }
  cout << '\n';
  return 0;
}
