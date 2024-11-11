#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int LEN = 1010;
vector<pair<int, int> > Map[LEN];
pair<int, int> tax[LEN];
int n, m, x, y;
long long dis[LEN][LEN];
void Dij(int v) {
  int vis[LEN] = {0};
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      q;
  dis[v][v] = 0;
  q.push(make_pair(dis[v][v], v));
  while (!q.empty()) {
    pair<long long, int> nvex = q.top();
    q.pop();
    int nv = nvex.second;
    if (vis[nv]) continue;
    vis[nv] = 1;
    for (int i = 0; i < Map[nv].size(); i++) {
      int tx = Map[nv][i].first;
      long long ty = Map[nv][i].second;
      if (dis[v][tx] > dis[v][nv] + ty) {
        dis[v][tx] = dis[v][nv] + ty;
        q.push(make_pair(dis[v][tx], tx));
      }
    }
  }
}
long long solve() {
  for (int i = 0; i < LEN; i++) Map[i].clear();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (dis[i][j] <= tax[i].first) {
        Map[i].push_back(make_pair(j, tax[i].second));
      }
    }
  }
  memset(dis[x], 0x3f, sizeof dis[x]);
  Dij(x);
  if (dis[x][y] > INF * INF) return -1;
  return dis[x][y];
}
int main() {
  int a, b, c;
  while (scanf("%d%d", &n, &m) != EOF) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    for (int i = 0; i < LEN; i++) Map[i].clear();
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &a, &b, &c);
      a--;
      b--;
      Map[a].push_back(make_pair(b, c));
      Map[b].push_back(make_pair(a, c));
    }
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &tax[i].first, &tax[i].second);
    }
    memset(dis, 0x3f, sizeof dis);
    for (int i = 0; i < n; i++) Dij(i);
    long long ans = solve();
    printf("%I64d\n", ans);
  }
  return 0;
}
