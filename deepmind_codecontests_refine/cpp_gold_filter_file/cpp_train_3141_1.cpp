#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100005;
int n, st, ed, deg[Maxn];
int pre[Maxn], nxt[Maxn];
int dist[Maxn], flag[Maxn];
int q[Maxn];
vector<int> g[Maxn];
inline int bfs(int start) {
  memset(dist, 63, sizeof(dist));
  memset(pre, 0, sizeof(pre));
  memset(nxt, 0, sizeof(nxt));
  int qh = 0, qe = 0, u, pos = start;
  dist[q[qe++] = start] = 1;
  while (qh < qe)
    for (auto &v : g[u = q[qh++]])
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1, q[qe++] = v;
        pre[v] = u, nxt[u] = v;
        if (dist[v] > dist[pos]) pos = v;
      }
  return pos;
}
inline bool dfs(int u, int par, int dep) {
  if (!~deg[dep])
    deg[dep] = g[u].size() + 1;
  else if (deg[dep] != g[u].size() + 1)
    return false;
  for (auto &v : g[u]) {
    if (v == par) continue;
    if (!dfs(v, u, dep + 1)) return false;
  }
  return true;
}
inline bool check(int root) {
  memset(deg, -1, sizeof(deg));
  return dfs(root, -1, 0);
}
inline int bfs2(int start) {
  memset(dist, 63, sizeof(dist));
  int qh = 0, qe = 0, u, pos = start;
  dist[q[qe++] = start] = 1;
  while (qh < qe)
    for (auto &v : g[u = q[qh++]]) {
      if (dist[v] != 0x3f3f3f3f || flag[v] || (int)g[v].size() > 2) continue;
      if (pos == start && (int)g[v].size() == 1) pos = v;
      dist[q[qe++] = v] = dist[u] + 1;
    }
  return pos;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ed = bfs(st = bfs(1));
  if (check(st)) return printf("%d\n", st) & 0;
  if (check(ed)) return printf("%d\n", ed) & 0;
  if (~dist[ed] & 1) return puts("-1") & 0;
  for (int i = ed; i != st; i = pre[i]) flag[i] = 1;
  flag[st] = 1;
  int dis = dist[ed] - 1 >> 1, mid = ed;
  for (int i = 0; i < dis; ++i) mid = pre[mid];
  if (check(mid)) return printf("%d\n", mid) & 0;
  int pos = bfs2(mid);
  if (check(pos)) return printf("%d\n", pos) & 0;
  return puts("-1") & 0;
}
