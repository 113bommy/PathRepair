#include <bits/stdc++.h>
using namespace std;
const long long ff = 1e5 + 1;
const long long inf = 1e18 + 7;
long long x[ff], y[ff];
long long n = 1000, ax, bx, ay, by, st;
long long xs, ys, t, dmin = inf, ju, ans;
long long dis(long long a, long long b, long long c, long long d) {
  return abs(a - c) + abs(b - d);
}
void init() {
  cin >> x[0] >> y[0] >> ax >> ay >> bx >> by;
  cin >> xs >> ys >> t;
  st = 0;
  dmin = dis(xs, ys, x[0], y[0]);
  for (long long i = 1; i <= n; ++i) {
    x[i] = x[i - 1] * ax + bx;
    y[i] = y[i - 1] * ay + by;
    long long dist = dis(xs, ys, x[i], y[i]);
    if (dist > 1e7 + 1) {
      n = i - 1;
      break;
    }
  }
  for (long long i = 0; i <= n / 3; ++i)
    for (long long j = 0; j <= i; ++j)
      for (long long z = j; z <= n / 3; ++z) {
        long long diss = dis(xs, ys, x[i], y[i]);
        long long dis2 = diss + dis(x[i], y[i], x[j], y[j]);
        long long dis3 = diss + dis(x[i], y[i], x[z], y[z]);
        if (dis2 <= t) ans = max(ans, i - j + 1);
        if (dis3 <= t) ans = max(ans, z - i + 1);
        diss = diss + dis(x[i], y[i], x[j], y[j]) + dis(x[j], y[j], x[z], y[z]);
        diss = min(diss, diss + dis(x[i], y[i], x[z], y[z]) +
                             dis(x[z], y[z], x[j], y[j]));
        if (diss <= t) ans = max(ans, z - j + 1);
      }
  printf("%lld", ans);
}
signed main() { init(); }
