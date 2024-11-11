#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int u, v, Next;
} G[1000010];
int head[1000010], tot;
inline void add(int u, int v) {
  G[++tot] = (Edge){u, v, head[u]};
  head[u] = tot;
}
int vis[1000010], wt[1000010];
int ans[1000010], t;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  memset(head, -1, sizeof(head));
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v);
  }
  for (int i = 1; i <= n; ++i) {
    if (vis[i] == 0) {
      vis[i] = -1;
      for (int j = head[i]; j != -1; j = G[j].Next) {
        int v = G[j].v;
        if (vis[v] == 0) vis[v] = 1;
      }
    }
  }
  for (int i = n; i >= 1; --i) {
    if (vis[i] != -1 || wt[i]) continue;
    ans[++t] = i;
    for (int j = head[i]; j != -1; j = G[j].Next) {
      int v = G[j].v;
      wt[v] = 1;
    }
  }
  printf("%d\n", t);
  for (int i = 1; i <= t; ++i) {
    printf("%d ", ans[i]);
  }
}
