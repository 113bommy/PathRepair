#include <bits/stdc++.h>
const int maxn = 3e5 + 10;
const int SIGMA = 26;
char buf[maxn];
int c[maxn];
struct node {
  int son[SIGMA], sz;
} rt[maxn];
int head[maxn], nxt[maxn << 1], to[maxn << 1];
int ct, mx, i;
void up(int x) {
  rt[x].sz = 1;
  for (i = 0; i < SIGMA; i++) rt[x].sz += rt[rt[x].son[i]].sz;
}
void merge(int &x, int y) {
  if (!x) {
    x = y;
    return;
  }
  for (int j = 0; j < SIGMA; j++) {
    if (rt[y].son[j]) merge(rt[x].son[j], rt[y].son[j]);
  }
  up(x);
}
void dfs(int u, int f) {
  for (int e = head[u], v; e; e = nxt[e]) {
    v = to[e];
    if (v != f) {
      dfs(v, u);
      merge(rt[u].son[buf[v] - 'a'], v);
    }
  }
  up(u);
  c[u] += rt[u].sz;
  if (c[u] > mx)
    mx = c[u], ct = 1;
  else if (c[u] == mx)
    ct++;
}
int V, E, u, v;
int main() {
  scanf("%d", &V);
  for (i = 1; i <= V; i++) scanf("%d", c + i);
  scanf("%s", buf + 1);
  for (i = 1; i < V; i++) {
    scanf("%d%d", &u, &v);
    nxt[++E] = head[u];
    to[E] = v;
    head[u] = E;
    nxt[++E] = head[v];
    to[E] = u;
    head[v] = E;
  }
  dfs(1, 0);
  printf("%d\n%d\n", mx, ct);
  return 0;
}
