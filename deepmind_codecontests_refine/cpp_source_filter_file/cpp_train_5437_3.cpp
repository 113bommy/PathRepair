#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
void chmin(T& a, const T& b) noexcept {
  if (b < a) a = b;
}
template <class T>
void chmax(T& a, const T& b) noexcept {
  if (a < b) a = b;
}
template <class T>
void drop(const T& x) {
  std::cout << x << endl;
  exit(0);
}
void debug_out() { std::cout << "\n"; }
template <class T, class... Args>
void debug_out(const T& x, const Args&... args) {
  std::cout << x << " ";
  debug_out(args...);
}
struct InitIO {
  InitIO() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
  }
} init_io;
const int mod = 1000000007;
struct mint {
  ll x;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }
  mint inv() const { return pow(mod - 2); }
  mint& operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
  bool operator==(const mint rhs) const { return x == rhs.x; }
  bool operator!=(const mint rhs) const { return x != rhs.x; }
  bool operator<(const mint& a) const { return x < a.x; };
};
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }
template <typename ModInt>
struct Combination {
  vector<ModInt> fact, ifact;
  Combination(int n) : fact(n + 1), ifact(n + 1) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
  }
  ModInt C(int n, int k) {
    if (k < 0 || n < k) return 0;
    return fact[n] * ifact[k] * ifact[n - k];
  }
  ModInt P(int n, int r) {
    if (r < 0 || n < r) return 0;
    return fact[n] * ifact[n - r];
  }
  ModInt H(int n, int r) {
    if (r < 0 || n < 0) return 0;
    return r == 0 ? 1 : C(n + r - 1, r);
  }
  ModInt operator()(int n, int k) { return C(n, k); }
};
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<mint> > dp(m + 5, vector<mint>(n + 5, 0));
  for (int i = 0; i < (n + 5); ++i) dp[0][i] = 1;
  for (int i = 1; i < (m); ++i) {
    for (int j = 1; j < (n + 1); ++j) {
      for (int k = 1; k <= j; ++k) dp[i][j] += dp[i - 1][k];
    }
  }
  Combination<mint> comb(1000);
  mint ans = 0;
  for (int i = 1; i < (n + 1); ++i) {
    ans += dp[m - 1][i] * comb.H(n - i + 1, m);
  }
  cout << ans << endl;
  return 0;
}
