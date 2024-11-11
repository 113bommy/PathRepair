#include <bits/stdc++.h>
using namespace std;
const long long N = 405;
const long long oo = 0x7fffffff;
struct node {
  long long to, next, w;
} e1[N * N * 2];
struct no {
  long long x1, x2, y1, y2;
} e[N];
long long tot = -1, n, m, xx[N], yy[N], nx, ny, csx, csy, dep[N], ans, s, t,
          head[N];
void add(long long x, long long y, long long w) {
  tot++;
  e1[tot].to = y;
  e1[tot].w = w;
  e1[tot].next = head[x];
  head[x] = tot;
}
bool BFS() {
  memset(dep, 0, sizeof dep);
  queue<long long> q;
  q.push(s);
  dep[s] = 1;
  while (!q.empty()) {
    long long now = q.front();
    q.pop();
    for (register long long i = head[now]; i != -1; i = e1[i].next) {
      long long v = e1[i].to;
      if (!e1[i].w || dep[v]) continue;
      dep[v] = dep[now] + 1;
      if (v == t) return 1;
      q.push(v);
    }
  }
  return 0;
}
long long dfs(long long x, long long flow) {
  long long an = flow;
  if (x == t) return flow;
  for (register long long i = head[x]; i != -1 && an; i = e1[i].next) {
    long long v = e1[i].to;
    if (dep[v] != dep[x] + 1 || e1[i].w == 0) continue;
    long long pl = dfs(v, min(an, e1[i].w));
    an -= pl;
    e1[i].w -= pl;
    e1[i ^ 1].w += pl;
  }
  return flow - an;
}
long long read() {
  long long s = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') s = s * 10 + c - '0', c = getchar();
  return s * w;
}
int main() {
  memset(head, -1, sizeof head);
  n = read();
  m = read();
  for (register long long i = 1; i <= m; i++) {
    e[i].x1 = read();
    e[i].y1 = read();
    e[i].x2 = read();
    e[i].y2 = read();
    e[i].x2++;
    e[i].y2++;
    xx[++csx] = e[i].x1;
    xx[++csx] = e[i].x2;
    yy[++csy] = e[i].y1;
    yy[++csy] = e[i].y2;
  }
  xx[++csx] = n + 1;
  yy[++csy] = n + 1;
  sort(xx + 1, xx + 1 + csx);
  sort(yy + 1, yy + 1 + csy);
  nx = unique(xx + 1, xx + 1 + csx) - xx - 1;
  ny = unique(yy + 1, yy + 1 + csy) - yy - 1;
  s = 0;
  t = nx + ny + 1;
  for (register long long i = 1; i <= m; i++) {
    e[i].x1 = lower_bound(xx + 1, xx + 1 + nx, e[i].x1) - xx;
    e[i].x2 = lower_bound(xx + 1, xx + 1 + nx, e[i].x2) - xx;
    e[i].y1 = lower_bound(yy + 1, yy + 1 + ny, e[i].y1) - yy;
    e[i].y2 = lower_bound(yy + 1, yy + 1 + ny, e[i].y2) - yy;
    for (register long long j = e[i].x1; j < e[i].x2; j++)
      for (register long long k = e[i].y1; k < e[i].y2; k++)
        add(j, k + nx, oo), add(k + nx, j, 0);
  }
  for (register long long i = 1; i < nx; i++)
    add(s, i, xx[i + 1] - xx[i]), add(i, s, 0);
  for (register long long i = 1; i < ny; i++)
    add(i + nx, t, yy[i + 1] - yy[i]), add(t, i + nx, 0);
  while (BFS()) {
    ans += dfs(s, oo);
  }
  printf("%lld\n", ans);
  return 0;
}
