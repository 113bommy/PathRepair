#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const double PI = acos(-1.);
const double eps = 1e-10;
const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const int MX = 2222;
const int MXE = 4 * MX * MX;
struct MaxFlow {
  struct Edge {
    int v, w, nxt;
  } edge[MXE];
  int tot, num, s, t;
  int head[MX];
  void init() {
    memset(head, -1, sizeof(head));
    tot = 0;
  }
  void add(int u, int v, int w) {
    edge[tot].v = v;
    edge[tot].w = w;
    edge[tot].nxt = head[u];
    head[u] = tot++;
    edge[tot].v = u;
    edge[tot].w = 0;
    edge[tot].nxt = head[v];
    head[v] = tot++;
  }
  int d[MX], vis[MX], gap[MX];
  void bfs() {
    memset(d, 0, sizeof(d));
    memset(gap, 0, sizeof(gap));
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(t);
    vis[t] = 1;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if (!vis[v]) {
          d[v] = d[u] + 1;
          gap[d[v]]++;
          q.push(v);
          vis[v] = 1;
        }
      }
    }
  }
  int last[MX];
  int dfs(int u, int f) {
    if (u == t) return f;
    int sap = 0;
    for (int i = last[u]; ~i; i = edge[i].nxt) {
      int v = edge[i].v;
      if (edge[i].w > 0 && d[u] == d[v] + 1) {
        last[u] = i;
        int tmp = dfs(v, min(f - sap, edge[i].w));
        edge[i].w -= tmp;
        edge[i ^ 1].w += tmp;
        sap += tmp;
        if (sap == f) return sap;
      }
    }
    if (d[s] >= num) return sap;
    if (!(--gap[d[u]])) d[s] = num;
    ++gap[++d[u]];
    last[u] = head[u];
    return sap;
  }
  int solve(int st, int ed, int n) {
    int flow = 0;
    num = n;
    s = st;
    t = ed;
    bfs();
    memcpy(last, head, sizeof(head));
    while (d[s] < num) flow += dfs(s, inf);
    return flow;
  }
} F;
int deg[MAXN];
int col[MAXN];
vector<int> G[666];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    F.init();
    for (int i = 1; i <= n; i++) {
      G[i].clear();
      deg[i] = 0;
    }
    int st = 0, en = n + m + 1, f = 0;
    for (int i = 1; i <= m; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      deg[x]++;
      deg[y]++;
      F.add(x, i + n, 1);
      G[x].push_back(F.tot - 1);
      F.add(y, i + n, 1);
      G[y].push_back(F.tot - 1);
      F.add(i + n, en, 1);
      col[i] = 0;
    }
    int ok = 1;
    for (int i = 1; i <= n; i++) {
      if (deg[i] > 2 * k) ok = 0;
      if (deg[i] > k) F.add(st, i, 2 * (deg[i] - k)), f += 2 * (deg[i] - k);
    }
    if (!ok || f != F.solve(st, en, n)) {
      for (int i = 1; i <= m; i++) printf("0 ");
      puts("");
    } else {
      int tot = 0;
      for (int i = 1; i <= n; i++) {
        vector<int> v;
        for (int j : G[i])
          if (F.edge[j].w > 0) v.push_back(j);
        if (v.size())
          for (int j = 1; j < v.size(); j += 2) {
            col[F.edge[v[j] ^ 1].v - n] = col[F.edge[v[j - 1] ^ 1].v - n] =
                ++tot;
          }
      }
      for (int i = 1; i <= m; i++) {
        if (!col[i]) col[i] = ++tot;
        printf("%d ", col[i]);
      }
      puts("");
    }
  }
  return 0;
}
