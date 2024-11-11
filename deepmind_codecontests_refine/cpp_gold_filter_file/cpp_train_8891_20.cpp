#include <bits/stdc++.h>
using namespace std;
int n, m, opt, x, y, Dfs_Clock, Num_Edge, a[200010], head[200010], dep[200010],
    in[200010], out[200010];
struct Edge {
  int v, nxt;
} E[400010];
void Add_Edge(int u, int v) {
  E[++Num_Edge].v = v;
  E[Num_Edge].nxt = head[u];
  head[u] = Num_Edge;
}
struct BIT {
  int n, T[200010];
  void Add(int x, int y) {
    for (int i = x; i <= n; i += (i & (-i))) T[i] += y;
  }
  int Qry(int x) {
    int sum = 0;
    for (int i = x; i; i -= (i & (-i))) sum += T[i];
    return sum;
  }
} T;
void DFS(int u, int fa) {
  dep[u] = dep[fa] + 1;
  in[u] = ++Dfs_Clock;
  for (int i = head[u]; i; i = E[i].nxt)
    if (E[i].v != fa) DFS(E[i].v, u);
  out[u] = Dfs_Clock;
}
int main() {
  scanf("%d%d", &n, &m);
  T.n = n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    Add_Edge(x, y);
    Add_Edge(y, x);
  }
  DFS(1, 0);
  while (m--) {
    scanf("%d", &opt);
    if (opt == 1) {
      scanf("%d%d", &x, &y);
      if (dep[x] & 1) {
        T.Add(in[x], y);
        T.Add(out[x] + 1, -y);
      } else {
        T.Add(in[x], -y);
        T.Add(out[x] + 1, y);
      }
    } else {
      scanf("%d", &x);
      int tmp = T.Qry(in[x]);
      if (dep[x] & 1)
        printf("%d\n", a[x] + tmp);
      else
        printf("%d\n", a[x] - tmp);
    }
  }
  return 0;
}
