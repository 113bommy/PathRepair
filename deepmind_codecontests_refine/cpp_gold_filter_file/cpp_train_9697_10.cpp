#include <bits/stdc++.h>
using namespace std;
int lg(long long n) {
  assert(n > 0);
  int ans = -1;
  while (n) {
    ans++;
    n >>= 1;
  }
  return ans;
}
template <int mod_>
struct modint {
  static const int mod = mod_;
  int val;
  modint() { val = 0; }
  modint(const long long& v) {
    val = (-mod <= v && v < mod) ? v : v % mod;
    if (val < 0) val += mod;
  }
  friend ostream& operator<<(ostream& os, const modint& a) {
    return os << a.val;
  }
  friend bool operator==(const modint& a, const modint& b) {
    return a.val == b.val;
  }
  friend bool operator!=(const modint& a, const modint& b) { return !(a == b); }
  friend bool operator<(const modint& a, const modint& b) {
    return a.val < b.val;
  }
  modint operator-() const { return modint(-val); }
  modint& operator+=(const modint& m) {
    if ((val += m.val) >= mod) val -= mod;
    return *this;
  }
  modint& operator-=(const modint& m) {
    if ((val -= m.val) < 0) val += mod;
    return *this;
  }
  modint& operator*=(const modint& m) {
    val = (long long)val * m.val % mod;
    return *this;
  }
  modint qpow(long long p) {
    modint ans = 1, base = val;
    for (; p; p /= 2, base *= base)
      if (p & 1) ans *= base;
    return ans;
  }
  modint inv() { return qpow((long long)mod - 2); }
  modint& operator/=(modint m) { return (*this) *= m.inv(); }
  friend modint operator+(modint a, const modint& b) { return a += b; }
  friend modint operator-(modint a, const modint& b) { return a -= b; }
  friend modint operator*(modint a, const modint& b) { return a *= b; }
  friend modint operator/(modint a, const modint& b) { return a /= b; }
  operator long long() const { return val; }
};
using mint = modint<998244353>;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(2);
  a[0].push_back(0), a[1].push_back(0);
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    a[i % 2].push_back(b);
  }
  a[0].push_back(k + 1), a[1].push_back(k + 1);
  vector<mint> diff(n + 1), same(n + 1);
  same[0] = 0, diff[0] = 1;
  for (int i = 1; i <= n; i++) {
    same[i] = mint(k - 1) * diff[i - 1];
    diff[i] = same[i - 1] + diff[i - 1] * mint(k - 2);
  }
  mint ans = 1;
  for (int i = 0; i < 2; i++) {
    int sz = (int)a[i].size();
    for (int l = 0, r = 0; l < sz - 1;) {
      r = l + 1;
      while (a[i][r] == -1) r++;
      assert(r < sz);
      if (l == 0 && r == sz - 1) {
        assert(r - l >= 2);
        ans *= mint(k) * mint(k - 1).qpow(r - l - 2);
      } else if (l == 0 || r == sz - 1) {
        ans *= mint(k - 1).qpow(r - l - 1);
      } else {
        if (a[i][l] == a[i][r])
          ans *= same[r - l - 1];
        else
          ans *= diff[r - l - 1];
      }
      l = r;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
