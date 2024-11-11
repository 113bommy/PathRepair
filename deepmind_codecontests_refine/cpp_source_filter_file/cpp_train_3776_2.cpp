#include <bits/stdc++.h>
template <class T>
std::vector<T> vec(int len, T elem) {
  return std::vector<T>(len, elem);
}
template <class T>
std::map<T, int> compress(std::vector<T>& v) {
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  std::map<T, int> rev;
  for (int i = 0; i < (int)v.size(); ++i) rev[v[i]] = i;
  return rev;
}
template <int MOD>
struct ModInt {
  using lint = long long;
  int val;
  ModInt(lint v = 0) : val(v % MOD) {
    if (val < 0) val += MOD;
  };
  ModInt operator+() const { return ModInt(val); }
  ModInt operator-() const { return ModInt(MOD - val); }
  ModInt inv() const { return this->pow(MOD - 2); }
  ModInt operator+(const ModInt& x) const { return ModInt(*this) += x; }
  ModInt operator-(const ModInt& x) const { return ModInt(*this) -= x; }
  ModInt operator*(const ModInt& x) const { return ModInt(*this) *= x; }
  ModInt operator/(const ModInt& x) const { return ModInt(*this) /= x; }
  ModInt pow(lint n) const {
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
    val = lint(val) * x.val % MOD;
    return *this;
  }
  ModInt& operator/=(const ModInt& x) { return *this *= x.inv(); }
  bool operator==(const ModInt& b) const { return val == b.val; }
  bool operator!=(const ModInt& b) const { return val != b.val; }
  bool operator<(const ModInt& b) const { return val < b.val; }
  bool operator<=(const ModInt& b) const { return val <= b.val; }
  bool operator>(const ModInt& b) const { return val > b.val; }
  bool operator>=(const ModInt& b) const { return val >= b.val; }
  friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept {
    lint v;
    is >> v;
    x = v;
    return is;
  }
  friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept {
    return os << x.val;
  }
};
template <class T>
struct Combination {
  int max_n;
  std::vector<T> f, invf;
  explicit Combination(int n) : max_n(n), f(n + 1), invf(n + 1) {
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
      f[i] = f[i - 1] * i;
    }
    invf[max_n] = f[max_n].inv();
    for (int i = max_n - 1; i >= 0; --i) {
      invf[i] = invf[i + 1] * (i + 1);
    }
  }
  T fact(int n) const { return n < 0 ? T(0) : f[n]; }
  T invfact(int n) const { return n < 0 ? T(0) : invf[n]; }
  T perm(int a, int b) const {
    return a < b || b < 0 ? T(0) : f[a] * invf[a - b];
  }
  T binom(int a, int b) const {
    return a < b || b < 0 ? T(0) : f[a] * invf[a - b] * invf[b];
  }
};
constexpr int MOD = 998244353;
using mint = ModInt<MOD>;
const Combination<mint> C(500000);
void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> ins(n + 1), outs(n + 1);
  for (int i = 0; i < n; ++i) {
    int l, r;
    std::cin >> l >> r;
    ins[l].push_back(i);
    outs[r].push_back(i);
  }
  std::vector<std::pair<int, int>> es(m);
  std::map<int, int> vcnt;
  for (auto& [u, v] : es) {
    std::cin >> u >> v;
    ++vcnt[--u];
    ++vcnt[--v];
  }
  std::map<int, int> uid;
  int l = 0;
  for (auto it = es.begin(); it != es.end();) {
    auto [u, v] = *it;
    if (vcnt[u] == 1 && vcnt[v] == 1) {
      vcnt.erase(u);
      vcnt.erase(v);
      uid[u] = l;
      uid[v] = l;
      ++l;
      it = es.erase(it);
    } else {
      ++it;
    }
  }
  std::vector<int> vs;
  for (auto [v, c] : vcnt) vs.push_back(v);
  auto vrev = compress(vs);
  int k = vs.size();
  for (auto& [u, v] : es) u = vrev[u], v = vrev[v];
  auto ind = vec(1 << k, vec(k + 1, mint(0)));
  for (int b = 0; b < (1 << k); ++b) {
    bool judge = true;
    for (auto [i, j] : es) {
      if (((b >> i) & 1) && ((b >> j) & 1)) judge = false;
    }
    if (!judge) continue;
    ind[b][__builtin_popcount(b)] = 1;
  }
  for (int i = 0; i < k; ++i) {
    for (int b = 0; b < (1 << k); ++b) {
      if (!((b >> i) & 1)) continue;
      for (int j = 0; j < k; ++j) {
        ind[b][j] += ind[b ^ (1 << i)][j];
      }
    }
  }
  mint ans = 0;
  int num = 0, b = 0;
  std::vector<int> cnt(l, 0);
  std::vector<mint> poly;
  auto recalc = [&]() {
    poly.assign(1, 1);
    for (auto c : cnt) {
      poly.push_back(0);
      for (int i = (int)poly.size() - 1; i > 0; --i) {
        poly[i] += poly[i - 1] * c;
      }
    }
  };
  recalc();
  for (int x = 1; x <= n; ++x) {
    for (auto v : ins[x]) {
      if (vrev.count(v)) {
        b ^= (1 << vrev[v]);
      } else if (uid.count(v)) {
        ++cnt[uid[v]];
        recalc();
      } else {
        ++num;
      }
    }
    for (int y = 0; y <= k; ++y) {
      for (int z = 0; z <= l; ++z) {
        ans += C.binom(num, x - y - l) * poly[z] * ind[b][y];
      }
    }
    for (auto v : outs[x]) {
      if (vrev.count(v)) {
        b ^= (1 << vrev[v]);
      } else if (uid.count(v)) {
        --cnt[uid[v]];
        recalc();
      } else {
        --num;
      }
    }
  }
  std::cout << ans << "\n";
}
int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  solve();
  return 0;
}
