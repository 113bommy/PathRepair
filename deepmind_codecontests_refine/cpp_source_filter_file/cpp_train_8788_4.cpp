#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, k;
int type[10 + 100000], cnt[10 + 500], root[10 + 100000];
int dist[10 + 500][10 + 500];
int getroot(int u) {
  if (u == root[u]) return u;
  return root[u] = getroot(root[u]);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; ++i) {
    int u;
    scanf("%d", &u);
    cnt[i] = cnt[i - 1] + u;
    for (int j = cnt[i - 1] + 1; j <= cnt[i]; ++j) type[j] = i;
  }
  memset(dist, 0x3f, sizeof(dist));
  for (int i = 1; i <= n; ++i) root[i] = i;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    if (!w) {
      root[getroot(u)] = getroot(v);
    }
    u = type[u];
    v = type[v];
    dist[u][v] = dist[v][u] = min(dist[u][v], w);
  }
  for (int i = 1; i <= k; ++i) {
    int st = getroot(cnt[i - 1] + 1);
    for (int j = cnt[i - 1] + 1; j <= cnt[i]; ++j)
      if (st != getroot(j)) {
        puts("No");
        return 0;
      }
    dist[i][i] = 0;
  }
  puts("Yes");
  for (int kk = 1; kk <= k; ++kk)
    for (int i = 1; i <= k; ++i)
      for (int j = 1; j <= k; ++j)
        if (dist[i][j] > dist[i][kk] + dist[kk][j])
          dist[i][j] = dist[i][kk] + dist[kk][j];
  for (int i = 1; i <= k; ++i) {
    for (int j = 1; j <= k; ++j)
      printf("%d ", dist[i][j] == INF ? 1 : dist[i][j]);
    puts("");
  }
  return 0;
}
