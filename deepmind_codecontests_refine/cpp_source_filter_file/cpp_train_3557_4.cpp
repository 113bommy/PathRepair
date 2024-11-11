#include <bits/stdc++.h>
using namespace std;
struct edge {
  int v, w;
  edge(int _v = 0, int _w = 0) {
    v = _v;
    w = _w;
  }
};
struct operation {
  int u, v, c;
  operation(int _u = 0, int _v = 0, int _c = 0) {
    u = _u;
    v = _v;
    c = _c;
  }
};
const int N = 1001;
int n;
vector<edge> adj[N];
vector<operation> ans;
vector<int> leaves[N];
int root, val[N], sum[N];
bool noSolution;
void dfs(int u, int p) {
  for (edge e : adj[u]) {
    int v = e.v;
    int w = e.w;
    if (v != p) {
      val[v] = w;
      dfs(v, u);
      sum[u] += sum[v];
      if (leaves[u].size() < 2) leaves[u].push_back(leaves[v].back());
    }
  }
  val[u] += sum[u];
  if ((int)adj[u].size() == 1 && p != -1) {
    leaves[u].push_back(u);
    sum[u] -= val[u];
    ans.push_back(operation(u, root, -val[u]));
    val[u] = 0;
    return;
  }
  if (val[u] == sum[u] || p == -1) return;
  if ((int)leaves[u].size() < 2) {
    noSolution = 1;
    return;
  }
  sum[u] -= val[u];
  ans.push_back(operation(leaves[u][0], root, -val[u] / 2));
  ans.push_back(operation(leaves[u][1], root, -val[u] / 2));
  ans.push_back(operation(leaves[u][0], leaves[u][1], val[u] / 2));
  val[u] = 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back(edge(v, c));
    adj[v].push_back(edge(u, c));
  }
  root = 1;
  while ((int)adj[root].size() != 1) root++;
  dfs(root, -1);
  if (noSolution) {
    cout << "NO";
  } else {
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (operation op : ans) cout << op.u << ' ' << op.v << ' ' << op.c << '\n';
  }
  return 0;
}
