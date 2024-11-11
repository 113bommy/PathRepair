#include <bits/stdc++.h>
using namespace std;
const int N = 110, M = 10;
char tab[N][N];
char pre[N][N][M];
int dp[N][N][M], MOD;
string str;
int back(int r, int c, int k) {
  if (r == 1) return c;
  int mod = (k - (tab[r][c] - '0') + 10 * MOD) % MOD,
      nc = pre[r][c][k] == 'L' ? c + 1 : c - 1, ans = back(r - 1, nc, mod);
  str += pre[r][c][k];
  return ans;
}
int main() {
  int n, m;
  scanf("%d %d %d", &n, &m, &MOD);
  MOD++;
  for (int i = 0; i < n; i++) scanf("%s", tab[n - i] + 1);
  for (int i = 1; i <= m; i++) fill(dp[0][i] + 1, dp[0][i] + MOD, INT_MIN);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int k = 0; k < MOD; k++) {
        dp[i][j][k] = INT_MIN;
        int mod = (k - (tab[i][j] - '0') + 10 * MOD) % MOD;
        if (j > 1 and dp[i - 1][j - 1][mod] > dp[i][j][k]) {
          dp[i][j][k] = dp[i - 1][j - 1][mod];
          pre[i][j][k] = 'R';
        }
        if (j < m and dp[i - 1][j + 1][mod] > dp[i][j][k]) {
          dp[i][j][k] = dp[i - 1][j + 1][mod];
          pre[i][j][k] = 'L';
        }
        dp[i][j][k] += tab[i][j] - '0';
      }
  int chosen = 0, ans = -1;
  for (int i = 1; i <= m; i++)
    if (dp[n][i][0] > ans) {
      ans = dp[n][i][0];
      chosen = i;
    }
  printf("%d\n", ans);
  if (ans > -1) {
    chosen = back(n, chosen, 0);
    printf("%d\n%s\n", chosen, str.c_str());
  }
  return 0;
}
