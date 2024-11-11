#include <bits/stdc++.h>
using namespace std;
long long int n, m;
vector<long long int> a, b;
bool possible(long double x) {
  long double mass = m + x;
  for (long long int i = 0; i < n; i++) {
    x -= mass / a[i];
    mass = m + x;
    if (x <= 0) return 0;
    x -= mass / b[(i + 1) % n];
    mass = m + x;
  }
  if (x <= 0) return 0;
  return 1;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> n >> m;
  b.resize(n);
  a.resize(n);
  for (auto &it : a) cin >> it;
  for (auto &it : b) cin >> it;
  long double l = 0, h = 1e9 + 1;
  while (h - l > 1e-7) {
    long double mid = (l + h) / 2;
    if (possible(mid))
      h = mid;
    else
      l = mid;
  }
  if (h == 1e9 + 1) return cout << "-1", 0;
  cout << fixed << setprecision(10) << h;
  return 0;
}
