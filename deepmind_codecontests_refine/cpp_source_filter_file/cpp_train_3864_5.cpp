#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
const ll mod = 998244353;
int dp[1005][2010][4] = {0};
int main() {
  int T, n, m, k, i, j, t;
  scanf("%d%d", &n, &k);
  dp[1][1][0] = 1;
  dp[1][2][1] = 1;
  dp[1][2][2] = 1;
  dp[1][1][3] = 1;
  for (i = 2; i <= n; i++)
    for (j = 1; j <= (i << 1); j++) {
      dp[i][j][0] += (dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2] +
                      dp[i - 1][j - 1][3]) %
                     mod;
      dp[i][j][1] += (dp[i - 1][j - 1][0] + dp[i - 1][j][1] +
                      dp[i - 1][j - 2][2] + dp[i - 1][j - 1][3]) %
                     mod;
      dp[i][j][2] += (dp[i - 1][j - 1][0] + dp[i - 1][j][1] +
                      dp[i - 1][j - 2][2] + dp[i - 1][j - 1][3]) %
                     mod;
      dp[i][j][3] += (dp[i - 1][j - 1][0] + dp[i - 1][j][1] + dp[i - 1][j][2] +
                      dp[i - 1][j][3]) %
                     mod;
    }
  int ans = (dp[n][k][0] + dp[n][k][1] + dp[n][k][2] + dp[n][k][3]) % mod;
  printf("%d\n", ans);
  return 0;
}
