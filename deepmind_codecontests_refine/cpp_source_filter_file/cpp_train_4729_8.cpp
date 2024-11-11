#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const long long MOD = 1e9 + 7;
long long dp[N][N][2];
long long ncr[N][N];
int n, k;
int main() {
  cin >> n >> k;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= i; j++)
      ncr[i][j] =
          (i == j || !j) ? 1 : (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
  memset(dp, 0, sizeof dp);
  dp[0][0][0] = dp[1][0][1] = 0;
  dp[1][0][0] = dp[0][0][1] = 1;
  long long way;
  int ri, kri;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= k; j++)
      for (int z = 0; z <= 1; z++)
        for (int lef = 0; lef < i; lef++) {
          ri = i - 1 - lef;
          if (ri > lef) continue;
          way = (ri == lef) ? ncr[i - 2][lef - 1] : ncr[i - 1][lef];
          way = (way * ri * lef) % MOD;
          for (int klef = 0; klef <= j - z; klef++) {
            kri = j - z - klef;
            if (z == 0)
              dp[i][j][z] +=
                  (dp[lef][klef][1] * dp[ri][kri][1] % MOD) * way % MOD;
            else {
              dp[i][j][z] += ((dp[lef][klef][1] * dp[ri][kri][0] % MOD) +
                              (dp[lef][klef][0] * dp[ri][kri][1] % MOD) +
                              (dp[lef][klef][0] * dp[ri][kri][0] % MOD)) *
                             way % MOD;
            }
            dp[i][j][z] %= MOD;
          }
        }
  long long ans = (dp[n][k][0] + dp[n][k][1]) % MOD;
  cout << ans << '\n';
  return 0;
}
