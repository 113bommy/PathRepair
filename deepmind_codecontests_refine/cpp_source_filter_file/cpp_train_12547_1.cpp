#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
typedef class TwoSatisfiction {
 public:
  int n;
  int dfc, cscc;
  stack<int> stk;
  vector<int> dfn, low;
  vector<bool> vis, ins;
  vector<vector<int>> G;
  vector<int> bel;
  void init(int _n) {
    n = _n << 1;
    dfc = 0;
    cscc = 0;
    G.assign(n, vector<int>());
    dfn.assign(n, -1);
    low.assign(n, -1);
    vis.assign(n, false);
    ins.assign(n, false);
    while (!stk.empty()) stk.pop();
    bel.assign(n, -1);
  }
  void tarjan(int p) {
    dfn[p] = low[p] = dfc++;
    vis[p] = ins[p] = true;
    stk.push(p);
    for (auto e : G[p]) {
      if (!vis[e]) {
        tarjan(e);
        low[p] = min(low[p], low[e]);
      } else if (ins[e]) {
        low[p] = min(low[p], dfn[e]);
      }
    }
    if (dfn[p] == low[p]) {
      int e = -1;
      do {
        e = stk.top();
        stk.pop();
        bel[e] = cscc;
        ins[e] = false;
        low[e] = low[p];
      } while (e ^ p);
      cscc++;
    }
  }
  void do_tarjan() {
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        tarjan(i);
      }
    }
  }
  bool has_solution() {
    for (int i = 0; i < n; i++) {
      if (bel[i] == bel[i ^ 1]) {
        return false;
      }
    }
    return true;
  }
  vector<bool> get_solution() {
    vector<bool> ret(n >> 1, false);
    for (int i = 0; i < n; i++) {
      if (bel[i] == bel[i ^ 1]) {
        throw i;
      }
      if (bel[i] < bel[i ^ 1]) {
        ret[i >> 1] = (i & 1);
      }
    }
    return ret;
  }
  void contract() {
    vector<vector<int>> nG(n, vector<int>());
    for (int p = 0; p < n; p++) {
      for (auto q : G[p]) {
        if (bel[p] ^ bel[q]) {
          nG[bel[p]].push_back(bel[q]);
        }
      }
    }
    G = nG;
  }
  vector<int> topusort() {
    vector<int> deg(n, 0);
    queue<int> Q;
    for (int i = 0; i < n; i++) {
      for (auto q : G[i]) {
        deg[q]++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (!deg[i]) {
        Q.push(i);
      }
    }
    vector<int> tour;
    tour.reserve(n);
    while (!Q.empty()) {
      int p = Q.front();
      Q.pop();
      tour.push_back(p);
      for (auto e : G[p]) {
        if (!--deg[e]) {
          Q.push(e);
        }
      }
    }
    assert((signed)tour.size() == n);
    return tour;
  }
  void add_edge(int x, int y) {
    G[x].push_back(y);
    G[y ^ 1].push_back(x ^ 1);
  }
} TwoSatisfiction;
int n, m1, m2;
TwoSatisfiction f, g, _f, _g, h;
int main() {
  scanf("%d%d%d", &n, &m1, &m2);
  f.init(n);
  g.init(n);
  for (int i = 0, x, y, f1, f2; i < m1; i++) {
    scanf("%d%d", &x, &y);
    f1 = x<0, f2 = y> 0;
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    --x, --y;
    x <<= 1, y <<= 1;
    f.add_edge(x ^ f1, y ^ f2);
  }
  for (int i = 0, x, y, f1, f2; i < m2; i++) {
    scanf("%d%d", &x, &y);
    f1 = x<0, f2 = y> 0;
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    --x, --y;
    x <<= 1, y <<= 1;
    g.add_edge(x ^ f1, y ^ f2);
  }
  _f = f, _g = g;
  f.do_tarjan();
  g.do_tarjan();
  bool flg_f = f.has_solution();
  bool flg_g = g.has_solution();
  if (!flg_f && !flg_g) {
    puts("SIMILAR");
  } else if (!flg_f && flg_g) {
    auto v = g.get_solution();
    for (auto x : v) {
      putchar('0' + x);
      putchar(' ');
    }
  } else if (flg_f && !flg_g) {
    auto v = f.get_solution();
    for (auto x : v) {
      putchar('0' + x);
      putchar(' ');
    }
  } else {
    f.contract();
    g.contract();
    auto of = f.topusort();
    auto og = g.topusort();
    int n2 = n << 1;
    vector<bitset<N>> bf(n2), bg(n2);
    reverse(of.begin(), of.end());
    reverse(og.begin(), og.end());
    for (auto x : of) {
      bf[x].set(x);
      for (auto e : f.G[x]) {
        bf[x] |= bf[e];
      }
    }
    for (auto x : og) {
      bg[x].set(x);
      for (auto e : g.G[x]) {
        bg[x] |= bg[e];
      }
    }
    vector<bool> det(n2, false);
    auto qryf = [&](int x, int y) { return bf[f.bel[x]].test(f.bel[y]); };
    auto qryg = [&](int x, int y) { return bg[g.bel[x]].test(g.bel[y]); };
    for (int i = 0; i < n2; i++) {
      if (qryf(i, i ^ 1) ^ qryg(i, i ^ 1)) {
        h = (qryf(i, i ^ 1)) ? _g : _f;
        h.add_edge(i ^ 1, 1);
        goto finish;
      }
      if (qryf(i, i ^ 1)) {
        det[i] = det[i ^ 1] = true;
      }
    }
    for (int x = 0; x < n2; x++) {
      if (det[x]) continue;
      for (int y = 0; y < n2; y++) {
        if (det[y]) continue;
        if (qryf(x, y) ^ qryg(x, y)) {
          h = qryf(x, y) ? _g : _f;
          h.add_edge(x ^ 1, x);
          h.add_edge(y, y ^ 1);
          goto finish;
        }
      }
    }
    puts("SIMILAR");
    return 0;
  finish:
    h.do_tarjan();
    auto v = h.get_solution();
    for (auto x : v) {
      putchar('0' + x);
      putchar(' ');
    }
  }
  return 0;
}
