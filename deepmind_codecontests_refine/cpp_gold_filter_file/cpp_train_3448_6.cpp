#include <bits/stdc++.h>
using namespace std;
template <class T, class T1>
inline bool chkmax(T &x, const T1 &y) {
  return x < y ? x = y, true : false;
}
template <class T, class T1>
inline bool chkmin(T &x, const T1 &y) {
  return x > y ? x = y, true : false;
}
const int MAXN = (int)3e5 + 2;
struct Edge {
  int node;
  long long cost;
  Edge(int node, long long cost) {
    this->node = node;
    this->cost = cost;
  }
};
int n;
int values[MAXN];
vector<Edge> g[MAXN];
void read() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> values[i];
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    long long cost;
    cin >> u >> v >> cost;
    g[u].push_back(Edge(v, cost));
    g[v].push_back(Edge(u, cost));
  }
}
long long ans = 0;
long long dp[MAXN];
void dfs(int node, int parent) {
  dp[node] = values[node];
  chkmax(ans, dp[node]);
  for (Edge adj : g[node]) {
    if (adj.node == parent) continue;
    dfs(adj.node, node);
    chkmax(ans, dp[node] + dp[adj.node] - adj.cost);
    chkmax(dp[node], values[node] - adj.cost + dp[adj.node]);
  }
}
void solve() {
  memset(dp, 0, sizeof(dp));
  dfs(1, 0);
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  read();
  solve();
  return EXIT_SUCCESS;
}
