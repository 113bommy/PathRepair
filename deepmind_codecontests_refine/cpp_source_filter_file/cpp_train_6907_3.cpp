#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 2e5 + 5;
const int inf = 1e9 + 5;
long long tot, nxt[M], head[M], edg[M], val[M];
long long n, m, s, u, v, w, dis[N], frm[N], ans[N], cnt;
bool vis[N];
priority_queue<pair<long long, long long> > q;
void add(long long u, long long v, long long w) {
  nxt[++tot] = head[u];
  head[u] = tot;
  edg[tot] = v;
  val[tot] = w;
}
void dijkstra() {
  for (long long i = 1; i <= n; i++) dis[i] = inf;
  dis[1] = 0;
  q.push(make_pair(-dis[1], 1));
  while (!q.empty()) {
    u = q.top().second;
    q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (long long i = head[u]; i; i = nxt[i]) {
      v = edg[i];
      if (dis[u] + val[i] < dis[v]) {
        dis[v] = dis[u] + val[i];
        frm[v] = u;
        if (!vis[v]) q.push(make_pair(-dis[v], v));
      }
    }
  }
}
int main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 1; i <= m; i++) {
    scanf("%lld%lld%lld", &u, &v, &w);
    add(u, v, w);
    add(v, u, w);
  }
  dijkstra();
  for (long long i = n; i; i = frm[i]) ans[++cnt] = i;
  if (ans[cnt] != 1) {
    puts("-1");
    return 0;
  }
  for (long long i = cnt; i >= 1; i--) printf("%lld ", ans[i]);
  return 0;
}
