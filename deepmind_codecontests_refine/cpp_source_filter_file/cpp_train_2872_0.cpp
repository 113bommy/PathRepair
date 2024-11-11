#include <bits/stdc++.h>
using namespace std;
struct edge {
  int from, to;
  long long c;
};
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e5 + 5;
int N, Q, S;
vector<edge> G[MAXN * 9];
vector<int> IDS;
void getIDS(int x, int y, int id = 1, int l = 0, int r = N) {
  if (id == 1) IDS.clear();
  if (x == l && y == r) {
    IDS.push_back(id);
    return;
  }
  int M = (l + r) >> 1, L = id << 1, R = id | 1;
  if (y <= M)
    getIDS(x, y, L, l, M);
  else if (x >= M)
    getIDS(x, y, R, M, r);
  else {
    getIDS(x, M, L, l, M);
    getIDS(M, y, R, M, r);
  }
}
void build(int id = 1, int l = 0, int r = N) {
  if (l == r - 1) {
    G[l].push_back({l, 5 * N + id, 0});
    G[N + id].push_back({N + id, l, 0});
    return;
  }
  int M = (l + r) >> 1, L = id << 1, R = id | 1;
  G[N + id].push_back({N + id, N + L, 0});
  G[N + id].push_back({N + id, N + R, 0});
  G[5 * N + L].push_back({5 * N + L, 5 * N + id, 0});
  G[5 * N + R].push_back({5 * N + R, 5 * N + id, 0});
  build(L, l, M);
  build(R, M, r);
}
long long d[MAXN * 9];
void dijk() {
  memset(d, 0x3f, sizeof(d));
  d[S] = 0;
  priority_queue<pair<long long, int> > pq;
  pq.push({0, S});
  while (!pq.empty()) {
    int v = pq.top().second;
    long long dv = -pq.top().first;
    pq.pop();
    if (dv != d[v]) continue;
    for (int i = 0; i < (int)G[v].size(); i++) {
      int u = G[v][i].to;
      long long vu = G[v][i].c;
      if (d[u] > d[v] + vu) {
        d[u] = d[v] + vu;
        pq.push({-d[u], u});
      }
    }
  }
}
int main() {
  scanf("%d", &N);
  scanf("%d", &Q), scanf("%d", &S);
  S--;
  build();
  for (int _ = 0; _ < (int)Q; _++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int v, u, c;
      scanf("%d", &v), scanf("%d", &u);
      v--;
      u--;
      scanf("%d", &c);
      G[v].push_back({v, u, c});
    } else if (t == 2) {
      int v, l, r, c;
      scanf("%d", &v);
      scanf("%d", &l), scanf("%d", &r);
      v--;
      l--;
      r--;
      scanf("%d", &c);
      getIDS(l, r + 1);
      for (int i = 0; i < (int)IDS.size(); i++)
        G[v].push_back({v, N + IDS[i], c});
    } else {
      int v, l, r, c;
      scanf("%d", &v);
      scanf("%d", &l), scanf("%d", &r);
      v--;
      l--;
      r--;
      scanf("%d", &c);
      getIDS(l, r + 1);
      for (int i = 0; i < (int)IDS.size(); i++)
        G[5 * N + IDS[i]].push_back({5 * N + IDS[i], v, c});
    }
  }
  dijk();
  for (int i = 0; i < (int)N; i++) printf("%lld ", d[i] == INF ? -1 : d[i]);
  printf("\n");
}
