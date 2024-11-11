#include <bits/stdc++.h>
using namespace std;
unsigned long long n, m, dp[1005][55], k, mul;
unsigned long long res = 2 * 1000000000000000000;
unsigned long long prime[16] = {0,  2,  3,  5,  7,  11, 13, 17,
                                19, 23, 29, 31, 37, 41, 43, 47};
signed main() {
  cin >> n;
  m = 16;
  dp[1][0] = 1;
  for (unsigned long long i = 1; i < n; i++) {
    for (unsigned long long j = 0; j < m; j++) {
      if (!dp[i][j]) continue;
      k = 0, mul = 1;
      while (1) {
        if (1000000000000000000 / dp[i][j] < mul) break;
        if (i * (k + 1) > 1000) break;
        if (!dp[i * (k + 1)][j + 1])
          dp[i * (k + 1)][j + 1] = dp[i][j] * mul;
        else
          dp[i * (k + 1)][j + 1] = min(dp[i * (k + 1)][j + 1], dp[i][j] * mul);
        if (1000000000000000000 / mul < prime[j + 1]) break;
        k++;
        mul *= prime[j + 1];
      }
    }
  }
  for (unsigned long long i = 0; i <= 1000; i++)
    if (dp[n][i]) res = min(res, dp[n][i]);
  cout << res;
}
