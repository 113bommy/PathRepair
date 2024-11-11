#include <bits/stdc++.h>
char s[100001];
int pr[27];
int dp[2][27];
int min(int a, int b) { return a < b ? a : b; }
int main() {
  scanf(" %s", s);
  int n = strlen(s);
  int i, j, m;
  scanf("%d", &m);
  for (i = 0; i <= 26; i++) pr[i] = -1;
  for (i = 0; i < m; i++) {
    char a, b;
    scanf(" %c %c", &a, &b);
    a -= 'a';
    b -= 'a';
    pr[a] = b;
    pr[b] = a;
  }
  for (i = 0; i <= 26; i++) dp[0][i] = 100000000;
  dp[0][26] = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j <= 26; j++) dp[(i + 1) % 2][j] = dp[i % 2][j] + 1;
    for (j = 0; j <= 26; j++)
      if (pr[j] != s[i] - 'a') {
        dp[(i + 1) % 2][s[i] - 'a'] =
            min(dp[(i + 1) % 2][s[i] - 'a'], dp[i % 2][j]);
      }
  }
  int ans = 100000000;
  for (i = 0; i <= 26; i++) ans = min(ans, dp[n % 2][i]);
  printf("%d\n", ans);
  return 0;
}
