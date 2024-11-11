#include <bits/stdc++.h>
using namespace std;
template <typename T>
T mod_inv_in_range(T a, T m) {
  T x = a, y = m;
  T vx = 1, vy = 0;
  while (x) {
    T k = y / x;
    y %= x;
    vy -= k * vx;
    std::swap(x, y);
    std::swap(vx, vy);
  }
  assert(y == 1);
  return vy < 0 ? m + vy : vy;
}
template <typename T>
T mod_inv(T a, T m) {
  a %= m;
  a = a < 0 ? a + m : a;
  return mod_inv_in_range(a, m);
}
template <int MOD_>
struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");

 private:
  using ll = long long;
  int v;

 public:
  modnum() : v(0) {}
  modnum(ll v_) : v(int(v_ % MOD)) {
    if (v < 0) v += MOD;
  }
  explicit operator int() const { return v; }
  friend std::ostream& operator<<(std::ostream& out, const modnum& n) {
    return out << int(n);
  }
  friend std::istream& operator>>(std::istream& in, modnum& n) {
    ll v_;
    in >> v_;
    n = modnum(v_);
    return in;
  }
  friend bool operator==(const modnum& a, const modnum& b) {
    return a.v == b.v;
  }
  friend bool operator!=(const modnum& a, const modnum& b) {
    return a.v != b.v;
  }
  modnum inv() const {
    modnum res;
    res.v = mod_inv_in_range(v, MOD);
    return res;
  }
  friend modnum inv(const modnum& m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD - v : 0;
    return res;
  }
  friend modnum neg(const modnum& m) { return m.neg(); }
  modnum operator-() const { return neg(); }
  modnum operator+() const { return modnum(*this); }
  modnum& operator++() {
    v++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum& operator--() {
    if (v == 0) v = MOD;
    v--;
    return *this;
  }
  modnum& operator+=(const modnum& o) {
    v -= MOD - o.v;
    v = (v < 0) ? v + MOD : v;
    return *this;
  }
  modnum& operator-=(const modnum& o) {
    v -= o.v;
    v = (v < 0) ? v + MOD : v;
    return *this;
  }
  modnum& operator*=(const modnum& o) {
    v = int(ll(v) * ll(o.v) % MOD);
    return *this;
  }
  modnum& operator/=(const modnum& o) { return *this *= o.inv(); }
  friend modnum operator++(modnum& a, int) {
    modnum r = a;
    ++a;
    return r;
  }
  friend modnum operator--(modnum& a, int) {
    modnum r = a;
    --a;
    return r;
  }
  friend modnum operator+(const modnum& a, const modnum& b) {
    return modnum(a) += b;
  }
  friend modnum operator-(const modnum& a, const modnum& b) {
    return modnum(a) -= b;
  }
  friend modnum operator*(const modnum& a, const modnum& b) {
    return modnum(a) *= b;
  }
  friend modnum operator/(const modnum& a, const modnum& b) {
    return modnum(a) /= b;
  }
};
template <typename T>
T pow(T a, long long b) {
  assert(b >= 0);
  T r = 1;
  while (b) {
    if (b & 1) r *= a;
    b >>= 1;
    a *= a;
  }
  return r;
}
const int MOD = 998244353;
using mint = modnum<MOD>;
const int N = 1e5 + 5;
int n, m, l[N], r[N];
mint f[N], dp[N], pre[N];
int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> l[i] >> r[i];
  for (int g = m; g >= 1; --g) {
    int T = m / g;
    for (int i = 0; i <= T; ++i) dp[i] = 0;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
      pre[0] = dp[0];
      for (int j = 1; j <= T; ++j) {
        pre[j] = (pre[j - 1] + dp[j]);
      }
      for (int i = 0; i <= T; ++i) dp[i] = 0;
      int lef = (l[i] + g - 1) / g;
      int rig = r[i] / g;
      if (lef <= rig) {
        for (int j = 1; j <= T; ++j) {
          int y = j - lef, x = max(j - rig, 0);
          if (x <= y) {
            dp[j] = pre[y] - (x == 0 ? 0 : pre[x - 1]);
          }
        }
      }
    }
    for (int i = 1; i <= T; ++i) {
      f[g] = (f[g] + dp[i]);
    }
    for (int k = g * 2; k <= m; k += g) {
      f[g] = f[g] - f[k];
    }
  }
  cout << f[1] << '\n';
}
