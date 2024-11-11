#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mod = (ll)1e9 + 7;
const int INF = 1e9 + 1;
const int N = 2e5 + 100;
const double eps = 1e-7;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
template <typename XPAX>
void ckma(XPAX &x, XPAX y) {
  x = (x < y ? y : x);
}
template <typename XPAX>
void ckmi(XPAX &x, XPAX y) {
  x = (x > y ? y : x);
}
template <long long mod = 1000000007>
struct modint {
  long long a;
  modint() : a(0) {}
  modint(long long t) {
    a = t % mod;
    if (a < 0) a += mod;
  }
  operator long long() const { return a; }
  bool operator==(const modint &x) const { return a == x.a; }
  bool operator!=(const modint &x) const { return a != x.a; }
  modint operator-() const { return modint(a ? (mod - a) : 0); }
  modint operator~() const { return pow(mod - 2); }
  modint operator+(const modint &x) const { return modint(*this) += x; }
  modint operator-(const modint &x) const { return modint(*this) -= x; }
  modint operator*(const modint &x) const { return modint(*this) *= x; }
  modint operator/(const modint &x) const { return modint(*this) /= x; }
  modint &operator+=(const modint &x) {
    a += x.a;
    if (a >= mod) a -= mod;
    return *this;
  }
  modint &operator-=(const modint &x) {
    a -= x.a;
    if (a < 0) a += mod;
    return *this;
  }
  modint &operator*=(const modint &x) {
    a = a * x.a % mod;
    return *this;
  }
  modint &operator/=(const modint &x) {
    a = a * (~x).a % mod;
    return *this;
  }
  friend ostream &operator<<(ostream &os, const modint &x) { return os << x.a; }
  friend istream &operator>>(istream &is, modint &x) {
    long long t;
    is >> t;
    x = modint(t);
    return is;
  }
  modint pow(long long x) const {
    modint ret = 1, tmp = a;
    for (; x; tmp *= tmp, x >>= 1) {
      if (x & 1) ret *= tmp;
    }
    return ret;
  }
};
const ll MOD = 1e9 + 7;
using Mint = modint<MOD>;
template <class T>
struct Combination {
  vector<T> fact, factinv;
  Combination(int n) : fact(n + 1), factinv(n + 1) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * T(i);
    factinv[n] = ~fact[n];
    for (int i = n; i >= 1; i--) factinv[i - 1] = factinv[i] * T(i);
  }
  T nCr(int n, int r) {
    if (r < 0 || n < r) return 0;
    return fact[n] * factinv[r] * factinv[n - r];
  }
};
void solve() {
  int n;
  cin >> n;
  Combination<Mint> comb(2 * n + 2);
  Mint ans = 0;
  V<int> a(2 * n);
  for (int i = 0; i < (2 * n); ++i) {
    cin >> a[i];
  }
  sort((a).begin(), (a).end());
  ll s1 = 0;
  ll s2 = 0;
  for (int i = 0; i < (2 * n); ++i) {
    if (i < n)
      s1 += a[i];
    else
      s2 += a[i];
  }
  s2 -= s1;
  ans = comb.nCr(2 * n, n) * Mint(s2);
  cout << ans << '\n';
}
void test_case() {
  int t;
  cin >> t;
  for (int p = 0; p < (t); ++p) {
    solve();
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
}
