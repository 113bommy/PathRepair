#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000 + 10;
const long long INF = 1LL << 60;
int n, h[maxn], ecnt, dep[maxn];
long long val[maxn];
struct enode {
  int v, n;
  long long w1, w2;
  enode() {}
  enode(int _v, int _n, long long _w1, long long _w2)
      : v(_v), n(_n), w1(_w1), w2(_w2) {}
} e[maxn << 1];
inline void addedge(int u, int v, long long w1, long long w2) {
  ecnt++;
  e[ecnt] = enode(v, h[u], w1, w2);
  h[u] = ecnt;
}
struct qnode {
  int u;
  long long w;
  qnode() {}
  qnode(int _u, long long _w) : u(_u), w(_w) {}
  friend bool operator<(qnode a, qnode b) { return a.w > b.w; }
};
inline void upmin(long long &x, long long y) { x = min(x, y); }
priority_queue<qnode> q;
long long d[maxn];
int vis[maxn];
inline void prepare() {
  while (!q.empty()) q.pop();
  int S = 0;
  d[S] = 0;
  for (int i = 1; i <= n; i++) {
    d[i] = val[i];
    q.push(qnode(i, d[i]));
  }
  while (!q.empty()) {
    qnode now = q.top();
    q.pop();
    int u = now.u;
    long long w = now.w;
    vis[u] = 1;
    if (d[u] < w) continue;
    for (int i = h[u]; ~i; i = e[i].n) {
      int v = e[i].v;
      if (vis[v]) continue;
      long long w = (long long)e[i].w1 + e[i].w2;
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        q.push(qnode(v, d[v]));
      }
    }
  }
}
long long dis[22][maxn][2][2];
int pre[22][maxn];
void dfs(int u, int fa) {
  dep[u] = dep[fa] + 1;
  for (int i = 1; i <= 20; i++) {
    pre[i][u] = pre[i - 1][pre[i - 1][u]];
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        dis[i][u][j][k] = INF;
        for (int l = 0; l < 2; l++) {
          upmin(dis[i][u][j][k],
                dis[i - 1][u][j][l] + dis[i - 1][pre[i - 1][u]][l][k]);
        }
      }
    }
  }
  for (int i = h[u]; ~i; i = e[i].n) {
    int v = e[i].v;
    if (v == fa) continue;
    pre[0][v] = u;
    dis[0][v][0][0] = min((long long)e[i].w1, (long long)d[u] + d[v] + e[i].w2);
    dis[0][v][1][1] = min((long long)e[i].w2, (long long)d[u] + d[v] + e[i].w1);
    dis[0][v][0][1] = min((long long)d[v] + e[i].w2, (long long)d[u] + e[i].w1);
    dis[0][v][1][0] = min((long long)d[v] + e[i].w1, (long long)d[u] + e[i].w2);
    dfs(v, u);
  }
}
inline int LCA(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int d = dep[u] - dep[v];
  for (int i = 0; i <= 20; i++)
    if (d & (1 << i)) u = pre[i][u];
  if (u == v) return u;
  for (int i = 20; i >= 0; i--)
    if (pre[i][u] != pre[i][v]) {
      u = pre[i][u];
      v = pre[i][v];
    }
  return pre[0][u];
}
inline pair<long long, long long> work(int u, int v, int k) {
  int d = dep[u] - dep[v];
  long long now[2];
  now[k] = 0;
  now[k ^ 1] = val[u];
  for (int i = 0; i <= 20; i++) {
    if (d & (1 << i)) {
      long long tmp[2] = {INF, INF};
      for (int j = 0; j < 2; j++) {
        upmin(tmp[j], now[j] + dis[i][u][j][j]);
        upmin(tmp[j], now[j ^ 1] + dis[i][u][j ^ 1][j]);
      }
      u = pre[i][u];
      now[0] = tmp[0];
      now[1] = tmp[1];
    }
  }
  return make_pair(now[0], now[1]);
}
int main() {
  scanf("%d", &n);
  ecnt = 0;
  memset(h, -1, sizeof(h));
  for (int i = 1; i <= n; i++) scanf("%I64d", &val[i]);
  for (int i = 1; i < n; i++) {
    int u, v;
    long long w1, w2;
    scanf("%d%d%I64d%I64d", &u, &v, &w1, &w2);
    addedge(u, v, w1, w2);
    addedge(v, u, w1, w2);
  }
  prepare();
  dfs(1, 0);
  int Q;
  scanf("%d", &Q);
  for (int i = 1; i <= Q; i++) {
    int x, y, u, v, ku, kv;
    scanf("%d%d", &x, &y);
    u = (x + 1) >> 1;
    v = (y + 1) >> 1;
    ku = (x + 1) & 1;
    kv = (y + 1) & 1;
    int lca = LCA(u, v);
    pair<long long, long long> t1 = work(u, lca, ku);
    pair<long long, long long> t2 = work(v, lca, kv);
    long long Ans = min(t1.first + t2.first, t1.second + t2.second);
    printf("%I64d\n", Ans);
  }
  return 0;
}
