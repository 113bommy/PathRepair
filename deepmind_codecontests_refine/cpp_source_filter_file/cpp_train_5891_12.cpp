#include <bits/stdc++.h>
using namespace std;
int n, m, k, l, r;
long double x[11121], y[11212], ans;
long double dist(long double x, long double y, long double xx, long double yy) {
  return sqrtl((x - xx) * (x - xx) + (y - yy) * (y - yy));
}
long double f(long double x, long double y, long double xx, long double yy,
              long double xxx, long double yyy) {
  long double c = dist(x, y, xxx, yyy);
  long double s =
      (x + xx) * (y - yy) + (xx + xxx) * (yy - yyy) + (xxx + x) * (yyy - y);
  s = abs(s);
  return s / (c * 2.0);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i];
  }
  ans = 1e22;
  x[n + 1] = x[1];
  y[n + 1] = y[1];
  x[n + 2] = x[2];
  y[n + 2] = y[2];
  for (int i = 1; i <= n - 2; ++i) {
    ans = min(ans, f(x[i], y[i], x[i + 1], y[i + 1], x[i + 2], y[i + 2]));
  }
  cout << fixed << setprecision(6) << ans;
}
