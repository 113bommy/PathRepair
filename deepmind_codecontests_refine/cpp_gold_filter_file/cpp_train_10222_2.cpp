#include <bits/stdc++.h>
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const long long llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end() {}
const int Gmod = 3, maxn = (1 << 18) - 1;
inline int ksm(long long x, long long y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = 1ll * ret * x % mod;
    x = 1ll * x * x % mod;
    y >>= 1;
  }
  return ret;
}
int rev[maxn], _lstN, P[maxn], iP[maxn];
inline void ntt(int *A, int polyN, int t) {
  for (int i = 0; i < polyN; ++i)
    if (rev[i] > i) std::swap(A[i], A[rev[i]]);
  for (int o = 1; o < polyN; o <<= 1) {
    int W = t ? P[o] : iP[o];
    for (int *p = A; p != A + polyN; p += o << 1)
      for (int i = 0, w = 1; i < o; ++i, w = 1ll * w * W % mod) {
        int t = 1ll * w * p[i + o] % mod;
        p[i + o] = (1ll * p[i] - t + mod) % mod;
        p[i] = (p[i] + t) % mod;
      }
  }
  if (!t) {
    int inv = ksm(polyN, mod - 2);
    for (int i = 0; i < polyN; ++i) A[i] = 1ll * A[i] * inv % mod;
  }
}
int polyN, lg;
inline void setN(int n) {
  polyN = 1, lg = 0;
  while (polyN < n) polyN <<= 1, ++lg;
  if (polyN != _lstN)
    for (int i = 0; i < polyN; ++i)
      rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (lg - 1));
}
inline void ntt(std::vector<int> &a, int t) {
  static int A[maxn];
  for (int i = 0; i < (int)a.size(); ++i) A[i] = a[i];
  memset(A + a.size(), 0, 4 * (polyN - a.size()));
  ntt(A, polyN, t);
  a.resize(polyN);
  for (int i = 0; i < polyN; ++i) a[i] = A[i];
  int s = a.size();
  while (s && !a[s - 1]) --s;
  a.resize(s);
}
inline std::vector<int> mul(std::vector<int> a, std::vector<int> b,
                            int newn = -1) {
  if (newn == -1) newn = a.size() + b.size() - 1;
  setN(a.size() + b.size() - 1);
  ntt(a, 1), ntt(b, 1);
  for (int i = 0; i < polyN; ++i) a[i] = 1ll * a[i] * b[i] % mod;
  ntt(a, 0);
  a.resize(newn);
  return a;
}
inline std::vector<int> operator+(std::vector<int> a,
                                  const std::vector<int> &b) {
  if (a.size() < b.size()) a.resize(b.size());
  for (int i = 0; i < (int)a.size(); ++i)
    if (i < (int)b.size()) a[i] = (a[i] + b[i]) % mod;
  return a;
}
inline std::vector<int> operator-(std::vector<int> a,
                                  const std::vector<int> &b) {
  if (a.size() < b.size()) a.resize(b.size());
  for (int i = 0; i < (int)a.size(); ++i)
    if (i < (int)b.size()) a[i] = (a[i] - b[i] + mod) % mod;
  return a;
}
inline std::vector<int> operator*(std::vector<int> a, int b) {
  for (auto &i : a) i = 1ll * i * b % mod;
  return a;
}
inline std::vector<int> polydiff(std::vector<int> a) {
  for (int i = 0; i < (int)a.size() - 1; ++i)
    a[i] = 1ll * a[i + 1] * (i + 1) % mod;
  a.erase(a.end() - 1);
  return a;
}
inline std::vector<int> polyint(std::vector<int> a) {
  a.insert(a.begin(), 0);
  for (int i = 1; i < (int)a.size(); ++i)
    a[i] = 1ll * a[i] * ksm(i, mod - 2) % mod;
  return a;
}
inline std::vector<int> getinv(std::vector<int> a) {
  if (a.size() == 1) return std::vector<int>(1, ksm(a[0], mod - 2));
  int n = a.size(), m = (a.size() + 1) >> 1;
  std::vector<int> _a(m);
  for (int i = 0; i < m; ++i) _a[i] = a[i];
  std::vector<int> b = getinv(_a);
  setN(n + m * 2 - 2);
  ntt(a, 1);
  ntt(b, 1);
  for (int i = 0; i < polyN; ++i) a[i] = 1ll * a[i] * b[i] % mod * b[i] % mod;
  ntt(a, 0), ntt(b, 0);
  a.resize(n);
  return b * 2 - a;
}
inline std::vector<int> getln(std::vector<int> a, int n = -1) {
  if (n == -1) n = a.size();
  a.resize(n);
  return polyint(mul(polydiff(a), getinv(a), n));
}
inline std::vector<int> getexp(std::vector<int> a) {
  if (a.size() == 1) return a[0] = 1, a;
  int m = (a.size() + 1) >> 1;
  std::vector<int> _a(m);
  for (int i = 0; i < m; ++i) _a[i] = a[i];
  std::vector<int> b = getexp(_a);
  return mul(b, std::vector<int>(1, 1) - getln(b, a.size()) + a, a.size());
}
inline std::vector<int> operator^(std::vector<int> a, int b) {
  int n = a.size();
  a = getexp(getln(a) * b);
  a.resize(n);
  return a;
}
inline std::vector<int> operator%(std::vector<int> a, std::vector<int> b) {
  int n = a.size(), m = b.size();
  if (n < m) return a;
  std::reverse(a.begin(), a.end());
  std::reverse(b.begin(), b.end());
  b.resize(n);
  std::vector<int> c = mul(a, getinv(b), n - m + 1);
  std::reverse(a.begin(), a.end());
  b.resize(m);
  std::reverse(b.begin(), b.end());
  std::reverse(c.begin(), c.end());
  a = a - mul(b, c);
  int s = a.size();
  while (s && !a[s - 1]) --s;
  a.resize(s);
  return a;
}
inline std::vector<int> sqrt(std::vector<int> a) {
  if (a.size() == 1) return a;
  int n = a.size(), m = (a.size() + 1) >> 1;
  std::vector<int> _a(m);
  for (int i = 0; i < m; ++i) _a[i] = a[i];
  std::vector<int> b = sqrt(_a);
  b.resize(n);
  return (b + mul(a, getinv(b), n)) * ((mod + 1) >> 1);
}
inline void poly_init() {
  int G = Gmod, iG = ksm(G, mod - 2);
  for (int i = 1; i < maxn; i <<= 1)
    P[i] = ksm(G, (mod - 1) / (i << 1)), iP[i] = ksm(iG, (mod - 1) / (i << 1));
}
struct auto_poly_init {
  auto_poly_init() { poly_init(); }
} __auto_init;
int n, a[N], Q, k, b[N], q;
std::vector<int> solventt(int l, int r) {
  if (l == r) {
    std::vector<int> ret;
    ret.push_back(1), ret.push_back(q - b[l] + mod);
    return ret;
  }
  int mid = (l + r) >> 1;
  auto polyl = solventt(l, mid);
  auto polyr = solventt(mid + 1, r);
  return mul(polyl, polyr);
}
inline void solve() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]), a[i] %= mod;
  scanf("%d", &Q);
  while (Q--) {
    int type;
    scanf("%d%d", &type, &q);
    for (int i = 0; i < n; ++i) b[i] = a[i];
    if (type == 1) {
      int ii, d;
      scanf("%d%d", &ii, &d), ii--;
      b[ii] = d % mod;
    } else {
      int l, r, d;
      scanf("%d%d%d", &l, &r, &d), l--, r--;
      for (int i = l; i <= r; ++i) b[i] += d, b[i] %= mod;
    }
    auto ans = solventt(0, n - 1);
    printf("%d\n", ans[k] % mod);
  }
}
int main() {
  TIME__START = clock();
  int Test = 1;
  while (Test--) {
    solve();
  }
  TIME__END = clock();
  program_end();
  return 0;
}
