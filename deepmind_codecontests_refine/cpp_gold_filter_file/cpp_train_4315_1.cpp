#include <bits/stdc++.h>
using namespace std;
int n, tot, sum[200010];
int b[200010], l[200010], r[200010];
struct Node {
  int to, nxt, id;
} Edge[200010 << 1];
int Head[200010], cnt_Edge = 1;
void Add_Edge(int u, int v, int id) {
  Edge[++cnt_Edge] = (Node){v, Head[u], id};
  Head[u] = cnt_Edge;
}
int ans[200010], vis[200010 << 1], fl[200010];
void dfs(int u) {
  fl[u] = 1;
  for (int i = Head[u]; i; i = Edge[i].nxt) {
    int v = Edge[i].to, w = Edge[i].id;
    if (vis[i]) continue;
    if (u < v)
      ans[w] = 0;
    else
      ans[w] = 1;
    vis[i] = vis[i ^ 1] = 1;
    dfs(v);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &l[i], &r[i]);
    r[i]++;
    b[++tot] = l[i];
    b[++tot] = r[i];
  }
  sort(b + 1, b + tot + 1);
  tot = unique(b + 1, b + tot + 1) - b - 1;
  for (int i = 1; i <= n; i++) {
    l[i] = lower_bound(b + 1, b + tot + 1, l[i]) - b;
    r[i] = lower_bound(b + 1, b + tot + 1, r[i]) - b;
    sum[l[i]]++;
    sum[r[i]]--;
    Add_Edge(l[i], r[i], i);
    Add_Edge(r[i], l[i], i);
  }
  for (int i = 1; i <= tot; i++) sum[i] += sum[i - 1];
  for (int i = 1; i <= tot; i++)
    if (sum[i] & 1) Add_Edge(i, i + 1, n + 1), Add_Edge(i + 1, i, n + 1);
  for (int i = 1; i <= tot; i++)
    if (!fl[i]) dfs(i);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
