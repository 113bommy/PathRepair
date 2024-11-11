#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline void read(int &x) {
  char c = nc();
  x = 0;
  for (; c > '9' || c < '0'; c = nc())
    ;
  for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = nc())
    ;
}
int n, m, q, cnt, G[N];
struct edge {
  int t, nx;
} E[N << 1];
inline void addedge(int x, int y) {
  E[++cnt].t = y;
  E[cnt].nx = G[x];
  G[x] = cnt;
  E[++cnt].t = x;
  E[cnt].nx = G[y];
  G[y] = cnt;
}
int t, c[N], k[N], p[N], id[N];
inline bool cmp(const int &x, const int &y) { return p[x] < p[y]; }
int dis[N];
const int inf = 1 << 29;
priority_queue<pair<int, int> > Q;
inline void spfa(int S) {
  for (int i = 1; i <= n; i++) dis[i] = inf;
  dis[S] = 0;
  Q.push(pair<int, int>(-dis[S], S));
  while (!Q.empty()) {
    int d = -Q.top().first, x = Q.top().second;
    Q.pop();
    if (dis[x] != d) continue;
    for (int i = G[x]; i; i = E[i].nx)
      if (dis[E[i].t] > dis[x] + 1) {
        dis[E[i].t] = dis[x] + 1;
        Q.push(pair<int, int>(-dis[E[i].t], E[i].t));
      }
  }
}
int main() {
  read(n);
  read(m);
  for (int i = 1, x, y; i <= m; i++) read(x), read(y), addedge(x, y);
  read(t);
  for (int i = 1; i <= t; i++) read(c[i]), read(k[i]), read(p[i]), id[i] = i;
  sort(id + 1, id + 1 + t);
  read(q);
  while (q--) {
    int g, rr, a;
    read(g);
    read(rr);
    read(a);
    spfa(g);
    int l = 0, r = n, ans = -1;
    while (l <= r) {
      int mid = l + r >> 1, ct = rr;
      long long sum = 0;
      for (int i = 1; i <= n && ct; i++)
        if (dis[c[id[i]]] <= mid) {
          sum += 1LL * min(ct, k[id[i]]) * p[id[i]];
          ct -= min(ct, k[id[i]]);
        }
      if (sum <= a && !ct)
        r = (ans = mid) - 1;
      else
        l = mid + 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
