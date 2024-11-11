#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int maxn = 2005;
int n, dp[maxn][maxn];
int a[maxn], cnt[maxn], fac[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cnt[i] = 2;
  for (int i = 1; i <= n; i++) {
    if (a[i] != -1) cnt[i]--;
    if (a[i] != -1) cnt[a[i]]--;
  }
  int x = 0, y = 0;
  for (int i = 1; i <= n; i++)
    if (cnt[i] == 2) y++;
  for (int i = 1; i <= n; i++)
    if (a[i] == -1) x++;
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (int i = 1; i <= x; i++)
    for (int j = 0; j <= i; j++) {
      if (j == 0) {
        dp[i][j] = fac[i];
      } else {
        dp[i][j] = 0;
        if (j >= 1) {
          dp[i][j] += 1ll * dp[i - 1][j - 1] * (i - j) % mod;
          if (dp[i][j] >= mod) dp[i][j] -= mod;
        }
        if (j >= 2) {
          dp[i][j] += 1ll * dp[i - 1][j - 2] * (j - 1) % mod;
          if (dp[i][j] >= mod) dp[i][j] -= mod;
        }
      }
    }
  printf("%d\n", dp[x][y] % mod);
  return 0;
}
