#include <bits/stdc++.h>
const int MAXINT = 2147483640;
const long long MAXLL = 9223372036854775800LL;
const long long MAXN = 1100000;
const long long N = 1e3;
const long long MOD = 1e9 + 7;
const double eps = 1e-9;
using namespace std;
long long dp[2011][2011];
bool f[2011][2011];
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  dp[0][N] = 1;
  long long ans = 0;
  for (int i = 0; i < 2 * n; i++) {
    for (int j = 0; j <= 2 * N; j++)
      if (j >= N) {
        if (j + 1 <= 2 * N)
          dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
        if (j - 1 >= 0) dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % MOD;
      }
  }
  f[2 * n][N] = 1;
  for (int i = 2 * n; i > 0; i--) {
    for (int j = 0; j <= 2 * N; j++)
      if (j <= N) {
        if (j + 1 <= 2 * N) f[i - 1][j + 1] |= f[i][j];
        if (j - 1 >= 0) f[i - 1][j - 1] |= f[i][j];
      }
  }
  for (int i = 1; i < 2 * n; i += 2) {
    for (int j = 0; j <= 2 * N; j++)
      if (j >= N && f[i][2 * N - j]) {
        ans = (ans + dp[i][j]) % MOD;
      }
  }
  cout << ans << "\n";
  return 0;
}
