#include <bits/stdc++.h>
int main() {
  int n, a, d;
  int t, v;
  double lt, ltv, lsv, ct;
  scanf("%d%d%d%d%d", &n, &a, &d, &t, &v);
  ltv = v * 1.0 / a;
  lsv = 0.5 * a * ltv * ltv;
  if (lsv > d) {
    lt = t + sqrt(2.0 * d / a);
  } else {
    lt = t + ltv + (d - lsv) / v;
  }
  printf("%lf\n", lt);
  n--;
  while (n--) {
    scanf("%d%d", &t, &v);
    ltv = v * 1.0 / a;
    lsv = 0.5 * a * ltv * ltv;
    if (lsv > d) {
      ct = t + sqrt(2.0 * d / a);
    } else {
      ct = t + ltv + (d - lsv) / v;
    }
    if (ct > lt) lt = ct;
    printf("%lf\n", lt);
  }
}
