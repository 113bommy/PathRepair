#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using ld = long double;
template <typename T>
using V = vector<T>;
template <typename T>
using VV = vector<vector<T>>;
const ll mod = 1000000007;
const ll INF = 1000000099;
const ll LINF = (ll)(1e18 + 99);
const vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
template <typename T, typename U>
inline bool chmin(T& t, const U& u) {
  if (t > u) {
    t = u;
    return 1;
  }
  return 0;
}
template <typename T, typename U>
inline bool chmax(T& t, const U& u) {
  if (t < u) {
    t = u;
    return 1;
  }
  return 0;
}
template <typename T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T, typename Y>
inline T mpow(T a, Y n) {
  T res = 1;
  for (; n; n >>= 1) {
    if (n & 1) res = res * a;
    a = a * a;
  }
  return res;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  string s;
  cin >> s;
  ll n = (ll)(s).size(), ans = 0;
  V<ll> mnr(n, INF);
  for (ll i = 0; i < (ll)(n); ++i) {
    for (ll j = 1; j < (ll)(11); ++j) {
      if (n <= i + 2 * j) break;
      if (s[i] == s[i + j] && s[i + j] == s[i + 2 * j]) {
        mnr[i] = i + 2 * j;
        break;
      }
    }
  }
  for (ll i = n - 1 - 1; (ll)0 <= i; --i) {
    chmin(mnr[i], mnr[i + 1]);
  }
  for (ll i = 0; i < (ll)(n); ++i) {
    if (mnr[i] < INF) ans += n - mnr[i];
  }
  cout << ans << '\n';
}
