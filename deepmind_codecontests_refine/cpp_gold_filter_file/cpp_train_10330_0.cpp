#include <bits/stdc++.h>
char s[410], t[410];
int dp[410], n, m, T;
bool gao(int ed) {
  memset(dp, -1, sizeof dp);
  dp[0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = ed; j >= 0; j--)
      if (dp[j] != -1) {
        if (s[i] == t[j + 1]) dp[j + 1] = std::max(dp[j + 1], dp[j]);
        if (t[ed + dp[j] + 1] == s[i]) dp[j]++;
      }
  return dp[ed] >= m - ed;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%s%s", s + 1, t + 1);
    n = strlen(s + 1), m = strlen(t + 1);
    for (int i = 1; i <= m; i++)
      if (gao(i)) {
        puts("YES");
        goto loop;
      }
    puts("NO");
  loop:;
  }
  return 0;
}
