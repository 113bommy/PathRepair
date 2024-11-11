#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, x, y, con[N], tot[N];
int head[N], nxt[N * 2], to[N * 2], cnt;
void addedge(int u, int v) {
  to[cnt] = v;
  nxt[cnt] = head[u];
  head[u] = cnt++;
}
int dfs(int u) {
  if (tot[u]) return tot[u];
  for (int i = head[u]; ~i; i = nxt[i])
    if (to[i] < u) {
      tot[u] = max(tot[u], 1 + dfs(to[i]));
    }
  return tot[u] ? tot[u] : tot[u] = 1;
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    memset(head, -1, sizeof(head));
    memset(con, 0, sizeof(con));
    memset(tot, 0, sizeof(tot));
    cnt = 0;
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &x, &y);
      if (x > y) swap(x, y);
      con[x]++, con[y]++;
      addedge(x, y);
    }
    for (int u = 1; u <= n; u++) {
      if (!tot[u]) tot[u]++;
      for (int i = head[u]; ~i; i = nxt[i])
        if (u < to[i]) tot[to[i]] = max(tot[to[i]], tot[u] + 1);
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) res = max(res, (long long)con[i] * tot[i]);
    printf("%d\n", res);
  }
  return 0;
}
