#include <bits/stdc++.h>
using namespace std;
double dp[2020][2020];
bool bc[2020], br[2020];
int n, m, r, c;
int main() {
  cin >> n >> m;
  r = c = n;
  for (int i = 0, a, b; i < m; i++) {
    cin >> a >> b;
    if (!br[a]) r--;
    if (!br[b]) c--;
    br[a] = br[b] = 1;
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i - 1][0] + 1.0 * n / i;
    dp[0][i] = dp[0][i - 1] + 1.0 * n / i;
  }
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      dp[i][j] = 1. + (i * j * dp[i - 1][j - 1] + i * (n - j) * dp[i - 1][j] +
                       (n - i) * j * dp[i][j - 1]) /
                          (n * n);
      dp[i][j] /= (1. - 1. * (n - i) * (n - j) / (n * n));
    }
  }
  cout << setprecision(12) << dp[r][c];
  return 0;
}
