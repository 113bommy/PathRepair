#include <bits/stdc++.h>
using namespace std;
struct rect {
  int x1, y1, x2, y2;
  void in() { scanf("%d%d%d%d", &x1, &y1, &x2, &y2); }
} r[55];
bool tag[105][105];
namespace MF {
using flow_t = int;
const int N = 205, M = 2e4 + 5, inf = 1e9;
int cnt, head[N];
struct edge {
  int next, to, w;
} e[M << 1];
inline void addedge(int u, int v, int w) {
  e[++cnt] = {head[u], v, w};
  head[u] = cnt;
}
int n, s, t, d[N], cur[N];
flow_t maxflow;
void init(int _n, int _s, int _t) {
  n = _n, s = _s, t = _t;
  cnt = 1, maxflow = 0;
  memset(head, 0, (n + 1) << 2);
}
void add(int u, int v, int cap) { addedge(u, v, cap), addedge(v, u, 0); }
bool bfs() {
  memset(d, 0, (n + 1) << 2);
  memcpy(cur, head, (n + 1) << 2);
  queue<int> q;
  q.push(s);
  d[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].to;
      if (e[i].w && !d[v]) {
        d[v] = d[u] + 1;
        if (v == t) return 1;
        q.push(v);
      }
    }
  }
  return 0;
}
int dfs(int u, int flow) {
  if (u == t) return flow;
  int res = flow;
  for (int &i = cur[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (e[i].w && d[v] == d[u] + 1) {
      int low = dfs(v, min(flow, e[i].w));
      if (low) {
        e[i].w -= low, e[i ^ 1].w += low;
        flow -= low;
        if (!flow) break;
      } else
        d[v] = -1;
    }
  }
  return res - flow;
}
void go() {
  while (bfs()) maxflow += dfs(s, inf);
}
}  // namespace MF
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> lshx, lshy;
  for (int i = 1; i <= m; i++) {
    r[i].in();
    lshx.push_back(r[i].x1), lshx.push_back(r[i].x2 + 1);
    lshy.push_back(r[i].y1), lshy.push_back(r[i].y2 + 1);
  }
  sort(begin(lshx), end(lshx));
  lshx.resize(unique(begin(lshx), end(lshx)) - begin(lshx));
  sort(begin(lshy), end(lshy));
  lshy.resize(unique(begin(lshy), end(lshy)) - begin(lshy));
  int xsz = lshx.size(), ysz = lshy.size();
  MF::init(xsz + ysz + 2, xsz + ysz + 1, xsz + ysz + 2);
  for (int i = 0; i < xsz - 1; i++) MF::add(MF::s, i, lshx[i + 1] - lshx[i]);
  for (int i = 0; i < ysz - 1; i++)
    MF::add(xsz + i, MF::t, lshy[i + 1] - lshy[i]);
  for (int i = 1; i <= m; i++) {
    int xl = lower_bound(begin(lshx), end(lshx), r[i].x1) - begin(lshx),
        xr = lower_bound(begin(lshx), end(lshx), r[i].x2 + 1) - begin(lshx);
    int yl = lower_bound(begin(lshy), end(lshy), r[i].y1) - begin(lshy),
        yr = lower_bound(begin(lshy), end(lshy), r[i].y2 + 1) - begin(lshy);
    for (int a = xl; a < xr; a++)
      for (int b = yl; b < yr; b++)
        if (!tag[a][b]) MF::add(a, xsz + b, MF::inf), tag[a][b] = 1;
  }
  MF::go();
  printf("%d\n", MF::maxflow);
  return 0;
}
