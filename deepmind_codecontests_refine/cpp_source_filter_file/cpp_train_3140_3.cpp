#include <bits/stdc++.h>
using namespace std;
int n, dp[2005][2005];
int tp[2005], tot;
char s[2005];
void Error() { puts("0"), exit(0); }
int main() {
  scanf("%s", s + 1), n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    if (isdigit(s[i]) && isdigit(s[i + 1])) continue;
    if (isdigit(s[i]))
      tp[++tot] = 1;
    else {
      if (s[i + 1] == '*' || s[i + 1] == '/') Error();
      if (s[i] == '+' || s[i] == '-')
        tp[++tot] = -1;
      else
        tp[++tot] = -2;
    }
  }
  if (tp[1] < 0 || tp[tot] < 0) Error();
  dp[0][0] = 1;
  for (int i = 1; i <= tot; i++) {
    if (tp[i] < 0)
      if (tp[i + 1] > 0) {
        dp[i][tot + 1] = dp[i - 1][tot];
        for (int j = tot; j >= 1; j--)
          dp[i][j] = dp[i][j + 1] + dp[i - 1][j - 1],
          (dp[i][j] >= 1000003) && (dp[i][j] -= 1000003);
        dp[i][0] = dp[i][1];
      } else
        for (int j = 1; j <= tot; j++) dp[i][j] = dp[i - 1][j - 1];
    else
      memcpy(dp[i], dp[i - 1], sizeof dp[i - 1]);
  }
  printf("%d\n", dp[tot][0]);
  return 0;
}
