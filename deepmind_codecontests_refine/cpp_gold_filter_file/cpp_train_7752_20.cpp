#include <bits/stdc++.h>
int n, k, X0, Y0;
double p, pi;
double dis[110], f[110][110];
double sqr(double x) { return x * x; }
int main() {
  int i, j, x, y;
  double l, mid, r;
  scanf("%d%d%lf", &n, &k, &p);
  p /= 1000.0;
  scanf("%d%d", &X0, &Y0);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    dis[i] = sqrt(sqr(x - X0) + sqr(y - Y0));
  }
  l = 0, r = 3000;
  f[0][0] = 1;
  while (r - l > 0.00000001) {
    mid = (l + r) / 2;
    for (i = 1; i <= n; i++) {
      if (mid - dis[i] >= 0.000000001)
        pi = 1;
      else
        pi = exp(1 - sqr(dis[i]) / sqr(mid));
      for (j = 0; j <= i; j++)
        f[i][j] = f[i - 1][j] * (1 - pi) + f[i - 1][j - 1] * pi;
    }
    pi = 0;
    for (i = 0; i < k; i++) pi += f[n][i];
    if (p - pi >= 0.000000001)
      r = mid;
    else
      l = mid;
  }
  printf("%.7lf", l);
}
