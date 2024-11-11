#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long dp[51][25][2];
long long C[51][51];
void dod(long long& a, long long b) { a = (a + b) % MOD; }
int main() {
  ios_base::sync_with_stdio(0);
  for (int i = 0; i <= 50; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0 || i == j)
        C[i][j] = 1;
      else
        C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
  }
  int n, k;
  cin >> n >> k;
  dp[1][0][0] = 1;
  for (int wlk = 2; wlk <= n; ++wlk) {
    for (int wlk1 = 1; wlk1 <= wlk - 2; ++wlk1) {
      int wlk2 = wlk - wlk1 - 1;
      for (int sko1 = 0; sko1 <= wlk1 / 2; ++sko1) {
        for (int sko2 = 0; sko2 <= wlk2 / 2; ++sko2) {
          long long il = C[wlk - 2][wlk1 - 1] * wlk1 % MOD * wlk2 % MOD *
                         dp[wlk1][sko1][0] % MOD * dp[wlk2][sko2][0] % MOD;
          dod(dp[wlk][sko1 + sko2 + 1][1], il);
          il = C[wlk - 2][wlk1 - 1] * wlk1 % MOD * wlk2 % MOD *
               dp[wlk1][sko1][0] % MOD * dp[wlk2][sko2][1] % MOD;
          dod(dp[wlk][sko1 + sko2 + 1][1], il);
          il = C[wlk - 2][wlk1 - 1] * wlk1 % MOD * wlk2 % MOD *
               dp[wlk1][sko1][1] % MOD * dp[wlk2][sko2][0] % MOD;
          dod(dp[wlk][sko1 + sko2 + 1][1], il);
          il = C[wlk - 2][wlk1 - 1] * wlk1 % MOD * wlk2 % MOD *
               dp[wlk1][sko1][1] % MOD * dp[wlk2][sko2][1] % MOD;
          dod(dp[wlk][sko1 + sko2][0], il);
        }
      }
    }
    for (int sko = 0; sko <= (wlk - 1) / 2; ++sko) {
      dod(dp[wlk][sko + 1][1], dp[wlk - 1][sko][0] * (wlk - 1));
      dod(dp[wlk][sko][0], dp[wlk - 1][sko][1] * (wlk - 1));
    }
  }
  long long odp = (dp[n][k][0] + dp[n][k][1]) % MOD;
  cout << odp;
  return 0;
}
