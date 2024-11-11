#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
long long dis(pair<long long, long long> a, pair<long long, long long> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  long long x0, y0, ax, ay, bx, by;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by;
  vector<pair<long long, long long>> a(1, {x0, y0});
  for (;;) {
    long long x = a.back().first, y = a.back().second;
    x = ax * x + bx;
    y = ay * y + by;
    if (x > 20000000000000000 || y > 2000000000000000) break;
    a.push_back({x, y});
  }
  int n = a.size(), ans = 0;
  long long xs, ys, t;
  cin >> xs >> ys >> t;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      long long d =
          dis(a[i], a[j]) + min(dis(a[i], {xs, ys}), dis(a[j], {xs, ys}));
      if (d <= t) ans = max(ans, j - i + 1);
    }
  }
  cout << ans << "\n";
  return 0;
}
