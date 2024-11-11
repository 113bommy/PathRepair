#include <bits/stdc++.h>
using namespace std;
long long dp[60][60][60][2];
int C[60][60];
int mod = 1e9 + 7;
void build() {
  for (int i = 0; i < 60; i++) {
    C[i][0] = C[i][i] = 1;
  }
  for (int i = 1; i < 60; i++) {
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }
}
int main() {
  build();
  int n, p;
  scanf("%d %d", &n, &p);
  int c[55];
  for (int i = 0; i < n; i++) scanf("%d", &c[i]);
  dp[0][0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    if (c[i] == 0 || c[i] == -1) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          for (int l = 0; l <= k; l++) {
            if (l % 2 == 0) {
              dp[i + 1][j + 1][k][1] +=
                  dp[i][j][k][0] * C[k][l] % mod * ((1ll << (i - k)) % mod);
              dp[i + 1][j + 1][k][0] +=
                  dp[i][j][k][1] * C[k][l] % mod * ((1ll << (i - k)) % mod);
              dp[i + 1][j + 1][k][1] %= mod;
              dp[i + 1][j + 1][k][0] %= mod;
            } else {
              dp[i + 1][j][k][0] +=
                  dp[i][j][k][0] * C[k][l] % mod * ((1ll << (i - k)) % mod);
              dp[i + 1][j][k][1] +=
                  dp[i][j][k][1] * C[k][l] % mod * ((1ll << (i - k)) % mod);
              dp[i + 1][j][k][1] %= mod;
              dp[i + 1][j][k][0] %= mod;
            }
          }
        }
      }
    }
    if (c[i] == 1 || c[i] == -1) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          for (int l = 0; l <= j; l++) {
            if (l % 2 == 0) {
              dp[i + 1][j][k + 1][1] +=
                  dp[i][j][k][0] * C[j][l] % mod * ((1ll << (i - j)) % mod);
              dp[i + 1][j][k + 1][0] +=
                  dp[i][j][k][1] * C[j][l] % mod * ((1ll << (i - j)) % mod);
              dp[i + 1][j][k + 1][1] %= mod;
              dp[i + 1][j][k + 1][0] %= mod;
            } else {
              dp[i + 1][j][k][0] +=
                  dp[i][j][k][0] * C[j][l] % mod * ((1ll << (i - j)) % mod);
              dp[i + 1][j][k][1] +=
                  dp[i][j][k][1] * C[j][l] % mod * ((1ll << (i - j)) % mod);
              dp[i + 1][j][k][1] %= mod;
              dp[i + 1][j][k][0] %= mod;
            }
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int j = 0; j <= n; j++) {
    for (int k = 0; k <= n; k++) {
      ans += dp[n][j][k][p];
    }
  }
  printf("%lld\n", ans % mod);
}
