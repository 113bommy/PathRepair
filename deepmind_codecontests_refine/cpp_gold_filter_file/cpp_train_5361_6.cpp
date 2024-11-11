#include <bits/stdc++.h>
using namespace std;
long long dp[4002][4002];
long long Init(int n) {
  int i, j;
  dp[1][1] = 1;
  for (i = 2; i <= n + 1; ++i) {
    for (j = 1; j <= i; ++j) {
      if (j == 1)
        dp[i][j] = dp[i - 1][i - 1];
      else
        dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % 1000000007;
      if (i == n + 1 && j == n) return dp[i][j];
    }
  }
}
int main() {
  int n;
  while (~scanf("%d", &n)) {
    printf("%lld\n", Init(n));
  }
  return 0;
}
