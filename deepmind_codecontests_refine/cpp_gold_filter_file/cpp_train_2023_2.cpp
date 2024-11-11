#include <bits/stdc++.h>
using namespace std;
char str[1000100];
long long dp[1000100][5];
long long solve(int n) {
  int i;
  memset(dp, 0, sizeof(dp));
  if (str[0] == '?')
    dp[0][0] = dp[0][1] = dp[0][4] = 1;
  else if (str[0] == '*')
    dp[0][4] = 1;
  else if (str[0] < '2')
    dp[0][str[0] - '0'] = 1;
  for (i = 1; i < n; ++i) {
    if (str[i] == '?') {
      dp[i][0] = (dp[i - 1][0] + dp[i - 1][3]) % 1000000007;
      dp[i][1] = (dp[i - 1][0] + dp[i - 1][3]) % 1000000007;
      dp[i][2] = dp[i - 1][4];
      dp[i][3] = dp[i - 1][4];
      dp[i][4] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % 1000000007;
    } else if (str[i] == '*') {
      dp[i][4] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % 1000000007;
    } else if (str[i] == '0') {
      dp[i][0] = (dp[i - 1][0] + dp[i - 1][3]) % 1000000007;
    } else if (str[i] == '1') {
      dp[i][1] = (dp[i - 1][0] + dp[i - 1][3]) % 1000000007;
      dp[i][3] = dp[i - 1][4];
    } else {
      dp[i][2] = dp[i - 1][4];
    }
  }
  return (dp[n - 1][0] + dp[n - 1][3] + dp[n - 1][4]) % 1000000007;
}
int main() {
  int n;
  while (~scanf("%s", str)) {
    n = strlen(str);
    printf("%I64d\n", solve(n));
  }
  return 0;
}
