#include <bits/stdc++.h>
using namespace std;
const int mac = 210;
int a[mac];
double p[mac];
double dp[mac][mac][2 * mac];
int main() {
  int n, l, v;
  scanf("%d%d%d", &n, &l, &v);
  for (int i = 1; i <= n; i++) scanf("%lf", &p[i]), p[i] /= 100;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  dp[0][0][v + 200] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      for (int k = 0; k <= 400; k++) {
        int last = min(k + a[i + 1], 400);
        dp[i + 1][j][k] += dp[i][j][k] * (1 - p[i + 1]);
        if (last > 0) dp[i + 1][j + 1][last] += dp[i][j][k] * p[i + 1];
      }
  double ans = 0;
  for (int i = 200; i <= 400; i++)
    for (int j = l; j <= n; j++) ans += dp[n][j][i];
  printf("%.10f\n", ans);
  return 0;
}
