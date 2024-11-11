#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
struct modint {
  static constexpr int MOD = 998244353;
  int v;
  modint(const int _v = 0) : v(_v % MOD) {
    if (v < 0) v += MOD;
  }
  modint(const modint& other) { v = other.v; }
  bool operator==(const modint& other) const { return v == other.v; }
  modint& operator+=(const modint& other) {
    v += other.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modint& operator-=(const modint& other) {
    v -= other.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modint& operator*=(const modint& other) {
    v = 1LL * v * other.v % MOD;
    return *this;
  }
  modint& operator/=(const modint& other) {
    *this *= other.inv();
    return *this;
  }
  modint operator+(const modint& other) const { return modint(v) += other; }
  modint operator-(const modint& other) const { return modint(v) -= other; }
  modint operator*(const modint& other) const { return modint(v) *= other; }
  modint operator/(const modint& other) const { return modint(v) /= other; }
  static modint pow(const modint& b, ll e) {
    if (e == 0) return 1;
    modint x = pow(b * b, e / 2);
    return (e % 2) ? b * x : x;
  }
  modint pow(ll e) const { return pow(*this, e); }
  modint inv() const { return pow(MOD - 2); }
  friend ostream& operator<<(ostream& os, modint m) { return os << m.v; }
};
constexpr int MAXN = 1e5 + 5;
modint fact[MAXN], tcaf[MAXN];
void gen_fact() {
  fact[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    fact[i] = fact[i - 1] * i;
  }
  tcaf[MAXN - 1] = fact[MAXN - 1].inv();
  for (int i = MAXN - 2; i >= 0; --i) {
    tcaf[i] = tcaf[i + 1] * (i + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  gen_fact();
  ll x;
  cin >> x;
  vector<ll> primes;
  for (ll i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      primes.push_back(i);
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    primes.push_back(x);
  }
  int m = primes.size();
  auto parse = [&](ll u) {
    vi res(m, 0);
    for (int i = 0; i < m; ++i) {
      while (u % primes[i] == 0) {
        ++res[i];
        u /= primes[i];
      }
    }
    return res;
  };
  int q;
  cin >> q;
  while (q-- > 0) {
    ll u, v;
    cin >> u >> v;
    vi a = parse(u);
    vi b = parse(v);
    modint ups = 1;
    modint downs = 1;
    int tot_up = 0;
    int tot_down = 0;
    for (int i = 0; i < m; ++i) {
      if (a[i] > b[i]) {
        int d = a[i] - b[i];
        tot_down += d;
        downs *= tcaf[d];
      } else if (a[i] < b[i]) {
        int d = b[i] - a[i];
        tot_up += d;
        ups *= tcaf[d];
      }
    }
    ups *= fact[tot_up];
    downs *= fact[tot_down];
    modint ans = ups * downs;
    cout << ans << '\n';
  }
  return 0;
}
