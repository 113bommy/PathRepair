#include <bits/stdc++.h>
int n, q, x[1000050], sz, first[1000050], nxt[2000050], tail[2000050],
    dep[1000050], li[1000050], eul[2000050], b, minv[30][1000050];
void addedge(int u, int v) {
  tail[++sz] = v;
  nxt[sz] = first[u];
  first[u] = sz;
}
void dfs(int u) {
  eul[++eul[0]] = u;
  li[u] = eul[0];
  int v, e;
  for (e = first[u]; e; e = nxt[e]) {
    v = tail[e];
    if (li[v]) continue;
    dep[v] = dep[u] + 1;
    dfs(v);
    eul[++eul[0]] = u;
  }
}
void rmq() {
  b = sizeof(int) * 8 - __builtin_clz(n * 2 - 1) - 1;
  int i, j;
  for (i = 1; i <= n * 2 - 1; i++) minv[0][i] = eul[i];
  for (i = 1; i <= b; i++)
    for (j = 1; j <= n * 2 - 1; j++)
      if (j + (1 << (i - 1)) > n * 2 - 1 ||
          dep[minv[i - 1][j]] < dep[minv[i - 1][j + (1 << (i - 1))]])
        minv[i][j] = minv[i - 1][j];
      else
        minv[i][j] = minv[i - 1][j + (1 << (i - 1))];
}
int query(int l, int r) {
  int w = sizeof(int) * 8 - __builtin_clz(r - l + 1) - 1;
  if (dep[minv[w][l]] < dep[minv[w][r - (1 << w) + 1]])
    return minv[w][l];
  else
    return minv[w][r - (1 << w) + 1];
}
int lca(int u, int v) {
  return query(std::min(li[u], li[v]), std::max(li[u], li[v]));
}
int main() {
  scanf("%d", &q);
  int i, j;
  for (n = 1, sz = 0, i = 2; i <= 4; i++) {
    addedge(1, i);
    addedge(i, 1);
    n++;
  }
  for (i = 1; i <= q; i++) {
    scanf("%d", &x[i]);
    for (j = 1; j <= 2; j++) {
      n++;
      addedge(x[i], n);
      addedge(n, x[i]);
    }
  }
  dep[1] = 1;
  dfs(1);
  rmq();
  int u = 1, v = 1, ans = 2, a, b;
  for (i = 1; i <= q; i++) {
    a = lca(u, x[i]);
    b = lca(v, x[i]);
    if (dep[x[i]] + dep[u] - dep[a] * 2 + 2 > ans) {
      ans = dep[x[i]] + dep[u] - dep[a] * 2 + 2;
      v = x[i];
    } else if (dep[x[i]] + dep[v] - dep[b] * 2 + 2 > ans) {
      ans = dep[x[i]] + dep[v] - dep[b] * 2 + 2;
      u = x[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}
