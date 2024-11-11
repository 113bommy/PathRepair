#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
int mod;
int n, m, i, j, p, ans, num;
int fac[270005], inv[270005], first[270005];
int f[19][262144], g[19];
int pw(int x, int y) {
  int z = 1;
  while (y) {
    if (y & 1) z = 1ll * z * x % mod;
    x = 1ll * x * x % mod;
    y /= 2;
  }
  return z;
}
void fwt(int *a) {
  int i, j;
  for (i = 1; i < 262144; i <<= 1) {
    for (((j)) = (0); ((j)) <= (((int)(262144)) - 1); ((j))++)
      if (i & j) {
        a[j] = (a[j] + a[j - i]) % mod;
      }
  }
}
void ifwt(int *a) {
  int i, j;
  for (i = 1; i < 262144; i <<= 1) {
    for (((j)) = (0); ((j)) <= (((int)(262144)) - 1); ((j))++)
      if (i & j) {
        a[j] = (a[j] - a[j - i] + mod) % mod;
      }
  }
}
int main() {
  read(n);
  read(m);
  read(mod);
  fac[0] = fac[1] = inv[1] = first[0] = first[1] = 1;
  for ((i) = (2); (i) <= (270002); (i)++) {
    fac[i] = 1ll * fac[i - 1] * i % mod;
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
    first[i] = 1ll * first[i - 1] * inv[i] % mod;
  }
  num = __builtin_popcount(n);
  ans = pw(m, n);
  if (n & 1) {
    cout << ans << endl;
    return 0;
  }
  for (((i)) = (0); ((i)) <= (((int)(n + 1)) - 1); ((i))++) {
    f[__builtin_popcount(i)][i] = first[i];
  }
  for (((i)) = (0); ((i)) <= (((int)(num + 1)) - 1); ((i))++) {
    fwt(f[i]);
  }
  for (((i)) = (0); ((i)) <= (((int)(262144)) - 1); ((i))++) {
    memset(g, 0, sizeof(g));
    g[0] = pw(f[0][i], m);
    for (((j)) = (0); ((j)) <= (((int)(num)) - 1); ((j))++) {
      g[j + 1] = 1ll * m * (j + 1) % mod * g[0] % mod * f[j + 1][i] % mod;
      for (((p)) = (1); ((p)) <= ((j)); ((p))++) {
        g[j + 1] = (g[j + 1] + 1ll * g[p] * f[j - p + 1][i] % mod *
                                   ((1ll * m * (j - p + 1) - p + mod) % mod)) %
                   mod;
      }
      g[j + 1] = 1ll * g[j + 1] * inv[j + 1] % mod * pw(f[0][i], mod - 2) % mod;
    }
    for (((j)) = (0); ((j)) <= (((int)(num + 1)) - 1); ((j))++) f[j][i] = g[j];
  }
  ifwt(f[num]);
  cout << (ans + mod - 1ll * fac[n] * f[num][n] % mod) % mod << endl;
  return 0;
}
