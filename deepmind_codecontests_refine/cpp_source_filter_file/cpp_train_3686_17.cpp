#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, m, en, q[maxn], depth[maxn], f[maxn][20], dist[maxn];
struct edge {
  int e;
  edge *next;
} * v[maxn], ed[maxn << 1];
void add_edge(int s, int e) {
  en++;
  ed[en].next = v[s];
  v[s] = ed + en;
  v[s]->e = e;
}
void bfs(int root) {
  int front = 1, tail = 1;
  q[1] = root;
  depth[1] = 1;
  for (; front <= tail;) {
    int now = q[front++];
    for (edge *e = v[now]; e; e = e->next)
      if (!depth[e->e]) {
        depth[e->e] = depth[now] + 1;
        f[e->e][0] = now;
        int p = now, x = 0;
        while (f[p][x]) {
          f[e->e][x + 1] = f[p][x];
          p = f[p][x];
          x++;
        }
        q[++tail] = e->e;
      }
  }
}
int get_lca(int p1, int p2) {
  if (depth[p1] < depth[p2]) swap(p1, p2);
  int delta = depth[p1] - depth[p2], x = 0;
  while (delta) {
    if (delta & 1) p1 = f[p1][x];
    delta >>= 1;
    x++;
  }
  x = 0;
  while (p1 != p2) {
    if (!x || f[p1][x] != f[p2][x]) {
      p1 = f[p1][x];
      p2 = f[p2][x];
      x++;
    } else
      x--;
  }
  return p1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int a = 1; a < n; a++) {
    int s, e;
    scanf("%d%d", &s, &e);
    add_edge(s, e);
    add_edge(e, s);
  }
  int size = (int)sqrt(n);
  bfs(1);
  int cnt = 1;
  q[1] = 1;
  memset(dist, 0x3f, sizeof(dist));
  dist[1] = 0;
  int opt, p;
  for (int a = 1; a <= m; a++) {
    scanf("%d%d", &opt, &p);
    if (opt == 1) {
      q[++cnt] = p;
      dist[p] = 0;
    } else {
      int ans = dist[p];
      for (int b = 1; b <= cnt; b++)
        ans = min(ans, depth[p] + depth[q[b]] - depth[get_lca(p, q[b])] - 1);
      printf("%d\n", ans);
    }
    if (cnt >= size) {
      for (int front = 1, tail = cnt + 1; front != tail;) {
        int now = q[front++];
        if (front == maxn) front = 0;
        for (edge *e = v[now]; e; e = e->next)
          if (dist[e->e] > dist[now] + 1) {
            dist[e->e] = dist[now] + 1;
            q[tail++] = e->e;
            if (tail == maxn) tail = 0;
          }
      }
      cnt = 0;
    }
  }
  return 0;
}
