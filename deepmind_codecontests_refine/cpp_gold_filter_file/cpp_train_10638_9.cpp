#include <bits/stdc++.h>
using std::max;
char S[1001000];
int dp[2000100], n, ans;
int main() {
  scanf("%s", S + 1);
  n = strlen(S + 1);
  for (int i = 1; i <= n; i++) {
    int s = 0;
    for (int j = 1; j <= 20 && i + j - 1 <= n; j++) {
      int x = S[i + j - 1] - 'a';
      if (s & (1 << x)) break;
      s |= (1 << x);
      dp[s] = j;
    }
  }
  for (int i = 0; i < (1 << 20); i++)
    for (int j = 0; j < 20; j++)
      if (i & (1 << j)) dp[i] = max(dp[i], dp[i ^ (1 << j)]);
  for (int i = 0; i < (1 << 20); i++) {
    int s = i, t = ((1 << 20) - 1) - s;
    ans = max(ans, dp[s] + dp[t]);
  }
  printf("%d\n", ans);
}
