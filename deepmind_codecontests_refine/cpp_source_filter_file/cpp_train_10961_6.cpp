#include <bits/stdc++.h>
using namespace std;
bool islucky(long long x) {
  while (x) {
    long long y = x % 10;
    if (y != 4 && y != 7) {
      return false;
    }
    x /= 10;
  }
  return true;
}
map<long long, long long> foo;
struct mint {
  typedef decay<decltype(1000000007)>::type T;
  T v;
  explicit operator T() const { return v; }
  mint() { v = 0; }
  mint(long long _v) {
    v = (-1000000007 < _v && _v < 1000000007) ? _v : _v % 1000000007;
    if (v < 0) v += 1000000007;
  }
  friend bool operator==(const mint& a, const mint& b) { return a.v == b.v; }
  friend bool operator!=(const mint& a, const mint& b) { return !(a == b); }
  friend bool operator<(const mint& a, const mint& b) { return a.v < b.v; }
  mint& operator+=(const mint& m) {
    if ((v += m.v) >= 1000000007) v -= 1000000007;
    return *this;
  }
  mint& operator-=(const mint& m) {
    if ((v -= m.v) < 0) v += 1000000007;
    return *this;
  }
  mint& operator*=(const mint& m) {
    v = (long long)v * m.v % 1000000007;
    return *this;
  }
  mint& operator/=(const mint& m) { return (*this) *= inv(m); }
  friend mint pow(mint a, long long p) {
    mint ans = 1;
    assert(p >= 0);
    for (; p; p /= 2, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  friend mint inv(const mint& a) {
    assert(a.v != 0);
    return pow(a, 1000000007 - 2);
  }
  mint operator-() const { return mint(-v); }
  mint& operator++() { return *this += 1; }
  mint& operator--() { return *this -= 1; }
  friend mint operator+(mint a, const mint& b) { return a += b; }
  friend mint operator-(mint a, const mint& b) { return a -= b; }
  friend mint operator*(mint a, const mint& b) { return a *= b; }
  friend mint operator/(mint a, const mint& b) { return a /= b; }
};
vector<mint> fact;
void bincoeff(long long n) {
  fact.resize(n + 1);
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * i;
  }
}
mint ncr(long long n, long long r) {
  if ((n < 0) || (r < 0) || ((n - r) < 0)) return 0;
  return (fact[n] / (fact[n - r] * fact[r]));
}
mint dp[2][100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, x, t, m, y, z, k;
  cin >> n >> k;
  bincoeff(n + 5);
  vector<long long> a;
  for (int e = 0; e < n; e++) {
    long long y;
    cin >> y;
    a.push_back(y);
  };
  x = 0;
  for (int i = 0; i < n; i++) {
    if (islucky(a[i])) {
      x++;
      foo[a[i]]++;
    }
  }
  vector<long long> boo;
  for (auto it : foo) {
    boo.push_back(it.second);
  }
  foo.clear();
  m = boo.size();
  dp[0][0] = 1;
  long long rip = 1;
  for (int i = m - 1; i >= 0; i--, rip++) {
    for (int j = 0; j <= k; j++) {
      dp[rip % 2][j] = dp[(rip + 1) % 2][j];
      if (j) {
        dp[rip % 2][j] = dp[(rip + 1) % 2][j - 1] * boo[i];
      }
    }
  }
  rip++;
  rip %= 2;
  mint ans = 0;
  n -= x;
  for (int i = 0; i <= k; i++) {
    ans += (ncr(n, i)) * (dp[rip][k - i]);
  }
  cout << ans.v;
  return 0;
}
