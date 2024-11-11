#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <int MOD>
struct ModInt {
  int val;
  ModInt(ll v = 0) : val(int(v % MOD)) {
    if (val < 0) val += MOD;
  };
  ModInt operator+() const { return ModInt(val); }
  ModInt operator-() const { return ModInt(MOD - val); }
  ModInt inv() const { return this->pow(MOD - 2); }
  ModInt operator+(const ModInt& x) const { return ModInt(*this) += x; }
  ModInt operator-(const ModInt& x) const { return ModInt(*this) -= x; }
  ModInt operator*(const ModInt& x) const { return ModInt(*this) *= x; }
  ModInt operator/(const ModInt& x) const { return ModInt(*this) /= x; }
  ModInt pow(ll n) const {
    auto x = ModInt(1);
    auto b = *this;
    while (n > 0) {
      if (n & 1) x *= b;
      n >>= 1;
      b *= b;
    }
    return x;
  }
  ModInt& operator+=(const ModInt& x) {
    if ((val += x.val) >= MOD) val -= MOD;
    return *this;
  }
  ModInt& operator-=(const ModInt& x) {
    if ((val -= x.val) < 0) val += MOD;
    return *this;
  }
  ModInt& operator*=(const ModInt& x) {
    val = int(ll(val) * x.val % MOD);
    return *this;
  }
  ModInt& operator/=(const ModInt& x) { return *this *= x.inv(); }
  bool operator==(const ModInt& b) const { return val == b.val; }
  bool operator!=(const ModInt& b) const { return val != b.val; }
  friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept {
    return is >> x.val;
  }
  friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept {
    return os << x.val;
  }
};
using mint = ModInt<int(1e9 + 7)>;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k, r, c, ax, ay, bx, by;
  cin >> n >> m >> k >> r >> c >> ax >> ay >> bx >> by;
  if (ax > bx) {
    swap(ax, bx);
    swap(ay, by);
  }
  if (by < ay) {
    int d = ay - by;
    ay = by, by = ay + d;
  }
  assert(ax <= bx && ay <= by);
  if (ax == bx && ay == by) {
    cout << mint(k).pow(ll(n) * m) << endl;
    return 0;
  }
  mint ans = 1;
  for (int i = 0; i < r; i++) {
    int w = (i < bx - ax ? c : min(by - ay, c));
    ans *= mint(k).pow(w);
  };
  ans *= mint(k).pow((ll)n * m - 2 * r * c +
                     max(0, c - (by - ay)) * max(0, r - (bx - ax)));
  cout << ans << endl;
}
