#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int MOD = 1e9 + 7;
long long dp[maxn][3];
void init() {
  dp[1][1] = 1, dp[1][2] = 0;
  for (int i = 2; i <= 1000000; i++) {
    if (i & 1) {
      dp[i][1] = (dp[i - 1][2] + 1 + dp[i - 1][1]) % MOD;
      dp[i][2] = dp[i - 1][2];
    } else {
      dp[i][2] = (dp[i - 1][1] + 1 + dp[i - 1][2]) % MOD;
      dp[i][1] = dp[i - 1][1];
    }
  }
}
int main() {
  int n;
  init();
  while (~scanf("%d", &n)) printf("%I64d\n", dp[n][1] + dp[n][2]);
  return 0;
}
