#include <bits/stdc++.h>
using namespace std;
bool Mbe;
namespace IO {
char buf[1 << 21], *p1 = buf, *p2 = buf, Obuf[1 << 24], *O = Obuf;
inline long long read() {
  long long x = 0;
  bool sgn = 0;
  char s =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (!isdigit(s))
    sgn |= s == '-',
        s = (p1 == p2 &&
                     (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
                 ? EOF
                 : *p1++);
  while (isdigit(s))
    x = x * 10 + s - '0',
    s = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
             ? EOF
             : *p1++);
  return sgn ? -x : x;
}
template <class T>
inline void rprint(T x) {
  if (x >= 10) rprint(x / 10);
  (*O++ = x % 10 + '0');
}
template <class T>
inline void print(T x) {
  if (x < 0) (*O++ = '-'), x = -x;
  rprint(x);
}
}  // namespace IO
using namespace IO;
template <class T1, class T2>
void cmin(T1 &a, T2 b) {
  a = a < b ? a : b;
}
template <class T1, class T2>
void cmax(T1 &a, T2 b) {
  a = a > b ? a : b;
}
const int N = 1 << 18;
const int mod = 998244353;
int ksm(int a, int b) {
  int s = 1;
  while (b) {
    if (b & 1) s = 1ll * s * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return s;
}
int pre, r[N];
void init(int n) {
  if (pre != n) {
    for (int i = 0; i < n; i++) r[i] = (r[i >> 1] >> 1) | (i & 1 ? n >> 1 : 0);
  }
  pre = n;
}
void DFT(vector<int> &a, int op, int n) {
  static unsigned long long w[N], f[N];
  w[0] = 1, init(n);
  for (int i = 0; i < n; i++) f[i] = a[r[i]];
  for (int l = 1; l < n; l <<= 1) {
    int ww = ksm(op ? 3 : (mod + 1) / 3, mod / l / 2);
    for (int i = 1; i < l; i++) w[i] = w[i - 1] * ww % mod;
    for (int i = 0; i < n; i += l << 1)
      for (int j = 0; j < l; j++) {
        int y = f[i | j | l] * w[j] % mod;
        f[i | j | l] = f[i | j] - y + mod, f[i | j] += y;
      }
    if (l == 1 << 16)
      for (int i = 0; i < n; i++) f[i] %= mod;
  }
  if (!op) {
    int iv = ksm(n, mod - 2);
    for (int i = 0; i < n; i++) a[i] = f[i] % mod * iv % mod;
  } else
    for (int i = 0; i < n; i++) a[i] = f[i] % mod;
}
vector<int> NTT(vector<int> &x, vector<int> &y) {
  int len = x.size() + y.size() - 1;
  int n = 1 << (int)log2(len - 1) + 1;
  vector<int> z(n, 0);
  x.resize(n), y.resize(n), DFT(x, 1, n), DFT(y, 1, n);
  for (int i = 0; i < n; i++) z[i] = 1ll * x[i] * y[i] % mod;
  DFT(z, 0, n), z.resize(len);
  return z;
}
int n, m, ans, deg[N], fc[N];
vector<int> f[N];
void solve(int l, int r) {
  if (l == r) return;
  int m = l + r >> 1;
  solve(l, m), solve(m + 1, r), f[r] = NTT(f[m], f[r]);
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
  cin >> n, fc[0] = 1;
  for (int i = 1; i <= n; i++) fc[i] = 1ll * fc[i - 1] * i % mod;
  for (int i = 1, u, v; i < n; i++) cin >> u >> v, deg[u]++, deg[v]++;
  f[1].emplace_back(1), f[1].emplace_back(deg[1]), m = 1;
  for (int i = 2; i <= n; i++)
    if (deg[i] > 1) f[++m].emplace_back(1), f[m].emplace_back(deg[i] - 1);
  solve(1, m);
  for (int i = 0; i <= m; i++) {
    int coef = 1ll * f[m][i] * fc[n - i] % mod;
    ans = (ans + (i & 1 ? mod - coef : coef)) % mod;
  }
  cout << ans << "\n";
  return cerr << "Time : " << clock() << endl,
         fwrite(Obuf, 1, O - Obuf, stdout), 0;
}
