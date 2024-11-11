#include <bits/stdc++.h>
using namespace std;
const int Len = 1000;
long long dp[Len + 5][102][2];
long long mul[Len + 5];
int n, K, m;
long long ans;
void Init() {
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
  mul[0] = 1;
  for (int i = 1; i < n; ++i) {
    mul[i] = (mul[i - 1] * 10) % K;
  }
}
int main() {
  while (scanf("%d%d%d", &n, &K, &m) != EOF) {
    Init();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < K; ++j) {
        for (int k = (i == n - 1); k < 10; ++k) {
          long long mod = (k * mul[i] + j) % K;
          dp[i + 1][mod][1] += dp[i][j][1];
          if (mod == 0 && k) {
            dp[i + 1][mod][1] += dp[i][j][0];
          } else {
            dp[i + 1][mod][0] += dp[i][j][0];
          }
          dp[i + 1][mod][1] %= m;
          dp[i + 1][mod][0] %= m;
        }
      }
    }
    ans = 0;
    for (int i = 0; i < K; ++i) {
      ans += dp[n][i][1];
      ans %= m;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
