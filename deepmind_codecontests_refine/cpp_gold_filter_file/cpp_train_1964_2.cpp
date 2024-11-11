#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

struct uni {
  vector<int> p;
  uni(int n) :
      p(n, -1) {}
  int root(int a) {
    return p[a] < 0 ? a : (p[a] = root(p[a]));
  }
  bool find(int a, int b) {
    return root(a) == root(b);
  }
  bool merge(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return false;
    p[a] = b;
    return true;
  }
};

struct edge {
  int f, t, c;
  edge() {}
  edge(int f, int t, int c) :
      f(f), t(t), c(c) {}
  bool operator<(const edge& e) const {
    return c < e.c;
  }
};

edge e[444444];
vector<edge> g[4444];
int res[4444][4444];

void solve(int f, int v, int p, int c) {
  res[f][v] = c;
  for (int i = 0; i < int(g[v].size()); i++) {
    if (g[v][i].t == p) continue;
    solve(f, g[v][i].t, v, max(c, g[v][i].c));
  }
}

int main(void) {
  scanf("%d%d", &n, &m);
  uni u(n);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &e[i].f, &e[i].t, &e[i].c);
    --e[i].f;
    --e[i].t;
  }
  sort(e, e+m);
  long long c = 0;
  for (int i = 0; i < m; i++) {
    if (u.merge(e[i].f, e[i].t)) {
      c += e[i].c;
      g[e[i].f].push_back(edge(e[i].f, e[i].t, e[i].c));
      g[e[i].t].push_back(edge(e[i].t, e[i].f, e[i].c));
    }
  }
  for (int i = 0; i < n; i++) {
    solve(i, i, -1, 0);
  }
  int q; scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int s, t; scanf("%d%d", &s, &t); --s; --t;
    printf("%lld\n", c-res[s][t]);
  }
  return 0;
}
