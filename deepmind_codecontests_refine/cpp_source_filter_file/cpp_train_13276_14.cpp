#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
bitset<int(1e5)> visited;
int parent[int(1e5)];
long long min(long long a, long long b) { return a < b ? a : b; }
void dfs(int u) {
  visited[u] = true;
  for (int v : g[u])
    if (!visited[v]) dfs(v);
}
int find(int u) {
  if (parent[u] == u) return u;
  return parent[u] = find(parent[u]);
}
void solve(int n, int m) {
  for (int i = 0; i < n; i++) parent[i] = i;
  int cnt = n;
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    u = find(u), v = find(v);
    if (u == v)
      visited[u] = true;
    else {
      parent[v] = u;
      cnt--;
      visited[v] = visited[u] || visited[v];
    }
  }
  for (int i = 0; i < n; i++)
    if (parent[i] == i && visited[i]) cnt--;
  cout << cnt << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  solve(n, m);
}
