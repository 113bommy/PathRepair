#include <bits/stdc++.h>
using namespace std;
const int N = 7;
const int M = 10000 + 5;
int l[N], r[N], n;
double dp[N][N][N];
double calc(int price) {
  memset(dp, 0, sizeof dp);
  dp[0][0][0] = 1;
  int bound;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++) {
        double p = 1. / (double)(r[i] - l[i] + 1);
        if (l[i] <= price && price <= r[i])
          dp[i + 1][j + 1][k] += dp[i][j][k] * p;
        bound = max(l[i], price + 1);
        if (bound <= r[i])
          dp[i + 1][j][k + 1] += dp[i][j][k] * p * (double)(r[i] - bound + 1);
        bound = min(price - 1, r[i]);
        if (l[i] <= bound)
          dp[i + 1][j][k] += dp[i][j][k] * p * (double)(bound - l[i] + 1);
      }
  double res = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= 1; j++)
      if ((!j && i > 1) || j == 1) res += dp[n][i][j];
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", l + i, r + i);
  double res = 0;
  for (int x = 1; x <= 10000; x++) res += (double)x * calc(x);
  printf("%.10lf\n", res);
  return 0;
}
