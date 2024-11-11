#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int msz = 1e5 + 1;
struct Edge {
  int v, next;
};
Edge eg[666666];
bool vis[233333];
int tp;
int head[233333];
int fth[233333];
void Add(int u, int v) {
  eg[tp].v = v;
  eg[tp].next = head[u];
  head[u] = tp++;
}
int dfs(int u, int pre) {
  vis[u] = 1;
  int ans = -1;
  int tmp;
  for (int i = head[u]; i != -1; i = eg[i].next) {
    if (eg[i].v == pre || eg[i].v == u) continue;
    if (fth[u] == eg[i].v && fth[eg[i].v] == fth[u]) ans = u;
    if (vis[eg[i].v]) {
      if (fth[eg[i].v] == u)
        ans = eg[i].v;
      else
        ans = u;
    } else {
      tmp = dfs(eg[i].v, u);
      if (tmp != -1) ans = tmp;
    }
  }
  if (fth[u] == u) ans = u;
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  memset(head, -1, sizeof(head));
  tp = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &fth[i]);
    Add(i, fth[i]);
    Add(fth[i], i);
  }
  int ans = 0;
  int root = -1;
  int to = -1;
  int tmp[233333];
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    tmp[ans++] = dfs(i, i);
    if (to == -1 && tmp[ans - 1] == fth[tmp[ans - 1]]) {
      ans--;
      to = tmp[ans];
    }
  }
  for (int i = 0; i < ans; ++i) {
    if (to == -1)
      fth[tmp[i]] = tmp[i];
    else
      fth[tmp[i]] = to;
  }
  printf("%d\n", ans);
  for (int i = 1; i <= n; ++i) {
    if (i != 1) putchar(' ');
    printf("%d", fth[i]);
  }
  return 0;
}
