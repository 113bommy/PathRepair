#include <bits/stdc++.h>
using namespace std;
const long long maxn = 600005;
struct node {
  long long next, to, val;
} edge[maxn];
long long head[maxn];
long long tot = 0;
long long n, m;
void add(long long u, long long v, long long val) {
  edge[++tot].to = v;
  edge[tot].val = val;
  edge[tot].next = head[u];
  head[u] = tot;
}
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               greater<pair<long long, long long> > >
    qp;
long long dis[maxn];
long long vis[maxn];
void dijkstra(long long src) {
  while (!qp.empty()) qp.pop();
  for (long long i = 1; i <= n; ++i) {
    dis[i] = 2 << 30;
    vis[i] = 0;
  }
  dis[src] = 0;
  qp.push({0, src});
  while (!qp.empty()) {
    pair<long long, long long> t = qp.top();
    qp.pop();
    long long u = t.second;
    if (vis[u]) continue;
    vis[u] = 1;
    for (long long i = head[u]; i; i = edge[i].next) {
      if (dis[edge[i].to] > dis[u] + edge[i].val) {
        dis[edge[i].to] = dis[u] + edge[i].val;
        qp.push({dis[edge[i].to], edge[i].to});
      }
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    long long x, y, z;
    cin >> x >> y >> z;
    add(x, y, z * 2);
    add(y, x, z * 2);
  }
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    add(0, i, x);
  }
  dijkstra(0);
  for (long long i = 1; i <= n; i++) cout << dis[i] << ' ';
}
