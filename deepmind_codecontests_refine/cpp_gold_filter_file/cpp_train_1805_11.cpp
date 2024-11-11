#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    que;
int size, n, k, S, T, dis[2010000], i, j, g[2010000], p[2010000], flow[2010000],
    num[2010000], tot, ex[2010000], cnt, vis[2010000], h[2010000];
struct node {
  int to, next, f, v;
} e[2010000];
void add1(int o, int p, int q, int w) {
  e[++size].to = p, e[size].next = g[o], g[o] = size, e[size].f = q,
  e[size].v = w;
}
void add(int o, int p, int q, int w) { add1(o, p, q, w), add1(p, o, 0, -w); }
struct node1 {
  int s, t, val;
} a[2010000];
bool check(int i, int j) {
  int tmp = a[i].s + a[i].t - 1;
  return tmp < a[j].s;
}
void init() {
  sort(ex + 1, ex + 1 + cnt);
  tot = unique(ex + 1, ex + 1 + cnt) - ex - 1;
  for (i = 1; i <= n; i++) {
    a[i].s = lower_bound(ex + 1, ex + 1 + tot, a[i].s) - ex;
    a[i].t = lower_bound(ex + 1, ex + 1 + tot, a[i].t) - ex;
  }
}
void mcmf() {
  for (i = 1; i <= T; i++) {
    for (int x = S; x <= T; x++)
      for (int k = g[x]; k; k = e[k].next) {
        if (e[k].f == 0) continue;
        int y = e[k].to;
        if (h[y] > h[x] + e[k].v) h[y] = h[x] + e[k].v;
      }
  }
  while (1) {
    for (i = S; i <= T; i++) dis[i] = 2000000000, vis[i] = 0;
    dis[S] = 0;
    que.push(make_pair(0, S));
    flow[S] = 2000000000;
    while (!que.empty()) {
      int x = que.top().second;
      que.pop();
      if (vis[x] == 1) continue;
      vis[x] = 1;
      for (int k = g[x]; k; k = e[k].next) {
        int y = e[k].to, cost = e[k].v + h[x] - h[y];
        if (e[k].f && dis[y] > dis[x] + cost) {
          dis[y] = dis[x] + cost;
          flow[y] = min(flow[x], e[k].f);
          p[y] = k;
          que.push(make_pair(dis[y], y));
        }
      }
    }
    if (vis[T] == 0) break;
    for (i = S; i <= T; i++) h[i] += dis[i];
    int now = p[T];
    while (now) {
      e[now].f -= flow[T], e[now ^ 1].f += flow[T], now = p[e[now ^ 1].to];
    };
  }
}
int main() {
  scanf("%d %d", &n, &k);
  size = 1;
  for (i = 1; i <= n; i++) {
    scanf("%d %d %d", &a[i].s, &a[i].t, &a[i].val);
    a[i].t += a[i].s;
    ex[++cnt] = a[i].s, ex[++cnt] = a[i].t;
  }
  init();
  S = 0, T = tot + 1;
  for (i = 0; i <= tot; i++) add(i, i + 1, k, 0);
  for (i = 1; i <= n; i++) add(a[i].s, a[i].t, 1, -a[i].val), num[i] = size - 1;
  mcmf();
  for (i = 1; i <= n; i++) printf("%d ", 1 - e[num[i]].f);
}
