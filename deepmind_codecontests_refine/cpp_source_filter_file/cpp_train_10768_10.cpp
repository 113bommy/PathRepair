#include <bits/stdc++.h>
using namespace std;
const int N = 20000 + 5, E = 200000 + 5, inf = 1000000000, BigN = 300000;
int n, m, M, source, sink, cnt[N];
struct Edge {
  int nxt, t, c;
} e[E * 2];
struct Node {
  int cur, pre, beg, lim, d;
} a[N];
void init() {
  M = 1;
  memset(e, 0, sizeof(e));
  memset(a, 0, sizeof(a));
}
void add(int u, int v, int c) {
  e[++M].t = v;
  e[M].c = c;
  e[M].nxt = a[u].beg;
  a[u].beg = M;
  e[++M].t = u;
  e[M].c = 0;
  e[M].nxt = a[v].beg;
  a[v].beg = M;
}
int maxflow() {
  int u, v, cur, flow, ret = 0;
  for (u = 0; u < n; u++) a[u].cur = a[u].beg;
  a[u = source].lim = inf;
  cnt[0] = n;
  while (a[source].d < n) {
    for (cur = a[u].cur; v = e[cur].t, cur; cur = e[cur].nxt)
      if (e[cur].c && a[v].d + 1 == a[u].d) break;
    a[u].cur = cur;
    if (cur) {
      a[v].pre = cur;
      a[v].lim = min(e[cur].c, a[u].lim);
      if ((u = v) == sink) {
        flow = a[sink].lim;
        do {
          cur = a[u].pre;
          e[cur].c -= flow;
          e[cur ^ 1].c += flow;
          u = e[cur ^ 1].t;
        } while (u != source);
        ret += flow;
      }
    } else {
      if (--cnt[a[u].d] == 0) break;
      a[u].d = n, a[u].cur = a[u].beg;
      for (cur = a[u].cur; v = e[cur].t, cur; cur = e[cur].nxt)
        if (e[cur].c && a[v].d + 1 < a[u].d) a[u].d = a[v].d + 1;
      cnt[a[u].d]++;
      if (u != source) u = e[a[u].pre ^ 1].t;
    }
  }
  return ret;
}
const int max_g = 50 + 5, max_r = 100 + 5;
struct Generator {
  int a, b, c, l, r;
} g[max_g];
struct Restriction {
  int u, v, d;
} r[max_r];
int nG, nR;
inline pair<int, int> mp(int x, int y) { return make_pair(x, y); }
inline int func(int i, int x) { return (g[i].a * x + g[i].b) * x + g[i].c; }
void build() {
  init();
  n = 0;
  source = n++;
  sink = n++;
  map<pair<int, int>, int> view;
  for (int i = 0; i < nG; i++) {
    view[mp(i, g[i].l - 1)] = n;
    int last = n++, cur;
    add(source, last, inf);
    for (int j = g[i].l; j <= g[i].r; j++) {
      cur = view[mp(i, j)] = n++;
      add(last, cur, BigN - func(i, j));
      if (j == g[i].r) add(cur, sink, inf);
      last = cur;
    }
  }
  for (int i = 0; i < nR; i++) {
    int u = r[i].u - 1, v = r[i].v - 1, d = r[i].d;
    for (int j = g[u].l; j <= g[u].r; j++) {
      if (j - d < g[v].l - 1) continue;
      if (j - d > g[v].r) break;
      add(view[mp(u, j)], view[mp(v, j - d)], inf);
    }
  }
}
int main() {
  while (cin >> nG >> nR) {
    for (int i = 0; i < nG; i++) {
      cin >> g[i].a >> g[i].b >> g[i].c;
    }
    for (int i = 0; i < nG; i++) {
      cin >> g[i].l >> g[i].r;
    }
    for (int i = 0; i < nR; i++) {
      cin >> r[i].u >> r[i].v >> r[i].d;
    }
    build();
    cout << nG * BigN - maxflow() << endl;
  }
  return 0;
}
