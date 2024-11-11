#include <bits/stdc++.h>
const int MAXN = 550;
const int eps = 1e-10;
double a[MAXN];
int main() {
  int n, m, i, x, y;
  double z, j, dmax;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%lf", &a[i]);
  dmax = 0.0;
  for (i = 1; i <= m; i++) {
    scanf("%d%d%lf", &x, &y, &z);
    if (z > eps) j = (a[x] + a[y]) / z;
    if (j > dmax) dmax = j;
  }
  printf("%.12lf\n", dmax);
  return 0;
}
