#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
const int inf = 0x3f3f3f3f;
int d[MAXN], now[MAXN], m, g, n, nodenum, a[MAXN], num[MAXN], h[MAXN], cnt = 1;
long long maxflow, ans = 0;
struct eage {
  int v, w, nxt;
} e[MAXN << 1];
void link(int x, int y, int w) {
  e[++cnt] = (eage){y, w, h[x]};
  h[x] = cnt;
  e[++cnt] = (eage){x, w, h[y]};
  h[y] = cnt;
}
bool bfs() {
  queue<int> q;
  memset(d, 0, sizeof(d));
  q.push(0);
  d[0] = 1;
  now[0] = h[0];
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = h[x]; i; i = e[i].nxt) {
      int y = e[i].v;
      if (!d[y] && e[i].w > 0) {
        d[y] = d[x] + 1;
        now[y] = h[y];
        q.push(y);
        if (y == 1) return 1;
      }
    }
  }
  return 0;
}
int dinic(int x, int flow) {
  if (x == 1) return flow;
  int res = flow;
  for (int i = now[x]; i && res; i = e[i].nxt) {
    int y = e[i].v;
    now[x] = i;
    if (d[y] == d[x] + 1 && e[i].w > 0) {
      int k = dinic(y, min(e[i].w, res));
      if (!k) d[y] = 0;
      res -= k;
      e[i].w -= k;
      e[i ^ 1].w += k;
    }
  }
  return flow - res;
}
int main() {
  scanf("%d %d %d", &n, &m, &g);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    int co;
    scanf("%d", &co);
    if (!a[i])
      link(0, i + 1, co);
    else
      link(i + 1, 1, co);
  }
  nodenum = n + 1;
  for (int i = 1; i <= m; i++) {
    int req, w, k, needpay;
    scanf("%d %d %d", &req, &w, &k);
    for (int j = 1; j <= k; j++) scanf("%d", &num[j]);
    scanf("%d", &needpay);
    ans += w;
    if (needpay) w += g;
    if (!req) {
      link(0, ++nodenum, w);
    } else {
      link(++nodenum, 1, w);
    }
    for (int j = 1; j <= k; j++) {
      if (!req) {
        link(nodenum, num[j] + 1, inf);
      } else {
        link(num[j] + 1, nodenum, inf);
      }
    }
  }
  int flow = 0;
  while (bfs())
    while (flow = dinic(0, inf)) maxflow += flow;
  printf("%lld\n", ans - maxflow);
  return 0;
}
