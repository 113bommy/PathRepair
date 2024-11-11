#include <bits/stdc++.h>
using namespace std;
int i, j, n, m, o, x, y, tot;
int a[100010];
int tov[300010], pre[300010], las[100010];
int dfn[100010], low[100010], vis[100010];
int C[100010], color[100010], inf[100010][2], ans[100010];
int link(int a, int b) {
  tot++;
  tov[tot] = b;
  pre[tot] = las[a];
  las[a] = tot;
}
int tarjan(int p) {
  dfn[p] = low[p] = ++x;
  C[++C[0]] = p, vis[p] = 1;
  for (int i = las[p]; i; i = pre[i])
    if (!dfn[tov[i]]) {
      tarjan(tov[i]);
      low[p] = (low[p] < low[tov[i]] ? low[p] : low[tov[i]]);
    } else if (vis[tov[i]])
      low[p] = (low[p] < low[tov[i]] ? low[p] : low[tov[i]]);
  if (dfn[p] == low[p]) {
    for (y++; C[C[0]] != p; C[0]--) color[C[C[0]]] = y, vis[C[C[0]]] = 0;
    color[C[C[0]]] = y, vis[C[C[0]--]] = 0;
  }
  return 0;
}
int main() {
  scanf("%d%d%d", &n, &m, &o);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    if ((a[x] + 1) % o == a[y]) link(x, y);
    if ((a[y] + 1) % o == a[x]) link(y, x);
  }
  x = y = 0;
  for (i = 1; i <= n; i++)
    if (!dfn[i]) tarjan(i);
  for (i = 1; i <= n; i++)
    for (inf[color[i]][0]++, j = las[i]; j; j = pre[j])
      if (color[i] != color[tov[j]]) inf[color[i]][1]++;
  x = 1e9;
  for (i = 1; i <= y; i++)
    if ((!inf[i][1]) && (x > inf[i][0])) {
      x = inf[i][0];
      j = i;
    }
  printf("%d\n", x);
  for (i = 1; i <= n; i++)
    if (color[i] == j) printf("%d ", i);
  return 0;
}
