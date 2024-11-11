#include <bits/stdc++.h>
using namespace std;
mt19937 gen(time(0));
const int maxn = 100010;
const int maxm = 300010;
const long long INF = 1e18;
struct E1 {
  int to, next, w;
} edge[maxm << 1];
int head[maxn], tol;
inline void Addedge(int u, int v, int w) {
  edge[tol].to = v;
  edge[tol].w = w;
  edge[tol].next = head[u];
  head[u] = tol++;
}
long long dis[maxn];
bool vis[maxn];
priority_queue<pair<long long, int>, vector<pair<long long, int> >,
               greater<pair<long long, int> > >
    Q;
void dijkstra(int k, int n) {
  fill(dis + k + 1, dis + n + 1, INF);
  for (int i = 1; i <= k; ++i) Q.push(make_pair(dis[i] = 0, i));
  while (!Q.empty()) {
    int u = Q.top().second;
    Q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (int i = head[u]; i != -1; i = edge[i].next) {
      int v = edge[i].to;
      if (!vis[v] && dis[v] > dis[u] + edge[i].w) {
        Q.push(make_pair(dis[v] = dis[u] + edge[i].w, v));
      }
    }
  }
  return;
}
struct E2 {
  int u, v;
  long long w;
  bool operator<(const E2& P) const { return w < P.w; }
} E[maxm];
long long ans[maxm];
vector<pair<int, int> > vec[maxn];
int fa[maxn];
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void unite(int x, int y, long long w) {
  int fx = find(x), fy = find(y);
  if (fx == fy) return;
  if (vec[fx].size() > vec[fy].size()) swap(fx, fy);
  for (pair<int, int>& elem : vec[fx]) {
    if (ans[elem.second]) continue;
    if (find(elem.first) == fy)
      ans[elem.second] = w;
    else
      vec[fy].push_back(elem);
  }
  fa[fx] = fy;
  return;
}
int main() {
  memset(head, -1, sizeof(head));
  int n, m, k, q, u, v, w;
  scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    Addedge(u, v, w);
    Addedge(v, u, w);
    E[i] = E2{u, v, w};
  }
  dijkstra(k, n);
  for (int i = 0; i < m; ++i) E[i].w += dis[E[i].u] + dis[E[i].v];
  sort(E, E + m);
  for (int i = 1; i <= n; ++i) fa[i] = i;
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &u, &v);
    vec[u].emplace_back(make_pair(v, i));
    vec[v].emplace_back(make_pair(u, i));
  }
  for (int i = 0; i < m; ++i) unite(E[i].u, E[i].v, E[i].w);
  for (int i = 0; i < q; ++i) printf("%lld\n", ans[i]);
  return 0;
}
