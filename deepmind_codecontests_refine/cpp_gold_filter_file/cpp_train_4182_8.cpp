#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long Min[N << 2], tag[N << 2];
void build(int x, int l, int r) {
  Min[x] = 1e15;
  tag[x] = 1e15;
  if (l == r) return;
  build(x << 1, l, (l + r) / 2);
  build(x << 1 | 1, (l + r) / 2 + 1, r);
}
void af(int x, long long v) {
  Min[x] = min(Min[x], v);
  tag[x] = min(tag[x], v);
}
void pu(int x, int l, int r) {
  af(x << 1, tag[x]);
  af(x << 1 | 1, tag[x]);
  tag[x] = 1e15;
}
void up(int x, int l, int r, int L, int R, long long v) {
  if (l >= L && r <= R) {
    af(x, v);
    return;
  }
  pu(x, l, r);
  if (L <= (l + r) / 2) up(x << 1, l, (l + r) / 2, L, R, v);
  if (R > (l + r) / 2) up(x << 1 | 1, (l + r) / 2 + 1, r, L, R, v);
}
long long qu(int x, int l, int r, int p) {
  if (l == r) return Min[x];
  pu(x, l, r);
  if (p <= (l + r) / 2) return qu(x << 1, l, (l + r) / 2, p);
  return qu(x << 1 | 1, (l + r) / 2 + 1, r, p);
}
struct Edge {
  int go, next, id, x;
  long long w;
} e[N * 2];
int head[N], tot = 1;
void add(int x, int y, long long w) {
  e[++tot].go = y;
  e[tot].x = x;
  e[tot].w = w;
  e[tot].next = head[x];
  head[x] = tot;
}
struct P {
  int x;
  long long v;
  bool operator<(P B) const { return v > B.v; }
};
priority_queue<P> pq;
long long ds[N], dt[N];
int pre[2 * N], vis[N], sta[N], top, l[N], r[N];
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= m; i++) {
    int x, y;
    long long w;
    scanf("%d%d%lld", &x, &y, &w);
    add(x, y, w);
    add(y, x, w);
  }
  memset(ds, 0x3f3f3f, sizeof(ds));
  ds[1] = 0;
  memset(dt, 0x3f3f3f, sizeof(dt));
  dt[n] = 0;
  pq.push((P){1, 0});
  while (!pq.empty()) {
    int x = pq.top().x;
    pq.pop();
    while (!pq.empty() && vis[x]) x = pq.top().x, pq.pop();
    vis[x] = 1;
    for (int i = head[x]; i; i = e[i].next) {
      int v = e[i].go, w = e[i].w;
      if (ds[v] > ds[x] + w) {
        ds[v] = ds[x] + w;
        pq.push((P){v, ds[v]});
        pre[v] = i;
      }
    }
  }
  int v = n;
  while (v != 1) {
    int i = pre[v];
    sta[++top] = i;
    v = e[i].x;
  }
  int cnt = 0;
  for (int i = top; i >= 1; i--) {
    int t = sta[i];
    e[t].id = ++cnt;
    e[t ^ 1].id = cnt;
  }
  for (int i = 1; i <= n; i++) r[i] = cnt + 1;
  memset(vis, 0, sizeof(vis));
  pq.push((P){n, 0});
  while (!pq.empty()) {
    int x = pq.top().x;
    pq.pop();
    while (!pq.empty() && vis[x]) x = pq.top().x, pq.pop();
    vis[x] = 1;
    for (int i = head[x]; i; i = e[i].next) {
      int v = e[i].go, w = e[i].w;
      if (dt[v] > dt[x] + w) {
        dt[v] = dt[x] + w;
        pq.push((P){v, dt[v]});
        if (e[i].id)
          r[v] = e[i].id;
        else
          r[v] = r[x];
      } else if (dt[v] == dt[x] + w) {
        if (e[i].id)
          r[v] = min(e[i].id, r[v]);
        else
          r[v] = min(r[x], r[v]);
      }
    }
  }
  memset(ds, 0x3f3f3f, sizeof(ds));
  ds[1] = 0;
  memset(vis, 0, sizeof(vis));
  pq.push((P){1, 0});
  while (!pq.empty()) {
    int x = pq.top().x;
    pq.pop();
    while (!pq.empty() && vis[x]) x = pq.top().x, pq.pop();
    vis[x] = 1;
    for (int i = head[x]; i; i = e[i].next) {
      int v = e[i].go, w = e[i].w;
      if (ds[v] > ds[x] + w) {
        ds[v] = ds[x] + w;
        pq.push((P){v, ds[v]});
        if (e[i].id)
          l[v] = e[i].id;
        else
          l[v] = l[x];
      } else if (ds[v] == ds[x] + w) {
        if (e[i].id)
          l[v] = min(l[v], e[i].id);
        else
          l[v] = min(l[v], l[x]);
      }
    }
  }
  build(1, 1, cnt);
  for (int i = 2; i <= 2 * m + 1; i++) {
    int x = e[i].x, y = e[i].go, w = e[i].w;
    int u = e[i].x, v = e[i].go;
    x = l[x] + 1, y = r[y] - 1;
    if (e[i].id) continue;
    if (x > y) continue;
    up(1, 1, cnt, x, y, ds[u] + w + dt[v]);
  }
  for (int i = 1; i <= q; i++) {
    int t, x;
    scanf("%d%d", &t, &x);
    t = 2 * t;
    long long ans = 1e15, w = e[t].w;
    int u = e[t].x, v = e[t].go;
    if (x < w) {
      ans = x + min(ds[u] + dt[v], dt[u] + ds[v]);
      if (ans < ds[n])
        printf("%lld\n", ans);
      else
        printf("%lld\n", ds[n]);
    } else {
      if (!e[t].id)
        printf("%lld\n", ds[n]);
      else {
        ans = min(ds[n] + x - w, qu(1, 1, cnt, e[t].id));
        printf("%lld\n", ans);
      }
    }
  }
  return 0;
}
