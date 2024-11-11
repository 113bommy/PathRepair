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
const int maxn = 4e5 + 10;
const int inf = 1e9;
const double eps = 1e-8;
const int mod = 998244353;
int n, m, a[maxn], t[maxn << 2], N = 4e5;
void build(int p, int l, int r) {
  if (l == r) return t[p] = 1, void();
  build(p << 1, l, ((l + r) >> 1)), build(p << 1 | 1, ((l + r) >> 1) + 1, r);
  t[p] = t[p << 1] + t[p << 1 | 1];
}
void fuck(int p, int l, int r, int x) {
  if (l == r) return t[p] ^= 1, void();
  if (x <= ((l + r) >> 1))
    fuck(p << 1, l, ((l + r) >> 1), x);
  else
    fuck(p << 1 | 1, ((l + r) >> 1) + 1, r, x);
  t[p] = t[p << 1] + t[p << 1 | 1];
}
int find(int p, int l, int r, int k) {
  if (l == r) return l;
  if (t[p << 1] >= k)
    return find(p << 1, l, ((l + r) >> 1), k);
  else
    return find(p << 1 | 1, ((l + r) >> 1) + 1, r, k - t[p << 1]);
}
int sta[maxn], top, fac[maxn], ifac[maxn];
int qpow(int a, int x) {
  int res = 1;
  for (; x; x >>= 1, a = 1ll * a * a % mod)
    if (x & 1) res = 1ll * res * a % mod;
  return res;
}
void prepare() {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= N; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[N] = qpow(fac[N], mod - 2);
  for (int i = N - 1; i; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
}
int c(int a, int b) { return 1ll * fac[a] * ifac[b] % mod * ifac[a - b] % mod; }
void solve() {
  read(n), read(m);
  int cnt = 0, ans = 0;
  for (int i = 1; i <= m; i++) read(a[i]), read(a[i]);
  for (int i = m; i; i--) {
    int x = find(1, 1, N, a[i]), nxt = find(1, 1, N, a[i] + 1);
    fuck(1, 1, N, x), sta[++top] = x;
    if (nxt == x + 1) cnt++;
  }
  while (top) fuck(1, 1, N, sta[top--]);
  ans = c(2 * n - cnt - 1, n - cnt - 1);
  write(ans);
}
int main() {
  build(1, 1, N);
  prepare();
  int t;
  read(t);
  while (t--) solve();
  return 0;
}
