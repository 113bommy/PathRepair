#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -f;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  x *= f;
}
void print(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (!x) return;
  print(x / 10), putchar(x % 10 + 48);
}
void write(int x) {
  if (!x)
    putchar('0');
  else
    print(x);
  putchar('\n');
}
const int maxn = 2.5e6 + 10;
const int inf = 1e9;
const double eps = 1e-8;
const int mod = 998244353;
int qpow(int a, int x) {
  int res = 1;
  for (; x; x >>= 1, a = 1ll * a * a % mod)
    if (x & 1) res = 1ll * res * a % mod;
  return res;
}
int n, k, a[maxn], b[12], q, t[maxn], ans[maxn], s[maxn];
int f[maxn], g[maxn], fac[maxn], ifac[maxn], mx;
int c(int a, int b) {
  if (a < b) return 0;
  return 1ll * fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}
int w[maxn], pos[maxn], N, bit;
void gen(int l) {
  for (N = 1, bit = -1; N <= l << 1; N <<= 1, bit++)
    ;
  for (int i = 1; i < N; i++) pos[i] = pos[i >> 1] >> 1 | ((i & 1) << bit);
  w[0] = 1, w[1] = qpow(3, (mod - 1) / N);
  for (int i = 2; i < N; i++) w[i] = 1ll * w[i - 1] * w[1] % mod;
}
void ntt(int *r, int op) {
  for (int i = 1; i < N; i++)
    if (pos[i] > i) swap(r[i], r[pos[i]]);
  for (int i = 1, d = N >> 1; i < N; i <<= 1, d >>= 1)
    for (int j = 0; j < N; j += i << 1)
      for (int k = 0; k < i; k++) {
        int x = r[j + k], y = 1ll * w[k * d] * r[i + j + k] % mod;
        r[j + k] = (x + y) % mod, r[i + j + k] = (x - y + mod) % mod;
      }
  if (op == -1) {
    int d = qpow(N, mod - 2);
    reverse(r + 1, r + N);
    for (int i = 0; i < N; i++) r[i] = 1ll * r[i] * d % mod;
  }
}
void solve(int x) {
  int m = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] >= x) continue;
    if (!s[a[i]])
      m++;
    else if (s[a[i]] == 1)
      cnt++, m--;
    s[a[i]]++;
  }
  int l = (mx - x * 2 - 2) >> 1;
  gen(l);
  for (int i = 0; i <= l; i++) {
    f[i] = 1ll * c(m, i) * qpow(2, i) % mod;
    g[i] = c(cnt * 2, i);
  }
  for (int i = l + 1; i <= mx; i++) f[i] = g[i] = 0;
  ntt(f, 1), ntt(g, 1);
  for (int i = 0; i < N; i++) f[i] = 1ll * f[i] * g[i] % mod;
  ntt(f, -1);
  for (int i = 1; i <= q; i++)
    if (t[i] >= x * 2 + 2) ans[i] = (ans[i] + f[(t[i] - x * 2 - 2) >> 1]) % mod;
  for (int i = 1; i <= n; i++) s[a[i]] = 0;
}
int main() {
  read(n), read(k);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= k; i++) read(b[i]);
  read(q);
  for (int i = 1; i <= q; i++) read(t[i]), mx = max(mx, t[i]);
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = qpow(fac[n], mod - 2) % mod;
  for (int i = n - 1; i; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
  for (int i = 1; i <= k; i++) solve(b[i]);
  for (int i = 1; i <= q; i++) write(ans[i]);
  return 0;
}
