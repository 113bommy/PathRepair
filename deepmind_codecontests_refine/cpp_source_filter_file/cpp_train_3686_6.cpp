#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, t, u, l;
vector<vector<int> > g;
vector<int> col;
deque<int> q;
vector<int> tin, tout;
int timer;
vector<vector<int> > up;
void bfs() {
  while (!q.empty()) {
    int v = q.front();
    q.pop_back();
    for (int(i) = (0); (i) < int(g[v].size()); ++(i)) {
      int to = g[v][i];
      if (col[to] > col[v] + 1) {
        col[to] = col[v] + 1;
        q.push_back(to);
      }
    }
  }
}
void dfs(int v, int p = 0) {
  tin[v] = ++timer;
  up[v][0] = p;
  for (int i = 1; i <= l; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
  for (size_t i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (to != p) dfs(to, v);
  }
  tout[v] = ++timer;
}
bool upper(int a, int b) { return tin[a] <= tin[b] && tout[a] >= tout[b]; }
int lca(int a, int b) {
  if (upper(a, b)) return a;
  if (upper(b, a)) return b;
  for (int i = l; i >= 0; --i)
    if (!upper(up[a][i], b)) a = up[a][i];
  return up[a][0];
}
int DIST(int a, int b) {
  int lca = -1;
  if (upper(a, b)) lca = a;
  if (upper(b, a)) lca = b;
  int dist = 0;
  for (int i = l; i >= 0; --i) {
    if (!upper(up[a][i], b)) {
      dist += (1 << i);
      a = up[a][i];
    }
  }
  if (lca == -1) lca = up[a][0];
  for (int i = l; i >= 0; --i) {
    if (!upper(up[b][i], a)) {
      dist += (1 << i);
      b = up[b][i];
    }
  }
  return dist + (a != lca) + (b != lca);
}
int get(int u) {
  int res = col[u];
  for (int(i) = (0); (i) < int(q.size()); ++(i)) res = min(res, DIST(q[i], u));
  return res;
}
int main() {
  scanf("%d %d", &n, &m);
  g.resize(n);
  col.resize(n);
  for (int(i) = (0); (i) < int(n - 1); ++(i)) {
    scanf("%d %d", &a, &b);
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  col.assign(n, 2000000);
  q.push_back(0);
  col[0] = 0;
  tin.resize(n), tout.resize(n), up.resize(n);
  l = 1;
  while ((1 << l) <= n) ++l;
  for (int i = 0; i < n; ++i) up[i].resize(l + 1);
  dfs(0);
  for (int(i) = (0); (i) < int(m); ++(i)) {
    scanf("%d %d", &t, &u);
    --u;
    if (t == 1) {
      col[u] = 0;
      q.push_back(u);
      if (i % 100 == 0) bfs();
    } else {
      printf("%d\n", get(u));
    }
  }
  return 0;
}
