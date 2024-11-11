#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long p, m, len;
char s[3005];
long long shu[3005], yu[3005], tot;
long long cs1, cs2, xz1, xz2;
int f[4005][4005][2][2];
void init() {
  for (long long i = 1; i <= len; ++i) shu[i] = s[i] - '0';
  while (1) {
    long long x = 0, y = 0;
    for (long long i = 1; i <= len; ++i) {
      x = y * 10 + shu[i];
      shu[i] = x / p;
      y = x % p;
    }
    yu[++tot] = y;
    long long ff = 0;
    for (long long i = 1; i <= len; ++i)
      if (shu[i]) {
        ff = 1;
        break;
      }
    if (!ff) return;
  }
}
void js() {
  cs1 = p * (p + 1) / 2 % mod;
  cs2 = p * (p - 1) / 2 % mod;
  f[tot + 1][0][1][0] = 1;
  for (long long i = tot + 1; i > 1; --i) {
    long long now = yu[i - 1];
    xz1 = now * (now + 1) / 2 % mod;
    xz2 = now * (now - 1) / 2 % mod;
    for (long long j = 0; j <= tot; ++j) {
      if (f[i][j][0][0]) {
        long long zhi = f[i][j][0][0];
        f[i - 1][j][0][0] =
            ((long long)f[i - 1][j][0][0] + zhi * cs1 % mod) % mod;
        f[i - 1][j + 1][0][1] =
            ((long long)f[i - 1][j + 1][0][1] + zhi * cs2 % mod) % mod;
      }
      if (f[i][j][0][1]) {
        long long zhi = f[i][j][0][1];
        f[i - 1][j][0][0] =
            ((long long)f[i - 1][j][0][0] + zhi * cs2 % mod) % mod;
        f[i - 1][j + 1][0][1] =
            ((long long)f[i - 1][j + 1][0][1] + zhi * cs1 % mod) % mod;
      }
      if (f[i][j][1][0]) {
        long long zhi = f[i][j][1][0];
        f[i - 1][j][1][0] =
            ((long long)f[i - 1][j][1][0] + zhi * (now + 1) % mod) % mod;
        f[i - 1][j + 1][1][1] =
            ((long long)f[i - 1][j + 1][1][1] + zhi * now % mod) % mod;
        f[i - 1][j][0][0] =
            ((long long)f[i - 1][j][0][0] + zhi * xz1 % mod) % mod;
        if (now > 1)
          f[i - 1][j + 1][0][1] =
              ((long long)f[i - 1][j + 1][0][1] + zhi * xz2 % mod) % mod;
      }
      if (f[i][j][1][1]) {
        long long zhi = f[i][j][1][1];
        f[i - 1][j][1][0] =
            ((long long)f[i - 1][j][1][0] + zhi * (p - now - 1) % mod) % mod;
        f[i - 1][j + 1][1][1] =
            ((long long)f[i - 1][j + 1][1][1] + zhi * (p - now) % mod) % mod;
        f[i - 1][j][0][0] = ((long long)f[i - 1][j][0][0] +
                             zhi * (xz1 + (p - now - 1) * now % mod) % mod) %
                            mod;
        f[i - 1][j + 1][0][1] = ((long long)f[i - 1][j + 1][0][1] +
                                 zhi * (xz1 + (p - now) * now % mod) % mod) %
                                mod;
      }
    }
  }
  long long ans = 0;
  for (long long i = m; i <= tot + 1; ++i)
    ans = (ans + f[1][i][0][0]) % mod, ans = (ans + f[1][i][1][0]) % mod;
  printf("%lld", ans);
}
int main() {
  scanf("%lld%lld", &p, &m);
  scanf("%s", s + 1);
  len = strlen(s + 1);
  init();
  js();
  return 0;
}
