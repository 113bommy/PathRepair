#include <bits/stdc++.h>
using namespace std;
template <class T>
void checkmin(T &t, T x) {
  if (x < t) t = x;
}
template <class T>
void checkmax(T &t, T x) {
  if (x > t) t = x;
}
struct MinCostMaxFlow {
  struct edge {
    int x, y, c, w;
    edge *next, *op;
  } g[440000], *ls[405], *fa[405];
  int n, S, T, flow, cost, e;
  int d[405], inQ[405];
  void init(int _n, int _S, int _T) {
    n = _n;
    S = _S;
    T = _T;
    e = 0;
    for (int i = 0; i < n; i++) ls[i] = NULL;
  }
  void addedge(int x, int y, int c, int w = 0) {
    g[e].x = x;
    g[e].y = y;
    g[e].c = c;
    g[e].w = w;
    g[e].op = &g[e + 1];
    g[e].next = ls[x];
    ls[x] = &g[e++];
    g[e].x = y;
    g[e].y = x;
    g[e].c = 0;
    g[e].w = -w;
    g[e].op = &g[e - 1];
    g[e].next = ls[y];
    ls[y] = &g[e++];
  }
  bool spfa() {
    queue<int> q;
    for (int i = 0; i < n; i++) {
      d[i] = 0x7FFFFFFF;
      inQ[i] = 0;
    }
    q.push(S);
    d[S] = 0;
    inQ[S] = 1;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      inQ[x] = 0;
      for (edge *t = ls[x]; t; t = t->next) {
        if (t->c && d[t->x] + t->w < d[t->y]) {
          d[t->y] = d[t->x] + t->w;
          fa[t->y] = t;
          if (!inQ[t->y]) {
            inQ[t->y] = 1;
            q.push(t->y);
          }
        }
      }
    }
    return d[T] != 0x7FFFFFFF;
  }
  void aug() {
    int nf = 0x7FFFFFFF;
    for (int i = T; i != S; i = fa[i]->x) checkmin(nf, fa[i]->c);
    for (int i = T; i != S; i = fa[i]->x) {
      fa[i]->c -= nf;
      fa[i]->op->c += nf;
    }
    flow += nf;
    cost += nf * d[T];
  }
  void MCMF() {
    flow = cost = 0;
    while (spfa()) {
      aug();
    }
  }
} flow;
const int N = 405;
int n, m, k, t;
int deg[N], tag[N];
int color[N][N];
vector<pair<int, int> > edge;
int main() {
  memset(color, 0xFF, sizeof(color));
  scanf("%d%d%d%d", &n, &m, &k, &t);
  for (int x, y, i = 0; i < k; i++) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    edge.push_back(pair<int, int>(x, y));
    deg[x]++;
    deg[n + y]++;
    color[x][n + y] = -2;
  }
  int ans = 0;
  for (int i = 0; i < m + n; i++) {
    ans += !!(deg[i] % t);
  }
  printf("%d\n", ans);
  for (int _i = t; _i >= 1; _i--) {
    int S = n + m;
    int T = n + m + 1;
    flow.init(n + m + 2, n + m, n + m + 1);
    for (int j = 0; j < n; j++) {
      flow.addedge(S, j, deg[j] / _i);
      if (deg[j] % _i) flow.addedge(S, j, 1, 1);
    }
    for (int j = 0; j < m; j++) {
      flow.addedge(n + j, T, deg[n + j] / _i);
      if (deg[n + j] % _i) flow.addedge(n + j, T, 1, 1);
    }
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        if (color[j][n + k] == -2) {
          flow.addedge(j, n + k, 1);
        }
      }
    }
    flow.MCMF();
    for (int i = 1; i < flow.e; i += 2) {
      if (flow.g[i].x < S && flow.g[i].y < S && flow.g[i].c) {
        color[flow.g[i].y][flow.g[i].x] = _i;
        deg[flow.g[i].y]--;
        deg[flow.g[i].x]--;
      }
    }
  }
  for (__typeof((edge).begin()) it = (edge).begin(); it != (edge).end(); it++) {
    printf("%d ", color[it->first][it->second + n]);
  }
}
