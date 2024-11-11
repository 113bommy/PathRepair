#include <bits/stdc++.h>
using namespace std;
int n, m;
double dp[305][3005], last[3005], ans, p[3005][305], del[305];
void DP(int k) {
  for (int i = 0; i <= n; ++i) last[i] = dp[k][i];
  dp[k][0] = 0;
  for (int i = 1; i <= n; ++i)
    dp[k][i] = last[i - 1] * p[i][k] + dp[k][i - 1] * (1 - p[i][k]);
  del[k] -= dp[k][n];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) scanf("%lf", &p[i][j]), p[i][j] *= 0.001;
  for (int i = 1; i <= m; ++i) {
    dp[i][0] = 1;
    for (int j = 1; j <= n; ++j) dp[i][j] = dp[i][j - 1] * (1 - p[j][i]);
    del[i] = 1 - dp[i][n];
  }
  for (int i = 1; i <= n; ++i) {
    int tmp = 0;
    for (int j = 1; j <= m; ++j)
      if (del[j] > del[tmp]) tmp = j;
    ans += del[tmp], DP(tmp);
  }
  printf("%.10lf", ans);
  return 0;
}
