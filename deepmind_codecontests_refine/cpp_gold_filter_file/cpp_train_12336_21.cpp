#include <bits/stdc++.h>
using namespace std;
int dp[1111][1111];
char s[1111], t[1111];
int n, m;
int main() {
  int i, j, k;
  scanf("%s%s", s, t);
  n = strlen(s);
  m = strlen(t);
  memset(dp, 10, sizeof(dp));
  for (i = 0; i <= m; i++) dp[0][i] = i;
  for (i = 0; i <= n; i++) dp[i][0] = i;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= m; j++) {
      if (j && dp[i][j] > dp[i][j - 1] + 1) dp[i][j] = dp[i][j - 1] + 1;
      if (i && dp[i][j] > dp[i - 1][j] + 1) dp[i][j] = dp[i - 1][j] + 1;
      if (i && j && dp[i][j] > dp[i - 1][j - 1] + 1)
        dp[i][j] = dp[i - 1][j - 1] + 1;
      if (i && j && s[i - 1] == t[j - 1] && dp[i][j] > dp[i - 1][j - 1])
        dp[i][j] = dp[i - 1][j - 1];
    }
  }
  printf("%d\n", dp[n][m]);
  while (n > 0 || m > 0) {
    if (m && dp[n][m - 1] + 1 == dp[n][m]) {
      printf("INSERT %d %c\n", n + 1, t[m - 1]);
      m--;
      continue;
    }
    if (n && dp[n - 1][m] + 1 == dp[n][m]) {
      printf("DELETE %d\n", n);
      n--;
      continue;
    }
    if (n && m && dp[n - 1][m - 1] + 1 == dp[n][m]) {
      printf("REPLACE %d %c\n", n, t[m - 1]);
      n--;
      m--;
      continue;
    }
    n--;
    m--;
  }
  return 0;
}
