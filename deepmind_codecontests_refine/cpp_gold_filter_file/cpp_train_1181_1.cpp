#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MAX = 200;
int dig[10];
long long C[MAX][MAX];
long long dp[MAX][MAX];
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < 10; ++i) scanf("%d", dig + i);
  for (int i = 0; i <= N; ++i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
  }
  dp[10][0] = 1;
  for (int i = 9; i >= 0; --i) {
    for (int j = 0; j <= N; ++j)
      for (int k = dig[i]; k <= j; ++k)
        dp[i][j] = (dp[i][j] + dp[i + 1][j - k] * C[j][k]) % MOD;
  }
  long long ret = 0;
  for (int i = 1; i <= N; ++i) {
    ret += dp[0][i];
    ret %= MOD;
  }
  long long zero = 0;
  for (int i = 1; i <= N; ++i)
    for (int k = dig[0] - (dig[0] > 0); k <= i - 1; ++k) {
      zero = zero + dp[1][i - 1 - k] * C[i - 1][k];
      zero %= MOD;
    }
  ret -= zero;
  ret = ((ret % MOD) + MOD) % MOD;
  printf("%d\n", (int)ret);
  return 0;
}
