#include <bits/stdc++.h>
using namespace std;
const int maxn = 1100;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
int n, k;
char s[maxn];
long long dp[maxn][maxn << 1][5];
int main() {
  scanf("%d%d", &n, &k);
  memset(dp, 0, sizeof dp);
  dp[1][1][0] = dp[1][1][3] = 1;
  dp[1][2][1] = dp[1][2][2] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < n << 1; j++) {
      dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2] +
                     dp[i - 1][j - 1][3]) %
                    998244353;
      dp[i][j][1] = (dp[i - 1][j][1] + dp[i - 1][j - 2][2] +
                     dp[i - 1][j - 1][0] + dp[i - 1][j - 1][3]) %
                    998244353;
      dp[i][j][2] = (dp[i - 1][j][2] + dp[i - 1][j - 2][1] +
                     dp[i - 1][j - 1][0] + dp[i - 1][j - 1][3]) %
                    998244353;
      dp[i][j][3] = (dp[i - 1][j][3] + dp[i - 1][j][1] + dp[i - 1][j][2] +
                     dp[i - 1][j - 1][0]) %
                    998244353;
    }
  }
  long long ans = dp[n][k][0] + dp[n][k][1] + dp[n][k][2] + dp[n][k][3];
  ans = ans % 998244353;
  printf("%lld\n", ans);
  return 0;
}
