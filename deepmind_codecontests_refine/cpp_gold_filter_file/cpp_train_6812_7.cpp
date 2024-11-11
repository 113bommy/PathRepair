#include <bits/stdc++.h>
using namespace std;
const int maxn = 110, maxm = 15;
int dp[maxn][maxn][12];
int pre[maxn][maxn][12], Pre[maxn][maxn][12];
int a[maxn][maxn];
int n, m, k;
char Ans[maxn];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  k++;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      char c = 0;
      while (!isdigit(c)) c = getchar();
      a[i][j] = c - 48;
    }
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < m; ++i) dp[n - 1][i][a[n - 1][i] % k] = a[n - 1][i];
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < m; ++j)
      for (int l = 0; l < k; ++l) {
        int h = (l - a[i][j] + (k << 4)) % k;
        if (j != 0 && dp[i + 1][j - 1][h] > -1 &&
            dp[i + 1][j - 1][h] + a[i][j] >= dp[i][j][l])
          dp[i][j][l] = dp[i + 1][j - 1][h] + a[i][j], pre[i][j][l] = 1,
          Pre[i][j][l] = h;
        if (j != m - 1 && dp[i + 1][j + 1][h] > -1 &&
            dp[i + 1][j + 1][h] + a[i][j] >= dp[i][j][l])
          dp[i][j][l] = dp[i + 1][j + 1][h] + a[i][j], pre[i][j][l] = 2,
          Pre[i][j][l] = h;
      }
  }
  int ans = -1, st;
  for (int i = 0; i < m; ++i)
    if (dp[0][i][0] > ans) ans = dp[0][i][0], st = i;
  printf("%d\n", ans);
  int nowx = 0, nowy = st, nowz = 0;
  if (ans == -1) return 0;
  while (nowx != n - 1) {
    if (pre[nowx][nowy][nowz] == 1)
      Ans[nowx] = 'R', nowz = Pre[nowx][nowy][nowz], nowy--;
    else
      Ans[nowx] = 'L', nowz = Pre[nowx][nowy][nowz], nowy++;
    nowx++;
  }
  printf("%d\n", nowy + 1);
  for (int i = n - 2; i >= 0; --i) putchar(Ans[i]);
}
