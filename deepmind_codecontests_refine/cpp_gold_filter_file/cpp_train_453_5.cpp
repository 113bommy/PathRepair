#include <bits/stdc++.h>
using namespace std;
int MOD = 1000000007;
const int MAXN = 2005;
long long DP[MAXN][MAXN], DP0[MAXN][MAXN];
int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  if (M == 1) {
    printf("0\n");
    return 0;
  }
  for (int i = 0; i < (M); ++i) DP[0][i] = 1;
  for (int i = (1); i < (N + 1); ++i) {
    DP0[i - 1][0] = DP[i - 1][0];
    for (int j = (1); j < (M + 5); ++j)
      DP0[i - 1][j] = (DP[i - 1][j] + DP0[i - 1][j - 1]) % MOD;
    DP[i][0] = i + 1;
    for (int j = (1); j < (M + 5); ++j)
      DP[i][j] = (DP[i][j - 1] + DP0[i - 1][j]) % MOD;
  }
  long long result = 0;
  for (int t = 0; t < (N); ++t) {
    for (int w = 0; w < (M - 1); ++w) {
      long long tmp0 = (M - 1 - w) * DP[t][w] % MOD;
      long long tmp1 = DP[N - 1 - t][w];
      if (N - 1 - t != 0) tmp1 -= DP[N - 1 - t - 1][w];
      result += tmp0 * tmp1 % MOD;
    }
  }
  result %= MOD;
  result += MOD;
  result %= MOD;
  printf("%d\n", (int)result);
}
