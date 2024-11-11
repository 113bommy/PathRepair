#include <bits/stdc++.h>
using namespace std;
using db = long double;
using pll = pair<long long, long long>;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, i, x, j, y, z, k, n;
  cin >> n;
  long long x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long rx[n], ry[n], vx[n], vy[n];
  db l = 0.0, r = LLONG_MAX;
  auto cont = [](db l, db r, db x) { return l <= x and x <= r; };
  for (i = 0; i < n; i += 1) {
    db rx, ry, vx, vy;
    cin >> rx >> ry >> vx >> vy;
    if (vx != 0.0) {
      if (rx > x1 and vx < 0) {
        l = max(l, (x2 - rx) / (vx));
        r = min(r, (x1 - rx) / (vx));
      } else if (rx < x2 and vx > 0) {
        l = max(l, (x1 - rx) / (vx));
        r = min(r, (x2 - rx) / (vx));
      } else
        l = 1, r = -1;
    } else if (!cont(x1, x2, rx)) {
      l = 1, r = -1;
    }
    if (vy != 0.0) {
      if (ry > y1 and vy < 0) {
        l = max(l, (y2 - ry) / (vy));
        r = min(r, (y1 - ry) / (vy));
      } else if (ry < y2 and vy > 0) {
        l = max(l, (y1 - ry) / (vy));
        r = min(r, (y2 - ry) / (vy));
      } else
        l = 1, r = -1;
    } else if (!cont(y1, y2, ry)) {
      l = 1, r = -1;
    }
  }
  if (l >= r)
    puts("-1");
  else
    cout << fixed << setprecision((8)) << l << '\n';
  42;
}
