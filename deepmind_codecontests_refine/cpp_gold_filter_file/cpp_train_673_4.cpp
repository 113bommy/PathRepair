#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200001;
const long long mod = 1e9 + 7;
int parent[MAXN][20];
int depth[MAXN];
long long dp[MAXN][2];
long long pw[MAXN * 6];
vector<pair<int, int> > tree[MAXN];
pair<int, int> e[MAXN];
int type[MAXN];
void dfs(int here, int dad, int d) {
  depth[here] = d;
  parent[here][0] = dad;
  for (int i = 0; i < tree[here].size(); i++) {
    int there = tree[here][i].first;
    if (there == dad) continue;
    dfs(there, here, d + 1);
  }
}
int getLca(int u, int v) {
  if (depth[u] > depth[v]) swap(u, v);
  int diff = depth[v] - depth[u];
  int i = 0;
  while (diff) {
    if (diff & (1 << i)) {
      diff -= (1 << i);
      v = parent[v][i];
    }
    i++;
  }
  if (u == v) return u;
  for (int i = 19; i >= 0; i--) {
    if (parent[u][i] != parent[v][i]) {
      u = parent[u][i];
      v = parent[v][i];
    }
  }
  return parent[u][0];
}
void go(int here, int dad) {
  for (int i = 0; i < tree[here].size(); i++) {
    int there = tree[here][i].first;
    if (there == dad) continue;
    go(there, here);
    dp[here][0] += dp[there][0];
    dp[here][1] += dp[there][1];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  pw[0] = 1;
  long long start = 1;
  for (int i = 1; i <= MAXN * 5; i++) {
    pw[i] = pw[i - 1] + start * 2;
    pw[i] %= mod;
    start *= 2;
    start %= mod;
  }
  for (int i = 1; i <= n - 1; i++) {
    cin >> e[i].first >> e[i].second;
    cin >> type[i];
    tree[e[i].first].push_back({e[i].second, i});
    tree[e[i].second].push_back({e[i].first, i});
  }
  dfs(1, -1, 0);
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j <= n; j++) {
      if (parent[j][i - 1] == -1)
        parent[j][i] = -1;
      else
        parent[j][i] = parent[parent[j][i - 1]][i - 1];
    }
  }
  vector<int> event;
  int k;
  cin >> k;
  event.push_back(1);
  for (int i = 0; i < k; i++) {
    int node;
    cin >> node;
    event.push_back(node);
  }
  for (int i = 1; i < event.size(); i++) {
    int prv = event[i - 1];
    int cur = event[i];
    int lca = getLca(prv, cur);
    if (lca == prv) {
      dp[prv][0]--;
      dp[cur][0]++;
    } else {
      dp[prv][1]++;
      dp[cur][0]++;
      dp[lca][1]--;
      dp[lca][0]--;
    }
  }
  go(1, -1);
  long long ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    if (type[i] == 0) continue;
    if (parent[e[i].first][0] == e[i].second) {
      int g = dp[e[i].first][0];
      if (g == 0) continue;
      g--;
      ans = ans + (pw[g]);
      ans %= mod;
    } else {
      int g = dp[e[i].second][1];
      if (g == 0) continue;
      g--;
      ans = ans + (pw[g]);
      ans %= mod;
    }
  }
  cout << ans;
  return 0;
}
