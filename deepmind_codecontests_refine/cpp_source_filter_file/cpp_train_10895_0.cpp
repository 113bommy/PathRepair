#include <bits/stdc++.h>
using ll = long long;
using std::cin;
using std::cout;
using std::endl;
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
const int inf = (int)1e9 + 7;
const long long INF = 1LL << 60;
template <int mod>
struct ModInt {
  int x;
  ModInt() : x(0) {}
  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  ModInt &operator+=(const ModInt &p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator-=(const ModInt &p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  ModInt &operator*=(const ModInt &p) {
    x = (int)(1LL * x * p.x % mod);
    return *this;
  }
  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }
  ModInt operator-() const { return ModInt(-x); }
  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
  bool operator==(const ModInt &p) const { return x == p.x; }
  bool operator!=(const ModInt &p) const { return x != p.x; }
  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      std::swap(a -= t * b, b);
      std::swap(u -= t * v, v);
    }
    return ModInt(u);
  }
  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &p) {
    return os << p.x;
  }
  friend std::istream &operator>>(std::istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt<mod>(t);
    return (is);
  }
  static int get_mod() { return mod; }
};
constexpr int mod = (int)1e9 + 7;
using mint = ModInt<mod>;
void solve() {
  int n, kkt;
  cin >> n >> kkt;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  std::vector<int> res(kkt);
  std::vector<std::vector<std::pair<int, int>>> R(n);
  for (int i = 0; i < kkt; ++i) {
    int l, x;
    cin >> l >> x;
    l -= 1;
    R[l].emplace_back(x, i);
  }
  std::vector<int> bases;
  ll ans = 1;
  for (int i = 0; i < n; ++i) {
    ll e = a[i];
    for (const auto &b : bases) chmin(e, e ^ b);
    if (e > 0)
      bases.emplace_back(e);
    else
      ans *= 2;
    for (const auto &[x, idx] : R[i]) {
      ll e = x;
      for (const auto &b : bases) chmin(e, e ^ b);
      if (e > 0)
        res[idx] = 0;
      else
        res[idx] = ans;
    }
  }
  for (int i = 0; i < kkt; ++i) {
    cout << res[i] << "\n";
  }
}
int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int kkt = 1;
  while (kkt--) solve();
  return 0;
}
