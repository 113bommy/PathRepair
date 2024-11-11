#include <bits/stdc++.h>
int dd[100], n, k;
double dp[100 + 1], pp[100], eps;
int check(double r) {
  int i, j;
  double p;
  r *= r;
  for (i = 0; i < n; i++) pp[i] = dd[i] <= r ? 1 : exp(1 - dd[i] / r);
  memset(dp, 0, (k + 1) * sizeof *dp), dp[0] = 1;
  for (i = 0; i < n; i++)
    for (j = k; j >= 0; j--)
      if (dp[j] != 0) {
        if (j + 1 <= k) dp[j + 1] += dp[j] * pp[i];
        dp[j] *= 1 - pp[i];
      }
  p = 0;
  for (j = 0; j < k; j++) p += dp[j];
  return p <= eps;
}
int main() {
  int i, x0, y0, x, y;
  double lower, upper, r;
  scanf("%d%d%lf%d%d", &n, &k, &eps, &x0, &y0), eps /= 1000.0;
  for (i = 0; i < n; i++) {
    scanf("%d%d", &x, &y), x -= x0, y -= y0;
    dd[i] = x * x + y * y;
  }
  lower = 0, upper = 4000;
  while (upper - lower > 1e-6) {
    r = (lower + upper) / 2;
    if (check(r))
      upper = r;
    else
      lower = r;
  }
  printf("%f\n", upper);
  return 0;
}
