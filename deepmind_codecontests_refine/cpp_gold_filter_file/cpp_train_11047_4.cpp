#include <bits/stdc++.h>
using namespace std;
int v[2 * 1000 + 1], P[2 * 1000 + 1], dp[2 * 1000 + 1][1000 + 1];
int main() {
  int n, m, a, b, c, d, i, k;
  cin >> n >> m >> c >> d;
  i = c;
  k = 0;
  while (i <= n) {
    v[++k] = c;
    P[k] = d;
    i += c;
  }
  for (i = 1; i <= m; i++) {
    cin >> a >> b >> c >> d;
    int j = b;
    int jj = c;
    while (j <= a && jj <= n) {
      v[++k] = c;
      P[k] = d;
      j += b;
      jj += c;
    }
  }
  for (i = 1; i <= k; i++)
    for (int j = 0; j <= n; j++) {
      if (j - v[i] >= 0)
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + P[i]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  cout << dp[k][n];
  return 0;
}
