#include <bits/stdc++.h>
using namespace std;
int N, M, X;
const int MM = 1e5 + 5, MN = 350;
const long long MOD = 1e9 + 7;
long long dp[2][MN][MN];
bool cur = 1;
int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  cin >> N >> M >> X;
  if (N > M) {
    cout << "0" << endl;
    return 0;
  }
  dp[0][0][0] = 1;
  for (int i = 1; i <= M; i++) {
    for (int j = 0; j <= min(i, N); j++) {
      for (int k = 0; k <= min(i, N); k++) {
        dp[cur][j][k] = 0;
        if (i == X) {
          if (j > 0 && k > 0) {
            dp[cur][j][k] += dp[!cur][j - 1][k - 1];
          }
          if (k > 0) dp[cur][j][k] += dp[!cur][j][k - 1];
        } else {
          if (j > 0 && k > 0) dp[cur][j][k] += dp[!cur][j - 1][k - 1];
          dp[cur][j][k] += dp[!cur][j][k] + dp[!cur][j + 1][k];
          if (k > 0) dp[cur][j][k] += dp[!cur][j][k - 1];
        }
        dp[cur][j][k] %= MOD;
      }
    }
    cur ^= 1;
  }
  long long fact = 1;
  for (int i = 1; i <= N; i++) fact = fact * i % MOD;
  cout << dp[!cur][0][N] * fact % MOD << endl;
}
