#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
int n, m, lim;
int ecnt, pt[maxn << 1], nt[maxn << 1];
int d[maxn], hd[maxn], fa[maxn], a[maxn], b[maxn];
void ins(int u, int v) {
  d[u]++;
  pt[++ecnt] = v;
  nt[ecnt] = hd[u];
  hd[u] = ecnt;
}
int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }
int tot, rev, A[maxn * maxn], B[maxn * maxn], C[maxn * maxn];
int dfs(int x, int f, int &rem) {
  int i, cut = min(a[x], rem);
  a[x] -= cut;
  rem -= cut;
  if (rem) {
    for (i = hd[x]; i; i = nt[i])
      if (d[pt[i]] && pt[i] != f) cut += dfs(pt[i], x, rem);
  }
  if (cut) {
    ++tot;
    if (rev)
      A[tot] = f, B[tot] = x;
    else
      A[tot] = x, B[tot] = f;
    C[tot] = cut;
  }
  return cut;
}
int main() {
  int i, j, u, v, l, r, rem;
  scanf("%d%d%d", &n, &lim, &m);
  for (i = 1; i <= n; i++) scanf("%d", a + i);
  for (i = 1; i <= n; i++) scanf("%d", b + i);
  for (i = 1; i <= n; i++) fa[i] = i;
  while (m--) {
    scanf("%d%d", &u, &v);
    if (get(u) != get(v)) {
      ins(u, v), ins(v, u);
      fa[get(u)] = get(v);
    }
  }
  static int que[maxn];
  l = r = 0;
  for (i = 1; i <= n; i++)
    if (d[i] <= 1) que[r++] = i;
  for (; l < r; l++) {
    u = que[l];
    if (a[u] > b[u])
      for (rev ^= 1, j = 1; j <= n; j++) a[j] = lim - a[j], b[j] = lim - b[j];
    rem = b[u] - a[u];
    if (rem) {
      for (i = hd[u]; i; i = nt[i])
        if (d[pt[i]]) {
          dfs(pt[i], u, rem);
          break;
        }
      if (rem) puts("NO"), exit(0);
    }
    d[u]--;
    for (u = hd[u]; i; i = nt[i])
      if (d[pt[i]]) {
        d[pt[i]]--;
        if (d[pt[i]] == 1) que[r++] = pt[i];
      }
  }
  printf("%d\n", tot);
  for (i = 1; i <= tot; i++) printf("%d %d %d\n", A[i], B[i], C[i]);
  return 0;
}
