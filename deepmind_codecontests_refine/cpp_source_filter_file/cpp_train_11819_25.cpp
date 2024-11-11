#include <bits/stdc++.h>
using namespace std;
struct edge {
  int v, nxt, c;
} e[1500005];
int p[1305], eid, pp[1305];
void init() {
  memset(p, -1, sizeof p);
  eid = 0;
}
void insert(int u, int v, int c) {
  e[eid].v = v;
  e[eid].c = c;
  e[eid].nxt = p[u];
  p[u] = eid++;
}
void add(int u, int v, int c) {
  insert(u, v, c);
  insert(v, u, 0);
}
int d[1305], S, T, n, m, b;
queue<int> q;
int bfs() {
  for (int i = 1; i <= m + 8; i++) pp[i] = p[i], d[i] = -1;
  d[S] = 0;
  q.push(S);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = p[u]; i + 1; i = e[i].nxt) {
      int v = e[i].v, c = e[i].c;
      if (d[v] == -1 && c) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
  return d[T] != -1;
}
int dfs(int u, int flow) {
  if (u == T) return flow;
  int ret = 0;
  for (int &i = pp[u]; i + 1; i = e[i].nxt) {
    int v = e[i].v, c = e[i].c;
    if (c && d[v] == d[u] + 1) {
      int tmp = dfs(v, min(flow, c));
      e[i].c -= tmp, e[i ^ 1].c += tmp;
      flow -= tmp, ret += tmp;
      if (!flow) break;
    }
  }
  if (!ret) d[u] = -1;
  return ret;
}
int Dinic() {
  int ret = 0;
  for (; bfs();) ret += dfs(S, 23333333);
  return ret;
}
struct A {
  int l, r, s;
} a[1305 << 1];
int cmp(A x, A y) { return x.r < y.r; }
int main() {
  init();
  scanf("%d%d%d", &n, &b, &m);
  for (int i = 1; i <= m; i++) scanf("%d%d", &a[i].r, &a[i].s);
  sort(a + 1, a + 1 + m, cmp);
  a[++m] = A{0, b, n};
  for (int i = m; i >= 1; i--) a[i].l = a[i - 1].r, a[i].s -= a[i - 1].s;
  S = m + 5 + 1, T = m + 5 + 2;
  for (int i = m + 1; i <= m + 5; i++) add(i, T, n / 5);
  for (int i = 1; i <= m; i++) {
    if (a[i].s < 0 || a[i].s > a[i].r - a[i].l) {
      printf("unfail");
      return 0;
    }
    add(S, i, a[i].s);
    for (int j = 1; j <= 5; j++)
      add(i, j + m, (a[i].r - j + 1 + 5) / 5 - (a[i].l - j + 1 + 5) / 5);
  }
  if (Dinic() == n)
    printf("fair");
  else
    printf("unfair");
  return 0;
}
