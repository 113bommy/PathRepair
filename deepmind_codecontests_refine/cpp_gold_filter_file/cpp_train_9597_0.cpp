#include <bits/stdc++.h>
using namespace std;
const int Z = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  bool s[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      s[i][j] = c == '.';
    }
  }
  if (n == 1 && m == 1) {
    cout << 1 << endl;
    return 0;
  }
  int dr[n][m], rr[n][m];
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      dr[i][j] = i == n - 1 ? 0 : dr[i + 1][j] + !s[i + 1][j];
      rr[i][j] = j == m - 1 ? 0 : rr[i][j + 1] + !s[i][j + 1];
    }
  }
  int dp[n][m][2], ps[n + 1][m + 1][2];
  memset(dp, 0, sizeof(dp));
  memset(ps, 0, sizeof(ps));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (i == n - 1 && j == m - 1) {
        dp[i][j][0] = dp[i][j][1] = s[i][j];
      } else {
        if (i < n - 1) {
          dp[i][j][0] = (ps[i + 1][j][1] - ps[n - dr[i][j]][j][1] + Z) % Z;
        }
        if (j < m - 1) {
          dp[i][j][1] = (ps[i][j + 1][0] - ps[i][m - rr[i][j]][0] + Z) % Z;
        }
      }
      ps[i][j][0] = (ps[i][j + 1][0] + dp[i][j][0]) % Z;
      ps[i][j][1] = (ps[i + 1][j][1] + dp[i][j][1]) % Z;
    }
  }
  int ans = (dp[0][0][0] + dp[0][0][1]) % Z;
  cout << ans << endl;
  return 0;
}
