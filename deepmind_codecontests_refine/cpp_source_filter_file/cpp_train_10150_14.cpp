#include <bits/stdc++.h>
using namespace std;
int dp[2][505][505];
char mp[505][505];
const int mod = 1000000009;
int dis(int a, int b, int c, int d) { return abs(a - c) + abs(b - d) <= 1; }
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", mp[i]);
  if (mp[0][0] != mp[n - 1][m - 1]) {
    printf("0\n");
    return 0;
  }
  memset(dp, 0, sizeof(dp));
  dp[0][0][n - 1] = 1;
  int t = n + m;
  t /= 2;
  int ans = 0;
  for (int i = 1; i < t; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = n - 1; k >= j; k--) dp[i & 1][j][k] = 0;
    }
    for (int j = 0; j < n; j++) {
      for (int k = n - 1; k >= j; k--) {
        int m1 = i - j;
        int m2 = (n + m - 2 - k - i);
        if (m1 > m - 1) continue;
        if (m2 > m - 1) continue;
        if (mp[j][m1] != mp[k][m2]) continue;
        if (j > 0 && k < n - 1) dp[i & 1][j][k] += dp[!(i & 1)][j - 1][k + 1];
        if (j > 0 && m2 < m - 1) dp[i & 1][j][k] += dp[!(i & 1)][j - 1][k];
        if (dp[i & 1][j][k] >= mod) dp[i & 1][j][k] -= mod;
        if (m1 > 0 && k < n - 1) dp[i & 1][j][k] += dp[!(i & 1)][j][k + 1];
        if (dp[i & 1][j][k] >= mod) dp[i & 1][j][k] -= mod;
        if (m1 > 0 && m2 < m - 1) dp[i & 1][j][k] += dp[!(i & 1)][j][k];
        if (dp[i & 1][j][k] >= mod) dp[i & 1][j][k] -= mod;
        if (i == t - 1 && dis(j, m1, k, m2)) ans += dp[i & 1][j][k];
        if (ans >= mod) ans -= mod;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
