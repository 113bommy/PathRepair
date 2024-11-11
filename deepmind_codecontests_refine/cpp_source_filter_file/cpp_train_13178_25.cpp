#include <bits/stdc++.h>
char s[5000005];
int dp[5000005];
int main() {
  scanf("%s", s);
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  unsigned long long ha = s[0];
  unsigned long long haf = s[0];
  unsigned long long hb = 1;
  int ans = 1;
  for (int i = 1; s[i]; i++) {
    hb *= 131;
    ha = ha * 131 + s[i];
    haf = s[i] * hb + haf;
    if (ha == haf) dp[i] = dp[(i - 1) >> 1] + 1;
    ans += dp[i];
  }
  printf("%d/n", ans);
  return 0;
}
