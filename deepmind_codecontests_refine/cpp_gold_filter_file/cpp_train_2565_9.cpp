#include <bits/stdc++.h>
using namespace std;
namespace IO {
const int RLEN = 1 << 20 | 1;
char ibuf[RLEN], *ib, *ob;
inline char gc() {
  (ib == ob) && (ob = (ib = ibuf) + fread(ibuf, 1, RLEN, stdin));
  return (ib == ob) ? EOF : *ib++;
}
inline int read() {
  char ch = gc();
  int res = 0;
  bool f = 1;
  while (!isdigit(ch)) f ^= ch == '-', ch = gc();
  while (isdigit(ch)) res = (res * 10) + (ch ^ 48), ch = gc();
  return f ? res : -res;
}
inline long long readll() {
  char ch = gc();
  long long res = 0;
  bool f = 1;
  while (!isdigit(ch)) f ^= ch == '-', ch = gc();
  while (isdigit(ch)) res = (res * 10) + (ch ^ 48), ch = gc();
  return f ? res : -res;
}
inline char readchar() {
  char ch = gc();
  while (isspace(ch)) ch = gc();
  return ch;
}
inline int readstring(char *s) {
  int top = 0;
  char ch = gc();
  while (isspace(ch)) ch = gc();
  while (!isspace(ch) && ch != EOF) s[++top] = ch, ch = gc();
  s[top + 1] = '\0';
  return top;
}
}  // namespace IO
using IO::read;
using IO::readchar;
using IO::readll;
using IO::readstring;
template <typename tp>
inline void chemx(tp &a, tp b) {
  a = max(a, b);
}
template <typename tp>
inline void chemn(tp &a, tp b) {
  a = min(a, b);
}
const int mod = 998244353;
inline int add(int a, int b) {
  return (a + b) >= mod ? (a + b - mod) : (a + b);
}
inline int dec(int a, int b) { return (a < b) ? (a - b + mod) : (a - b); }
inline int mul(int a, int b) {
  static long long r;
  r = (long long)a * b;
  return (r >= mod) ? (r % mod) : r;
}
inline void Add(int &a, int b) { a = (a + b) >= mod ? (a + b - mod) : (a + b); }
inline void Dec(int &a, int b) { a = (a < b) ? (a - b + mod) : (a - b); }
inline void Mul(int &a, int b) {
  static long long r;
  r = (long long)a * b;
  a = (r >= mod) ? (r % mod) : r;
}
inline int ksm(int a, int b, int res = 1) {
  for (; b; b >>= 1, Mul(a, a)) (b & 1) && (Mul(res, a), 1);
  return res;
}
inline int Inv(int x) { return ksm(x, mod - 2); }
namespace Poly {
const int C = 18, M = (1 << C) | 5;
int rev[M], *w[C + 1], iv[M];
inline void init_rev(int lim) {
  for (int i = 0; i < lim; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (lim >> 1));
}
inline void init_w() {
  for (int i = 1; i <= C; i++) w[i] = new int[(1 << (i - 1)) | 1];
  int wn = ksm(3, (mod - 1) / (1 << C));
  w[C][0] = 1;
  for (int i = 1, l = 1 << (C - 1); i < l; i++) w[C][i] = mul(w[C][i - 1], wn);
  for (int i = C - 1; i; i--)
    for (int j = 0, l = 1 << (i - 1); j < l; j++) w[i][j] = w[i + 1][j << 1];
  iv[0] = iv[1] = 1;
  for (int i = 2; i < M; i++) iv[i] = mul(mod - mod / i, iv[mod % i]);
}
inline void dft(int *f, int lim) {
  for (int i = 0; i < lim; i++)
    if (i > rev[i]) swap(f[i], f[rev[i]]);
  for (int mid = 1, l = 1, a0, a1; mid < lim; mid <<= 1, l++)
    for (int i = 0; i < lim; i += mid << 1)
      for (int j = 0; j < mid; j++)
        a0 = f[i + j], a1 = mul(w[l][j], f[i + j + mid]),
        f[i + j] = add(a0, a1), f[i + j + mid] = dec(a0, a1);
}
inline void ntt(vector<int> &f, int lim, int kd) {
  dft(&f[0], lim);
  if (kd == -1) {
    reverse(f.begin() + 1, f.begin() + lim);
    for (int i = 0; i < lim; i++) Mul(f[i], iv[lim]);
  }
}
inline vector<int> operator*(vector<int> a, vector<int> b) {
  if (!a.size() || !b.size()) return vector<int>(0);
  int deg = a.size() + b.size() - 1;
  if (a.size() <= 32 || b.size() <= 32) {
    vector<int> c(deg, 0);
    for (int i = 0; i < a.size(); i++)
      for (int j = 0; j < b.size(); j++) Add(c[i + j], mul(a[i], b[j]));
    return c;
  }
  int lim = 1;
  while (lim < deg) lim <<= 1;
  init_rev(lim);
  a.resize(lim), ntt(a, lim, 1);
  b.resize(lim), ntt(b, lim, 1);
  for (int i = 0; i < lim; i++) Mul(a[i], b[i]);
  ntt(a, lim, -1), a.resize(deg);
  return a;
}
}  // namespace Poly
using namespace Poly;
const int N = 100005;
int fac[N], ifac[N];
inline void init_fac() {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < N; i++) fac[i] = mul(fac[i - 1], i);
  ifac[N - 1] = Inv(fac[N - 1]);
  for (int i = N - 2; i; i--) ifac[i] = mul(ifac[i + 1], i + 1);
}
int n, m;
int main() {
  init_w(), init_fac();
  n = read(), m = readll() % (mod - 1);
  vector<int> f(n + 1, 0), g(n + 1, 0), p(n + 1, 0);
  for (int i = 0; i <= n; i++) f[i] = mul(read(), fac[i]), p[i] = ifac[i];
  reverse(f.begin(), f.end());
  f = f * p;
  for (int i = 0; i <= n; i++) g[i] = mul(f[n - i], ksm(iv[i + 1], m));
  reverse(g.begin(), g.end());
  for (int i = 0; i <= n; i++) p[i] = (i & 1) ? mod - ifac[i] : ifac[i];
  g = g * p;
  for (int i = 0; i <= n; i++) cout << mul(ifac[i], g[n - i]) << " ";
  puts("");
  return 0;
}
