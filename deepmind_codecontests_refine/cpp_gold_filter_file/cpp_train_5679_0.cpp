#include <bits/stdc++.h>
using namespace std;
const int N = int(2e5) + 10, mod = int(1e9) + 7;
int n, m, q, x[N], y[N], l[N], r[N], second[N], t[N];
vector<int> g[N];
int first[N];
int d[1010][1010];
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  for (int i = 1; i <= q; i++) {
    scanf("%d%d%d%d", &l[i], &r[i], &second[i], &t[i]);
    g[r[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      d[i][j] = -mod;
    }
    d[i][i] = mod;
  }
  for (int i = 1; i <= m; i++) {
    int u = x[i];
    int v = y[i];
    for (int j = 1; j <= n; j++) {
      if (d[u][j] < i) {
        d[v][j] = max(d[v][j], d[u][j]);
      }
      if (d[v][j] < i) {
        d[u][j] = max(d[v][j], d[u][j]);
      }
    }
    d[v][u] = i;
    d[u][v] = i;
    for (int j = 0; j < g[i].size(); j++) {
      int id = g[i][j];
      int u = second[id];
      int v = t[id];
      if (d[v][u] >= l[id]) first[id] = 1;
    }
  }
  for (int i = 1; i <= q; i++) {
    if (first[i])
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
