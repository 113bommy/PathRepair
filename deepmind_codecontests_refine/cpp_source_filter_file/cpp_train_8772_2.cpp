#include <bits/stdc++.h>
using namespace std;
const int M = 1000000 + 7;
const int N = 20000 + 7;
struct Dinic {
  long long maxflow;
  int s, t, n;
  int v[N], pre[N], d[N], now[N];
  long long incf[N];
  int head[N], cnt = 1;
  struct EDGE {
    int to, nxt;
    long long w;
  } ee[M * 2];
  inline void AD(int x, int y, long long w) {
    ee[++cnt].nxt = head[x], ee[cnt].w = w, ee[cnt].to = y, head[x] = cnt;
  }
  inline void add(int x, int y, long long w) {
    AD(x, y, w);
    AD(y, x, 0);
  }
  inline bool bfs() {
    for (int i = 0; i <= n; i++) d[i] = 0;
    queue<int> q;
    q.push(s);
    d[s] = 1;
    while (q.size()) {
      int x = q.front();
      q.pop();
      for (int i = head[x]; i; i = ee[i].nxt) {
        int y = ee[i].to;
        long long w = ee[i].w;
        if (w && !d[y]) {
          q.push(y);
          d[y] = d[x] + 1;
          if (y == t) return 1;
        }
      }
    }
    return false;
  }
  inline int dinic(int x, int flow) {
    if (x == t) return flow;
    long long rest = flow, k;
    for (int i = now[x]; i && rest; i = ee[i].nxt) {
      int y = ee[i].to;
      long long w = ee[i].w;
      now[x] = i;
      if (w && d[y] == d[x] + 1) {
        k = dinic(y, min(rest, w));
        if (!k) d[y] = 0;
        ee[i].w -= k;
        ee[i ^ 1].w += k;
        rest -= k;
      }
    }
    return flow - rest;
  }
  inline void gao() {
    int flow = 0;
    while (bfs()) {
      for (int i = 0; i <= n; i++) now[i] = head[i];
      while (flow = dinic(s, 0x3f3f3f3f)) maxflow += flow;
    }
  }
  inline void init(int nn, int S, int T) {
    cnt = 1;
    maxflow = 0;
    for (int i = 0; i <= n; i++) head[i] = 0;
    s = S, t = T, n = nn;
  }
} D;
int n, m, s, t;
struct node {
  int x, y, w;
} p[M];
bool ck(int x) {
  s = 2 * n + 1, t = 2 * n + 2;
  D.init(n * 2 + 2, s, t);
  for (int i = 1; i <= m; i++) {
    if (p[i].w > x) continue;
    D.add(p[i].x, p[i].y + n, 1);
  }
  for (int i = 1; i <= n; i++) D.add(s, i, 1), D.add(i + n, t, 1);
  D.gao();
  if (D.maxflow == n) return true;
  return false;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    int w;
    scanf("%d%d%d", &x, &y, &w);
    p[i] = node{y, x, w};
  }
  int l = 1, r = 1e9, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ck(mid))
      r = mid - 1, ans = mid;
    else
      l = mid + 1;
  }
  cout << ans << endl;
  return 0;
}
