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
constexpr int mod = (int)1e9 + 7;
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
using mint = ModInt<mod>;
const int MAX = (int)1e6;
mint fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i;
    inv[i] = -inv[mod % i] * (mod / i);
    finv[i] = finv[i - 1] * inv[i];
  }
}
mint COM(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * finv[k] * finv[n - k];
}
mint LCOM(ll n, ll k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  if (k > n / 2) k = n - k;
  mint res = 1;
  for (int i = 0; i < k; i++) res *= (n - i);
  res *= finv[k];
  return res;
}
int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  COMinit();
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  mint res = 0;
  for (int cnt = 0; cnt <= n - 2; ++cnt) {
    mint t = 1;
    t *= COM(n - 2, cnt) * fac[cnt] * COM(m - 1, cnt) * (cnt + 2) *
         mint(n).pow(n - (cnt + 2)) * mint(m).pow(n - (cnt + 2));
    t *= inv[n];
    res += t;
  }
  cout << res << "\n";
  return 0;
}
