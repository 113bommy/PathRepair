#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
vector<int> adj[100005];
pii dfs(int i, int p) {
  pii ret = {i, 0};
  for (int x : adj[i]) {
    if (x == p) continue;
    pii r = dfs(x, i);
    r.second++;
    if (r.second > ret.second) ret = r;
  }
  return ret;
}
int depth[100005], par[100005];
void f(int i, int p, int d) {
  depth[i] = d;
  par[i] = p;
  for (int x : adj[i]) {
    if (x == p) continue;
    f(x, i, d + 1);
  }
}
int lca(int a, int b) {
  int len = 0;
  while (depth[a] > depth[b]) a = par[a], len++;
  while (depth[b] > depth[a]) b = par[b], len++;
  while (a != b) {
    a = par[a];
    b = par[b];
    len += 2;
  }
  return len;
}
void solve() {
  ll i, j;
  int n, a, b, da, db;
  cin >> n >> a >> b >> da >> db;
  for (i = 1; i <= n; i++) adj[i].clear();
  for (i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int mx = dfs(dfs(1, 0).first, 0).second;
  f(1, 0, 0);
  int len = lca(a, b);
  if (len <= da || da * 2 >= db || mx <= da * 2) {
    cout << "Alice\n";
    return;
  } else
    cout << "Bob\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
