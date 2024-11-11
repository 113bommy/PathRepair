#include <bits/stdc++.h>
using namespace std;
long long a, b, c, n, m, k = 0, T, x[10 * 100010], dp[100010],
                         head[10 * 100010], dis[10 * 100010], vis[10 * 100010],
                         maxx = -0x3f3f3f3f;
struct node {
  long long u, v, Next, val;
} g[10 * 100010];
void add(long long u, long long v, long long val) {
  g[++k].v = v;
  g[k].val = val;
  g[k].Next = head[u];
  head[u] = k;
}
struct tree {
  long long l, r, fa;
} t[10 * 100010];
void build(long long u, long long l, long long r) {
  t[u].l = l;
  t[u].r = r;
  if (l == r) {
    add(u + 4 * 100010, l + 8 * 100010, 0);
    add(l + 8 * 100010, u + 4 * 100010, 0);
    add(u, l + 8 * 100010, 0);
    add(l + 8 * 100010, u, 0);
    return;
  }
  long long mid = (l + r) / 2;
  add(u, 2 * u, 0);
  add(u, 2 * u + 1, 0);
  add(u * 2 + 4 * 100010, u + 4 * 100010, 0);
  add(u * 2 + 1 + 4 * 100010, u + 4 * 100010, 0);
  build(u * 2, l, mid);
  build(u * 2 + 1, mid + 1, r);
}
void addout(long long u, long long l, long long r, long long v, long long w) {
  if (t[u].l >= l && t[u].r <= r) {
    add(8 * 100010 + v, u, w);
    return;
  }
  long long mid = (t[u].l + t[u].r) / 2;
  if (l <= mid) addout(u * 2, l, r, v, w);
  if (mid < r) addout(2 * u + 1, l, r, v, w);
}
void addin(long long u, long long l, long long r, long long v, long long w) {
  if (t[u].l >= l && t[u].r <= r) {
    add(u + 4 * 100010, 8 * 100010 + v, w);
    return;
  }
  long long mid = (t[u].l + t[u].r) / 2;
  if (l <= mid) addin(u * 2, l, r, v, w);
  if (mid < r) addin(2 * u + 1, l, r, v, w);
}
struct S {
  long long w, now;
  inline bool operator<(const S &x) const { return w > x.w; }
};
priority_queue<S> q;
void dijkstra(long long s) {
  for (long long i = 1; i <= 8 * 100010 + 5000; i++)
    dis[i] = 0x3f3f3f3f3f3f3f3f;
  dis[0] = 0x3f3f3f3f3f3f3f3f;
  dis[s] = 0;
  q.push((S){0, s});
  while (!q.empty()) {
    S x = q.top();
    q.pop();
    long long u = x.now;
    if (vis[u]) continue;
    vis[u] = 1;
    for (long long i = head[u]; i; i = g[i].Next) {
      long long v = g[i].v, val = g[i].val;
      if (dis[v] > dis[u] + val) {
        dis[v] = dis[u] + val;
        q.push((S){dis[v], v});
      }
    }
  }
}
int main() {
  scanf("%lld%lld%lld", &n, &m, &c);
  build(1, 1, n);
  while (m--) {
    scanf("%lld", &a);
    long long t1, t2, t3, t4;
    if (a == 1) {
      scanf("%lld%lld%lld", &t1, &t2, &t3);
      add(t1 + 8 * 100010, t2 + 8 * 100010, t3);
    } else if (a == 2) {
      scanf("%lld%lld%lld%lld", &t1, &t2, &t3, &t4);
      addout(1, t2, t3, t1, t4);
    } else {
      scanf("%lld%lld%lld%lld", &t1, &t2, &t3, &t4);
      addin(1, t2, t3, t1, t4);
    }
  }
  dijkstra(c + 8 * 100010);
  for (long long i = 1; i <= n; i++) {
    if (dis[i + 8 * 100010] != dis[0])
      cout << dis[i + 8 * 100010] << ' ';
    else
      cout << -1 << ' ';
  }
}
