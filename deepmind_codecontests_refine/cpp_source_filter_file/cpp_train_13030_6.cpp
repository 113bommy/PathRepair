#include <bits/stdc++.h>
using namespace std;
int head[2 * 100100], pre[2 * 100100], nxt[2 * 100100], now[2 * 100100], e;
int dfn[100100], low[100100], vis[100100], ch[2 * 100100];
int n, m, idx;
void init() {
  memset(head, -1, sizeof(head));
  memset(vis, 0, sizeof(vis));
  memset(ch, 0, sizeof(ch));
  e = 0;
  idx = 0;
}
void addedge(int u, int v) {
  pre[e] = v, nxt[e] = head[u], now[e] = u, head[u] = e++;
}
int dfs(int u) {
  dfn[u] = low[u] = ++idx;
  vis[u] = 1;
  for (int i = head[u]; i != -1; i = nxt[i]) {
    int v = pre[i];
    if (ch[i ^ 1]) continue;
    ch[i] = 1;
    if (vis[v])
      low[u] = min(low[u], dfn[v]);
    else {
      if (!dfs(v)) return 0;
      low[u] = min(low[u], low[v]);
      if (dfn[v] <= low[v]) return 0;
    }
  }
  return 1;
}
void solve() {
  init();
  for (int i = 0; i < (int)(m); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  if (!dfs(1)) {
    printf("0\n");
  } else {
    for (int i = 0; i < (int)(e); i++) {
      if (ch[i]) {
        printf("%d %d\n", now[i], pre[i]);
      }
    }
  }
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    solve();
  }
  return 0;
}
