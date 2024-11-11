#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int BLOCK = 320;
vector<int> adj[N], red;
bool R[N];
int n, m, L, BFSTime;
int p[N][18], List[N], Vis[N], h[N], d[N];
void BFS() {
  ++BFSTime;
  queue<int> q;
  for (int u : red) {
    q.push(u);
    d[u] = 0;
    Vis[u] = BFSTime;
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (Vis[v] == BFSTime) continue;
      d[v] = d[u] + 1;
      q.push(v);
      Vis[u] = BFSTime;
    }
  }
}
void DFS(int u, int pr) {
  for (int v : adj[u]) {
    if (v == pr) continue;
    p[v][0] = u;
    h[v] = h[u] + 1;
    DFS(v, u);
  }
}
int LCA(int x, int y) {
  if (h[x] < h[y]) swap(x, y);
  int tmp = h[x] - h[y];
  for (int i = log2(tmp); i >= 0; --i) {
    if (tmp >> i & 1) x = p[x][i];
  }
  if (x == y) return x;
  for (int i = log2(h[x]); i >= 0; --i) {
    if (p[x][i] != p[y][i]) {
      x = p[x][i];
      y = p[y][i];
    }
  }
  return p[x][0];
}
int CalDist(int x, int y) {
  int lca = LCA(x, y);
  return h[x] + h[y] - h[lca] * 2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  DFS(1, 0);
  for (int i = 1; (1 << i) <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      p[j][i] = p[p[j][i - 1]][i - 1];
    }
  }
  List[++L] = 1;
  for (int i = 0; i < m; ++i) {
    int t, u;
    cin >> t >> u;
    if (t == 1) List[++L] = u;
    if (i % BLOCK == 0) {
      while (L) {
        R[List[L]] = true;
        red.push_back(List[L--]);
      }
      BFS();
    }
    if (t == 2) {
      int res = d[u];
      for (int i = 1; i <= L; ++i) {
        res = min(res, CalDist(u, List[i]));
      }
      cout << res << '\n';
    }
  }
  return 0;
}
