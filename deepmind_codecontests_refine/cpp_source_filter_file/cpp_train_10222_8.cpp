#include <bits/stdc++.h>
using namespace std;
const int N = 4e4 + 5;
const int mod = 998244353, G = 3;
int up, w[N], rev[N], inv[N];
int fpw(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return ans;
}
namespace poly {
void init(int n) {
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= n; i++)
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  up = 1;
  int l = 0;
  while (up <= n) up <<= 1, l++;
  for (int i = 0; i < up; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
  int wn = fpw(G, mod >> l);
  w[up >> 1] = 1;
  for (int i = (up >> 1) + 1; i < up; i++) w[i] = 1ll * w[i - 1] * wn % mod;
  for (int i = (up >> 1) - 1; i >= 1; i--) w[i] = w[i << 1];
}
void clear(int *a, int n) { memset(a, 0, n << 2); }
int getlen(int n) { return 1 << (32 - __builtin_clz(n)); }
inline void mul(int *a, int n, int x, int *b) {
  while (n--) *b++ = 1ll * *a++ * x % mod;
}
inline void dot(int *a, int *b, int n, int *c) {
  while (n--) *c++ = 1ll * *a++ * *b++ % mod;
}
void DFT(int *a, int l) {
  static unsigned long long tmp[N];
  int u = __builtin_ctz(up / l), t;
  for (int i = 0; i < l; i++) tmp[i] = a[rev[i] >> u];
  for (int i = 1; i ^ l; i <<= 1)
    for (int j = 0, d = i << 1; j ^ l; j += d)
      for (int k = 0; k < i; k++)
        t = tmp[i | j | k] * w[i | k] % mod,
        tmp[i | j | k] = tmp[j | k] + mod - t, tmp[j | k] += t;
  for (int i = 0; i < l; i++) a[i] = tmp[i] % mod;
}
void IDFT(int *a, int l) {
  reverse(a + 1, a + l);
  DFT(a, l);
  mul(a, l, mod - mod / l, a);
}
inline void conv(int *a, int *b, int l) {
  DFT(a, l);
  DFT(b, l);
  dot(a, b, l, a);
  IDFT(a, l);
}
void mul(int *a, int n, int *b, int m, int *c) {
  static int A[N], B[N], l;
  l = getlen(n + m), copy(a, a + n + 1, A), copy(b, b + m + 1, B);
  conv(A, B, l);
  copy(A, A + n + m + 1, c);
  clear(A, l), clear(B, l);
}
}  // namespace poly
int n, k, a[N], b[N];
int buf[N * 64], *f[N], *np;
void go(int p, int l, int r) {
  f[p] = np, np += r - l + 2;
  if (l == r) {
    f[p][0] = 1, f[p][1] = a[l];
    return;
  }
  int lc = p << 1, rc = lc | 1, mid = (l + r) >> 1;
  go(lc, l, mid);
  go(rc, mid + 1, r);
  poly::mul(f[lc], mid - l + 1, f[rc], r - mid, f[p]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
  poly::init(n);
  int _;
  cin >> _;
  while (_--) {
    int op, q;
    cin >> op >> q;
    if (op == 1) {
      int x, d;
      cin >> x >> d;
      a[x] = d;
      for (int i = 1; i <= n; i++) a[i] = (q - a[i] + mod) % mod;
      np = buf;
      go(1, 1, n);
      memcpy(a + 1, b + 1, sizeof(int) * n);
    } else {
      int l, r, d;
      cin >> l >> r >> d;
      for (int i = l; i <= r; i++) a[i] = (a[i] + d) % mod;
      for (int i = 1; i <= n; i++) a[i] = (q - a[i] + mod) % mod;
      np = buf;
      go(1, 1, n);
      memcpy(a + 1, b + 1, sizeof(int) * n);
    }
    cout << f[1][k] << '\n';
  }
  return 0;
}
