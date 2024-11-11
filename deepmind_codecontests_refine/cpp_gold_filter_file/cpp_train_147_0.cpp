#include <bits/stdc++.h>
using namespace std;
const int maxn = 300010;
int n, m, q, Maxx[maxn], Maxy[maxn];
int cnt[maxn], parent[maxn];
vector<int> G[maxn];
int find(int x) {
  if (parent[x] >= 0) {
    return parent[x] = find(parent[x]);
  }
  return x;
}
void dfs(int u, int fa, int p) {
  int v;
  for (int i = 0; i < G[u].size(); i++) {
    v = G[u][i];
    if (v != fa) {
      dfs(v, u, p);
      if (Maxy[v] + 1 > Maxy[u]) {
        Maxx[u] = Maxy[u];
        Maxy[u] = Maxy[v] + 1;
      } else if (Maxy[v] + 1 > Maxx[u]) {
        Maxx[u] = Maxy[v] + 1;
      }
    }
  }
  cnt[p] = max(cnt[p], Maxy[u] + Maxx[u]);
}
int main() {
  while (scanf("%d%d%d", &n, &m, &q) != EOF) {
    int i, j, type, u, v;
    for (i = 1; i <= n; i++) {
      G[i].clear();
      parent[i] = -1;
      Maxx[0] = Maxy[i] = 0;
      cnt[i] = 0;
    }
    for (i = 0; i < m; i++) {
      scanf("%d%d", &u, &v);
      G[u].push_back(v);
      G[v].push_back(u);
      u = find(u);
      v = find(v);
      if (u != v) {
        parent[u] = v;
      }
    }
    for (i = 1; i <= n; i++) {
      if (parent[i] == -1) {
        dfs(i, -1, i);
      }
    }
    for (i = 0; i < q; i++) {
      scanf("%d", &type);
      if (type == 2) {
        scanf("%d%d", &u, &v);
        u = find(u);
        v = find(v);
        if (u != v) {
          parent[u] = v;
          cnt[v] = max((cnt[v] + 1) / 2 + (cnt[u] + 1) / 2 + 1, cnt[v]);
          cnt[v] = max(cnt[u], cnt[v]);
        }
      } else {
        scanf("%d", &u);
        u = find(u);
        printf("%d\n", cnt[u]);
      }
    }
  }
  return 0;
}
