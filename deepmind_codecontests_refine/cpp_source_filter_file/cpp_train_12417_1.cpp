#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int get_random() {
  static uniform_int_distribution<int> dist(0, 1e9 + 6);
  return dist(rng);
}
template <class T>
void make_unique(T& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
int geti() {
  int x;
  cin >> x;
  return x;
}
long long getll() {
  long long x;
  cin >> x;
  return x;
}
double getd() {
  double x;
  cin >> x;
  return x;
}
const int MAXN = 3e5 + 100;
long long mod = 1e9 + 7;
struct mint {
  long long x;
  mint() : x(0) {}
  mint(long long _x) { x = _x >= 0 ? _x % mod : _x % mod + mod; }
  template <class T>
  mint operator^(T b) const {
    if (!b) return 1;
    mint tmp = (*this) ^ (b / 2);
    return b % 2 ? tmp * tmp * (*this) : tmp * tmp;
  }
  mint inv() const {
    static unordered_map<long long, long long> inv_dp;
    if (inv_dp.count(x))
      return inv_dp[x];
    else if (inv_dp.size() < 100000)
      return mint(inv_dp[x] = ((*this) ^ (mod - 2)).x);
    else
      return (*this) ^ (mod - 2);
  }
  mint operator+(const mint& b) const { return (x + b.x) % mod; }
  mint operator-(const mint& b) const { return (x - b.x + mod) % mod; }
  mint operator*(const mint& b) const { return (x * b.x) % mod; }
  mint operator/(const mint& b) const { return (*this) * b.inv(); }
  mint& operator+=(const mint& b) {
    x = (x + b.x) % mod;
    return *this;
  }
  mint& operator-=(const mint& b) {
    x = (x - b.x + mod) % mod;
    return *this;
  }
  mint& operator*=(const mint& b) {
    x = (x * b.x) % mod;
    return *this;
  }
  mint& operator/=(const mint& b) {
    x = (x * b.inv().x) % mod;
    return *this;
  }
  bool operator==(const mint& b) const { return x == b.x; }
  bool operator!=(const mint& b) const { return x != b.x; }
};
void solve(int tt) {}
mint a[10][MAXN];
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  string s;
  cin >> s;
  for (auto i = (0); i < (10); i++) {
    a[i][0] = mint(i);
    mint base = 10;
    for (auto j = (1); j < (100010); j++) {
      a[i][j] = base * i * (j + 1);
      a[i][j] += a[i][j - 1];
      base *= 10;
    }
  }
  mint res = 0, base = 1;
  int n = s.size();
  for (auto i = (0); i < (n); i++) {
    int cur = s[n - 1 - i] - '0';
    int rem = n - i - 1;
    mint tmp = mint(cur) * base * (rem * (rem - 1) / 2 + rem);
    if (i) tmp += a[cur][i - 1];
    res += tmp;
    base *= 10;
  }
  cout << res.x << endl;
  return 0;
}
