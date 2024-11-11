#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using si = set<int>;
using sl = set<ll>;
using qi = queue<int>;
using ql = queue<ll>;
template <class T>
bool uin(T& a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T& a, T b) {
  return a < b ? (a = b, true) : false;
}
template <class T>
bool uin(T& u, T& v, T a, T b) {
  return v - u > b - a ? (u = a, v = b, true) : false;
}
template <class T>
bool uax(T& u, T& v, T a, T b) {
  return v - u < b - a ? (u = a, v = b, true) : false;
}
namespace input {
template <class T>
void re(complex<T>& x);
template <class T1, class T2>
void re(pair<T1, T2>& p);
template <class T>
void re(vector<T>& a);
template <class T, size_t SZ>
void re(array<T, SZ>& a);
template <class T>
void re(T& x) {
  cin >> x;
}
void re(double& x) {
  string t;
  re(t);
  x = stod(t);
}
void re(ld& x) {
  string t;
  re(t);
  x = stold(t);
}
template <class T, class... Ts>
void re(T& t, Ts&... ts) {
  re(t);
  re(ts...);
}
template <class T>
void re(complex<T>& x) {
  T a, b;
  re(a, b);
  x = cd(a, b);
}
template <class T1, class T2>
void re(pair<T1, T2>& p) {
  re(p.f, p.s);
}
template <class T>
void re(vector<T>& a) {
  for (int i = 0; i < (((int)(a).size())); ++i) re(a[i]);
}
template <class T, size_t SZ>
void re(array<T, SZ>& a) {
  for (int i = 0; i < (SZ); ++i) re(a[i]);
}
}  // namespace input
using namespace input;
namespace output {
void pr(int x) { cout << x; }
void pr(long x) { cout << x; }
void pr(ll x) { cout << x; }
void pr(unsigned x) { cout << x; }
void pr(unsigned long x) { cout << x; }
void pr(unsigned long long x) { cout << x; }
void pr(float x) { cout << x; }
void pr(double x) { cout << x; }
void pr(ld x) { cout << x; }
void pr(char x) { cout << x; }
void pr(const char* x) { cout << x; }
void pr(const string& x) { cout << x; }
void pr(bool x) { pr(x ? "true" : "false"); }
template <class T>
void pr(const complex<T>& x) {
  cout << x;
}
template <class T1, class T2>
void pr(const pair<T1, T2>& x);
template <class T>
void pr(const T& x);
template <class T, class... Ts>
void pr(const T& t, const Ts&... ts) {
  pr(t);
  pr(ts...);
}
template <class T1, class T2>
void pr(const pair<T1, T2>& x) {
  pr("{", x.f, ", ", x.s, "}");
}
template <class T>
void pr(const T& x) {
  pr("{");
  bool fst = 1;
  for (const auto& a : x) pr(!fst ? ", " : "", a), fst = 0;
  pr("}");
}
void ps() { pr("\n"); }
template <class T, class... Ts>
void ps(const T& t, const Ts&... ts) {
  pr(t);
  if (sizeof...(ts)) pr(" ");
  ps(ts...);
}
void pc() { pr("]\n"); }
template <class T, class... Ts>
void pc(const T& t, const Ts&... ts) {
  pr(t);
  if (sizeof...(ts)) pr(", ");
  pc(ts...);
}
}  // namespace output
using namespace output;
inline int bs(bool (*valid)(int), int l, int r, bool order) {
  l--, r++;
  if (!order) swap(l, r);
  while (abs(r - l) > 1) {
    int mid = (l + r) >> 1;
    if (valid(mid))
      r = mid;
    else
      l = mid;
  }
  valid(r);
  return r;
}
struct dsu {
  vector<int> p;
  dsu(int n) { p.resize(n + 1); }
  inline int get(int x) { return p[x] ? p[x] = get(p[x]) : x; }
  inline bool mrg(int x, int y) {
    return get(x) == get(y) ? false : p[get(x)] = get(y);
  }
};
const int M = 1e9 + 7;
const ll lnf = 1e18 + 3;
const int inf = 1e9 + 3;
const int nax = 1e6 + 5;
typedef decay<decltype(M)>::type T;
struct mi {
  T val;
  explicit operator T() const { return val; }
  mi() { val = 0; }
  mi(const ll& v) {
    val = (-M <= v && v <= M) ? v : v % M;
    if (val < 0) val += M;
  }
  friend void pr(const mi& a) { pr(a.val); }
  friend void re(mi& a) {
    ll x;
    re(x);
    a = mi(x);
  }
  friend bool operator==(const mi& a, const mi& b) { return a.val == b.val; }
  friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
  friend bool operator<(const mi& a, const mi& b) { return a.val < b.val; }
  mi operator-() const { return mi(-val); }
  mi& operator+=(const mi& m) {
    if ((val += m.val) >= M) val -= M;
    return *this;
  }
  mi& operator-=(const mi& m) {
    if ((val -= m.val) < 0) val += M;
    return *this;
  }
  mi& operator*=(const mi& m) {
    val = (ll)val * m.val % M;
    return *this;
  }
  friend mi pow(mi a, ll p) {
    mi ans = 1;
    assert(p >= 0);
    for (; p; p /= 2, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  friend mi inv(const mi& a) {
    assert(a != 0);
    return pow(a, M - 2);
  }
  mi& operator/=(const mi& m) { return (*this) *= inv(m); }
  friend mi operator+(mi a, const mi& b) { return a += b; }
  friend mi operator-(mi a, const mi& b) { return a -= b; }
  friend mi operator*(mi a, const mi& b) { return a *= b; }
  friend mi operator/(mi a, const mi& b) { return a /= b; }
};
vi invs, fac, ifac;
void genFac(int SZ) {
  invs.resize(SZ), fac.resize(SZ), ifac.resize(SZ);
  invs[1] = fac[0] = ifac[0] = 1;
  for (int i = (2); i <= (SZ - 1); ++i)
    invs[i] = M - (ll)M / i * invs[M % i] % M;
  for (int i = (1); i <= (SZ - 1); ++i) {
    fac[i] = (ll)fac[i - 1] * i % M;
    ifac[i] = (ll)ifac[i - 1] * invs[i] % M;
  }
}
ll comb(int a, int b) {
  if (a < b || b < 0) return 0;
  return (ll)fac[a] * ifac[b] % M * ifac[a - b] % M;
}
ll p[nax], s, c;
int t, n, q[nax];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  re(n);
  vl a(n);
  re(a);
  for (int i = 0; i < (n); ++i) {
    s = a[i], c = 1;
    while (t && p[t] * c >= s * q[t]) s += p[t], c += q[t--];
    p[++t] = s, q[t] = c;
  }
  cout << setprecision(9);
  for (int i = (1); i <= (t); ++i)
    for (int j = 0; j < (q[i]); ++j) cout << (double)p[i] / q[i] << '\n';
}
