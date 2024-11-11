#include <bits/stdc++.h>
using namespace std;
int const N = 1024;
int const P = 1000000007;
long long dp[N][N];
long long sum[N];
int main() {
  memset(dp, 0, (sizeof dp));
  fill(dp[0] + 1, dp[0] + N, 1);
  for (int t = 1; t < N; ++t) {
    sum[0] = 0;
    partial_sum(dp[t - 1], dp[t - 1] + N - 1, sum + 1);
    for (int n_ = (N), i = 0; i < n_; ++i) sum[i] %= P;
    for (int k = 1; k < N; ++k) {
      dp[t][k] = dp[t][k - 1];
      dp[t][k] += sum[k - 2 + 1];
      dp[t][k] %= P;
    }
  }
  int n, m, K;
  while (scanf("%d%d%d", &n, &m, &K) == 3) {
    printf("%d\n", static_cast<int>(dp[K][n] * dp[K][m] % P));
  }
  return 0;
}
