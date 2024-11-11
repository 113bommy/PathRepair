#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
const long long INF = 1ll << 60;
struct edge {
  int from, to, next, val_l, val_r;
} e[(maxn + 200) * 2];
int head[maxn], e_num;
void add_edge(int u, int v, int cl, int cr) {
  e[++e_num] = (edge){u, v, head[u], cl, cr};
  head[u] = e_num;
}
int s1, s2, t, n, m, k, q[maxn];
bool inq[maxn];
long long d[2][maxn];
void spfa(long long dis[], int s) {
  for (int i = 1; i <= n; ++i) dis[i] = INF, inq[i] = 0;
  int hh, tt;
  hh = tt = dis[s] = 0;
  inq[s] = 1;
  q[tt++] = s;
  while (hh ^ tt) {
    int x = q[hh++];
    inq[x] = 0;
    if (hh == maxn) hh = 0;
    for (int i = head[x]; i; i = e[i].next)
      if (dis[e[i].to] > dis[x] + e[i].val_r) {
        dis[e[i].to] = dis[x] + e[i].val_r;
        if (!inq[e[i].to]) {
          inq[e[i].to] = 1;
          q[tt++] = e[i].to;
          if (tt == maxn) tt = 0;
        }
      }
  }
}
bool check(int delta) {
  bool tag = 1;
  while (tag) {
    spfa(d[0], s1);
    spfa(d[1], s2);
    tag = 0;
    for (int i = 1; i <= e_num; ++i)
      if (d[0][e[i].from] < d[1][e[i].from] + delta &&
          e[i].val_l != e[i].val_r) {
        tag = 1;
        e[i].val_r = e[i].val_l;
      }
    if (d[0][t] < d[1][t] + delta) {
      if (delta)
        puts("DRAW");
      else
        puts("WIN");
      for (int i = m + 1; i <= e_num; ++i) printf("%d ", e[i].val_r);
      return 1;
    }
  }
  return 0;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  scanf("%d%d%d", &s1, &s2, &t);
  int a, b, l, r;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &a, &b, &l);
    add_edge(a, b, l, l);
  }
  for (int i = 0; i < k; ++i) {
    scanf("%d%d%d%d", &a, &b, &l, &r);
    add_edge(a, b, l, r);
  }
  if (!check(0))
    if (!check(1)) puts("LOSE");
  return 0;
}
