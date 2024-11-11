#include <bits/stdc++.h>
const int N = 4e5 + 5, M = 5e6 + 5, INF = 1e9;
using namespace std;
int n, m, s, t, tot;
int d[N], now[N], dep[N], used[N], f[N][20], id[N][20];
vector<int> ans;
struct Graph {
  int num;
  int nt[M], to[M], val[M], head[N];
  Graph() { num = 1; }
  void Add(int x, int y, int z) {
    ++num;
    nt[num] = head[x];
    head[x] = num;
    to[num] = y;
    val[num] = z;
    ++num;
    nt[num] = head[y];
    head[y] = num;
    to[num] = x;
    val[num] = z;
  }
} G1, G2;
template <typename tp>
inline void r(tp &n) {
  n = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) n = n * 10 + c - 48, c = getchar();
}
bool BFS() {
  memset(d, 0, sizeof d);
  queue<int> q;
  q.push(s);
  now[s] = G2.head[s];
  d[s] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = G2.head[x], y = G2.to[i]; i; i = G2.nt[i], y = G2.to[i]) {
      if (!G2.val[i] || d[y]) continue;
      d[y] = d[x] + 1;
      now[y] = G2.head[y];
      if (y == t) return true;
      q.push(y);
    }
  }
  return false;
}
int dinic(int p, int flow) {
  if (p == t) return flow;
  int i, y, res = flow;
  for (i = now[p], y = G2.to[i]; i && res; i = G2.nt[i], y = G2.to[i]) {
    if (d[y] != d[p] + 1 || !G2.val[i]) continue;
    int k = dinic(y, min(res, G2.val[i]));
    if (!k) {
      d[y] = 0;
      continue;
    }
    G2.val[i] -= k;
    G2.val[i ^ 1] += k;
    res -= k;
  }
  now[p] = i;
  return flow - res;
}
void Pre(int p) {
  dep[p] = dep[f[p][0]] + 1;
  for (int i = 1; i <= 19; ++i)
    if (!f[p][i - 1])
      break;
    else {
      f[p][i] = f[f[p][i - 1]][i - 1];
      id[p][i] = ++tot;
      G2.Add(tot, id[p][i - 1], INF);
      G2.Add(tot, id[f[p][i - 1]][i - 1], INF);
    }
  for (int i = G1.head[p], y = G1.to[i]; i; i = G1.nt[i], y = G1.to[i])
    if (y != f[p][0])
      id[y][0] = m + i / 2, f[y][0] = p, G2.Add(id[y][0], t, 1), Pre(y);
}
void DFS(int p) {
  used[p] = 1;
  for (int i = G2.head[p]; i; i = G2.nt[i])
    if (!used[G2.to[i]] && G2.val[i]) DFS(G2.to[i]);
}
int LCA(int x, int y) {
  if (dep[x] > dep[y]) swap(x, y);
  for (int i = 19; i >= 0; --i)
    if (dep[f[x][i]] >= dep[y]) x = f[x][i];
  if (x == y) return x;
  for (int i = 19; i >= 0; --i)
    if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  return f[x][0];
}
void Link(int x, int y, int node) {
  for (int i = 19; i >= 0; --i)
    if (dep[f[x][i]] >= dep[y]) G2.Add(node, id[x][i], 1), x = f[x][i];
}
void Print() {
  printf("%d ", ans.size());
  for (int i = 0; i != ans.size(); ++i) printf("%d ", ans[i]);
  putchar(10);
}
int main() {
  r(n), r(m);
  for (int i = 1, x, y; i != n; ++i) r(x), r(y), G1.Add(x, y, 0);
  tot = m + n;
  s = ++tot;
  t = ++tot;
  Pre(1);
  for (int i = 1, x, y; i <= m; ++i) {
    r(x), r(y);
    G2.Add(s, i, 1);
    int lca = LCA(x, y);
    if (lca != x) Link(x, lca, i);
    if (lca != y) Link(y, lca, i);
  }
  int Maxflow = 0, flow;
  while (BFS())
    while (flow = dinic(s, INF)) Maxflow += flow;
  DFS(s);
  printf("%d\n", Maxflow);
  for (int i = 1; i <= m; ++i)
    if (!used[i]) ans.push_back(i);
  Print();
  ans.clear();
  for (int i = 2; i <= n; ++i)
    if (used[id[i][0]]) ans.push_back(id[i][0] - m);
  Print();
  return 0;
}
