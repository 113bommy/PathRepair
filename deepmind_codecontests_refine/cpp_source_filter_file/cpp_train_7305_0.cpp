#include <bits/stdc++.h>
const int INF = 1 << 28;
const long long LINF = 1LL << 59LL;
const long long MOD = 1000000007;
const int MAXN = 1000007;
using namespace std;
int main() {
  int T;
  cin >> T;
  int n;
  unsigned long long b, p;
  string s;
  while (T--) {
    cin >> n >> b >> p >> s;
    unsigned long long dp[3][n + 2];
    for (auto i = 0; i != 3; i++)
      for (auto j = 0; j != n + 2; j++) dp[i][j] = 0;
    dp[1][1] = p;
    dp[2][1] = 2 * p;
    for (auto i = 2; i <= n; i++) {
      if (s[i - 1] == '1') {
        dp[2][i] =
            min(dp[2][i - 1] + b + (2 * p), dp[1][i - 1] + (2 * b) + (2 * p));
        dp[1][i] = dp[2][i];
      } else {
        if ((i > 2) && (s[i - 2] == '1')) {
          dp[1][i] = dp[2][i - 1] + (2 * b) + (2 * p);
          dp[2][i] = dp[2][i - 1] + b + (2 * p);
        } else {
          dp[1][i] =
              min(dp[1][i - 1] + b + p, dp[2][i - 1] + (2 * b) + (2 * p));
          dp[2][i] =
              min(dp[1][i - 1] + (2 * b) + (2 * p), dp[2][i - 1] + b + (2 * p));
        }
      }
    }
    dp[1][n + 1] = min(dp[1][n] + p + b, dp[2][n] + (2 * p) + (2 * b));
    dp[2][n + 1] = min(dp[1][n] + (2 * p) + (2 * b), dp[2][n] + b + (2 * p));
    cout << dp[1][n + 1] << "\n";
  }
  return 0;
}
