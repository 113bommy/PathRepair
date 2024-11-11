#include <bits/stdc++.h>
using namespace std;
inline int gn() {
  int k = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) k = k * 10 + c - '0';
  return k * f;
}
int q[123], l = 1, r = 1, n;
struct edge {
  int to, w;
  edge *ne;
  edge() { ; }
  edge(int to_, int w_, edge *ne_) { to = to_, w = w_, ne = ne_; }
} * head[123];
inline void addedge(int fr, int to, int w) {
  edge *e = new edge(to, w, head[fr]);
  head[fr] = e;
  e = new edge(fr, w, head[to]);
  head[to] = e;
}
int dis[123];
int main() {
  memset(dis, -1, sizeof(dis));
  n = gn();
  for (int i = 1; i < n; i++) {
    int a = gn();
    int b = gn();
    int c = gn();
    addedge(a, b, c);
  }
  q[1] = 0;
  dis[0] = 0;
  int ans = 0;
  while (l <= r) {
    int u = q[l++];
    for (edge *e = head[u]; e; e = e->ne) {
      if (~dis[e->to]) continue;
      dis[e->to] = dis[u] + e->w;
      q[++r] = e->to;
    }
    ans = max(ans, dis[u]);
  }
  printf("%d\n", ans);
}
