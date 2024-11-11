#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 5001;
int dp[maxn][maxn];
int sum[maxn][maxn];
int n;
void getsum(int x) {
  for (int i = 1; i <= n; i++) sum[x][i] = (sum[x][i - 1] + dp[x][i]) % mod;
}
int main() {
  int a, b, k;
  while (scanf("%d%d%d%d", &n, &a, &b, &k) != EOF) {
    memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    dp[0][a] = 1;
    if (a < b)
      for (int i = 1; i <= k; i++) {
        getsum(i - 1);
        for (int j = 1; j < b; j++)
          dp[i][j] = (sum[i - 1][(b + j - 1) / 2] - dp[i - 1][j] + mod) % mod;
      }
    else
      for (int i = 1; i <= k; i++) {
        getsum(i - 1);
        for (int j = b + 1; j <= n; j++)
          dp[i][j] = (sum[i - 1][n] - sum[i - 1][(j + b) / 2] + mod -
                      dp[i - 1][j] + mod) %
                     mod;
      }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + dp[k][i]) % mod;
    printf("%d\n", ans);
  }
  return 0;
}
