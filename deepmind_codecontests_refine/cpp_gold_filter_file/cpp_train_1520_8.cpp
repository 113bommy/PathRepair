#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
const int delta = 500000;
const int INF = 1e9;
int n, q, tot, lef[MAXN];
struct Line {
  int up, dw, col, typ;
} lines[MAXN];
class NetworkFlow {
 private:
  int s, t;
  int dep[MAXN], iter[MAXN];
  struct Edge {
    int to;
    long long cap;
    int rev;
  };
  std::vector<Edge> G[MAXN];
  std::queue<int> q;
  inline bool bfs(int s, int t) {
    memset(dep, -1, sizeof(dep));
    dep[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (Edge e : G[u])
        if (e.cap && dep[e.to] == -1) dep[e.to] = dep[u] + 1, q.push(e.to);
    }
    return dep[t] != -1;
  }
  long long dfs(int u, int t, long long flow) {
    if (u == t) return flow;
    int sz = G[u].size();
    for (int &i = iter[u]; i < sz; i++) {
      Edge &e = G[u][i];
      if (e.cap && dep[e.to] > dep[u]) {
        long long d = dfs(e.to, t, std::min(flow, e.cap));
        if (d > 0) {
          e.cap -= d, G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

 public:
  inline void add_edge(int u, int v, int w) {
    G[u].push_back((Edge){v, w, (int)G[v].size()});
    G[v].push_back((Edge){u, 0, (int)G[u].size() - 1});
  }
  inline long long dinic() {
    long long flow = 0, res = 0;
    while (bfs(s, t)) {
      memset(iter, 0, sizeof(iter));
      while ((flow = dfs(s, t, 0x3f3f3f3f3f3f3f3f)) != 0) res += flow;
    }
    return res;
  }
  inline void init(int bg, int ed) { s = bg, t = ed; }
  inline int get_s() { return s; }
  inline int get_t() { return t; }
} net;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    (x *= 10) += ch - '0';
    ch = getchar();
  }
  return x * f;
}
void build(int p, int l, int r, int typ) {
  if (l == r) {
    if (typ == 0) net.add_edge(net.get_s(), p, 1);
    if (typ == 1) net.add_edge(p + delta, net.get_t(), 1);
    return;
  }
  int mid = (l + r) >> 1;
  build(p << 1, l, mid, typ);
  build(p << 1 | 1, mid + 1, r, typ);
  if (typ == 0)
    net.add_edge(p << 1, p, (int)1e9), net.add_edge(p << 1 | 1, p, (int)1e9);
  if (typ == 1)
    net.add_edge(p + delta, (p << 1) + delta, (int)1e9),
        net.add_edge(p + delta, (p << 1 | 1) + delta, (int)1e9);
}
void get(int p, int l, int r, int typ, int ql, int qr,
         vector<pair<int, int> > &s) {
  if (ql <= l && r <= qr) {
    if (typ == 0) s.push_back(make_pair(p, r - l + 1));
    if (typ == 1) s.push_back(make_pair(p + delta, r - l + 1));
    return;
  }
  int mid = (l + r) >> 1;
  if (ql <= mid) get(p << 1, l, mid, typ, ql, qr, s);
  if (qr > mid) get(p << 1 | 1, mid + 1, r, typ, ql, qr, s);
}
inline void connect(int x, int y, int l, int r) {
  vector<pair<int, int> > A, B;
  get(1, 1, n, 0, x, y, A);
  get(1, 1, n, 1, l, r, B);
  for (auto pi1 : A)
    for (auto pi2 : B)
      net.add_edge(pi1.first, pi2.first, pi1.second * pi2.second);
}
int main() {
  n = read(), q = read();
  net.init(0, 1000003);
  build(1, 1, n, 0), build(1, 1, n, 1);
  for (int i = 1, xl, yl, xr, yr; i <= q; i++) {
    xl = read(), yl = read(), xr = read(), yr = read();
    lines[++tot] = {xl, xr, yl, 0}, lines[++tot] = {xl, xr, yr, 1};
  }
  lines[++tot] = {1, n, n + 1, 0}, lines[++tot] = {1, n, n + 1, 1};
  sort(lines + 1, lines + tot + 1, [](Line x, Line y) {
    return x.col != y.col ? x.col < y.col : x.typ < y.typ;
  });
  for (int i = 1; i <= tot; i++) {
    if (lines[i].typ == 1)
      for (int j = lines[i].up; j <= lines[i].dw; j++) lef[j] = lines[i].col;
    if (lines[i].typ == 0)
      for (int j = lines[i].up, lst_w = lines[i].col - 1, lst_h = 0;
           j <= lines[i].dw + 1; j++)
        if (j == lines[i].dw + 1 || lef[j] != lst_w) {
          if (lst_w + 1 < lines[i].col)
            connect(lst_h, j - 1, lst_w + 1, lines[i].col - 1);
          lst_w = lef[j], lst_h = j;
        }
  }
  printf("%lld\n", net.dinic());
  return 0;
}
