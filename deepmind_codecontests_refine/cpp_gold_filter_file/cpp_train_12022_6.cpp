#include <bits/stdc++.h>
using namespace std;
const int oo = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
int n, a[5], b[5], c[5];
int main() {
  cin >> n;
  for (int i = 0; i < (int)(n); i++) {
    cin >> a[i] >> b[i];
    c[i] = b[i] - a[i] + 1;
  }
  double ret = 0;
  for (int pay = 1; pay < (int)(10001); pay++)
    for (int mask = 1; mask < (int)(1 << n); mask++) {
      bool ok = 1;
      double p = 1;
      for (int i = 0; i < (int)(n); i++)
        if (mask & (1 << i)) {
          p *= 1. / c[i];
          if (pay < a[i] || pay > b[i]) {
            ok = 0;
            break;
          }
        }
      if (!ok) continue;
      for (int mx = 0; mx < (int)(n + 1); mx++) {
        double p2 = p;
        if (__builtin_popcount(mask) == 1 && mx == n) continue;
        if (mx != n) {
          if (mask & (1 << mx)) continue;
          if (b[mx] <= pay) continue;
          p2 *= (b[mx] - max(pay + 1, a[mx]) + 1.) / c[mx];
        }
        ok = 1;
        for (int i = 0; i < (int)(n); i++) {
          if (mask & (1 << i)) continue;
          if (i == mx) continue;
          if (a[i] >= pay) {
            ok = 0;
            break;
          }
          p2 *= (min(pay - 1, b[i]) - a[i] + 1.) / c[i];
        }
        if (ok) ret += p2 * pay;
      }
    }
  printf("%.10lf\n", ret);
  return 0;
}
