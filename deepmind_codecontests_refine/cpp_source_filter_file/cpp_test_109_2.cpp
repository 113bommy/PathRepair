#include <bits/stdc++.h>
using namespace std;
template <unsigned _MOD_>
struct modint {
  static const int MOD = _MOD_;
  int v;
  modint(int _v = 0) {
    v = _v % MOD;
    if (v < 0) v += MOD;
  }
  explicit operator int() const { return v; }
  static int mod_inv(int a) {
    int g = MOD, r = a, x = 0, y = 1;
    while (r != 0) {
      int q = g / r;
      g %= r;
      swap(g, r);
      x -= q * y;
      swap(x, y);
    }
    return x < 0 ? x + MOD : x;
  }
  modint &operator+=(const modint &other) {
    v += other.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modint &operator-=(const modint &other) {
    v -= other.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modint &operator*=(const modint &other) {
    v = (int)(((uint64_t)v * other.v) % MOD);
    return *this;
  }
  modint &operator/=(const modint &other) { return *this *= other.inv(); }
  friend modint operator+(const modint &a, const modint &b) {
    return modint(a) += b;
  }
  friend modint operator-(const modint &a, const modint &b) {
    return modint(a) -= b;
  }
  friend modint operator*(const modint &a, const modint &b) {
    return modint(a) *= b;
  }
  friend modint operator/(const modint &a, const modint &b) {
    return modint(a) /= b;
  }
  modint &operator++() {
    v = v == MOD - 1 ? 0 : v + 1;
    return *this;
  }
  modint &operator--() {
    v = v == 0 ? MOD - 1 : v - 1;
    return *this;
  }
  modint operator++(int32_t) {
    modint before = *this;
    ++*this;
    return before;
  }
  modint operator--(int32_t) {
    modint before = *this;
    --*this;
    return before;
  }
  modint operator-() const { return v == 0 ? 0 : MOD - v; }
  bool operator==(const modint &other) const { return v == other.v; }
  bool operator!=(const modint &other) const { return v != other.v; }
  modint inv() const { return mod_inv(v); }
  modint pow(int p) const {
    modint a = *this, result = 1;
    while (p > 0) {
      if (p & 1) result *= a;
      a *= a;
      p >>= 1;
    }
    return result;
  }
  friend ostream &operator<<(ostream &out, const modint &m) {
    return out << m.v;
  }
};
const int MOD = 998244353;
using mint = modint<MOD>;
void solve() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int lb = 0, rb = 0, lw = 0, rw = 0;
  for (int i = 0; i < n; ++i) {
    string s = a[i];
    if (s[0] == 'W') lw++;
    if (s[0] == 'B') lb++;
    if (s[1] == 'W') rw++;
    if (s[1] == 'B') rb++;
  }
  vector<mint> f;
  f.emplace_back(1);
  auto fact = [&](int i) -> mint {
    while ((int)f.size() <= i) {
      f.emplace_back(f.back() * (int)f.size());
    }
    return f[i];
  };
  auto choose = [&](int n, int k) -> mint {
    return fact(n) / fact(k) / fact(n - k);
  };
  mint ans(0);
  int lops = n - lb - lw, rops = n - rb - rw;
  for (int alw = 0; alw <= n; ++alw) {
    int cl = alw - lw, cr = alw - rb;
    if (cl < 0 || cl > lops || rb < 0 || rb > lops) {
      continue;
    }
    ans += choose(lops, cl) * choose(rops, cr);
  }
  bool none = true;
  int w = 0, b = 0, o = 0;
  for (int i = 0; i < n; ++i) {
    string s = a[i];
    if (s == "BB" || s == "WW") {
      none = false;
      break;
    }
    if (s[0] == 'W' || s[1] == 'B') {
      w++;
    } else if (s[0] == 'B' || s[1] == 'W') {
      b++;
    } else {
      o++;
    }
  }
  if (none) {
    ans -= mint(2).pow(o);
    if (w == 0) {
      ans++;
    }
    if (b == 0) {
      ans++;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
