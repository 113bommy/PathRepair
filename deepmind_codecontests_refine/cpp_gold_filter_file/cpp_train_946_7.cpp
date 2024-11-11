#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct edge {
  int link, next;
} e[N << 1];
int tot, head[N], n, fa[N];
double ans, sum[N], p[N];
inline void add_edge(int u, int v) {
  e[++tot] = (edge){v, head[u]};
  head[u] = tot;
}
inline void insert(int u, int v) {
  add_edge(u, v);
  add_edge(v, u);
}
inline void init() {
  scanf("%d", &n);
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &p[i]);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u++;
    v++;
    insert(u, v);
  }
}
void dfs(int u, int Fa) {
  ans += p[Fa] * (1 - p[u]);
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].link;
    if (v != Fa) {
      dfs(v, u);
      fa[v] = u;
      sum[u] += (1 - p[v]);
    }
  }
}
int q;
inline void solve() {
  dfs(1, 0);
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    double y;
    int x;
    scanf("%d%lf", &x, &y);
    x++;
    ans -= sum[x] * p[x] + (1 - p[x]) * p[fa[x]];
    sum[fa[x]] -= 1 - p[x];
    p[x] = y;
    ans += sum[x] * p[x] + (1 - p[x]) * p[fa[x]];
    sum[fa[x]] += 1 - p[x];
    printf("%.5lf\n", ans);
  }
}
int main() {
  init();
  solve();
  return 0;
}
