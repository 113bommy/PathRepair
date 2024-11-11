#include <bits/stdc++.h>
using namespace std;
inline void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
const long long ost = 1e9 + 7;
inline void solve() {
  long long n, p;
  cin >> n >> p;
  double l = 0, r = 1e18;
  vector<pair<long long, long long>> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  double t;
  long long it = 0;
  while (it < 1000) {
    t = (l + r) / 2;
    double s = 0;
    for (long long i = 0; i < n; i++) {
      double x = v[i].second - v[i].first * t;
      if (x < 0) s += x;
    }
    if (s + p * t > 0)
      l = t;
    else
      r = t;
    it++;
  }
  if (l >= 1e11) {
    cout << -1;
  } else
    cout << fixed << setprecision(5) << l;
}
