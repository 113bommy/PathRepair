#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n;
long long c[500][500];
long long dp[500][500];
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= 400; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        c[i][j] = 1;
      else
        c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
  }
  dp[1][0] = dp[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int l = 0; l <= 300; l++) {
      for (int r = 0; r <= 300 - l; r++) {
        long long num = dp[i - 1][l] * dp[i - 1][r] % mod;
        dp[i][l + r] = (dp[i][l + r] + num) % mod;
        dp[i][l + r + 1] = (dp[i][l + r + 1] + num) % mod;
        dp[i][l + r] = (dp[i][l + r] + num * l * 2) % mod;
        dp[i][l + r] = (dp[i][l + r] + num * r * 2) % mod;
        dp[i][l + r - 1] = (dp[i][l + r - 1] + num * c[l + r][2] * 2) % mod;
      }
    }
  }
  printf("%lld\n", dp[n][1]);
}
