#include <bits/stdc++.h>
using namespace std;
const int N = 210;
struct edge {
  int from, to, next, f, v;
} e[N * N];
int head[N], tot, S, T;
void add(int x, int y, int f, int v) {
  e[++tot] = (edge){x, y, head[x], f, v};
  head[x] = tot;
  e[++tot] = (edge){y, x, head[y], 0, -v};
  head[y] = tot;
}
int dis[N], vis[N];
int q[N * N], from[N];
bool bfs() {
  for (int i = (int)(1); i <= (int)(T); i++) dis[i] = (1 << 29), vis[i] = 0;
  int h = 0, t = 1;
  dis[q[1] = S] = 0;
  while (h != t) {
    int x = q[++h];
    vis[x] = 0;
    for (int i = head[x]; i; i = e[i].next)
      if (e[i].f && dis[e[i].to] > dis[x] + e[i].v) {
        dis[e[i].to] = dis[x] + e[i].v;
        from[e[i].to] = i;
        if (!vis[e[i].to]) {
          q[++t] = e[i].to;
          vis[e[i].to] = 1;
        }
      }
  }
  if (dis[T] == (1 << 29)) return 0;
  int mn = 1e9;
  for (int i = from[T]; i; i = from[e[i].from]) mn = min(mn, e[i].f);
  for (int i = from[T]; i; i = from[e[i].from]) e[i].f -= mn, e[i ^ 1].f += mn;
  return 1;
}
const int M = 5005;
int n, m, k, s;
int x[M], y[M], co[M];
int dx[N], dy[N];
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &s);
  for (int i = (int)(1); i <= (int)(k); i++) {
    scanf("%d%d", &x[i], &y[i]);
    dx[x[i]]++;
    dy[y[i]]++;
  }
  int ans = 0;
  for (int i = (int)(1); i <= (int)(n); i++) ans += ((dx[i] % s) != 0);
  for (int i = (int)(1); i <= (int)(m); i++) ans += ((dy[i] % s) != 0);
  printf("%d\n", ans);
  for (int i = (int)(s); i >= (int)(1); i--) {
    memset(head, 0, sizeof(head));
    tot = 1;
    S = n + m + 1;
    T = S + 1;
    for (int j = (int)(1); j <= (int)(k); j++)
      if (!co[j]) add(x[j], n + y[j], 1, 0);
    for (int j = (int)(1); j <= (int)(n); j++) {
      add(S, j, dx[j] / i, 0);
      if (dx[j] % i) add(S, j, 1, 1);
    }
    for (int j = (int)(1); j <= (int)(m); j++) {
      add(j + n, T, dy[j] / i, 0);
      if (dy[j] % i) add(j + n, T, 1, 1);
    }
    for (; bfs();)
      ;
    int z = 2;
    for (int j = (int)(1); j <= (int)(k); j++)
      if (!co[j])
        if (!e[z += 2].f) co[j] = i, dx[x[j]]--, dy[y[j]]--;
  }
  for (int i = (int)(1); i <= (int)(k); i++) printf("%d ", co[i]);
}
