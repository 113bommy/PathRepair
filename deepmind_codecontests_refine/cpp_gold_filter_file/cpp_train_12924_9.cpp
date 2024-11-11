#include <bits/stdc++.h>
long long ans, dp[100050][12];
char s[100050];
void upd(long long &a, long long b) { a += b; }
int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    int c = s[i] - '0';
    if (c) dp[i][c] = 1;
    for (int j = c + 1; j <= 10; j++)
      upd(dp[i][(j * (j - 1) / 2 + c + 10) % 11], dp[i - 1][j]);
    for (int j = 0; j <= 10; j++) upd(ans, dp[i][j]);
  }
  printf("%lld\n", ans);
  return 0;
}
