#include <bits/stdc++.h>
using namespace std;
int top, n, anc[501000];
int ans[501000][5];
struct str {
  int v, nex;
};
struct tree {
  int fst[501000], fa[501000], f[501000], e;
  str edge[501000 << 1];
  void make_edge(int a, int b) {
    edge[++e].nex = fst[a];
    fst[a] = e;
    edge[e].v = b;
    edge[++e].nex = fst[b];
    fst[b] = e;
    edge[e].v = a;
  }
  void dfs(int u) {
    for (int i = fst[u]; i; i = edge[i].nex) {
      int v = edge[i].v;
      if (fa[u] == v) continue;
      fa[v] = u;
      dfs(v);
    }
  }
} A, B;
void proc(int u, int p) {
  int v = A.fa[u];
  if (B.fa[u] == v || B.fa[v] == u)
    ;
  else
    p = u;
  anc[u] = p;
  for (int i = A.fst[u]; i; i = A.edge[i].nex) {
    v = A.edge[i].v;
    if (A.fa[u] == v) continue;
    proc(v, p);
  }
}
void get_ans(int u) {
  int v = B.fa[u];
  if (v && !(A.fa[v] == u || A.fa[u] == v)) {
    top++;
    ans[top][1] = anc[u];
    ans[top][2] = A.fa[anc[u]];
    ans[top][3] = u;
    ans[top][4] = v;
  }
  for (int i = B.fst[u]; i; i = B.edge[i].nex) {
    v = B.edge[i].v;
    if (B.fa[u] == v) continue;
    get_ans(v);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) A.f[i] = B.f[i] = i;
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    A.make_edge(a, b);
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    B.make_edge(a, b);
  }
  A.dfs(1);
  B.dfs(1);
  proc(1, 0);
  get_ans(1);
  printf("%d\n", top);
  for (int i = 1; i <= top; i++) {
    for (int j = 1; j <= 3; j++) printf("%d ", ans[i][j]);
    printf("%d\n", ans[i][1]);
  }
  return 0;
}
