#include <bits/stdc++.h>
using namespace std;
double dp[201][201][508];
double a[201];
int c[201];
int main() {
  int n, l, k;
  cin >> n >> l >> k;
  dp[0][0][203 + k] = 1.;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] /= 100.;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int z = -202; z <= 202; ++z) {
        int next = z + c[i];
        next += 203;
        if (next > 406) next = 406;
        if (j > 0) dp[i][j][next] += a[i] * dp[i - 1][j - 1][z + 203];
        dp[i][j][z + 203] += (1. - a[i]) * dp[i - 1][j][z + 203];
      }
    }
  }
  double ans = 0;
  for (int j = l; j <= n; ++j)
    for (int z = 203; z <= 406; ++z) {
      ans += dp[n][j][z];
    }
  cout << fixed << setprecision(9) << ans;
  return 0;
}
