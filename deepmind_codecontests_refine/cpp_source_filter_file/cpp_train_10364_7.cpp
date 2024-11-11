#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, ln, v1, v2, k, groups;
  scanf("%lld%lld%lld%lld%lld", &n, &ln, &v1, &v2, &k);
  groups = (n + k - 1) / k;
  double l = 0.0, r = (1.0 * ln) / (1.0 * v1);
  while ((r - l) >= 1e-7) {
    double mid = (l + r) / 2.0;
    double t = 0.0, x, y;
    for (int i = 0; i < groups; i++) {
      x = (1.0 * ln - 1.0 * v1 * mid) / (1.0 * (v2 - v1));
      t += x;
      if (i < groups - 1) {
        y = 1.0 * (v2 - v1) * x / (1.0 * (v1 + v2));
        t += y;
      }
    }
    if (mid >= t)
      r = mid;
    else
      l = mid;
  }
  printf("%Lf\n", l);
  return 0;
}
