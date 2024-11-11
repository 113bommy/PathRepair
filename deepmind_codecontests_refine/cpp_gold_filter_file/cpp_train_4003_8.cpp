#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long G = 3;
const int N = 3e5 + 50;
int n, m, x;
long long a[N], b[N], F[N];
long long c[N], d[N], f[N], g[N], h[N];
int bit, tot, rev[N];
long long fpow(long long x, long long k) {
  long long ans = 1;
  while (k) {
    if (k & 1) ans = ans * x % mod;
    x = x * x % mod;
    k >>= 1;
  }
  return ans;
}
void NTT(long long a[], int tot, int inv) {
  for (int i = 0; i < tot; i++)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int mid = 1; mid < tot; mid <<= 1) {
    long long w1 = fpow(G, (mod - 1) / (mid * 2));
    if (~inv) w1 = fpow(w1, mod - 2);
    for (int i = 0; i < tot; i += mid * 2) {
      long long wk = 1;
      for (int j = 0; j < mid; j++, wk = wk * w1 % mod) {
        long long x = a[i + j], y = wk * a[i + j + mid] % mod;
        a[i + j] = (x + y) % mod, a[i + j + mid] = (x - y + mod) % mod;
      }
    }
  }
}
void Inv(int len, long long a[], long long b[]) {
  if (len == 1) {
    b[0] = fpow(a[0], mod - 2);
    return;
  }
  Inv((len + 1) >> 1, a, b);
  int bit = 0, tot = 0;
  while ((1 << bit) < (len << 1)) bit++;
  tot = 1 << bit;
  for (int i = 0; i < tot; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
  for (int i = 0; i < len; i++) c[i] = a[i];
  for (int i = len; i < tot; i++) c[i] = 0;
  NTT(c, tot, 1);
  NTT(b, tot, 1);
  for (int i = 0; i < tot; i++)
    b[i] = ((long long)2 - b[i] * c[i] % mod + mod) % mod * b[i] % mod;
  NTT(b, tot, -1);
  long long inv = fpow(tot, mod - 2);
  for (int i = 0; i < tot; i++) b[i] = b[i] * inv % mod;
  for (int i = len; i < tot; i++) b[i] = 0;
}
void Mul(long long a[], int n, long long b[], int m) {
  int bit = 0, tot = 0;
  while ((1 << bit) < (n + m - 1)) bit++;
  tot = 1 << bit;
  for (int i = 0; i < tot; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
  NTT(a, tot, 1);
  NTT(b, tot, 1);
  for (int i = 0; i < tot; i++) a[i] = a[i] * b[i] % mod;
  NTT(a, tot, -1);
  long long inv = fpow(tot, mod - 2);
  for (int i = 0; i < tot; i++) a[i] = a[i] * inv % mod;
  for (int i = n; i < tot; i++) a[i] = 0;
}
void Sqrt(int len, long long a[], long long b[]) {
  if (len == 1) {
    b[0] = 1;
    return;
  }
  Sqrt((len + 1) >> 1, a, b);
  memset(d, 0, sizeof d);
  memset(f, 0, sizeof f);
  memset(g, 0, sizeof g);
  for (int i = 0; i < len; i++) g[i] = (long long)2 * b[i] % mod, f[i] = b[i];
  Inv(len, g, d);
  Mul(b, len, f, len);
  for (int i = 0; i < len; i++) b[i] = (b[i] + a[i]) % mod;
  Mul(b, len, d, len);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &x), a[x] = 1;
  a[0] = 1;
  for (int i = 1; i <= m; i++) a[i] = (mod - (long long)4 * a[i] + mod) % mod;
  Sqrt(m + 1, a, b);
  b[0] = (b[0] + (long long)1) % mod;
  Inv(m + 1, b, F);
  for (int i = 1; i <= m; i++) F[i] = ((long long)2 * F[i]) % mod;
  for (int i = 1; i <= m; i++) printf("%lld\n", F[i]);
  return 0;
}
