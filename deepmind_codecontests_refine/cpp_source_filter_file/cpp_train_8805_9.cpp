#include <bits/stdc++.h>
using namespace std;
const int N = 85;
struct edge {
  int from, to, next, f, v;
} e[N * 14];
int head[N * 3], tot = 1;
int q[N * N], from[N * 3], vis[N * 3];
int n, k, S, T;
long long dis[N * 3], ans;
void add(int x, int y, int v, int f) {
  e[++tot] = (edge){x, y, head[x], f, v};
  head[x] = tot;
  e[++tot] = (edge){y, x, head[y], 0, -v};
  head[y] = tot;
}
void bfs() {
  for (int i = (int)(0); i <= (int)(3 * N - 1); i++)
    dis[i] = (1ll << 30) * (1ll << 30), vis[i] = 0;
  int h = 0, t = 1;
  q[1] = S;
  vis[S] = 1;
  dis[S] = 0;
  while (h != t) {
    int x = q[++h];
    vis[x] = 0;
    for (int i = head[x]; i; i = e[i].next)
      if (dis[e[i].to] > dis[x] + e[i].v && e[i].f) {
        dis[e[i].to] = dis[x] + e[i].v;
        from[e[i].to] = i;
        if (!vis[e[i].to]) {
          vis[e[i].to] = 1;
          q[++t] = e[i].to;
        }
      }
  }
}
int v[N], w[N], las[N];
int main() {
  scanf("%d%d", &n, &k);
  k = min(n, k);
  S = 1;
  T = 3 * n + 1;
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &v[i]);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &w[i]);
  for (int i = (int)(1); i <= (int)(n - 1); i++) {
    add(i * 3 - 2, i * 3 + 1, 0, (1ll << 30));
    add(i * 3, i * 3 + 1, 0, (1ll << 30));
  }
  for (int i = (int)(1); i <= (int)(n); i++) {
    add(i * 3 - 2, i * 3 - 1, w[v[i]], 1);
    add(i * 3 - 1, i * 3, -(1ll << 30), 1);
    add(i * 3, T, 0, 1);
  }
  for (int i = (int)(1); i <= (int)(n); i++) {
    if (las[v[i]]) {
      add(las[v[i]] * 3 - 1, i * 3 - 1, 0, (1ll << 30));
      add(las[v[i]] * 3, i * 3 - 1, 0, (1ll << 30));
    }
    las[v[i]] = i;
  }
  for (int i = (int)(1); i <= (int)(k); i++) {
    bfs();
    if (dis[T] >= 0) break;
    ans += dis[T];
    for (int j = from[T]; j; j = from[e[j].from]) e[j].f--, e[j ^ 1].f++;
  }
  printf("%lld\n", ans + 1ll * (1ll << 30) * n);
}
