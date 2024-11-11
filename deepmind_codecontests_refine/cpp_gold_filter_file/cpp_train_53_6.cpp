#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
const int N = 2002, M = (1 << 20), Q = 1001, S = 2 * M;
struct Edge {
  int u, v, w;
  Edge(int u = 0, int v = 0, int w = 0) : v(v), u(u), w(w) {}
  bool operator<(const Edge &e) const { return w < e.w; }
};
struct Segment {
  int l, r;
  Segment(int l = 0, int r = 0) : l(l), r(r) {}
};
int n, m, q;
Edge es[M];
vector<Edge> seg[S];
Segment range[S];
int par[N], cost[N], PAP[N];
Segment merge(Segment l, Segment r) { return Segment(l.l, r.r); }
void clear(vector<Edge> &es) {
  for (Edge e : es) {
    par[e.v] = par[e.u] = -1;
    cost[e.v] = cost[e.u] = 0;
    PAP[e.v] = PAP[e.u] = 1;
  }
}
int root(int v) {
  if (par[v] == -1) return v;
  int u = root(par[v]);
  cost[v] ^= cost[par[v]];
  return par[v] = u;
}
int parity(int v) {
  root(v);
  return cost[v];
}
int merge(Edge e) {
  if (PAP[root(e.u)] > PAP[root(e.v)]) swap(e.u, e.v);
  if (root(e.u) == root(e.v)) {
    if (parity(e.u) == parity(e.v)) return 2;
    return 0;
  }
  int u = root(e.u);
  int v = root(e.v);
  cost[u] ^= (parity(e.u) ^ 1 ^ parity(e.v));
  par[u] = root(v);
  PAP[v] += PAP[u];
  return 1;
}
bool hasOddCycle;
vector<Edge> merge(vector<Edge> &a, vector<Edge> &b) {
  vector<Edge> c;
  merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));
  clear(c);
  vector<Edge> res;
  for (int i = c.size() - 1; i >= 0; i--) {
    int x = merge(c[i]);
    if (x) res.push_back(c[i]);
    if (x == 2) {
      hasOddCycle = 1;
      break;
    }
  }
  reverse(res.begin(), res.end());
  return res;
}
void make() {
  for (int i = S - 1; i; i--) {
    if (i >= M) {
      range[i] = Segment(i - M, i - M + 1);
      if (i - M < m) seg[i].push_back(es[i - M]);
    } else {
      range[i] = merge(range[i * 2], range[i * 2 + 1]);
      seg[i] = merge(seg[i * 2], seg[i * 2 + 1]);
    }
  }
}
int solve(Segment s) {
  vector<Edge> es;
  hasOddCycle = 0;
  for (int l = s.l + M, r = s.r + M; l < r; l /= 2, r /= 2) {
    if (l % 2) es = merge(es, seg[l++]);
    if (r % 2) es = merge(es, seg[--r]);
  }
  if (hasOddCycle) return es[0].w;
  return -1;
}
int main() {
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    es[i].u = in() - 1;
    es[i].v = in() - 1;
    es[i].w = in();
  }
  make();
  while (q--) {
    int l = in() - 1, r = in();
    cout << solve(Segment(l, r)) << "\n";
  }
}
