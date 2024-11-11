#include <bits/stdc++.h>
using namespace std;
const int max_n = 1e5 + 5;
int n, head[max_n], nxt[max_n], to[max_n], dep[max_n];
void dfs(int p, int f) {
  dep[p] = dep[f] + 1;
  for (int i = head[p]; i; i = nxt[i]) {
    if (to[i] == f) continue;
    dfs(to[i], p);
  }
}
signed main() {
  scanf("%d", &n);
  for (int i = 1, tot = 0; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    to[++tot] = v, nxt[tot] = head[u], head[u] = tot;
    to[++tot] = u, nxt[tot] = head[v], head[v] = tot;
  }
  dfs(1, 0);
  double ans = 0;
  for (int i = 1; i <= n; i++) ans += 1.0 / dep[i];
  printf("%lf\n", ans);
  return 0;
}
