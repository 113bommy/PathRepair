#include <bits/stdc++.h>
class graph {
 public:
  int node[400200], next[400200], to[400200];
  int e, n;
  void ins(int x, int y) {
    e++;
    next[e] = node[x];
    node[x] = e;
    to[e] = y;
  }
};
class tree {
 public:
  int dsu[400200];
  int find(int x) { return (dsu[x] == x) ? x : dsu[x] = find(dsu[x]); }
  graph T;
  int col[400200], ned[400200];
  int red[400200][2], rcn, n;
  void gen(graph &G) {
    int i, j, k = 0;
    n = T.n = G.n;
    for (i = 1; i <= n; i++) dsu[i] = i;
    for (i = 1; i <= n; i++)
      for (j = G.node[i]; j; j = G.next[j])
        if (find(i) != find(G.to[j])) {
          dsu[dsu[i]] = dsu[G.to[j]];
          T.ins(i, G.to[j]);
          T.ins(G.to[j], i);
        } else
          red[++rcn][0] = i, red[rcn][1] = G.to[j];
    for (i = 1; i <= n; i++) ned[i] = 0;
    for (i = 1; i <= rcn; i++) ned[red[i][0]] ^= 1;
  }
  int dep[400200], siz[400200], tp[400200], dp[400200], pfc[400200],
      par[400200], boj[400200], ind[400200], rid[400200], cao[400200];
  int id;
  void dfs1(int x, int p) {
    int j;
    siz[x] = 1;
    for (j = T.node[x]; j; j = T.next[j])
      if (T.to[j] != p) {
        dep[T.to[j]] = dep[x] + 1;
        par[T.to[j]] = x;
        dfs1(T.to[j], x);
        siz[x] += siz[T.to[j]];
        if (siz[T.to[j]] > siz[pfc[x]]) pfc[x] = T.to[j];
        ned[x] ^= 1;
      }
  }
  void dfs2(int x, int p) {
    int j;
    if (pfc[x]) {
      ind[pfc[x]] = ++id;
      rid[id] = pfc[x];
      tp[pfc[x]] = tp[x];
      dp[pfc[x]] = dp[x] + 1;
      dfs2(pfc[x], x);
    }
    for (j = T.node[x]; j; j = T.next[j])
      if (T.to[j] != p && T.to[j] != pfc[x]) {
        ind[T.to[j]] = ++id;
        rid[id] = T.to[j];
        tp[T.to[j]] = T.to[j];
        dp[T.to[j]] = 1;
        dfs2(T.to[j], x);
      }
  }
  void paint(int x, int y) {
    while (tp[x] != tp[y]) {
      if (dep[tp[x]] >= dep[tp[y]]) {
        boj[ind[x]] ^= 1;
        boj[ind[tp[x]]] ^= 1;
        cao[ind[tp[x]]] ^= 1;
        x = par[tp[x]];
      } else {
        x ^= y;
        y ^= x;
        x ^= y;
      }
    }
    boj[ind[x]] ^= 1;
    boj[ind[y]] ^= 1;
  }
  graph O;
  int fuck[400200];
  bool doit() {
    int i, j, k;
    for (i = 1; i <= n; i++) O.ins(find(i), i);
    for (i = 1; i <= n; i++)
      if (find(i) == i) {
        dfs1(i, 0);
        tp[i] = i;
        dp[i] = 0;
        ind[i] = ++id;
        rid[id] = i;
        dfs2(i, 0);
      }
    for (i = 1; i <= n; i++) {
      k = 0;
      for (j = O.node[i]; j; j = O.next[j])
        if (ned[O.to[j]]) fuck[++k] = O.to[j];
      if (k & 1) return 0;
      for (j = 1; j <= k; j += 2) paint(fuck[j], fuck[j + 1]);
    }
    k = 0;
    for (i = 1; i <= n; i++) {
      cao[i] ^= k;
      k ^= boj[i];
    }
    return 1;
  }
  void print(graph &G) {
    int i, j, k;
    for (i = 1; i <= rcn; i++) G.ins(red[i][0], red[i][1]);
    for (i = 1; i <= n; i++)
      for (j = T.node[i]; j; j = T.next[j])
        if (par[T.to[j]] == i) {
          if (cao[ind[T.to[j]]])
            G.ins(T.to[j], i);
          else
            G.ins(i, T.to[j]);
        }
  }
} T;
int E[400200][2];
graph res, ori;
int n, m;
void init() {
  int i, j, u, v;
  scanf("%d %d\n", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d %d\n", &u, &v);
    ori.ins(u, v);
  }
  ori.n = n;
  T.gen(ori);
}
int go[400200];
int main() {
  int i, j;
  init();
  if (!T.doit()) {
    printf("no solution");
    return 0;
  }
  T.print(res);
  for (i = 1; i <= n; i++)
    for (j = res.node[i]; j; j = res.next[res.next[j]])
      printf("%d %d %d\n", res.to[j], i, res.to[res.next[j]]);
  return 0;
}
