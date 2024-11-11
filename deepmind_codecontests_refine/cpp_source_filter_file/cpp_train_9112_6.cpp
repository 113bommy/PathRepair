#include <bits/stdc++.h>
const double eps = 1e-12;
double a[11111];
int n, k;
int ok(double mid) {
  int i;
  double s = 0.0;
  double z = 0.0;
  for (i = 0; i < n; i++) {
    if (a[i] > mid)
      s += (a[i] - mid);
    else if (a[i] < mid)
      z += (mid - a[i]);
  }
  double tem = s * (100.0 - k * 1.0);
  z *= 100.0;
  if (tem - z >= 0.0 && tem - z < eps * 1e5)
    return 0;
  else if (tem - z < 0)
    return -1;
  else if (tem - z > eps * 1e5)
    return 1;
  return 2;
}
int main() {
  int i, tem;
  double mid, l, r, adv, sum, ans;
  while (~scanf("%d%d", &n, &k)) {
    for (i = 0; i < n; i++) {
      scanf("%lf", &a[i]);
      sum += a[i];
    }
    adv = sum / (n * 1.0);
    l = 0.0;
    r = adv + 1.0;
    while (l + eps < r) {
      mid = (l + r) / 2.0;
      tem = ok(mid);
      if (tem == 0)
        ans = mid, l = mid;
      else if (tem == 1)
        l = mid;
      else if (tem == -1)
        r = mid;
    }
    printf("%.7lf\n", ans);
  }
}
