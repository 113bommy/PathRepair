#include <bits/stdc++.h>
using namespace std;
double x[500005], v[500005];
const double eps = 1e-10;
int main() {
  int i, j, n;
  bool okr = 0, ok = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%lf%lf", &x[i], &v[i]);
    if (v[i] > 0) okr = 1;
    if (v[i] < 0 && okr) ok = 1;
  }
  if (!ok) {
    puts("-1");
    return 0;
  }
  double mid, l = 0, r = 1e9;
  double left, right;
  bool can, t;
  while (fabs(r - l) > eps) {
    mid = (l + r) / 2.0;
    t = can = 0;
    for (i = 0; i < n; i++) {
      if (v[i] > 0) {
        if (!t) {
          right = x[i] + v[i] * mid;
          t = 1;
        } else
          right = max(right, x[i] + v[i] * mid);
      } else if (t) {
        left = x[i] + v[i] * mid;
        if (right - left > 0) {
          r = mid;
          can = 1;
          break;
        }
      }
    }
    if (!can) l = mid;
  }
  printf("%.9lf\n", r);
  return 0;
}
