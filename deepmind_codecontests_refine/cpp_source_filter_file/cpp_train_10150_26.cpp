#include <bits/stdc++.h>
using namespace std;
long long i, j, n, k, k1, k2, k3, m, fldgjdflgjhrthrl, fldggfhfghjdflgjl,
    fldgjdflgrtyrtyjl, ffgfldgjdflgjl, h, x, y;
string s1, s2, s3, s;
long long dp[3][505][505];
char c[505][505];
int main() {
  cin >> n >> m;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) cin >> c[i][j];
  long long pos = (n + m - 2) / 2;
  if (c[0][0] == c[n - 1][m - 1]) dp[0][0][n - 1] = 1;
  for (int i = 0; i < pos; i++) {
    for (j = 0; j < n; j++)
      for (k = 0; k < n; k++) {
        dp[(i + 1) & 1][j][k] = 0;
        if (dp[i & 1][j][k] >= 1000000007) dp[i & 1][j][k] -= 1000000007;
      }
    for (int first_row = 0; first_row < n; first_row++)
      for (int last_row = 0; last_row < n; last_row++) {
        long long first_col = i - first_row;
        long long last_col = m - 1 - (i - (n - 1 - last_row));
        j = first_row;
        k = last_row;
        if (first_col < m - 1 && last_col > 0 &&
            c[first_row][first_col + 1] == c[last_row][last_col - 1])
          dp[(i + 1) & 1][j][k] = (dp[(i + 1) & 1][j][k] + dp[i & 1][j][k]);
        if (first_col < m - 1 && last_row > 0 &&
            c[first_row][first_col + 1] == c[last_row - 1][last_col])
          dp[(i + 1) & 1][j][k - 1] =
              (dp[(i + 1) & 1][j][k - 1] + dp[i & 1][j][k]);
        if (first_row < n - 1 && last_col > 0 &&
            c[first_row + 1][first_col] == c[last_row][last_col - 1])
          dp[(i + 1) & 1][j + 1][k] =
              (dp[(i + 1) & 1][j + 1][k] + dp[i & 1][j][k]);
        if (first_row < n - 1 && last_row > 0 &&
            c[first_row + 1][first_col] == c[last_row - 1][last_col])
          dp[(i + 1) & 1][j + 1][k - 1] =
              (dp[(i + 1) & 1][j + 1][k - 1] + dp[i & 1][j][k]);
      }
  }
  long long ans = 0;
  if ((n + m) % 2 == 0) {
    for (i = 0; i < n; i++) ans += dp[pos & 1][i][i];
    ans %= 1000000007;
    cout << ans << endl;
  } else {
    for (i = 0; i < n; i++) {
      long long first_col = pos - i;
      if (c[i][first_col] == c[i][first_col + 1]) ans += dp[pos & 1][i][i];
    }
    for (i = 0; i < n - 1; i++) {
      long long first_col = pos - i;
      if (c[i][first_col] == c[i + 1][first_col]) ans += dp[pos & 1][i][i + 1];
    }
    ans %= 1000000007;
    cout << ans << endl;
  }
  return 0;
}
