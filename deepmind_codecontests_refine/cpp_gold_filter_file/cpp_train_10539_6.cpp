#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3005;
const int MOD = 998244353;
int dp[MAXN][MAXN];
char s[MAXN], t[MAXN];
int main() {
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  int n = strlen(s + 1);
  int m = strlen(t + 1);
  for (int i = 1; i <= n; i++)
    if (s[1] == t[i] || i > m) dp[i][i] = 1;
  for (int len = 2; len <= n; len++)
    for (int i = 1; i <= n - len + 1; i++) {
      int j = i + len - 1;
      if (j > m || s[len] == t[j]) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
      if (i > m || s[len] == t[i]) dp[i][j] = (dp[i][j] + dp[i + 1][j]) % MOD;
    }
  int ans = 0;
  for (int i = m; i <= n; i++) ans = (ans + dp[1][i]) % MOD;
  printf("%d\n", ans * 2 % MOD);
  return 0;
}
