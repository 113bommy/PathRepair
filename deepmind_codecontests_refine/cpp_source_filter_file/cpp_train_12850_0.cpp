#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int> adj[N], adjr[N];
vector<int> order;
map<int, int> mm;
int mini = INT_MAX;
int vis[N], cost[N];
void dfs1(int v) {
  vis[v] = 1;
  for (int to : adj[v]) {
    if (!vis[to]) {
      dfs1(to);
    }
  }
  order.push_back(v);
}
void dfs2(int v) {
  vis[v] = 1;
  if (cost[v] <= mini) {
    mini = cost[v];
    mm[mini]++;
  }
  for (int to : adjr[v]) {
    if (!vis[to]) dfs2(to);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, u, v;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> cost[i];
  cin >> m;
  while (m--) {
    cin >> u >> v;
    adj[u].push_back(v);
    adjr[v].push_back(u);
  }
  memset(vis, 0, sizeof vis);
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) dfs1(i);
  }
  reverse(order.begin(), order.end());
  memset(vis, 0, sizeof vis);
  int sum = 0;
  long long tot = 1LL;
  for (int i : order) {
    mm.clear();
    mini = INT_MAX;
    if (!vis[i]) {
      dfs2(i);
      sum += mini;
      tot = (tot * mm[mini] * 1LL) % 1000000007;
    }
  }
  cout << sum << ' ' << tot << endl;
  return 0;
}
