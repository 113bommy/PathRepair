#include <bits/stdc++.h>
using namespace std;
int x;
void dfsUtil(int node, int count, bool visited[], int& maxCount,
             vector<vector<int> >& adj) {
  visited[node] = true;
  count++;
  for (auto& i : adj[node]) {
    if (!visited[i]) {
      if (count >= maxCount) {
        maxCount = count;
        x = i;
      }
      dfsUtil(i, count, visited, maxCount, adj);
    }
  }
}
void dfs(int node, int n, vector<vector<int> >& adj, int& maxCount) {
  bool visited[n];
  int count = 0;
  for (int i = 0; i < n; ++i) visited[i] = false;
  dfsUtil(node, 1, visited, maxCount, adj);
}
int diameter(vector<vector<int> >& adj, int n) {
  int maxCount = INT_MIN;
  dfs(0, n, adj, maxCount);
  dfs(x, n, adj, maxCount);
  return maxCount;
}
bool vis[100010];
int dist[100010];
void dfs1(int v, int p, vector<vector<int> >& adj) {
  if (vis[v]) return;
  vis[v] = true;
  if (p == -1)
    dist[v] = 0;
  else
    dist[v] = dist[p] + 1;
  for (auto& u : adj[v]) {
    dfs1(u, v, adj);
  }
}
void solve() {
  int n, a, b, da, db;
  cin >> n >> a >> b >> da >> db;
  a--;
  b--;
  vector<vector<int> > adj(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (db <= 2 * da) {
    cout << "Alice" << endl;
    return;
  }
  for (int i = 0; i < n; i++) {
    vis[i] = false;
  }
  dfs1(a, -1, adj);
  if (dist[b] <= da) {
    cout << "Alice" << endl;
    return;
  }
  if (diameter(adj, n) - 1 >= 2 * da + 1) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
