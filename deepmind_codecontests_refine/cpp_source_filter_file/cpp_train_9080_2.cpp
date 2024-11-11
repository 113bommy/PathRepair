#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const ll MOD = 998244353, N = 1e3 + 10;
string s, t;
ll n, m;
ll dp[N][N];
ll dfs(ll l, ll r) {
  if (l > r) return 1;
  ll &ans = dp[l][r];
  if (ans != -1) return ans;
  ans = 0;
  if (l >= m or s[r - l] == t[l]) {
    ans += dfs(l + 1, r);
    ans %= MOD;
  }
  if (r >= m or s[r - l] == t[r]) {
    ans += dfs(l, r - 1);
    ans %= MOD;
  }
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s >> t;
  n = s.length();
  m = t.length();
  memset(dp, -1, sizeof dp);
  ll ans = 0;
  for (ll i = m - 1; i < n; i++) {
    ans += dfs(0, i);
    ans %= MOD;
  }
  cout << ans << '\n';
  return 0;
}
