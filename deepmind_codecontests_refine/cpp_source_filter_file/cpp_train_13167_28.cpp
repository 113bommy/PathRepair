#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, M = 6e5 + 10;
int T, n, m, s, t = 1, b[M], pre[N];
long long dis[N], ans = 0;
bool v[N];
struct edge {
  int nxt, y, v;
} a[M];
inline int read() {
  int sum = 0, fg = 1;
  char c;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') fg = -1;
  for (; c >= '0' && c <= '9'; c = getchar())
    sum = (sum << 3) + (sum << 1) + c - '0';
  return sum * fg;
}
inline void add(int x, int y, int v) {
  a[++t] = (edge){b[x], y, v};
  b[x] = t;
  return;
}
inline void dijkstra(int s) {
  priority_queue<pair<int, int> > q;
  memset(dis, 127, sizeof(dis));
  memset(pre, 0, sizeof(pre));
  memset(v, 0, sizeof(v));
  q.push(make_pair(0, s));
  dis[s] = 0;
  while (!q.empty()) {
    int x = q.top().second;
    q.pop();
    if (v[x]) continue;
    v[x] = 1;
    for (int i = b[x]; i; i = a[i].nxt) {
      int y = a[i].y;
      if (dis[y] > dis[x] + a[i].v) {
        dis[y] = dis[x] + a[i].v;
        pre[y] = i;
        q.push(make_pair(-dis[y], y));
      } else if (dis[y] == dis[x] + a[i].v && a[i].v < a[pre[y]].v)
        pre[y] = i;
    }
  }
  return;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; ++i) {
    int x = read(), y = read(), v = read();
    add(x, y, v);
    add(y, x, v);
  }
  s = read();
  dijkstra(s);
  for (int i = 1; i <= n; ++i)
    if (i ^ s) ans += a[pre[i]].v;
  printf("%lld\n", ans);
  for (int i = 1; i <= n; ++i)
    if (i ^ s) printf("%d ", pre[i] >> 1);
  return 0;
}
