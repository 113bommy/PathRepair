#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
const double EPS = 1e-10;
const double PI = acos(-1);
const long long MOD = (long long)1e9 + 7;
struct mint {
  long long x;
  mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD - a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res *= a;
  }
  mint pow(long long t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }
  mint inv() const { return pow(MOD - 2); }
  mint& operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const {
    mint res(*this);
    return res /= a;
  }
  friend istream& operator>>(istream& in, mint& a) {
    long long _v;
    in >> _v;
    a = mint(_v);
    return in;
  }
  friend ostream& operator<<(ostream& out, const mint& a) { return out << a.x; }
  friend bool operator==(const mint& a, const mint& b) { return a.x == b.x; }
  friend bool operator!=(const mint& a, const mint& b) { return a.x != b.x; }
};
class DNewYearAndArbitraryArrangement {
 public:
  int K;
  mint PA, PB, base;
  vector<vector<mint>> dp;
  vector<vector<int>> used;
  mint dfs(int x, int y) {
    if (used[x][y]) return used[x][y];
    if (x == 0 and y == 0) return dp[x][y] = dfs(x + 1, y);
    if (x + y >= K) return base + x + y;
    used[x][y] = 1;
    return dp[x][y] = PA * dfs(x + 1, y) + PB * dfs(x, x + y);
  }
  void solve(std::istream& in, std::ostream& out) {
    ios_base::sync_with_stdio(false);
    in.tie(nullptr), out.tie(nullptr);
    mint a, b;
    in >> K >> a >> b;
    PA = a / (a + b), PB = b / (a + b);
    base = PB * PA / (mint(1) - PA).pow(2);
    dp.assign(K + 1, vector<mint>(K + 1));
    used.assign(K + 1, vector<int>(K + 1, 0));
    out << dfs(0, 0) << '\n';
  }
};
int main() {
  DNewYearAndArbitraryArrangement solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
