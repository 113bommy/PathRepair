#include <bits/stdc++.h>
using namespace std;
struct str {
  int v, nex;
} edge[201000 << 1];
typedef int arr32[201000];
arr32 mark, fst, A, B, ans, val, is, fa, size;
int n, m, L, R, mid, e;
bool flag;
void make_edge(int a, int b) {
  edge[++e].nex = fst[a];
  fst[a] = e;
  edge[e].v = b;
  edge[++e].nex = fst[b];
  fst[b] = e;
  edge[e].v = a;
}
void update(int u) {
  size[u] = 1;
  for (int i = fst[u]; i; i = edge[i].nex) {
    int v = edge[i].v;
    if (fa[u] == v) continue;
    size[u] += size[v];
  }
  if (!is[u]) return;
  mark[u] = 1;
  ans[u] = 1;
  for (int i = fst[u]; i; i = edge[i].nex) {
    int v = edge[i].v;
    if (fa[u] == v) continue;
    if (mark[v])
      ans[u] += size[v];
    else {
      mark[u] = 0;
      if (ans[v] >= ans[A[u]]) {
        ans[u] += ans[v] - ans[A[u]];
        B[u] = A[u];
        A[u] = v;
      } else if (ans[v] >= ans[B[u]]) {
        B[u] = v;
      }
    }
  }
  return;
}
void dfs(int u) {
  for (int i = fst[u]; i; i = edge[i].nex) {
    int v = edge[i].v;
    if (fa[u] == v) continue;
    fa[v] = u;
    dfs(v);
  }
  update(u);
}
void change_root(int f, int u) {
  fa[u] = 0;
  fa[f] = u;
  if (!is[f])
    ;
  else {
    if (mark[f])
      ans[f] -= size[u];
    else if (mark[u]) {
      ans[f] -= size[u];
    } else {
      if (A[f] == u) {
        ans[f] -= ans[u], ans[f] += ans[B[f]];
        A[f] = B[f];
        B[f] = 0;
      }
      if (!A[f]) mark[f] = 1;
    }
  }
  if (!is[u])
    ;
  else {
    if (mark[f])
      ans[u] += size[f] - size[u];
    else {
      mark[u] = 0;
      if (ans[f] >= ans[A[u]]) {
        ans[u] += ans[f] - ans[A[u]];
        B[u] = A[u];
        A[u] = f;
      } else if (ans[f] >= ans[B[u]]) {
        B[u] = f;
      }
    }
  }
  size[f] -= size[u];
  size[u] += size[f];
}
void proc(int u, int pas) {
  if (ans[u] >= mid) flag = true;
  for (int i = fst[u]; i; i = edge[i].nex) {
    int v = edge[i].v;
    if (v == pas) continue;
    int ans_ = ans[u], mark_ = mark[u], A_ = A[u], B_ = B[u];
    change_root(u, v);
    proc(v, u);
    change_root(v, u);
    if (ans_ != ans[u] || mark_ != mark[u]) {
      printf("woc!\n");
    }
  }
}
bool judge() {
  flag = false;
  for (int i = 1; i <= n; i++) is[i] = (val[i] >= mid);
  for (int i = 1; i <= n; i++) ans[i] = mark[i] = size[i] = A[i] = B[i] = 0;
  for (int i = 1; i <= n; i++) fa[i] = 0;
  dfs(1);
  proc(1, 0);
  return flag;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    make_edge(a, b);
  }
  R = 0;
  L = (1 << 30);
  for (int i = 1; i <= n; i++) {
    R = max(R, val[i]);
    L = min(L, val[i]);
  }
  while (L < R) {
    mid = (L + R + 1) >> 1;
    if (judge())
      L = mid;
    else
      R = mid - 1;
  }
  printf("%d\n", L);
  return 0;
}
