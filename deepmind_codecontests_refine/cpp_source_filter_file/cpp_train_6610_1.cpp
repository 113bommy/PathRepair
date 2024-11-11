#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u, v, d;
  friend bool operator<(edge x, edge y) { return x.d < y.d; }
};
edge e[155];
int dist[155][155];
bitset<155> g[155], f[155];
int n, m;
void mul(bitset<155> *x, bitset<155> *y) {
  bitset<155> res[155];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (x[i][j]) res[i] |= y[j];
  for (int i = 0; i < n; i++) x[i] = res[i];
}
void pow(bitset<155> *x, int y) {
  bitset<155> tmp[155];
  for (int i = 0; i < n; i++) tmp[i][i] = 1;
  while (y) {
    if (y & 1) mul(tmp, x);
    y >>= 1;
    mul(x, x);
  }
  for (int i = 0; i < n; i++) x[i] = tmp[i];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].d);
    e[i].u--;
    e[i].v--;
  }
  sort(e + 1, e + 1 + m);
  if (e[1].d != 0) {
    puts("Impossible");
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) dist[i][j] = 1e9;
  for (int i = 0; i < n; i++) {
    dist[i][i] = 0;
    g[i][i] = 1;
  }
  int pre = 0;
  int ans = -1;
  for (int p = 1; p <= m; p++) {
    int xx = e[p].u, yy = e[p].v;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][xx] + dist[yy][j] + 1);
      }
    }
    bitset<155> trans[155];
    for (int i = 0; i < n; i++) trans[i] = f[i];
    pow(trans, e[p].d - pre);
    mul(g, trans);
    for (int i = 0; i < n; i++) {
      if (g[0][i] && dist[i][n - 1] < 1e9) {
        if (ans == -1)
          ans = e[p].d + dist[i][n - 1];
        else
          ans = min(ans, e[p].d + dist[i][n - 1]);
      }
    }
    pre = e[p].d;
    f[xx][yy] = 1;
  }
  if (ans == 2e9)
    puts("Impossible");
  else
    printf("%d\n", ans);
  return 0;
}
