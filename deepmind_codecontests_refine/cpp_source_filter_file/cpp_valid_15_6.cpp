#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using PP = pair<ll, P>;
const ll n_ = 111 + 100, inf = 1e18, mod = 1e9 + 7, sqrtN = 333, p = 27;
ll dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
ll n, m, k, tc = 1, a, b, c, d, sum, x, y, z, w, base, ans;
ll gcd(ll x, ll y) {
  if (!y) return x;
  return gcd(y, x % y);
}
vector<ll> v[n_];
ll checked[n_], cnt[n_], dp[n_][n_];
ll f(ll x, ll y) {
  for (int i = 0; i <= x; i++)
    for (int j = 0; j <= y; j++) dp[i][j] = 0;
  dp[0][0] = 1;
  for (int i = 0; i < x; i++)
    for (int j = 0; j <= y; j++) {
      dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
      dp[i + 1][j + 1] = (dp[i + 1][j + 1] + (dp[i][j] * cnt[i]) % mod) % mod;
    }
  return dp[x][y];
}
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) v[i].clear();
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  ans = 0;
  if (k == 2) {
    ans = n * (n - 1) / 2;
    cout << ans % mod << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    memset(checked, 0, sizeof(checked));
    checked[i] = true;
    vector<P> temp;
    for (int j = 0; j < v[i].size(); j++) {
      temp.push_back({v[i][j], j});
      cnt[j] = 1;
      checked[j] = true;
    }
    while (temp.size()) {
      ans += f((ll)v[i].size(), k);
      ans %= mod;
      vector<P> V;
      for (auto nxt : temp) {
        cnt[nxt.second]--;
        for (auto nxt2 : v[nxt.first]) {
          if (checked[nxt2]) continue;
          checked[nxt2] = true;
          cnt[nxt.second]++;
          V.push_back({nxt2, nxt.second});
        }
      }
      temp = V;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> tc;
  while (tc--) solve();
}
