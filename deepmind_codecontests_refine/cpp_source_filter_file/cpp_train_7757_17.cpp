#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;
const int L = 2000;
long long dp[2001][2001];
int main(void) {
  int n, m;
  cin >> n >> m;
  int openLeft = 0, openRight = 0;
  char ch;
  scanf("%c", &ch);
  for (int i = 0; i < m; i++) {
    scanf("%c", &ch);
    if (ch == '(') {
      ++openRight;
    } else {
      if (openRight > 0)
        --openRight;
      else
        ++openLeft;
    }
  }
  memset(dp, 0, sizeof(dp));
  dp[0][0] = dp[1][1] = 1LL;
  for (int i = 2; i <= n - m; i++) {
    for (int j = 0; j < i; ++j) {
      dp[i][j + 1] += dp[i - 1][j];
      dp[i][j + 1] %= MOD;
      if (j > 0) {
        dp[i][j - 1] += dp[i - 1][j];
        dp[i][j - 1] %= MOD;
      }
    }
  }
  long long ans = 0LL;
  for (int i = 0; i <= n - m; i++) {
    for (int j = 0; j <= i; j++) {
      int r = j - openRight + openLeft;
      if (r >= 0 && r <= n - m && j >= openLeft && r >= openRight) {
        ans += (dp[i][j] * dp[n - m - i][r]) % MOD;
        ans %= MOD;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
