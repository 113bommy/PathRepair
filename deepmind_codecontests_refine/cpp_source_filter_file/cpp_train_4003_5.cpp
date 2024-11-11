#include <bits/stdc++.h>
using namespace std;
const int Maxn = 400005, mod = 998244353;
int n, m, f[Maxn], g[Maxn];
int Pow(int x, int k) {
  int ret = 1;
  while (k) {
    if (k & 1) ret = (long long)ret * x % mod;
    k >>= 1;
    x = (long long)x * x % mod;
  }
  return ret;
}
void ntt(int *a, int p, int f) {
  static int rev[Maxn], lst;
  int n = 1 << p;
  if (n ^ lst)
    for (int i = 0; i < n; i++)
      rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << p - 1);
  for (int i = 0; i < n; i++)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  lst = n;
  for (int i = 1; i < n; i <<= 1) {
    int tmp = i << 1, wn = Pow(3, (mod - 1) / tmp);
    if (f == -1) wn = Pow(wn, mod - 2);
    for (int j = 0; j < n; j += tmp) {
      int w = 1;
      for (int k = 0; k < i; k++, w = (long long)w * wn % mod) {
        int x = a[j + k], y = (long long)w * a[i + j + k] % mod;
        a[j + k] = (x + y) % mod;
        a[i + j + k] = (x - y + mod) % mod;
      }
    }
  }
  if (f == -1)
    for (int i = 0, inv = Pow(n, mod - 2); i < n; i++)
      a[i] = (long long)a[i] * inv % mod;
}
void Inv(int *f, int *g, int len) {
  static int A[Maxn];
  if (len == 1) return g[0] = Pow(f[0], mod - 2), void();
  Inv(f, g, len >> 1);
  copy(f, f + len, A);
  int p = log2(len << 1), n = 1 << p;
  fill(A + len, A + n, 0);
  fill(g + (len >> 1), g + n, 0);
  ntt(A, p, 1);
  ntt(g, p, 1);
  for (int i = 0; i < n; i++)
    g[i] = (mod + 2 - (long long)A[i] * g[i] % mod) * g[i] % mod;
  ntt(g, p, -1);
  fill(g + len, g + n, 0);
}
void Sqrt(int *f, int *g, int len) {
  static int A[Maxn], B[Maxn], inv2 = Pow(2, mod - 2);
  if (len == 1) return g[0] = sqrt(f[0]), void();
  Sqrt(f, g, len >> 1);
  Inv(g, B, len);
  copy(f, f + len, A);
  int p = log2(len << 1), n = 1 << p;
  fill(A + len, A + n, 0);
  fill(B + len, B + n, 0);
  fill(g + (len >> 1), g + n, 0);
  ntt(A, p, 1);
  ntt(B, p, 1);
  ntt(g, p, 1);
  for (int i = 0; i < n; i++)
    g[i] = (g[i] + (long long)A[i] * B[i]) % mod * inv2 % mod;
  ntt(g, p, -1);
  fill(g + len, g + n, 0);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    f[x] = mod - 4;
  }
  int len = 1 << int(ceil(log2(m)));
  f[0] = (f[0] + 1) % mod;
  Sqrt(f, g, len);
  g[0] = (g[0] + 1) % mod;
  Inv(g, f, len);
  for (int i = 0; i < len; i++) f[i] = 2ll * f[i] % mod;
  for (int i = 1; i <= m; i++) cout << f[i] << "\n";
}
