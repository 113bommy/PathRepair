#include <bits/stdc++.h>
using namespace std;
double ncr[55][55];
int arr[55];
double dp[55][55][55], dp2[55][55][55];
int vis[55][55][55];
int n, m;
double f(int pos, int st, int ln) {
  if (pos == m) {
    if (st > 0) return 0.0;
    dp2[pos][st][ln] = 1;
    dp[pos][st][ln] = ln;
    return ln;
  }
  if (vis[pos][st][ln]) return dp[pos][st][ln];
  vis[pos][st][ln] = 1;
  for (int i = 0; i <= st; i++) {
    int mx_ln = max(ln, (i + arr[pos] - 1) / arr[pos]);
    if (pos == m - 1 && i != st) continue;
    dp[pos][st][ln] += ncr[st][i] * f(pos + 1, st - i, mx_ln);
    dp2[pos][st][ln] += ncr[st][i] * dp2[pos + 1][st - i][mx_ln];
  }
  return dp[pos][st][ln];
}
int main() {
  ncr[0][0] = 1;
  for (int i = 1; i <= 54; i++) {
    ncr[i][0] = 1;
    for (int j = 1; j <= i; j++) ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
  }
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> arr[i];
  f(0, n, 0);
  cout << fixed << setprecision(20) << dp[0][n][0] / dp2[0][n][0] << '\n';
  return 0;
}
