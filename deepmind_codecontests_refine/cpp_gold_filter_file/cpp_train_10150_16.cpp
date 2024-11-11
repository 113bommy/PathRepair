#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7, n, m, dp[2][502][502], adj[502][502], x, y;
long long ans = 0;
char c;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  x = n;
  y = m + 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> c;
      adj[i][j] = c;
    }
  if (adj[1][1] == adj[n][m])
    dp[0][1][n] = dp[1][1][n] = 1;
  else {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    long long tmp = 0;
    for (int j = 1; j <= m; j++) {
      if (i == 1 && j == 1) continue;
      for (int k = i; k <= n; k++) {
        int c1 = n + m - i - j - k + 2;
        if (c1 < j || c1 > m) continue;
        if (adj[i][j] == adj[k][c1]) {
          tmp = 0;
          if (i >= 2 && j >= 2)
            tmp = (dp[0][j][k] + dp[0][j][k + 1] + dp[1][i][k] +
                   dp[1][i][k + 1]) %
                  mod;
          else {
            if (i >= 2) tmp = (tmp + dp[0][j][k]) % mod;
            if (i >= 2 && k < n) tmp = (tmp + dp[0][j][k + 1]) % mod;
            if (j >= 2) tmp = (tmp + dp[1][i][k]) % mod;
            if (j >= 2 && k < n) tmp = (tmp + dp[1][i][k + 1]) % mod;
          }
          if (i == 1 && j == 1) tmp = 1;
          dp[0][j][k] = dp[1][i][k] = tmp;
          if (j + i - 1 == (n + m) / 2) ans = (ans + tmp) % mod;
        } else
          dp[0][j][k] = dp[1][i][k] = 0;
      }
    }
  }
  cout << ans;
  return 0;
}
