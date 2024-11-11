#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vec;
const int mod = 998244353;
const int mx = 1005;
ll mul(ll x, ll y) { return (x * 1ll * y); }
bool prime(ll x) {
  if (x < 2) return false;
  for (ll i = 2; i * i <= x; ++i) {
    if (x % i == 0) return false;
  }
  return true;
}
ll powerm(ll a, ll b, ll m = mod) {
  a %= m;
  ll res = 1 % m;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % m;
    }
    b >>= 1;
    a = (a * a) % m;
  }
  return res;
}
int solve() {
  ll n, k, x;
  cin >> n >> k >> x;
  ll beauty[n + 1], dp[n + 1][x + 1];
  for (int i = 1; i <= n; i++) cin >> beauty[i];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= x; j++) dp[i][j] = INT_MIN;
  for (int i = 0; i <= x; i++) dp[0][i] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < x; j++) {
      for (int p = 1; p <= k; p++) {
        if (i - p < 0) break;
        if (dp[i - p][j + 1] == INT_MIN) continue;
        dp[i][j] = max(dp[i][j], dp[i - p][j + 1] + beauty[i]);
      }
    }
  }
  ll ans = INT_MIN;
  for (int i = n - k + 1; i <= n; i++)
    ans = max(ans, *max_element(dp[i], dp[i] + x + 1));
  if (ans < 0) ans = -1;
  cout << ans;
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int q = 1;
  while (q--) solve();
}
