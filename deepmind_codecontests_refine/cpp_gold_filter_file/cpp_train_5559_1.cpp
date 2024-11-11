#include <bits/stdc++.h>
using namespace std;
const int N = 310, M = 50010;
int n, m, v, a[N], b[N], vis[N], dfn[N], dead[N], fa[N], tot;
struct order {
  int x[N * N << 2], y[N * N << 2], d[N * N << 2], tot;
  void push(int A, int B, int C) {
    if (C == 0) return;
    tot++;
    x[tot] = A;
    y[tot] = B;
    d[tot] = C;
    a[A] -= C;
    a[B] += C;
  }
  void draw() {
    printf("%d\n", tot);
    for (int i = 1; i <= tot; i++) printf("%d %d %d\n", x[i], y[i], d[i]);
  }
} ans;
struct Edge {
  int head[N], list[M << 1], next[M << 1], tot;
  Edge() : tot(1) {}
  void add(int a, int b) {
    tot++;
    list[tot] = b;
    next[tot] = head[a];
    head[a] = tot;
  }
} e, g;
long long dfs(int x) {
  vis[x] = 1;
  long long re = a[x] - b[x];
  for (int i = g.head[x]; i; i = g.next[i])
    if (!vis[g.list[i]]) {
      fa[g.list[i]] = x;
      e.add(x, g.list[i]);
      e.add(g.list[i], x);
      re += dfs(g.list[i]);
    }
  dfn[++tot] = x;
  return re;
}
void collect(int x, int y, int offset) {
  for (int i = e.head[x]; i; i = e.next[i])
    if (!dead[e.list[i]] && e.list[i] != y) collect(e.list[i], x, offset);
  if (y) {
    if (offset == 1) {
      int k = min(a[x], v - a[y]);
      ans.push(x, y, k);
    } else {
      int k = min(v - a[x], a[y]);
      ans.push(y, x, k);
    }
  }
}
bool build(int S) {
  tot = 0;
  e.tot = 1;
  memset(e.head, 0, sizeof(e.head));
  int i, j;
  if (dfs(S) != 0) return false;
  for (i = 1; i < tot; i++) {
    j = dfn[i];
    dead[j] = 1;
    if (a[j] < b[j]) {
      collect(fa[j], 0, 1);
      ans.push(fa[j], j, b[j] - a[j]);
    } else if (a[j] > b[j]) {
      collect(fa[j], 0, -1);
      ans.push(j, fa[j], a[j] - b[j]);
    }
  }
  return true;
}
int main() {
  int i, j, k;
  scanf("%d%d%d", &n, &v, &m);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &j, &k);
    g.add(j, k);
    g.add(k, j);
  }
  for (i = 1; i <= n; i++)
    if (vis[i] == 0 && build(i) == false) {
      puts("NO");
      return 0;
    }
  ans.draw();
  return 0;
}
