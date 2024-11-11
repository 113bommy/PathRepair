#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int dp[1001][1001];
void fillDP() {
  for (int k = 0; k <= 1000; ++k) {
    for (int n = 0; n <= 2 * k && n <= 1000; ++n) dp[k][n] = 0;
    int sum = 1;
    for (int n = 2 * k + 1; n <= 1000; ++n) {
      if (k == 0)
        dp[k][n] = 1;
      else {
        dp[k][n] = (dp[k][n - 1] + sum) % MOD;
        sum += dp[k - 1][n - 1];
        sum %= MOD;
      }
    }
  }
}
int N, M, K;
int main() {
  fillDP();
  scanf("%d%d%d", &N, &M, &K);
  printf("%lld\n", 1LL * dp[K][N] * dp[K][M]);
}
