#include <bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i < 2005; i++) dp[i][1] = 1;
  int ans = 0;
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      for (int k = i; k <= n; k += i) {
        dp[k][j + 1] = (dp[k][j + 1] + dp[i][j]) % 1000000007;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    ans += dp[i][m];
    ans %= 1000000007;
  }
  printf("%d\n", ans);
  return 0;
}
