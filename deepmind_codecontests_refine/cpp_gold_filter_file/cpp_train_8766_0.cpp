#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long x[100];
  long long y[100];
  long long ax, ay, bx, by;
  cin >> x[0] >> y[0] >> ax >> ay >> bx >> by;
  long long sx, sy, t;
  cin >> sx >> sy >> t;
  long long i;
  for (i = 1; i <= 100; i++) {
    x[i] = (ax * x[i - 1]) + bx;
    y[i] = (ay * y[i - 1]) + by;
    if (abs(x[i] - sx) + abs(y[i] - sy) >= 4 * (long long)1e16) break;
  }
  long long ans = 0;
  long long j, k;
  long long n = i;
  for (i = 1; i <= n; i++) {
    for (j = 0; j <= (n - i + 1); j++) {
      long long tt = 0;
      tt = abs(sx - x[j]) + abs(sy - y[j]) + abs(x[j + i - 1] - x[j]) +
           abs(y[j + i - 1] - y[j]);
      tt = min(tt, abs(sx - x[j + i - 1]) + abs(sy - y[j + i - 1]) +
                       abs(x[j + i - 1] - x[j]) + abs(y[j + i - 1] - y[j]));
      if (tt <= t) ans = max(ans, i);
    }
  }
  cout << ans;
}
