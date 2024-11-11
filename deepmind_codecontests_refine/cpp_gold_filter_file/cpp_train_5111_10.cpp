#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
struct Edge {
  int to, nex;
} edge[N << 1];
int idx;
int h[N];
void add_edge(int u, int v) {
  edge[++idx] = {v, h[u]};
  h[u] = idx;
}
int siz[N], son[N], dep[N];
int fa[N], cnt[N], ans[N];
int maxv, id;
int n;
void dfs1(int p, int father) {
  fa[p] = father;
  dep[p] = dep[father] + 1;
  siz[p] = 1;
  int max_son = 0;
  for (int i = h[p]; ~i; i = edge[i].nex) {
    int to = edge[i].to;
    if (to == father) continue;
    dfs1(to, p);
    if (siz[to] > max_son) max_son = siz[to], son[p] = to;
    siz[p] += siz[to];
  }
}
void calc(int p, int flag, int val) {
  cnt[dep[p]] += val;
  if (cnt[dep[p]] > maxv)
    maxv = cnt[dep[p]], id = dep[p];
  else if (cnt[dep[p]] == maxv && dep[p] < id)
    id = dep[p];
  for (int i = h[p]; ~i; i = edge[i].nex) {
    int to = edge[i].to;
    if (to == fa[p] || to == flag) continue;
    calc(to, flag, val);
  }
}
void dfs(int p, int keep) {
  for (int i = h[p]; ~i; i = edge[i].nex) {
    int to = edge[i].to;
    if (to == fa[p] || to == son[p]) continue;
    dfs(to, 0);
  }
  if (son[p]) dfs(son[p], 1);
  calc(p, son[p], 1);
  ans[p] = id - dep[p];
  if (!keep) {
    calc(p, 0, -1);
    maxv = 0;
  }
}
int main() {
  memset(h, -1, sizeof h);
  scanf("%d", &n);
  for (int i = 1, a, b; i <= n - 1; i++) {
    scanf("%d%d", &a, &b);
    add_edge(a, b);
    add_edge(b, a);
  }
  dfs1(1, 0);
  dfs(1, 1);
  for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
  return 0;
}
