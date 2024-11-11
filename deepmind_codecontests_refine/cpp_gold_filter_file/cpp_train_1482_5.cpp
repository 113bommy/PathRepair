#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int mat[55][20005], a[55][20005];
int dp[55][20005], pref[55][20005], suff[55][20005];
int getpos(int i, int esq, int dir) {
  int res = -1e9;
  for (int j = esq; j <= dir; j++)
    res = max(res, dp[i][j] - mat[i + 1][j + k - 1]);
  return res;
}
int getneg(int i, int esq, int dir) {
  int res = -1e9;
  for (int j = esq; j <= dir; j++) res = max(res, dp[i][j] + mat[i + 1][j - 1]);
  return res;
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) mat[i][j] += mat[i][j - 1] + a[i][j];
  for (int j = 1; j + k - 1 <= m; j++) {
    int intervalsum = mat[1][j + k - 1] - mat[1][j - 1];
    intervalsum += mat[2][j + k - 1] - mat[2][j - 1];
    dp[1][j] = intervalsum;
  }
  for (int j = 1; j <= m; j++) pref[1][j] = max(pref[1][j - 1], dp[1][j]);
  for (int j = m; j >= 1; j--) suff[1][j] = max(suff[1][j + 1], dp[1][j]);
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j + k - 1 <= m; j++) {
      int s = 0;
      int intervalsum = mat[i][j + k - 1] - mat[i][j - 1];
      intervalsum += mat[i + 1][j + k - 1] - mat[i + 1][j - 1];
      int pp = getpos(i - 1, max(1, j - k + 1), j);
      int nn = getneg(i - 1, j + 1, min(m, j + k - 1));
      s = max(s, intervalsum + mat[i][j - 1] + pp);
      s = max(s, intervalsum - mat[i][j + k - 1] + nn);
      if (j - k >= 0) s = max(s, intervalsum + pref[i - 1][j - k]);
      if (j + k <= m) s = max(s, intervalsum + suff[i - 1][j + k]);
      dp[i][j] = s;
    }
    for (int j = 1; j <= m; j++) pref[i][j] = max(dp[i][j], pref[i][j - 1]);
    for (int j = m; j >= 1; j--) suff[i][j] = max(dp[i][j], suff[i][j + 1]);
  }
  int res = 0;
  for (int j = 1; j <= m; j++) res = max(res, dp[n][j]);
  cout << res << endl;
  return 0;
}
