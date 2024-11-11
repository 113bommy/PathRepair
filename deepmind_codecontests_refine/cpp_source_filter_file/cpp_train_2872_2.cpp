#include <bits/stdc++.h>
using namespace std;
const double pi = acos((double)-1.0);
const double eps = 1e-6;
const int INF_INT = 0x3f3f3f3f;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
const long long MOD = (1 ? 1000000007 : 998244353);
const int maxn = 100100, maxlg = 21;
const int LG = 4;
int n, m;
int lt[maxn << LG];
int idtot = 0;
struct Edge {
  int to, next;
  long long w;
} edge[maxn << LG];
int tot, head[maxn << LG];
void initedge() {
  tot = 0;
  memset(head, -1, sizeof(head));
}
void addedge(int u, int v, long long w_) {
  edge[tot].w = w_;
  edge[tot].to = v;
  edge[tot].next = head[u];
  head[u] = tot;
  ++tot;
}
void buildtreeout(int le, int ri, int rt) {
  if (le == ri) {
    addedge(le, rt, 0LL);
    return;
  }
  int mid = (le + ri) >> 1;
  addedge(++idtot, rt, 0LL);
  lt[rt - n] = idtot;
  addedge(++idtot, rt, 0LL);
  buildtreeout(le, mid, lt[rt - n]);
  buildtreeout(mid + 1, ri, lt[rt - n] + 1);
}
void buildtreein(int le, int ri, int rt) {
  if (le == ri) {
    addedge(rt, le, 0LL);
    return;
  }
  int mid = (le + ri) >> 1;
  addedge(rt, ++idtot, 0LL);
  lt[rt - n] = idtot;
  addedge(rt, ++idtot, 0LL);
  buildtreein(le, mid, lt[rt - n]);
  buildtreein(mid + 1, ri, lt[rt - n] + 1);
}
void addpin(int v, int l, int r, int le, int ri, int rt, long long w) {
  if (l <= le && ri <= r) {
    addedge(rt, v, w);
    return;
  }
  int mid = (le + ri) >> 1;
  if (l <= mid) addpin(v, l, r, le, mid, lt[rt - n], w);
  if (r > mid) addpin(v, l, r, mid + 1, ri, lt[rt - n] + 1, w);
}
void addpout(int u, int l, int r, int le, int ri, int rt, long long w) {
  if (l <= le && ri <= r) {
    addedge(u, rt, w);
    return;
  }
  int mid = (le + ri) >> 1;
  if (l <= mid) addpout(u, l, r, le, mid, lt[rt - n], w);
  if (r > mid) addpout(u, l, r, mid + 1, ri, lt[rt - n] + 1, w);
}
struct qnode {
  int v;
  long long c;
  qnode(int v_ = 0, long long c_ = 0) : v(v_), c(c_) {}
  bool operator<(const qnode& rhs) const { return c > rhs.c; }
};
int vis[maxn << LG];
long long dis[maxn << LG];
void dijkstra(int s) {
  memset(vis, 0, sizeof(vis));
  memset(dis, 0x3f, sizeof(dis));
  dis[s] = 0;
  priority_queue<qnode> pq;
  pq.push(qnode(s, 0));
  qnode now;
  long long cost;
  while (!pq.empty()) {
    now = pq.top();
    pq.pop();
    int u = now.v;
    if (vis[u] != 0) continue;
    vis[u] = 1;
    for (int id = head[u], v; id >= 0; id = edge[id].next) {
      v = edge[id].to;
      cost = edge[id].w;
      if (vis[v] == 0 && dis[v] > dis[u] + cost) {
        dis[v] = dis[u] + cost;
        pq.push(qnode(v, dis[v]));
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int s;
  cin >> n >> m >> s;
  initedge();
  idtot = n + 1;
  buildtreein(1, n, n + 1);
  buildtreeout(1, n, ++idtot);
  long long wei = 0;
  for (int i = 1, cmd, u, v, l, r; i <= m; ++i) {
    cin >> cmd;
    switch (cmd) {
      case 1:
        cin >> u >> v >> wei;
        addedge(u, v, wei);
        break;
      case 2:
        cin >> u >> l >> r >> wei;
        addpout(u, l, r, 1, n, n + 1, wei);
        break;
      case 3:
        cin >> v >> l >> r >> wei;
        addpin(v, l, r, 1, n, n * 3, wei);
    }
  }
  dijkstra(s);
  for (int i = 1; i <= n; ++i)
    if (dis[i] >= INF_LL)
      cout << "-1 ";
    else
      cout << dis[i] << ' ';
  cout << '\n';
  return 0;
}
