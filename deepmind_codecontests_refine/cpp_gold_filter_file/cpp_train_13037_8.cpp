#include <bits/stdc++.h>
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
using namespace std;
using ll = long long;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
ll devc(ll x, ll y) { return (x + y - 1) / y; }
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  ll t;
  cin >> t;
  for (ll _ = 0; _ < (t); ++_) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < (n); ++i) cin >> a[i];
    vector<vector<ll>> f(n + 1, vector<ll>(27, 0LL));
    vector<vector<ll>> g(n + 1, vector<ll>(27, 0LL));
    for (ll i = 0; i < (n); ++i) ++f[i + 1][a[i]], ++g[i + 1][a[i]];
    for (ll i = 0; i < (n); ++i)
      for (ll j = 0; j < (27); ++j) f[i + 1][j] += f[i][j];
    for (ll i = n; i >= 1; --i)
      for (ll j = 0; j < (27); ++j) g[i - 1][j] += g[i][j];
    vector<vector<ll>> mx(n + 1, vector<ll>(n + 1, 0LL));
    ll ans = 1;
    for (ll i = 1; i <= (n); ++i)
      for (ll j = 1; j <= (n); ++j)
        if (i <= j) {
          for (ll b = 1; b <= (26); ++b) chmax(mx[i][j], f[j][b] - f[i - 1][b]);
          ll tp = 0;
          for (ll a = 1; a <= (26); ++a)
            chmax(tp, min(f[n][a] - f[j][a], f[i - 1][a]));
          chmax(ans, mx[i][j] + 2 * tp);
        }
    cout << (ans) << '\n';
  }
  return 0;
}
