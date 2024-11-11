#include <bits/stdc++.h>
using namespace std;
const long long PRIME = 23456789;
const long long MOD = 0xdeaddeadbeefULL;
const long long mod = 2147493647;
const double eps = 1e-7;
const int inf = 0x3f3f3f3f;
const long long infl = 1e16;
const int maxn = 1000 + 10;
const int maxm = 40000 + 10;
struct node {
  int st, u;
  long long dis;
};
vector<pair<int, int> > G[maxn];
bool vis[maxn][maxn];
int r[maxn], c[maxn];
vector<pair<int, int> > G2[maxn];
long long dis[maxn];
bool dj[maxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int x, y;
  scanf("%d%d", &x, &y);
  while (m--) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    G[u].push_back(make_pair(v, w));
    G[v].push_back(make_pair(u, w));
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &r[i], &c[i]);
    dis[i] = 1e16;
  }
  queue<node> q;
  for (int i = 1; i <= n; ++i) {
    q.push((node){i, i, 0});
    G2[i].clear();
  }
  while (!q.empty()) {
    node no = q.front();
    q.pop();
    int u = no.u, st = no.st;
    long long dist = no.dis;
    if (vis[st][u]) continue;
    vis[st][u] = 1;
    if (u != st) G2[st].push_back(make_pair(u, c[st]));
    long long mx = r[st];
    for (int i = 0; i < G[u].size(); ++i) {
      pair<int, int> p = G[u][i];
      int to = p.first, w = p.second;
      if (dist + w <= 1LL * mx && !vis[st][to]) {
        q.push((node){st, to, dist + w});
      }
    }
  }
  dis[x] = 0;
  priority_queue<pair<long long, int> > Q;
  Q.push(make_pair(0, x));
  while (!Q.empty()) {
    pair<long long, int> p = Q.top();
    Q.pop();
    int u = p.second;
    if (dj[u]) continue;
    dj[u] = 1;
    int sz = G2[u].size();
    for (int i = 0; i < sz; ++i) {
      pair<int, int> pp = G2[u][i];
      int to = pp.first, w = pp.second;
      if (dis[to] > dis[u] + w && !dj[to]) {
        dis[to] = dis[i] + w;
        Q.push(make_pair(-dis[to], to));
      }
    }
  }
  if (dis[y] < 1e16)
    printf("%lld", dis[y]);
  else
    puts("-1");
  return 0;
}
