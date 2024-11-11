#include <bits/stdc++.h>
using namespace std;
long long n, sxd, a[55], b[55];
double p[55];
double f[55][12000];
bool ok(double x) {
  for (long long i = n - 1; i >= 0; i--) {
    for (long long j = sxd + 1; j <= 10000; j++) f[i + 1][j] = x;
    for (long long j = 0; j <= sxd; j++)
      f[i][j] =
          min(x, (f[i + 1][j + a[i]] + a[i]) * p[i] / 100.0 +
                     (f[i + 1][j + b[i]] + b[i]) * (100.0 - p[i]) / 100.0);
  }
  return (f[0][0] < x);
}
signed main() {
  cin >> n >> sxd;
  for (long long i = 0; i < n; i++) cin >> a[i] >> b[i] >> p[i];
  double l = 0, r = 10000000;
  for (long long i = 1; i <= 150; i++) {
    double mid = (l + r) / 2;
    if (ok(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.10f", l);
  return 0;
}
