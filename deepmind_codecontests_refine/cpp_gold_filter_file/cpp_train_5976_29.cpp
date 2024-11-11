#include <bits/stdc++.h>
using namespace std;
long long q, dp[100005], a[555555], vis[555555], k, l, m, n, o, p;
map<long long, long long> mp;
vector<long long> adj[555555];
const long long mod = 1e9 + 7;
string s;
char ans[555555];
void dfs(long long v, long long par) {
  dp[v] = 1;
  for (auto u : adj[v]) {
    if (par == u || vis[u]) continue;
    dfs(u, v);
    dp[v] += dp[u];
  }
}
long long get(long long v, long long par, long long siz) {
  for (auto u : adj[v]) {
    if (par == u || dp[u] <= siz / 2 || vis[u]) continue;
    return get(u, v, siz);
  }
  return v;
}
void dfs_calc(long long v, long long cnt) {
  dfs(v, v);
  k = get(v, v, dp[v]);
  vis[k] = 1;
  ans[k] = cnt + 'A';
  for (auto u : adj[k]) {
    if (vis[u]) continue;
    dfs_calc(u, cnt + 1);
  }
}
void solve() {
  cin >> n;
  for (long long i = 1; i < n; i++) {
    cin >> o >> p;
    adj[o].push_back(p);
    adj[p].push_back(o);
  }
  dfs_calc(1, 0);
  for (long long i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  q = 1;
  while (q--) {
    solve();
  }
}
