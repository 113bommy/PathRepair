#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1040, Maxm = 5050;
int to_1[Maxn], to_n[Maxn], n, m, u[Maxn], v[Maxn];
void dfs1(int now) {
  to_1[now] = 1;
  for (int i = 1; i <= m; ++i)
    if (u[i] == now && !to_1[v[i]]) dfs1(v[i]);
}
void dfs2(int now) {
  to_n[now] = 1;
  for (int i = 1; i <= m; ++i)
    if (v[i] == now && !to_n[u[i]]) dfs2(u[i]);
}
int dis[Maxn], in[Maxn], vis[Maxn];
int nxt[Maxm << 1], to[Maxm << 1], w[Maxm << 1], head[Maxn], cnt;
void AddEdge(int u, int v, int x) {
  nxt[++cnt] = head[u], head[u] = cnt, to[cnt] = v, w[cnt] = x;
}
bool spfa(int s) {
  queue<int> q;
  q.push(s);
  memset(dis, 0x3f, sizeof dis);
  dis[s] = 0, vis[1] = 1, in[1] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i; i = nxt[i])
      if (dis[to[i]] > dis[u] + w[i]) {
        dis[to[i]] = dis[u] + w[i];
        if (!in[to[i]]) q.push(to[i]), vis[to[i]]++;
        if (vis[to[i]] > n) return 0;
      }
    in[u] = 0;
  }
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) scanf("%d%d", &u[i], &v[i]);
  dfs1(1), dfs2(n);
  for (int i = 1; i <= m; ++i)
    if (to_1[u[i]] && to_n[v[i]]) {
      AddEdge(u[i], v[i], 2);
      AddEdge(v[i], u[i], -1);
    }
  if (!spfa(1))
    puts("No");
  else {
    puts("Yes");
    for (int i = 1; i <= m; ++i)
      if (dis[v[i]] - dis[u[i]] == 2)
        puts("2");
      else
        puts("1");
  }
  return 0;
}
