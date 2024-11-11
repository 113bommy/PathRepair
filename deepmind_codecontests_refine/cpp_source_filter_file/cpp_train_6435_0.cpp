#include <bits/stdc++.h>
using namespace std;
int main() {
  string K;
  int D;
  cin >> K >> D;
  static long long dp[10001][2][100] = {};
  dp[0][0][0] = 1;
  for (size_t i = 0; i < K.size(); ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < D; ++k) {
        for (int d = 0; d <= (j ? 9 : K[i] - '0'); ++d) {
          dp[i + 1][j || d < K[i] - '0'][(k + d) % D] =
              (dp[i + 1][j || d < K[i] - '0'][(k + d) % D] + dp[i][j][k]) %
              1000000007;
        }
      }
    }
  }
  long long ans = dp[K.size()][0][0];
  ans = (ans + dp[K.size()][1][0] - 1) % 1000000007;
  ans = (ans + 1000000006) % 1000000007;
  cout << ans << endl;
}
