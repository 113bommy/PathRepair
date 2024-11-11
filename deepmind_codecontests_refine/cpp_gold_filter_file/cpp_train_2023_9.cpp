#include <bits/stdc++.h>
using namespace std;
long long dp[2][9];
char s[1000006];
int main() {
  scanf("%s", s);
  int len = strlen(s);
  memset(dp, 0, sizeof(dp));
  dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = 1;
  int now = 0, pre = 1;
  for (int i = 0; i < len; i++) {
    memset(dp[now], 0, sizeof(dp[now]));
    if (s[i] == '0' || s[i] == '?') {
      dp[now][0] = (dp[pre][0] + dp[pre][2]) % 1000000007;
      dp[now][2] = dp[pre][6];
    }
    if (s[i] == '1' || s[i] == '?') {
      dp[now][1] = (dp[pre][0] + dp[pre][2]) % 1000000007;
      dp[now][3] = dp[pre][6];
      dp[now][6] = (dp[pre][4] + dp[pre][5] + dp[pre][8]) % 1000000007;
    }
    if (s[i] == '2' || s[i] == '?') {
      dp[now][7] = (dp[pre][4] + dp[pre][5] + dp[pre][8]) % 1000000007;
    }
    if (s[i] == '*' || s[i] == '?') {
      dp[now][4] = (dp[pre][1] + dp[pre][3]) % 1000000007;
      dp[now][5] = dp[pre][7];
      dp[now][8] = (dp[pre][4] + dp[pre][5] + dp[pre][8]) % 1000000007;
    }
    now = !now, pre = !pre;
  }
  long long ans = dp[pre][0] + dp[pre][2] + dp[pre][4] + dp[pre][5] +
                  dp[pre][6] + dp[pre][8];
  printf("%I64d\n", ans % 1000000007);
  return 0;
}
