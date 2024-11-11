#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int n, g, mod, a[N], b[N], c[N], d[N], b1[N], c1[N], f3[N], f4[N], g1[N], ch[3];
inline int read() {
  int num = 0;
  char g = getchar(), t = '+';
  while (g < 48 || 57 < g) t = g, g = getchar();
  while (47 < g && g < 58) num = num * 10 + g - 48, g = getchar();
  if (t == '-') return -num;
  return num;
}
namespace Math {
inline int pw(int base, int p, const int mod) {
  static int res;
  for (res = 1; p; p >>= 1, base = static_cast<long long>(base) * base % mod)
    if (p & 1) res = static_cast<long long>(res) * base % mod;
  return res;
}
inline int inv(int x, const int mod) { return pw(x, mod - 2, mod); }
}  // namespace Math
const int mod1 = 998244353, mod2 = 1004535809, mod3 = 469762049, G = 3;
const long long mod_1_2 = static_cast<long long>(mod1) * mod2;
const int inv_1 = Math::inv(mod1, mod2),
          inv_2 = Math::inv(mod_1_2 % mod3, mod3);
struct Int {
  int A, B, C;
  explicit inline Int() {}
  explicit inline Int(int __num) : A(__num), B(__num), C(__num) {}
  explicit inline Int(int __A, int __B, int __C) : A(__A), B(__B), C(__C) {}
  static inline Int reduce(const Int &x) {
    return Int(x.A + (x.A >> 31 & mod1), x.B + (x.B >> 31 & mod2),
               x.C + (x.C >> 31 & mod3));
  }
  inline friend Int operator+(const Int &lhs, const Int &rhs) {
    return reduce(
        Int(lhs.A + rhs.A - mod1, lhs.B + rhs.B - mod2, lhs.C + rhs.C - mod3));
  }
  inline friend Int operator-(const Int &lhs, const Int &rhs) {
    return reduce(Int(lhs.A - rhs.A, lhs.B - rhs.B, lhs.C - rhs.C));
  }
  inline friend Int operator*(const Int &lhs, const Int &rhs) {
    return Int(static_cast<long long>(lhs.A) * rhs.A % mod1,
               static_cast<long long>(lhs.B) * rhs.B % mod2,
               static_cast<long long>(lhs.C) * rhs.C % mod3);
  }
  inline int get() {
    long long x =
        static_cast<long long>(B - A + mod2) % mod2 * inv_1 % mod2 * mod1 + A;
    return (static_cast<long long>(C - x % mod3 + mod3) % mod3 * inv_2 % mod3 *
                (mod_1_2 % mod) % mod +
            x) %
           mod;
  }
} f1[N], f2[N];
namespace Poly {
int lim, s, rev[N];
Int Wn[N | 1];
inline void init(int n) {
  s = -1, lim = 1;
  while (lim < n) lim <<= 1, ++s;
  for (register int i = 1; i < lim; ++i)
    rev[i] = rev[i >> 1] >> 1 | (i & 1) << s;
  const Int t(Math::pw(G, (mod1 - 1) / lim, mod1),
              Math::pw(G, (mod2 - 1) / lim, mod2),
              Math::pw(G, (mod3 - 1) / lim, mod3));
  *Wn = Int(1);
  for (register Int *i = Wn; i != Wn + lim; ++i) *(i + 1) = *i * t;
}
inline void NTT(Int *A, const int op = 1) {
  for (register int i = 1; i < lim; ++i)
    if (i < rev[i]) std::swap(A[i], A[rev[i]]);
  for (register int mid = 1; mid < lim; mid <<= 1) {
    const int t = lim / mid >> 1;
    for (register int i = 0; i < lim; i += mid << 1) {
      for (register int j = 0; j < mid; ++j) {
        const Int W = op ? Wn[t * j] : Wn[lim - t * j];
        const Int X = A[i + j], Y = A[i + j + mid] * W;
        A[i + j] = X + Y, A[i + j + mid] = X - Y;
      }
    }
  }
  if (!op) {
    const Int ilim(Math::inv(lim, mod1), Math::inv(lim, mod2),
                   Math::inv(lim, mod3));
    for (register Int *i = A; i != A + lim; ++i) *i = (*i) * ilim;
  }
}
}  // namespace Poly
int main() {
  n = read();
  for (int i = 0; i < n; i++) b[i] = read();
  for (int i = 0; i < n; i++) c[i] = read();
  if (n == 1) {
    int v = sqrt(c[0]);
    if (v * v == c[0]) {
      if (v == 0) {
        cout << 1 << endl;
        cout << b[0] << endl;
        return 0;
      } else {
        cout << 2 << endl;
        cout << b[0] - v << endl;
        cout << b[0] + v << endl;
        return 0;
      }
    }
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) b1[i] = b[n - i - 1];
  for (int i = 0; i < n; i++) c1[i] = c[i] - c[(i + n - 1) % n];
  for (int i = n;; i += n) {
    if (i <= 2000000) continue;
    mod = i + 1;
    for (int j = 2; j * j <= i + 1; j++)
      if ((i + 1) % j == 0) mod = -1;
    if (mod == i + 1) break;
  }
  for (int i = 0; i < n; i++) c1[i] = (c1[i] + mod) % mod;
  int g;
  for (int i = 2; i < mod; i++) {
    int c = Math::pw(i, (mod - 1) / n, mod);
    d[1] = 1;
    for (int j = 2; j <= n; j++) d[j] = 1ll * d[j - 1] * c % mod;
    sort(d + 1, d + n + 1);
    bool fl = 0;
    for (int j = 2; j <= n; j++)
      if (d[j] == d[j - 1]) fl = 1;
    if (fl) continue;
    g = c;
    break;
  }
  d[0] = d[n] = 1;
  for (int i = 1; i < n; i++) d[i] = 1ll * d[i - 1] * g % mod;
  for (int i = 0; i < n; i++)
    c1[i] = 1ll * c1[i] * Math::pw(mod - 2, mod - 2, mod) % mod;
  Poly::init(3 * n);
  memset(f1, 0, sizeof(f1));
  memset(f2, 0, sizeof(f2));
  for (int i = 0; i < n + n; i++) f1[i] = Int(d[(1ll * i * (i - 1) / 2) % n]);
  for (int i = 0; i < n; i++)
    f2[n - i] = Int(1ll * c1[i] * d[n - ((1ll * i * (i - 1)) / 2) % n] % mod);
  Poly::NTT(f1), Poly::NTT(f2);
  for (int i = 0; i < Poly::lim; i++) f1[i] = f1[i] * f2[i];
  Poly::NTT(f1, 0);
  for (int i = 0; i < n; i++)
    f3[i] = 1ll * f1[i + n].get() * d[n - ((1ll * i * (i - 1)) / 2) % n] % mod;
  Poly::init(3 * n);
  memset(f1, 0, sizeof(f1));
  memset(f2, 0, sizeof(f2));
  for (int i = 0; i < n + n; i++) f1[i] = Int(d[(1ll * i * (i - 1) / 2) % n]);
  for (int i = 0; i < n; i++)
    f2[n - i] = Int(1ll * b1[i] * d[n - ((1ll * i * (i - 1)) / 2) % n] % mod);
  Poly::NTT(f1), Poly::NTT(f2);
  for (int i = 0; i < Poly::lim; i++) f1[i] = f1[i] * f2[i];
  Poly::NTT(f1, 0);
  for (int i = 0; i < n; i++)
    f4[i] = 1ll * f1[i + n].get() * d[n - ((1ll * i * (i - 1)) / 2) % n] % mod;
  for (int i = 0; i < n; i++)
    f3[i] = 1ll * f3[i] * Math::pw(f4[i], mod - 2, mod) % mod;
  Poly::init(3 * n);
  memset(f1, 0, sizeof(f1));
  memset(f2, 0, sizeof(f2));
  for (int i = 0; i < n + n; i++)
    f1[i] = Int(d[n - (1ll * i * (i - 1) / 2) % n]);
  for (int i = 0; i < n; i++)
    f2[n - i] = Int(1ll * f3[i] * d[((1ll * i * (i - 1)) / 2) % n] % mod);
  Poly::NTT(f1), Poly::NTT(f2);
  for (int i = 0; i < Poly::lim; i++) f1[i] = f1[i] * f2[i];
  Poly::NTT(f1, 0);
  for (int i = 0; i < n; i++)
    f4[i] = 1ll * f1[i + n].get() * d[((1ll * i * (i - 1)) / 2) % n] % mod;
  long long invn = Math::pw(n, mod - 2, mod);
  for (int i = 0; i < n; i++) {
    if (f4[i] >= mod / 2) f4[i] = f4[i] - mod;
    f4[i] = f4[i] * invn % mod;
  }
  long long val = 0;
  for (int i = 0; i < n; i++) g1[i] = f4[(i + 1) % n], val += g1[i];
  long long fa = 0, fb = 0, fc = -c[0];
  g1[0] = 0;
  for (int i = 1; i < n; i++) g1[i] += g1[i - 1];
  for (int i = 0; i < n; i++) {
    b[i] -= g1[i];
    fc = fc + 1ll * b[i] * b[i];
    fb = fb - 2 * b[i];
    fa = fa + 1;
  }
  ch[0] = ch[1] = ch[2] = 0;
  for (int i = -50000; i <= 50000; i++)
    if (1ll * i * i * fa + 1ll * i * fb + fc == 0) ch[++ch[0]] = i;
  cout << ch[0] << endl;
  if (ch[1]) {
    for (int i = 0; i < n; i++) printf("%d ", ch[1] + g1[i]);
    cout << endl;
  }
  if (ch[2]) {
    for (int i = 0; i < n; i++) printf("%d ", ch[2] + g1[i]);
    cout << endl;
  }
}
