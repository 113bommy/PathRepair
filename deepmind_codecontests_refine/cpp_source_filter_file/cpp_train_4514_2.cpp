#include <bits/stdc++.h>
const int N = 105;
int n;
long long dp[2][N];
char s[N];
long long Dp(int k) {
  memset(dp, 0, sizeof dp);
  dp[k][0] = 1;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'B') {
      dp[0][i] = dp[0][i - 1];
    } else {
      if (s[i - 1] == 'B') {
        dp[1][i] = dp[0][i - 1];
        dp[0][i] = dp[0][i - 2] + dp[1][i - 2];
      } else {
        dp[1][i] = dp[0][i - 2] + dp[1][i - 2];
      }
    }
  }
  return dp[k][n];
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  int pos = -1;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'B') {
      pos = i;
      break;
    }
  }
  if (pos == -1) {
    puts("1");
    return 0;
  }
  for (int i = 1; i < pos; ++i) s[i + n] = s[i];
  for (int i = pos; i < pos + n; ++i) s[i - pos + 1] = s[i];
  printf("%lld\n", Dp(0) + Dp(1));
  return 0;
}
