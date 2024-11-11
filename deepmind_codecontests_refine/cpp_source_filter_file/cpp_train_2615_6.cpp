#include <bits/stdc++.h>
using namespace std;
const int N = 6e2 + 10;
const int M = 1e9 + 7;
const int E = 10000;
const int INF = 1e9;
struct DINIC {
  int vet[E], len[E], nxt[E], head[E], cao[E];
  int d[N], vd[N], mark[N];
  int num, S, T;
  void init(int n) {
    num = -1;
    memset(head, -1, sizeof head);
    S = n + 1;
    T = n + 2;
  }
  void add(int u, int v, int L) {
    num++;
    vet[num] = v;
    len[num] = cao[num] = L;
    nxt[num] = head[u];
    head[u] = num;
    num++;
    vet[num] = u;
    len[num] = cao[num] = 0;
    nxt[num] = head[v];
    head[v] = num;
  }
  queue<int> q;
  bool BFS() {
    memset(d, -1, sizeof d);
    int u;
    d[S] = 0;
    q.push(S);
    while (!q.empty()) {
      u = q.front();
      q.pop();
      for (int e = head[u]; e != -1; e = nxt[e])
        if (d[vet[e]] == -1 && len[e]) {
          q.push(vet[e]);
          d[vet[e]] = d[u] + 1;
        }
    }
    return d[T] >= 0;
  }
  int dfs(int u, int flow) {
    mark[u] = 1;
    if (u == T) return flow;
    for (int e = head[u]; e != -1; e = nxt[e])
      if (d[vet[e]] == d[u] + 1 && len[e] && !mark[vet[e]]) {
        int tmp = dfs(vet[e], min(flow, len[e]));
        if (tmp) {
          len[e] -= tmp;
          len[e ^ 1] += tmp;
          return tmp;
        }
      }
    return 0;
  }
  int solve() {
    int ans = 0;
    while (BFS()) {
      memset(mark, 0, sizeof mark);
      int flow = dfs(S, INF);
      if (!flow) break;
      ans += flow;
    }
    return ans;
  }
} dinic;
struct Edge {
  int u;
  int v;
  Edge() {}
  Edge(int u, int v) : u(u), v(v) {}
} edges[666];
int vis[666], ds[666], res[666];
int main() {
  int Case;
  scanf("%d", &Case);
  while (Case--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) ds[i] = 0;
    for (int i = 1; i <= m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      edges[i] = Edge(u, v);
      ds[u]++;
      ds[v]++;
    }
    dinic.init(n + m);
    for (int i = 1; i <= m; i++) {
      dinic.add(i, m + edges[i].u, 1);
      dinic.add(i, m + edges[i].v, 1);
    }
    for (int i = 1; i <= m; i++) dinic.add(dinic.S, i, 1);
    int totflow = 0;
    for (int i = 1; i <= n; i++)
      if (ds[i] > k) {
        dinic.add(i + m, dinic.T, 2 * (ds[i] - k));
        totflow += 2 * (ds[i] - k);
      }
    int ans = dinic.solve();
    if (ans != totflow) {
      for (int i = 1; i < m; i++) printf("0 ");
      printf("0\n");
      continue;
    }
    for (int i = 1; i <= n; i++) vis[i] = 0;
    for (int i = 1; i <= m; i++) res[i] = 0;
    int col = 0;
    for (int i = 0; i <= dinic.num && i < 4 * m; i += 2)
      if (dinic.len[i] == 0) {
        int u = dinic.vet[i] - m;
        if (vis[u]) {
          col++;
          res[(vis[u] - 1) / 4 + 1] = col;
          res[i / 4 + 1] = col;
          vis[u] = 0;
        } else {
          vis[u] = i + 1;
        }
      }
    for (int i = 1; i <= m; i++)
      if (res[i] == 0) {
        col++;
        res[i] = col;
      }
    for (int i = 1; i < m; i++) printf("%d ", res[i]);
    printf("%d\n", res[m]);
  }
  return 0;
}
