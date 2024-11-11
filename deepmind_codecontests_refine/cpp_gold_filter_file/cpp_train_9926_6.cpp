#include <bits/stdc++.h>
using namespace std;
const int inf = 987654321;
const long long int INF = 123456789987654321;
int N, M, K;
vector<vector<pair<int, int> > > adj;
vector<int> P;
vector<long long int> dist;
vector<int> par;
priority_queue<pair<long long int, long long int> > pq;
void dijkstra() {
  dist = vector<long long int>(N, INF);
  par = vector<int>(N, -1);
  for (int i = 0; i < K; i++) {
    pq.push(pair<long long int, long long int>(0, (long long int)P[i]));
    dist[P[i]] = 0;
    par[P[i]] = P[i];
  }
  while (!pq.empty()) {
    int now = (int)pq.top().second;
    long long int nowD = -pq.top().first;
    pq.pop();
    if (nowD > dist[now]) continue;
    for (int i = 0; i < adj[now].size(); i++) {
      int nxt = adj[now][i].first;
      long long int d = (long long int)adj[now][i].second;
      if (dist[nxt] > dist[now] + d) {
        dist[nxt] = dist[now] + d;
        par[nxt] = par[now];
        pq.push(
            pair<long long int, long long int>(-dist[nxt], (long long int)nxt));
      }
    }
  }
}
struct edge {
  int x, y;
  long long int w;
};
vector<edge> E1, E2;
void get_E2() {
  for (int i = 0; i < E1.size(); i++) {
    int x = par[E1[i].x], y = par[E1[i].y];
    long long int w = dist[E1[i].x] + E1[i].w + dist[E1[i].y];
    E2.push_back({x, y, w});
  }
}
struct DSU {
  int n;
  vector<int> par, rnk;
  void init(int n_) {
    n = n_;
    rnk = vector<int>(n, 0);
    for (int i = 0; i < n; i++) par.push_back(i);
  }
  int f(int u) {
    if (par[u] == u)
      return u;
    else
      return par[u] = f(par[u]);
  }
  void mrg(int u, int v) {
    u = f(u);
    v = f(v);
    if (u == v) return;
    if (rnk[u] < rnk[v]) swap(u, v);
    par[v] = u;
    if (rnk[u] == rnk[v]) rnk[u]++;
  }
} dsu;
bool cmp(edge a, edge b) { return a.w < b.w; }
long long int cost;
void kruskal() {
  dsu.init(N);
  cost = 0;
  sort((E2).begin(), (E2).end(), cmp);
  for (int i = 0; i < E2.size(); i++) {
    int x = E2[i].x, y = E2[i].y;
    long long int w = E2[i].w;
    if (dsu.f(x) == dsu.f(y)) continue;
    cost += w;
    dsu.mrg(x, y);
  }
}
int main() {
  scanf("%d %d", &N, &M);
  adj.resize(N);
  for (int i = 0; i < M; i++) {
    int x, y;
    long long int w;
    scanf("%d %d %I64d", &x, &y, &w);
    x--;
    y--;
    E1.push_back({x, y, w});
    adj[x].push_back(pair<int, int>(y, (int)w));
    adj[y].push_back(pair<int, int>(x, (int)w));
  }
  scanf("%d", &K);
  P.resize(K);
  for (int i = 0; i < K; i++) {
    scanf("%d", &P[i]);
    P[i]--;
  }
  dijkstra();
  get_E2();
  kruskal();
  printf("%I64d", cost + dist[0]);
}
