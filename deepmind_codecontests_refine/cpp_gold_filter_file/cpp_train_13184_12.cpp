#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int Mod = 1000000007;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e = exp(1);
const double PI = acos(-1);
const double ERR = 1e-10;
int n, cnt;
int head[maxn];
long long d[maxn];
bool vis[maxn];
struct edge {
  int v, nxt;
  long long w;
} Edge[6 * maxn];
struct node {
  long long d;
  int id;
  node(long long _d, int _id) : d(_d), id(_id) {}
  const bool operator<(const node b) const { return d > b.d; }
};
void init() {
  for (int i = 0; i <= n; i++) head[i] = -1;
  cnt = 0;
}
void addedge(int u, int v, long long w) {
  Edge[cnt].v = v;
  Edge[cnt].w = w;
  Edge[cnt].nxt = head[u];
  head[u] = cnt++;
}
priority_queue<node> que;
void Dijkstra() {
  memset(d, 0x3f, sizeof(d));
  d[0] = 0;
  que.push(node(d[0], 0));
  while (!que.empty()) {
    node now = que.top();
    que.pop();
    if (vis[now.id]) continue;
    vis[now.id] = true;
    for (int i = head[now.id]; i != -1; i = Edge[i].nxt) {
      int v = Edge[i].v;
      long long w = Edge[i].w;
      if (d[v] > d[now.id] + w) {
        d[v] = d[now.id] + w;
        que.push(node(d[v], v));
      }
    }
  }
}
int main() {
  int m, u, v;
  long long w;
  scanf("%d%d", &n, &m);
  init();
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%lld", &u, &v, &w);
    addedge(u, v, 2 * w);
    addedge(v, u, 2 * w);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &w);
    addedge(0, i, w);
    addedge(i, 0, w);
  }
  Dijkstra();
  for (int i = 1; i <= n; i++) {
    if (i > 1) printf(" ");
    printf("%lld", d[i]);
  }
  return 0;
}
