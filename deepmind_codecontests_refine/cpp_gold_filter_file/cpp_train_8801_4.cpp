#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int> > p(n, vector<int>(m + 1));
  vector<vector<vector<long long> > > dp(
      n + 1, vector<vector<long long> >(m + 1, vector<long long>(k + 1, 1e18)));
  for (int j = 0; j < m; j++) {
    dp[0][j][0] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> p[i][j + 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i - 1] == 0) {
      for (int j1 = 1; j1 <= m; j1++) {
        for (int j2 = 0; j2 <= m; j2++) {
          for (int u = 1; u <= k; u++) {
            if (j1 == j2) {
              dp[i][j1][u] = min(dp[i][j1][u], dp[i - 1][j2][u] + p[i - 1][j1]);
            } else {
              dp[i][j1][u] =
                  min(dp[i][j1][u], dp[i - 1][j2][u - 1] + p[i - 1][j1]);
            }
          }
        }
      }
    } else {
      for (int j2 = 0; j2 <= m; j2++) {
        for (int u = 1; u <= k; u++) {
          if (j2 == a[i - 1]) {
            dp[i][a[i - 1]][u] = min(dp[i][a[i - 1]][u], dp[i - 1][j2][u]);
          } else {
            dp[i][a[i - 1]][u] = min(dp[i][a[i - 1]][u], dp[i - 1][j2][u - 1]);
          }
        }
      }
    }
  }
  long long minl = 1e18;
  for (int j = 1; j <= m; j++) {
    minl = min(minl, dp[n][j][k]);
  }
  if (minl == 1e18) {
    cout << -1;
  } else {
    cout << minl;
  }
  return 0;
}
