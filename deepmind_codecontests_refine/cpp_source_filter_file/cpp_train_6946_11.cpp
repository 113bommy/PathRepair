#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 500;
struct edge {
  edge *nxt;
  int to, id, tp;
} pool[N * 2], *pt[N], *p = pool;
void add(int a, int b, int id) {
  *(++p) = (edge){pt[a], b, id, 1}, pt[a] = p;
  *(++p) = (edge){pt[b], a, id, -1}, pt[b] = p;
}
bool vis[N];
int sum[N], s[N], ans[N];
void dfs(int v) {
  vis[v] = true, sum[v] = s[v];
  for (edge *i = pt[v]; i; i = i->nxt)
    if (!vis[i->to]) {
      dfs(i->to);
      sum[v] += sum[i->to];
      ans[i->id] = i->tp * sum[i->to] * -1;
    }
}
int n, m, x, y;
int main(void) {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &x, &y), add(x, y, i);
  dfs(1);
  if (sum[1] != 0)
    puts("Impossible");
  else {
    puts("Possible");
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  }
  return 0;
}
