#include <bits/stdc++.h>
using namespace std;
const int maxn = 1550;
long long sum[maxn][maxn];
long long l[maxn][maxn], r[maxn][maxn];
long long dp[maxn][maxn];
long long x;
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%lld", &x);
      sum[i][j] = sum[i][j - 1] + x;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = -1e17;
    }
  }
  for (int i = 1; i <= m; i++) dp[1][i] = sum[1][i];
  l[1][1] = dp[1][1];
  for (int i = 2; i <= m; i++) l[1][i] = max(l[1][i - 1], dp[1][i]);
  r[1][m] = dp[1][m];
  for (int i = m - 1; i >= 1; i--) r[1][i] = max(r[1][i + 1], dp[1][i]);
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i % 2 == 0) {
        if (j == m) continue;
        dp[i][j] = r[i - 1][j + 1] + sum[i][j];
      } else {
        if (j == 1) continue;
        dp[i][j] = l[i - 1][j - 1] + sum[i][j];
      }
    }
    l[i][1] = dp[i][1];
    for (int j = 2; j <= m; j++) l[i][j] = max(l[i][j - 1], dp[i][j]);
    r[i][m] = dp[i][m];
    for (int j = m - 1; j >= 1; j--) r[i][j] = max(r[i][j + 1], dp[i][j]);
  }
  printf("%d\n", l[n][m]);
  return 0;
}
