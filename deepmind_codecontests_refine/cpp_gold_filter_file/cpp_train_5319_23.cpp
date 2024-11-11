#include <bits/stdc++.h>
using namespace std;
int main() {
  cout.precision(30);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int m;
  cin >> m;
  vector<long double> a(n), b(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  long double l = 0, r = 2e9;
  for (int it = 0; it < 100; it++) {
    long double cur_mass = m;
    long double mid = (l + r) / 2;
    cur_mass += mid;
    bool f = 1;
    for (int i = 0; i < n; i++) {
      int j = (i + 1) % n;
      long double waste = cur_mass / a[i];
      cur_mass -= waste;
      if (cur_mass < m) {
        f = 0;
        break;
      }
      waste = cur_mass / b[j];
      cur_mass -= waste;
      if (cur_mass < m) {
        f = 0;
        break;
      }
    }
    if (f)
      r = mid;
    else
      l = mid;
  }
  if (l > 15e8)
    cout << -1;
  else
    cout << l << endl;
  return 0;
}
