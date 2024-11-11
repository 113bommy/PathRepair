#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const long long linf = 4000000000000000000LL;
const long long inf = 998244353;
const long double pi = 3.1415926535;
void pv(vector<int> a) {
  for (auto& x : a) cout << x << " ";
  cout << '\n';
}
void pv(vector<long long> a) {
  for (auto& x : a) cout << x << " ";
  cout << '\n';
}
void pv(vector<vector<int> > a) {
  for (int i = (0); i < (int(a.size())); ++i) {
    cout << i << '\n';
    pv(a[i]);
    cout << '\n';
  }
}
void pv(vector<vector<long long> > a) {
  for (int i = (0); i < (int(a.size())); ++i) {
    cout << i << '\n';
    pv(a[i]);
  }
  cout << '\n';
}
void pv(vector<string> a) {
  for (auto& x : a) cout << x << '\n';
  cout << '\n';
}
void setIO(string second) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (int(second.size())) {
    freopen((second + ".in").c_str(), "r", stdin);
    if (second != "test2") freopen((second + ".out").c_str(), "w", stdout);
  }
}
template <int MOD, int RT>
struct mint {
  static const int mod = MOD;
  static constexpr mint rt() { return RT; }
  int v;
  explicit operator int() const { return v; }
  mint() { v = 0; }
  mint(long long _v) {
    v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
    if (v < 0) v += MOD;
  }
  friend bool operator==(const mint& a, const mint& b) { return a.v == b.v; }
  friend bool operator!=(const mint& a, const mint& b) { return !(a == b); }
  friend bool operator<(const mint& a, const mint& b) { return a.v < b.v; }
  mint& operator+=(const mint& m) {
    if ((v += m.v) >= MOD) v -= MOD;
    return *this;
  }
  mint& operator-=(const mint& m) {
    if ((v -= m.v) < 0) v += MOD;
    return *this;
  }
  mint& operator*=(const mint& m) {
    v = int((long long)v * m.v % MOD);
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
    return pow(a, MOD - 2);
  }
  mint operator-() const { return mint(-v); }
  mint& operator++() { return *this += 1; }
  mint& operator--() { return *this -= 1; }
  friend mint operator+(mint a, const mint& b) { return a += b; }
  friend mint operator-(mint a, const mint& b) { return a -= b; }
  friend mint operator*(mint a, const mint& b) { return a *= b; }
  friend mint operator/(mint a, const mint& b) { return a /= b; }
};
typedef mint<inf, 5> mi;
int main() {
  setIO("");
  int n;
  cin >> n;
  vector<string> a(n);
  string total;
  for (auto& x : a) cin >> x, total += x, total += " ";
  int base = 31;
  int m = int(total.size());
  vector<mi> prefix(m + 1), power(m + 1);
  power[0] = 1;
  for (int i = (0); i < (int(power.size()) - 1); ++i)
    power[i + 1] = power[i] * base;
  for (int i = (0); i < (m); ++i)
    prefix[i + 1] = prefix[i] + (power[i] * (total[i] - 'a'));
  vector<int> prefixlen(n + 1);
  for (int i = (0); i < (n); ++i)
    prefixlen[i + 1] = prefixlen[i] + int(a[i].size()) + 1;
  int ans = m;
  for (int i = (0); i < (n); ++i) {
    for (int len = (0); len < (n); ++len) {
      if (i + len > n) continue;
      int count = 1;
      int k = i + len;
      while (k < n) {
        int j = k;
        if (j + len > n) break;
        mi hash1 = prefix[prefixlen[i + len]] - prefix[prefixlen[i]];
        hash1 *= power[prefixlen[j]];
        mi hash2 = prefix[prefixlen[j + len]] - prefix[prefixlen[j]];
        hash2 *= power[prefixlen[i]];
        if (hash1 == hash2) {
          count++;
          k = j + len;
        }
        k++;
      }
      if (count > 1)
        ans = min(
            ans, m - count * ((prefixlen[i + len] - prefixlen[i]) - (len + 1)));
    }
  }
  cout << ans - 1 << '\n';
}
