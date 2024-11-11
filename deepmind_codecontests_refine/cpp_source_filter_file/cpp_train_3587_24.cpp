#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, maxn = 1505;
int n, m, s[maxn][maxn];
long long dp[maxn][maxn], l[maxn], r[maxn];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int a;
      scanf("%d", &a);
      s[i][j] = s[i][j - 1] + a;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) dp[i][j] = -1e18;
  for (int j = 1; j <= m; j++) dp[1][j] = s[1][j];
  r[m] = dp[1][m];
  for (int j = m - 1; j >= 1; j--) r[j] = max(r[j + 1], dp[1][j]);
  l[1] = dp[1][1];
  for (int j = 2; j <= m; j++) l[j] = max(l[j - 1], dp[1][j]);
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if ((i & 1) && j > 1 && l[j - 1] != -1e18)
        dp[i][j] = max(dp[i][j], l[j - 1] + s[i][j]);
      else if (!(i & 1) && j < m && r[j + 1] != -1e18)
        dp[i][j] = max(dp[i][j], r[j + 1] + s[i][j]);
    }
    r[m] = dp[i][m];
    for (int j = m - 1; j >= 1; j--) r[j] = max(r[j + 1], dp[i][j]);
    l[1] = dp[i][1];
    for (int j = 2; j <= m; j++) l[j] = max(l[j - 1], dp[i][j]);
  }
  printf("%I64d\n", l[n]);
  return 0;
}
