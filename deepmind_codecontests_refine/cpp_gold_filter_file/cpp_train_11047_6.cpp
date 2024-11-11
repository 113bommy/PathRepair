#include <bits/stdc++.h>
using namespace std;
#pragma GCC push_options
#pragma GCC optimize("unroll-loops")
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  long long dp[n + 1][m + 1];
  memset(dp, 0ll, sizeof(dp));
  long long ab[m + 1], c[m + 1], d[m + 1];
  cin >> c[0] >> d[0];
  for (int i = 1; i <= m; i++) {
    long long temp1, temp2;
    cin >> temp1 >> temp2;
    ab[i] = temp1 / temp2;
    cin >> c[i] >> d[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (j == 0) {
        if (i - c[0] >= 0) dp[i][0] = dp[i - c[0]][0] + d[0];
      } else {
        for (int k = 0; k <= ab[j]; k++) {
          if (i - c[j] * k >= 0)
            dp[i][j] = max(dp[i][j], dp[i - c[j] * k][j - 1] + k * d[j]);
        }
      }
    }
  }
  cout << dp[n][m] << "\n";
  return 0;
}
