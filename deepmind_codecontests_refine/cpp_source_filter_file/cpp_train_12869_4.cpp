#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long long dp[5009][5009];
int main() {
  for (int i = 0; i <= 5007; i++) dp[0][i] = 1;
  for (int i = 1; i <= 5007; i++) {
    dp[i][0] = 1;
    for (int j = 1; j <= 5007; j++) {
      dp[i][j] = (j * dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
    }
  }
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  long long res = (dp[a][b]) * (dp[b][c] % MOD) * (dp[c][a] % MOD);
  printf("%I64d \n", (res + MOD) % MOD);
  return 0;
}
