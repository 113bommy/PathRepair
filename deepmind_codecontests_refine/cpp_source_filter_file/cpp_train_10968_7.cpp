#include <bits/stdc++.h>
const int N = 1000 + 9;
int dis[N], son[N], ec, n, times[N], U[N * 10], V[N * 10], m;
bool inq[N], vis[N], vis1[N];
struct Edge {
  int lnk, nxt, w;
} es[N * 10];
std::queue<int> q;
inline void addedge(const int x, const int y, const int z) {
  es[++ec].nxt = son[x];
  son[x] = ec;
  es[ec].lnk = y;
  es[ec].w = z;
}
bool spfa() {
  memset(dis, 0x3f, sizeof dis);
  dis[1] = 0;
  q.push(1);
  inq[1] = true;
  for (; !q.empty();) {
    const int u = q.front();
    q.pop();
    inq[u] = false;
    for (int i = son[u]; i; i = es[i].nxt) {
      const int v = es[i].lnk;
      if (!vis1[v] || !vis[v]) continue;
      if (dis[v] > dis[u] + es[i].w) {
        dis[v] = dis[u] + es[i].w;
        if (inq[v]) continue;
        if (++times[v] == n) return false;
        inq[v] = true;
        q.push(v);
      }
    }
  }
  return true;
}
void dfs(int u) {
  if (vis[u]) return;
  vis[u] = true;
  for (int i = son[u]; i; i = es[i].nxt)
    if (es[i].w == -1) dfs(es[i].lnk);
}
void dfs1(int u) {
  if (vis1[u]) return;
  vis1[u] = true;
  for (int i = son[u]; i; i = es[i].nxt)
    if (es[i].w == 2) dfs(es[i].lnk);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", U + i, V + i);
    addedge(U[i], V[i], 2);
    addedge(V[i], U[i], -1);
  }
  dfs(n);
  dfs1(1);
  if (!spfa())
    puts("No");
  else {
    puts("Yes");
    for (int i = 1; i <= m; ++i) {
      if (!vis[V[i]] || !vis1[U[i]])
        puts("1");
      else
        printf("%d\n", dis[V[i]] - dis[U[i]]);
    }
  }
}
