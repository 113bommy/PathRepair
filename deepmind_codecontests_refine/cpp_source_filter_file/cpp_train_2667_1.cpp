#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
const int mod = 998244353;
const int base = 15;
int n;
int a[maxn];
int dp[maxn][maxn][15];
int l[maxn], d[maxn];
vector<int> g[2], w[2];
int p[15];
void divi(int x, int id) {
  int cnt = 0, ret = 0;
  while (x) {
    p[++cnt] = x % 10;
    x /= 10;
  }
  reverse(p + 1, p + 1 + cnt);
  for (int i = 1; i <= cnt; i++)
    if (i & 1)
      ret += p[i];
    else
      ret -= p[i];
  l[id] = cnt;
  d[id] = ret;
  ret = (ret % 11 + 11) % 11;
  g[cnt & 1].push_back(ret);
}
int tot;
int c;
long long ans;
int cnt1, cnt2;
long long h[maxn];
long long fac[maxn], inv[maxn];
long long Pow(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = ret * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ret;
}
void init() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i % mod;
  inv[maxn - 1] = Pow(fac[maxn - 1], mod - 2);
  for (int i = maxn - 2; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}
long long C(int n, int m) { return fac[n] * inv[m] % mod * inv[n - m] % mod; }
int main() {
  init();
  int T;
  scanf("%d", &T);
  while (T--) {
    ans = 0;
    scanf("%d", &n);
    g[0].clear();
    g[1].clear();
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      divi(a[i], i);
    }
    if (!g[1].size()) {
      int t = 0;
      for (int i = 0; i < g[0].size(); i++) (t += g[0][i]) %= 11;
      if (!t) {
        ans = 1;
        for (int i = 1; i <= n; i++) ans = ans * i % mod;
        printf("%I64d\n", ans);
      } else
        puts("0");
      continue;
    }
    cnt1 = g[1].size();
    c = (cnt1 + 1) / 2;
    for (int i = 1; i <= cnt1; i++)
      for (int j = 0; j <= c; j++)
        for (int k = 0; k < 11; k++) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    for (int i = 0; i < cnt1; i++) {
      for (int j = 0; j <= c; j++) {
        for (int k = 0; k < 11; k++) {
          (dp[i + 1][j + 1][(k + g[1][i]) % 11] += dp[i][j][k]) %= mod;
          (dp[i + 1][j][(k - g[1][i] + 11) % 11] += dp[i][j][k]) %= mod;
        }
      }
    }
    for (int i = 0; i < 11; i++)
      h[i] = 1ll * dp[cnt1][c][i] * fac[c] % mod * fac[cnt1 - c] % mod;
    cnt2 = g[0].size();
    for (int i = 1; i <= cnt2; i++)
      for (int j = 0; j <= c; j++)
        for (int k = 0; k < 11; k++) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    for (int i = 0; i < cnt2; i++) {
      for (int j = 0; j <= cnt2; j++) {
        for (int k = 0; k < 11; k++) {
          (dp[i + 1][j + 1][(k + g[0][i]) % 11] += dp[i][j][k]) %= mod;
          (dp[i + 1][j][(k - g[0][i] + 11) % 11] += dp[i][j][k]) %= mod;
        }
      }
    }
    for (int i = 0; i < 11; i++) {
      for (int j = 0; j <= cnt2; j++) {
        ans = (ans +
               1ll * dp[cnt2][j][i] * C(((cnt1 & 1) ? c : c + 1) - 1 + j, j) %
                   mod * fac[j] % mod *
                   C(((cnt1 & 1) ? cnt1 - c + 1 : cnt1 - c) - 1 + (cnt2 - j),
                     cnt2 - j) %
                   mod * fac[cnt2 - j] % mod * h[(11 - i) % 11] % mod) %
              mod;
      }
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
