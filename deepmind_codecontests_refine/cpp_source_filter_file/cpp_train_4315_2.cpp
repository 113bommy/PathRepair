#include <bits/stdc++.h>
const int maxn = 1e6 + 9;
int Read() {
  int x(0), f(1);
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3ll) + (x << 1ll) + c - '0';
    c = getchar();
  }
  return x * f;
}
struct node {
  int to, nxt, id;
} dis[maxn];
struct Edge {
  int u, v, id;
};
int n, num, tot;
int head[maxn], ans[maxn], l[maxn], r[maxn], a[maxn], deg[maxn], vis[maxn],
    col[2][maxn], mark[maxn];
std::vector<Edge> edge;
std::vector<int> V[maxn];
void Add(int u, int v, int id0) {
  dis[++num] = (node){v, head[u], id0};
  head[u] = num;
}
void Dfs(int u) {
  mark[u] = 1;
  for (int i = head[u]; i != -1; i = dis[i].nxt)
    if (!vis[i]) {
      int v(dis[i].to);
      ans[dis[i].id] = (u < v);
      vis[i] = vis[i ^ 1] = 1;
      Dfs(v);
    }
}
int main() {
  n = Read();
  for (int i = 1; i <= n; ++i) {
    l[i] = Read();
    r[i] = Read() + 1;
    a[++tot] = l[i];
    a[++tot] = r[i] + 1;
  }
  std::sort(a + 1, a + 1 + tot);
  tot = std::unique(a + 1, a + 1 + tot) - a - 1;
  num = -1;
  for (int i = 1; i <= tot; ++i) head[i] = -1;
  for (int i = 1; i <= n; ++i) {
    l[i] = std::lower_bound(a + 1, a + 1 + tot, l[i]) - a;
    r[i] = std::lower_bound(a + 1, a + 1 + tot, r[i]) - a;
    deg[l[i]]++;
    deg[r[i]]++;
    Add(l[i], r[i], i);
    Add(r[i], l[i], i);
  }
  int lst(0);
  for (int i = 1; i <= tot; ++i)
    if (deg[i] & 1) {
      if (!lst)
        lst = i;
      else {
        Add(lst, i, 0);
        Add(i, lst, 0);
        lst = 0;
      }
    }
  for (int i = 1; i <= tot; ++i)
    if (!mark[i]) Dfs(i);
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  puts("");
  return 0;
}
