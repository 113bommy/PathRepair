#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = int_fast64_t;
using ld = long double;
constexpr ll mod = 1e9 + 7;
constexpr ll Mod = 998244353;
constexpr ll MXN = 500000 + 100;
constexpr ld EPS = 1e-10;
constexpr ll inf = 3 * 1e18;
constexpr ll Inf = 15 * 1e8;
const vector<ll> dx{-1, 1, 0, 0}, dy{0, 0, -1, 1};
template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
ll read() {
  ll u, k = scanf("%lld", &u);
  return u;
}
string reads() {
  string s;
  cin >> s;
  return s;
}
pair<ll, ll> readh(bool g = 0) {
  pair<ll, ll> u;
  ll k = scanf("%lld %lld", &u.first, &u.second);
  if (g) u.first--, u.second--;
  return u;
}
void printh(pair<ll, ll> t) { printf("%lld %lld\n", t.first, t.second); }
bool inarea(pair<ll, ll> t, ll h, ll w) {
  return 0 <= t.first && t.first < h && 0 <= t.second && t.second < w;
}
ll gcd(ll i, ll j) { return j ? gcd(j, i % j) : i; }
ll mod_pow(ll x, ll n, ll p = mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % p;
    x = x * x % p;
    n >>= 1;
  }
  return res;
}
ll bitcount(ll x) {
  ll sum = 0;
  for (ll i = 0; i < 60; i++)
    if ((1ll << i) & x) sum++;
  return sum;
}
ll n, q;
ll a[2][200000];
ll b[200000];
set<ll> se, se2;
signed main() {
  cin >> n >> q;
  for (ll(i) = 0; (i) < (q); (i)++) {
    ll t = read(), r = read();
    t--;
    r--;
    if (a[t][r]) {
      if (se.find(r) != se.end()) se.erase(r);
      a[t][r] = 0;
      if (r > 0 && a[!t][r - 1]) {
        b[r - 1]--;
        if (b[r - 1] == 0) se2.erase(r - 1);
      }
      if (r < n - 1 && a[!t][r + 1]) {
        b[r]--;
        if (b[r] == 0) se2.erase(r);
      }
    } else {
      a[t][r] = 1;
      if (a[0][r] && a[1][r]) se.insert(r);
      if (r > 0 && a[!t][r - 1]) {
        b[r - 1]++;
        if (b[r - 1] >= 1) se2.insert(r - 1);
      }
      if (r < n - 1 && a[!t][r + 1]) {
        b[r]++;
        if (b[r] >= 1) se.insert(r);
      }
    }
    if (se.empty() && se2.empty())
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
