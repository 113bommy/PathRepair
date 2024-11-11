#include <bits/stdc++.h>
using namespace std;
void get(int &v) {
  char c;
  while ((c = getchar()) != EOF && isdigit(c) == 0)
    ;
  v = c - '0';
  while ((c = getchar()) != EOF && isdigit(c))
    v = (v << 3) + (v << 1) + c - '0';
  return;
}
int get() {
  char c;
  int v;
  while ((c = getchar()) != EOF && isdigit(c) == 0)
    ;
  v = c - '0';
  while ((c = getchar()) != EOF && isdigit(c))
    v = (v << 3) + (v << 1) + c - '0';
  return v;
}
struct node {
  int v;
  node *next;
} * adj[5000 + 4], edge[5000 + 4], *CNT = edge;
struct xjb {
  int c, d, v;
  node *s;
} goods[5000 + 4];
int f[5000 + 4][5000 + 4], g[5000 + 4][5000 + 4];
int subtreesz[5000 + 4];
void addedge(int u, int v) {
  node *p = ++CNT;
  p->v = v;
  p->next = goods[u].s;
  goods[u].s = p;
  return;
}
void dfs(int s) {
  node *p;
  int i, j;
  f[s][1] = goods[s].c - goods[s].d;
  g[s][0] = 0;
  g[s][1] = goods[s].c;
  subtreesz[s] = 1;
  for (p = goods[s].s; p; p = p->next) {
    dfs(p->v);
    for (i = subtreesz[s]; ~i; i--)
      for (j = subtreesz[p->v]; j; j--) {
        f[s][i + j] = min(f[s][i + j], f[s][i] + min(f[p->v][j], g[p->v][j]));
        g[s][i + j] = min(g[s][i + j], g[s][i] + g[p->v][j]);
      }
    subtreesz[s] += subtreesz[p->v];
  }
  return;
}
int main() {
  int n, i, Lim;
  get(n);
  get(Lim);
  for (i = 1; i <= n; i++) {
    get(goods[i].c);
    get(goods[i].d);
    if (i > 1) addedge(get(), i);
  }
  memset(f, 0x3f, sizeof(f));
  memset(g, 0x3f, sizeof(g));
  dfs(1);
  for (i = 0; i < n && (min(f[1][i + 1], g[1][i + 1]) <= Lim); i++)
    ;
  printf("%d", i);
  return 0;
}
