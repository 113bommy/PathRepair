#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
template <int MOD>
struct ModInt {
  long long x;
  explicit operator bool() const { return !!x; }
  ModInt(int v = 0) : x(v % MOD) {
    if (x < 0) x += MOD;
  }
  ModInt(long long v) : x(v % MOD) {
    if (x < 0) x += MOD;
  }
  ModInt &operator+=(const ModInt &r) {
    if ((x += r.x) >= MOD) x -= MOD;
    return *this;
  }
  ModInt &operator-=(const ModInt &r) {
    if ((x += MOD - r.x) >= MOD) x -= MOD;
    return *this;
  }
  ModInt &operator*=(const ModInt &r) {
    x = x * r.x % MOD;
    return *this;
  }
  ModInt &operator/=(const ModInt &r) { return *this *= r.inv(); }
  ModInt operator-() const { return x ? ModInt(MOD - x) : ModInt(x); }
  ModInt operator+(const ModInt &r) const { return ModInt(*this) += r; }
  ModInt operator-(const ModInt &r) const { return ModInt(*this) -= r; }
  ModInt operator*(const ModInt &r) const { return ModInt(*this) *= r; }
  ModInt operator/(const ModInt &r) const { return ModInt(*this) /= r; }
  ModInt inv() const {
    long long a = x, b = MOD, u = 1, v = 0;
    while (b) {
      long long t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    return ModInt(u);
  }
  ModInt pow(long long k) const {
    ModInt r(1), a(x);
    while (k) {
      if (k & 1) r *= a;
      a *= a;
      k >>= 1;
    }
    return r;
  }
  bool operator==(const ModInt r) const { return x == r.x; }
  bool operator!=(const ModInt r) const { return x != r.x; }
  bool operator<(const ModInt r) const { return x < r.x; }
  friend ostream &operator<<(ostream &os, const ModInt<MOD> &a) {
    return os << a.x;
  }
  friend istream &operator>>(istream &is, ModInt<MOD> &a) { return is >> a.x; }
};
template <typename T, int SZ>
struct Comb {
  vector<T> _fac, _ifac, _inv;
  Comb() : _fac(SZ + 1), _ifac(SZ + 1), _inv(SZ + 1) {
    _fac[0] = _ifac[SZ] = _inv[0] = 1;
    for (int i = 1; i <= SZ; i++) _fac[i] = _fac[i - 1] * i;
    _ifac[SZ] /= _fac[SZ];
    for (int i = SZ - 1; i >= 0; i--) _ifac[i] = _ifac[i + 1] * (i + 1);
    for (int i = 1; i <= SZ; i++) _inv[i] = _ifac[i] * _fac[i - 1];
  }
  T inv(int n) { return n < 0 ? T(0) : _inv[n]; }
  T fac(int n) { return n < 0 ? T(0) : _fac[n]; }
  T ifac(int n) { return n < 0 ? T(0) : _ifac[n]; }
  T P(int a, int b) { return (b < 0 || a < b) ? T(0) : _fac[a] * _ifac[a - b]; }
  T C(int a, int b) { return b < 0 ? T(0) : P(a, b) * _ifac[b]; }
  T H(int n, int k) {
    if (n < 0 || k < 0) return T(0);
    return k == 0 ? T(1) : C(n + k - 1, k);
  }
  T S(int n, int k) {
    T r = 0;
    for (int i = 0; i <= k; i++) {
      T t = C(k, i) * T(i).pow(n);
      r += ((k - i) & 1 ? -t : t);
    }
    return r * _ifac[k];
  }
  T B(int n, int k) {
    if (n == 0) return T(1);
    T r = 0;
    k = min(k, n);
    vector<T> dp(k + 1);
    dp[0] = T(1);
    for (int i = 1; i <= k; i++)
      dp[i] = dp[i - 1] + (i & 1 ? -_ifac[i] : _ifac[i]);
    for (int i = 1; i <= k; i++) r += T(i).pow(n) * _ifac[i] * dp[k - i];
    return r;
  }
};
Comb<ModInt<MOD>, 250000> com;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &ai : a) cin >> ai;
  map<long long, int> res;
  {
    auto prime_factorize = [&](long long n) {
      for (long long p = 2; p * p <= n; ++p) {
        while (n % p == 0) {
          ++res[p];
          n /= p;
        }
      }
      if (n != 1) res[n] = 1;
    };
    for (int ai : a) prime_factorize(ai);
  }
  ModInt<MOD> cnt = 1;
  for (auto &p : res) cnt *= com.H(n, p.second);
  cout << cnt << endl;
  return 0;
}
