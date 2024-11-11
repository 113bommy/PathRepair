#include <bits/stdc++.h>
using namespace std;
int n, l, k;
double dp[203][203][203];
double p[203];
int a[203], b[203];
int main() {
  cin >> n >> l >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    p[i] /= 100;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i <= k + n; ++i) {
    dp[0][0][i] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int c = 0; c <= n + n; ++c) {
        dp[i][j][c] += p[i] * (dp[i - 1][j - 1][max(0, c - a[i])]);
        dp[i][j][c] += (1 - p[i]) * dp[i - 1][j][c];
      }
    }
  }
  double sol = 0;
  for (int i = l; i <= n; ++i) {
    sol += dp[n][i][n];
  }
  cout << fixed << setprecision(10) << sol << "\n";
  return 0;
}
