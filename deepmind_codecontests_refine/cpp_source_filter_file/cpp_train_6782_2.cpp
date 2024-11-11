#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
namespace MaxFlow {
const int maxn = 3575;
const int maxm = maxn * 4 + maxn * 100;
struct node {
  int to, next;
  long long c;
} e[maxm];
int hd[maxn], cnt, n, cur[maxn], dis[maxn], q[maxn], l, r, x;
void addedge(int x, int y, long long c) {
  e[++cnt] = (node){y, hd[x], c}, hd[x] = cnt;
  e[++cnt] = (node){x, hd[y], 0}, hd[y] = cnt;
}
bool bfs() {
  for (int i = 1; i <= n; i++) dis[i] = 0;
  dis[1] = 1, q[l = r = 1] = 1;
  while (l <= r) {
    x = q[l++];
    for (int i = hd[x]; i; i = e[i].next)
      if (e[i].c > 0 && !dis[e[i].to])
        dis[e[i].to] = dis[x] + 1, q[++r] = e[i].to;
  }
  return (dis[n] > 0);
}
long long dinic(int x, long long f) {
  if (x == n) return f;
  for (int &i = cur[x]; i; i = e[i].next)
    if (e[i].c > 0 && dis[e[i].to] == dis[x] + 1) {
      long long nw = dinic(e[i].to, min(f, e[i].c));
      if (nw > 0) return e[i].c -= nw, e[i ^ 1].c += nw, nw;
    }
  return 0;
}
long long solve() {
  long long ans = 0, nw;
  while (bfs()) {
    for (int i = 1; i <= n; i++) cur[i] = hd[i];
    while (nw = dinic(1, inf)) ans += nw;
  }
  return ans;
}
}  // namespace MaxFlow
int h, n, m;
int Point(int x, int y) { return 1 + (x - 1) * (h + 2) + y; }
int main() {
  cin >> n >> h >> m;
  int T = n * (h + 2) + 2 + m;
  MaxFlow::n = T, MaxFlow::cnt = 1;
  for (int i = 1; i <= n; i++) {
    MaxFlow::addedge(1, Point(i, 1), inf);
    MaxFlow::addedge(Point(i, h + 2), T, inf);
  }
  for (int i = 2; i <= h + 2; i++) {
    for (int j = 1; j <= n; j++) {
      MaxFlow::addedge(Point(j, i - 1), Point(j, i), h * h - (i - 2) * (i - 2));
    }
  }
  int cnt = n * (h + 2);
  int l, r, x, c;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d%d", &l, &r, &x, &c);
    ++cnt;
    for (int j = l; j <= r; j++) {
      MaxFlow::addedge(Point(j, x + 2), cnt, inf);
    }
    MaxFlow::addedge(cnt, T, c);
  }
  long long ans = n * h * h;
  ans -= MaxFlow::solve();
  cout << ans;
  return 0;
}
