#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int maxm = 100010;
const long long INF = 1e12;
const long long mod = 1e9 + 13;
int n, m, s, t;
int head[maxn];
int pre[maxm];
int _head[maxn];
int _pre[maxm];
int cnt;
void init() {
  memset(head, -1, sizeof(head));
  memset(_head, -1, sizeof(_head));
  cnt = 1;
}
void addedge(int u, int v) {
  pre[cnt] = head[u];
  head[u] = cnt;
  _pre[cnt] = _head[v];
  _head[v] = cnt;
  cnt++;
}
int a[maxm];
int b[maxm];
int l[maxm];
long long dist_s[maxn];
long long dist_t[maxn];
long long way_s[maxn];
long long way_t[maxn];
bool vis[maxn];
struct node {
  int u;
  long long dist;
  node(int u, long long dist) : u(u), dist(dist) {}
  node() {}
  bool operator<(const node &other) const { return dist > other.dist; }
};
void dijkstra(int s, long long *d, long long *w, int *head, int *pre) {
  for (int i = 1; i <= n; i++) {
    d[i] = INF;
  }
  w[s] = 1;
  d[s] = 0;
  priority_queue<node> pq;
  pq.push(node(s, 0));
  while (pq.size()) {
    node cur = pq.top();
    pq.pop();
    if (vis[cur.u]) continue;
    for (int i = head[cur.u]; i != -1; i = pre[i]) {
      int v = b[i];
      long long tmp = d[v];
      if (d[cur.u] + l[i] < d[v]) {
        w[v] = w[cur.u];
        tmp = d[cur.u] + l[i];
        d[v] = tmp;
        pq.push(node(v, tmp));
      } else if (d[cur.u] + l[i] == d[v]) {
        w[v] += w[cur.u];
        d[v] = tmp;
      }
      w[v] %= mod;
    }
    vis[cur.u] = 1;
  }
}
int main() {
  init();
  cin >> n >> m >> s >> t;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &a[i], &b[i], &l[i]);
    addedge(a[i], b[i]);
  }
  dijkstra(s, dist_s, way_s, head, pre);
  for (int i = 1; i <= m; i++) swap(a[i], b[i]);
  memset(vis, 0, sizeof(vis));
  dijkstra(t, dist_t, way_t, _head, _pre);
  for (int i = 1; i <= m; i++) swap(a[i], b[i]);
  for (int i = 1; i <= m; i++) {
    long long need = dist_s[a[i]] + dist_t[b[i]] + l[i] - dist_s[t];
    if (0 == need && (way_s[a[i]] * way_t[b[i]]) % mod == way_s[t]) {
      printf("YES\n");
    } else {
      if (l[i] - need - 1 > 0) {
        printf("CAN %I64d\n", need + 1);
      } else {
        printf("NO\n");
      }
    }
  }
  return 0;
}
