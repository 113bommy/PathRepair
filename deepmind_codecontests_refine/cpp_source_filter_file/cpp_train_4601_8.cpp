#include <bits/stdc++.h>
using namespace std;
const long long N = 2e6;
const long long mod = 998244353;
int32_t main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n + 1], b[n + 1];
    for (long long i = 1; i <= n; i++) cin >> a[i] >> b[i];
    long long dp[n + 1][3];
    for (long long i = 0; i <= n; i++)
      for (long long j = 0; j < 3; j++) dp[i][j] = 1e9;
    dp[1][0] = 0, dp[1][1] = b[1], dp[1][2] = 2 * b[1];
    for (long long i = 2; i <= n; i++) {
      for (long long j = 0; j < 3; j++) {
        for (long long k = 0; k < 3; k++) {
          if ((a[i] + j) != (a[i - 1] + k)) {
            dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * b[i]);
          }
        }
      }
    }
    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
  }
  return 0;
}
