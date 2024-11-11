#include <bits/stdc++.h>
using namespace std;
struct edge {
  long long v, w;
  edge(long long v = 0, long long w = 0) : v(v), w(w) {}
};
struct cmp {
  bool operator()(edge x, edge y) { return x.w > y.w; }
};
void gg() {
  cout << "NO";
  exit(0);
}
long long n, m, l, s, t;
vector<edge> G[1005], G0[1005];
long long d[1005];
priority_queue<edge, vector<edge>, cmp> pq;
void dijkstra() {
  for (long long i = 0; i <= n; i++) d[i] = (1ll << 60);
  d[s] = 0;
  pq.push(edge(s, 0));
  while (pq.size()) {
    long long u = pq.top().v;
    long long dis = pq.top().w;
    pq.pop();
    if (dis != d[u]) continue;
    for (long long i = 0; i < G[u].size(); i++) {
      long long v = G[u][i].v;
      long long w = G[u][i].w;
      if (d[v] > dis + w) {
        d[v] = dis + w;
        pq.push(edge(v, d[v]));
      }
    }
  }
}
bool lt[1005], used[1005];
bool check[1005][1005];
vector<long long> wait;
void checklt(long long u, long long p) {
  lt[u] = 1;
  wait.push_back(u);
  for (long long i = 0; i < G[u].size(); i++) {
    long long v = G[u][i].v;
    if (v == p) continue;
    if (lt[v]) continue;
    checklt(v, u);
  }
}
int main() {
  scanf("%lld %lld %lld %lld %lld", &n, &m, &l, &s, &t);
  for (long long i = 1; i <= m; i++) {
    long long x, y, w;
    scanf("%lld %lld %lld", &x, &y, &w);
    if (!w)
      G0[x].push_back(edge(y, w)), G0[y].push_back(edge(x, w));
    else
      G[x].push_back(edge(y, w)), G[y].push_back(edge(x, w)), check[x][y] = 1,
                                                              check[y][x] = 1;
  }
  dijkstra();
  if (d[t] < l) gg();
  checklt(0, 0);
  for (long long i = 0; i < wait.size(); i++) {
    long long u = wait[i];
    for (long long j = 0; j < G0[u].size(); j++) {
      edge tmp = G0[u][j];
      if (check[u][tmp.v]) continue;
      G[u].push_back(edge(tmp.v, 1));
      G[tmp.v].push_back(edge(u, 1));
      check[u][tmp.v] = 1;
      check[tmp.v][u] = 1;
      if (!lt[tmp.v]) {
        lt[tmp.v] = 1;
        wait.push_back(tmp.v);
      }
      dijkstra();
      if (d[t] < l)
        G[u][G[u].size() - 1].w += l - d[t],
            G[tmp.v][G[tmp.v].size() - 1].w += l - d[t];
    }
  }
  dijkstra();
  if (d[t] != l) gg();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < G0[i].size(); j++) {
      if (check[i][G0[i][j].v]) continue;
      check[i][G0[i][j].v] = 1;
      check[G0[i][j].v][i] = 1;
      G[i].push_back(edge(G0[i][j].v, 1));
      G[G0[i][j].v].push_back(edge(i, 1));
    }
  }
  printf("YES\n");
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < G[i].size(); j++)
      if (i < G[i][j].v) printf("%lld %lld %lld\n", i, G[i][j].v, G[i][j].w);
  }
}
