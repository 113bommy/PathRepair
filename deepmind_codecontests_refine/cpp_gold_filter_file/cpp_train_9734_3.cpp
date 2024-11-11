#include <bits/stdc++.h>
struct {
  inline operator int() {
    int x;
    return scanf("%d", &x), x;
  }
  inline operator long long() {
    long long x;
    return scanf("%lld", &x), x;
  }
} read;
const int maxn = 5050, mod = 1000000007;
char s[maxn];
int t[maxn];
int divi(int p, int len) {
  long long now = 0;
  for (int i = 1; i <= len; i++) {
    now = now * 10 + s[i] - '0';
    s[i] = '0' + now / p;
    now %= p;
  }
  return now;
}
bool notzero(int len) {
  for (int i = 1; i <= len; i++)
    if (s[i] != '0') return 1;
  return 0;
}
long long F[maxn][2][2], G[maxn][2][2];
int main() {
  int p = read, a = read;
  scanf("%s", s + 1);
  int len = strlen(s + 1), n = 0;
  while (notzero(len)) t[++n] = divi(p, len);
  if (a >= n) return puts("0"), 0;
  F[0][1][0] = 1;
  F[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    std::swap(F, G);
    memset(F, 0, sizeof F);
    int a = t[i];
    for (int j = 0; j < i; j++) {
      F[j][0][0] += G[j][0][0] * (1ll * p * (p + 1) / 2 % mod);
      F[j][0][0] += G[j][0][1] * (1ll * p * (p - 1) / 2 % mod);
      F[j + 1][0][1] += G[j][0][0] * (1ll * p * (p - 1) / 2 % mod);
      F[j + 1][0][1] += G[j][0][1] * (1ll * p * (p + 1) / 2 % mod);
      F[j][1][0] += G[j][1][0] * (a + 1);
      F[j][1][0] += G[j][1][1] * a;
      F[j][1][0] += G[j][0][0] * (1ll * a * (a + 1) / 2 % mod);
      F[j][1][0] += G[j][0][1] * (1ll * a * (a - 1) / 2 % mod);
      F[j + 1][1][1] += G[j][1][0] * (p - a - 1);
      F[j + 1][1][1] += G[j][1][1] * (p - a);
      F[j + 1][1][1] += G[j][0][0] * (1ll * a * (p * 2 - a - 1) / 2 % mod);
      F[j + 1][1][1] += G[j][0][1] * (1ll * a * (p * 2 - a + 1) / 2 % mod);
    }
    for (int j = 0; j <= i; j++)
      for (int x = 0; x < 4; x++) F[j][x >> 1][x & 1] %= mod;
  }
  long long ans = 0;
  for (int j = a; j <= n; j++) ans += F[j][1][0];
  ans %= mod;
  printf("%lld\n", ans);
}
