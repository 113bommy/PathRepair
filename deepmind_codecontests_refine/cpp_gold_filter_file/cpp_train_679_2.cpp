#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 2000;
const int mod = 1e9 + 7;
int dp[2][N], a, b, k, t, sum[N];
int cha[2005];
inline void up(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
inline int mul(int x, int y) { return 1ll * x * y % mod; }
int qpow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = 1ll * x * ret % mod;
    y >>= 1;
    x = 1ll * x * x % mod;
  }
  return ret;
}
int main() {
  scanf("%d%d%d%d", &a, &b, &k, &t);
  int base = b - a + 2 * t * k;
  if (base < 0) {
    printf("%d\n", qpow(2 * k + 1, 2 * t));
    return 0;
  }
  if (a - b + 2 * t * k <= 0) {
    printf("0\n");
    return 0;
  }
  cha[0] = 2 * k + 1;
  for (int i = 1; i <= 2 * k; ++i) cha[i] = 2 * k + 1 - i;
  int lim = base + a - b + 2 * t * k;
  int cur = 0;
  dp[0][a - b + base] = 1;
  for (int i = 1; i <= t; ++i) {
    for (int j = 1; j <= lim; ++j) sum[j] = (sum[j - 1] + dp[cur][j]) % mod;
    int tmp = 0;
    for (int j = 0; j <= 2 * k; ++j) up(tmp, mul(cha[j], dp[cur][j]));
    cur ^= 1;
    dp[cur][0] = tmp;
    for (int j = 1; j <= lim; ++j) {
      tmp -= (sum[j - 1] - sum[max(0, j - 2 - 2 * k)] + mod) % mod;
      up(tmp, mod);
      up(tmp, (sum[min(j + 2 * k, lim)] - sum[j - 1] + mod) % mod);
      dp[cur][j] = tmp;
    }
  }
  int ret = 0;
  for (int i = base + 1; i <= lim; ++i) up(ret, dp[cur][i]);
  printf("%d\n", ret);
  return 0;
}
