#include <bits/stdc++.h>
using namespace std;
int n, m, q, v, mx, dia[300100], p[300100], vis[300100];
vector<int> adj[300100];
void dfs1(int node, int d, int par) {
  p[node] = par;
  if (d >= mx) {
    mx = d;
    v = node;
  }
  for (int i = 0; i < adj[node].size(); i++) {
    int nxt = adj[node][i];
    if (!vis[nxt]) {
      vis[nxt] = 1;
      dfs1(nxt, d + 1, node);
    }
  }
}
int dfs2(int node) {
  int temp = 0;
  for (int i = 0; i < adj[node].size(); i++) {
    int nxt = adj[node][i];
    if (vis[nxt] == 1) {
      vis[nxt] = 2;
      temp = max(temp, dfs2(nxt));
    }
  }
  return 1 + temp;
}
int find_parent(int node) {
  return (p[node] == node) ? node : (p[node] = find_parent(p[node]));
}
int issame(int x, int y) { return find_parent(x) == find_parent(y); }
void merg(int x, int y) {
  if (!issame(x, y)) {
    int px = find_parent(x), py = find_parent(y);
    int dx = dia[px], dy = dia[py];
    p[py] = px;
    dia[px] = max(max(dx, dy), dx / 2 + dx % 2 + dy / 2 + dy % 2 + 1);
  }
}
int main() {
  int x, y, is;
  cin >> n >> m >> q;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      vis[i] = 1;
      mx = 0;
      dfs1(i, 0, i);
      vis[i] = 2;
      dia[i] = dfs2(v) - 1;
    }
  }
  for (int i = 1; i <= q; i++) {
    scanf("%d", &is);
    if (is == 1) {
      scanf("%d", &x);
      printf("%d\n", dia[find_parent(x)]);
    } else {
      scanf("%d%d", &x, &y);
      merg(x, y);
    }
  }
}
