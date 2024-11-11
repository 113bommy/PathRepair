#include <bits/stdc++.h>
int n, k, i, j, t, x1, x2, m;
double a[700000 + 1], r, d, s;
int main() {
  scanf("%d%d", &n, &k);
  m = 700000 / k;
  for (j = 0; j < n; j++) {
    scanf("%d", &x1);
    s = 0;
    for (i = 0; i < k; i++) {
      scanf("%d", &x2);
      r = (double)(x2 - x1) / m;
      for (t = 0; t <= m; t++) {
        d = (double)x1 + r * t;
        if (a[i * m + t] < d) {
          s += d - a[i * m + t];
          a[i * m + t] = d;
        }
      }
      x1 = x2;
    }
    printf("%lf\n", s / m);
  }
  return 0;
}
