#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long dp[200003][3];
int main() {
  long long cnt = 1;
  int n;
  scanf("%d\n", &n);
  for (int i = 1; i <= n; i++) {
    char c;
    scanf("%c", &c);
    if (c == 'a' || c == '?') dp[i][0] += cnt;
    if (c == 'b' || c == '?') dp[i][1] += dp[i - 1][0];
    if (c == 'c' || c == '?') dp[i][2] += dp[i - 1][1];
    if (c == '?') {
      cnt = (cnt * 3) % MOD;
      dp[i][0] += 3 * dp[i - 1][0];
      dp[i][1] += 3 * dp[i - 1][1];
      dp[i][2] += 3 * dp[i - 1][2];
      dp[i][0] %= MOD;
      dp[i][1] %= MOD;
      dp[i][2] %= MOD;
    } else {
      dp[i][0] += dp[i - 1][0];
      dp[i][1] += dp[i - 1][1];
      dp[i][2] += dp[i - 1][2];
      dp[i][0] %= MOD;
      dp[i][1] %= MOD;
      dp[i][2] %= MOD;
    }
  }
  printf("%lld\n", dp[n][2]);
}
