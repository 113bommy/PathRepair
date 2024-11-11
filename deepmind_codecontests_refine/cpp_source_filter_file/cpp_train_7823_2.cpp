#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
struct Edge {
  int to, nxt;
} edge[maxn << 1];
int n;
int head[maxn], cnt;
long long ans[maxn];
void addedge(int u, int v) {
  edge[++cnt].to = v;
  edge[cnt].nxt = head[u];
  head[u] = cnt;
}
int siz[maxn], pos;
void dfs1(int u, int fa) {
  siz[u] = 1;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa) continue;
    dfs1(v, u);
    siz[u] += siz[v];
  }
}
void dfs2(int u, int fa) {
  if (ans[u] > ans[pos]) pos = u;
  for (int i = head[u]; i; i = edge[i].nxt) {
    int v = edge[i].to;
    if (v == fa) continue;
    ans[v] = ans[u] + (siz[u] - siz[v]) * siz[v];
    dfs2(v, u);
  }
}
int main() {
  scanf("%d", &n);
  for (int u, v, i = 1; i < n; i++) {
    scanf("%d%d", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  dfs1(1, 1);
  ans[1] = 1LL * n * (n - 1) >> 1;
  dfs2(1, 1);
  dfs1(pos, pos);
  ans[pos] = 1LL * n * (n - 1) >> 1;
  dfs2(pos, pos);
  printf("%I64d", ans[pos]);
  return 0;
}
