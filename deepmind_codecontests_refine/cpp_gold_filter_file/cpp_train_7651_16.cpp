#include <bits/stdc++.h>
using namespace std;
const int MAXn = 50 + 30;
const long long INF = 1ll << 50;
long long dp[MAXn][MAXn][MAXn];
long long solve(int n, int m, int k) {
  if (n > m) swap(n, m);
  if (dp[n][m][k] != -1) return dp[n][m][k];
  if (k == 0 || k == m * n) return dp[n][m][k] = 0;
  if (n == 1) {
    if (k == 0 || k == m)
      return dp[n][m][k] = 0;
    else if (k < m)
      return dp[n][m][k] = 1;
    else
      return INF;
  }
  long long ans = INF;
  for (int i = 1; i < n; i++)
    for (int j = 0; j <= k; j++)
      ans = min(ans, solve(i, m, j) + solve(n - i, m, k - j) + m * m);
  for (int i = 1; i < m; i++)
    for (int j = 0; j <= k; j++)
      ans = min(ans, solve(n, i, j) + solve(n, m - i, k - j) + n * n);
  return dp[n][m][k] = ans;
}
int main() {
  int t, m, n, k;
  for (int i = 0; i < MAXn; i++)
    for (int j = 0; j < MAXn; j++)
      for (int l = 0; l < MAXn; l++) dp[i][j][l] = -1;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    long long ans = solve(n, m, k);
    cout << ans << endl;
  }
  return 0;
}
