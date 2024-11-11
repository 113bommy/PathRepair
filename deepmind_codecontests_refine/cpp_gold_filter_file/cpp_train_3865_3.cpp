#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const long long mod = 998244353;
long long l, r;
int k;
long long dp[21][11][1 << 10], dp2[21][11][1 << 10];
int f[1 << 10];
long long play(long long x) {
  if (x == 0) return 0;
  if (x < 10) return x * (x + 1) / 2;
  int i;
  long long now = 1, ans = 0, w = 0, num = 1, w2 = 0;
  while (now * 10 <= x) {
    for (i = 1; i <= 9; i++) {
      for (int j = 0; j < 1 << 10; j++)
        if (f[j] <= k) ans += dp2[num][i][j];
    }
    num++;
    now *= 10;
  }
  ans %= mod;
  for (int i = 0; i < (1 << 10); i++)
    if (f[i] <= k) ans -= dp2[num][0][i];
  while (now) {
    for (i = 0;; i++) {
      if (now != 1) {
        if ((i + 1) * now > x) break;
      } else if (i > x)
        break;
      for (int j = 0; j < 1 << 10; j++)
        if (f[j | w] <= k) {
          ans += dp2[num][i][j] + dp[num][i][j] * (w2 % mod);
          ans %= mod;
        }
    }
    x %= now;
    w |= 1 << i;
    w2 += i * now;
    num--;
    now /= 10;
  }
  return ans;
}
int main() {
  scanf("%lld%lld%d", &l, &r, &k);
  int i, j, k, a, b;
  memset(dp2, 0, sizeof(dp2));
  dp[0][10][0] = 1;
  dp2[0][10][0] = 0;
  for (i = 0; i < 1 << 10; i++) {
    a = 0;
    for (j = 0; j < 10; j++)
      if (i & (1 << j)) a++;
    f[i] = a;
  }
  long long qaq = 1;
  for (i = 1; i <= 18; i++) {
    for (j = 0; j < 10; j++) {
      for (k = 0; k < (1 << 10); k++) {
        if (dp[i - 1][10][k] == 0) continue;
        dp[i][j][k | 1 << j] += dp[i - 1][10][k];
        dp[i][j][k | 1 << j] %= mod;
        dp2[i][j][k | 1 << j] +=
            dp2[i - 1][10][k] + qaq % mod * j % mod * dp[i - 1][10][k];
        dp2[i][j][k | 1 << j] %= mod;
        dp[i][10][k | 1 << j] += dp[i - 1][10][k];
        dp[i][10][k | 1 << j] %= mod;
        dp2[i][10][k | 1 << j] +=
            dp2[i - 1][10][k] + qaq % mod * j % mod * dp[i - 1][10][k];
        dp2[i][10][k | 1 << j] %= mod;
      }
    }
    qaq *= 10;
  }
  long long ans = play(r) - play(l - 1);
  printf("%lld\n", (ans % mod + mod) % mod);
}
