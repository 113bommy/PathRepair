#include <bits/stdc++.h>
using namespace std;
int n;
int K;
long long dp[501][501];
long long sum[25501];
int main(void) {
  scanf("%d%d", &n, &K);
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 1; k + i <= n; k++) {
        dp[i + k][max(j, k)] += dp[i][j];
        dp[i + k][max(j, k)] %= 998244353LL;
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    sum[i] += dp[n][i];
  }
  for (int i = 0; i <= K; i++) {
    sum[i + 1] += sum[i];
    sum[i + 1] %= 998244353LL;
  }
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    int v = (K - 1) / i;
    long long val = dp[n][i];
    val *= 2LL;
    val %= 998244353LL;
    val *= sum[v];
    val %= 998244353LL;
    res += val;
    res %= 998244353LL;
  }
  printf("%lld\n", res);
  return 0;
}
