#include <bits/stdc++.h>
using namespace std;
typedef int arr32[101000];
int js[1110 / 31];
int Mo, n, top, tp, e, T;
arr32 fst, fa, sou, L, R, pri, A;
int mark[101000 << 2];
struct str {
  int v, nex;
} edge[101000 << 1];
struct bits {
  int v[1110 / 31];
  void proc(int k) {
    k %= Mo;
    memcpy(js, v, sizeof(v));
    memset(v, 0, sizeof(v));
    for (int i = 0; i * 31 < Mo; i++) {
      int j = (i * 31 + k) % Mo;
      int res, roof, you, now;
      res = min(31, Mo - i * 31);
      while (true) {
        roof = (j >= ((Mo - 1) / 31) * 31) ? ((Mo - 1) % 31 + 1) : 31;
        you = roof - j % 31;
        now = min(res, you);
        v[j / 31] |= (js[i] & ((1 << now) - 1)) << (j % 31);
        if (res > you) {
          res -= you;
          j = ((j >= ((Mo - 1) / 31) * 31) ? 0 : (j / 31 + 1)) * 31;
          js[i] >>= you;
        } else
          break;
      }
    }
    return;
  }
} bt_now, bt[101000 << 2];
void make_edge(int a, int b) {
  edge[++e].nex = fst[a];
  fst[a] = e;
  edge[e].v = b;
  edge[++e].nex = fst[b];
  fst[b] = e;
  edge[e].v = a;
}
int dfs(int u) {
  L[u] = R[u] = ++top;
  sou[top] = u;
  for (int i = fst[u]; i; i = edge[i].nex) {
    int v = edge[i].v;
    if ((fa[u] == v)) continue;
    fa[v] = u;
    R[u] = dfs(v);
  }
  return R[u];
}
void down(int u, int L, int R) {
  if (!mark[u]) return;
  mark[u] %= Mo;
  bt[u].proc(mark[u]);
  if (L < R) mark[(u << 1)] += mark[u], mark[(u << 1 | 1)] += mark[u];
  mark[u] = 0;
  return;
}
void proc(int u, int L, int R, int l, int r, int v) {
  down(u, L, R);
  if (L == l && R == r) {
    mark[u] += v;
    mark[u] %= Mo;
    down(u, L, R);
    return;
  }
  if (r < (((L + R) >> 1) + 1))
    down((u << 1 | 1), (((L + R) >> 1) + 1), R),
        proc((u << 1), L, ((L + R) >> 1), l, r, v);
  else if (l > ((L + R) >> 1))
    down((u << 1), L, ((L + R) >> 1)),
        proc((u << 1 | 1), (((L + R) >> 1) + 1), R, l, r, v);
  else
    proc((u << 1), L, ((L + R) >> 1), l, ((L + R) >> 1), v),
        proc((u << 1 | 1), (((L + R) >> 1) + 1), R, (((L + R) >> 1) + 1), r, v);
  for (int i = 0; i <= (Mo - 1) / 31; i++)
    bt[u].v[i] = bt[(u << 1)].v[i] | bt[(u << 1 | 1)].v[i];
}
void query(int u, int L, int R, int l, int r) {
  down(u, L, R);
  if (L == l && R == r) {
    for (int i = 0; i <= (Mo - 1) / 31; i++)
      bt_now.v[i] = bt_now.v[i] | bt[u].v[i];
    return;
  }
  if (r < (((L + R) >> 1) + 1))
    query((u << 1), L, ((L + R) >> 1), l, r);
  else if (l > ((L + R) >> 1))
    query((u << 1 | 1), (((L + R) >> 1) + 1), R, l, r);
  else
    query((u << 1), L, ((L + R) >> 1), l, ((L + R) >> 1)),
        query((u << 1 | 1), (((L + R) >> 1) + 1), R, (((L + R) >> 1) + 1), r);
  return;
}
void build_tree(int u, int L, int R) {
  if (L == R) {
    bt[u].v[A[sou[L]] / 31] |= (1 << (A[sou[L]] % 31));
    return;
  }
  build_tree((u << 1), L, ((L + R) >> 1));
  build_tree((u << 1 | 1), (((L + R) >> 1) + 1), R);
  for (int i = 0; i <= (Mo - 1) / 31; i++)
    bt[u].v[i] = bt[(u << 1)].v[i] | bt[(u << 1 | 1)].v[i];
  return;
}
int main() {
  scanf("%d %d", &n, &Mo);
  for (int i = 2; i < Mo; i++) {
    bool flag = true;
    for (int j = 2; j < i && flag; j++)
      if (!(i % j)) flag = false;
    if (flag) pri[++tp] = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
    A[i] %= Mo;
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    make_edge(a, b);
  }
  dfs(1);
  build_tree(1, 1, n);
  for (scanf("%d", &T); T; T--) {
    int ch;
    scanf("%d", &ch);
    if (ch == 1) {
      int v, x;
      scanf("%d %d", &v, &x);
      x %= Mo;
      proc(1, 1, n, L[v], R[v], x);
    } else {
      int v;
      scanf("%d", &v);
      memset(bt_now.v, 0, sizeof(bt_now.v));
      query(1, 1, n, L[v], R[v]);
      int ans = 0;
      for (int i = 1; i <= tp; i++)
        ans += (bt_now.v[pri[i] / 31] >> (pri[i] % 31)) & 1;
      printf("%d\n", ans);
    }
  }
  return 0;
}
