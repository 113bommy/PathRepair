#include <bits/stdc++.h>
double dp[1 << 20 | 1], p[25], ans[25];
const double eps = 1e-8;
int n, k, num;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &p[i]);
    dp[1 << i - 1] = p[i];
    if (p[i] > eps) num++;
  }
  if (num == k) {
    for (int i = 1; i <= n; i++)
      if (p[i] > eps)
        printf("1.0 ");
      else
        printf("0.0 ");
    return 0;
  }
  for (int i = 0; i <= (1 << n) - 1; i++) {
    double tmpp = 0;
    int cnt = 0;
    for (int j = 0; j < n; j++)
      if (i & (1 << j)) {
        tmpp += p[j + 1];
        cnt++;
      }
    if (cnt == k) {
      for (int j = 0; j < n; j++)
        if (i & (1 << j)) ans[j + 1] += dp[i];
      continue;
    }
    if (cnt > k || fabs(1 - tmpp) < eps) continue;
    for (int j = 0; j < n; j++)
      if (!(i & (1 << j))) dp[i | (1 << j)] += dp[i] * p[j + 1] / (1.0 - tmpp);
  }
  for (int i = 1; i <= n; i++) printf("%.16lf ", ans[i]);
  return 0;
}
