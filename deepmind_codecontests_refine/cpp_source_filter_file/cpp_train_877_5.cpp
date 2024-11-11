#include <bits/stdc++.h>
using namespace std;
int f[300010], g[300010];
struct edge {
  int u, v, w;
  bool operator<(const edge& obj) const { return w < obj.w; }
} e[300010];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
  sort(e, e + m);
  int t = 0, ans = 0;
  for (int i = 0; i < m; i++) {
    f[i] = g[e[i].u] + 1;
    if (e[i].w != e[i + 1].w) {
      for (int j = t; j <= i; j++) g[e[j].v] = max(g[e[j].v], f[i]);
      t = i + 1;
    }
    ans = max(ans, f[i]);
  }
  printf("%d\n", ans);
  return 0;
}
