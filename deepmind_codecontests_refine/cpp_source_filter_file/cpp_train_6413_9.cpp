#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
const int MAXN = 200000;
const int MAXLOG = 18;
struct DSU {
  int n;
  int* p;
  DSU(int n) : n(n), p(new int[n]) {
    for (int i = 0; i < n; i++) {
      p[i] = i;
    }
  }
  int get(int i) {
    if (p[i] == i) return i;
    return p[i] = get(p[i]);
  }
  void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (rand() % 2) swap(a, b);
    swap(a, b);
    p[a] = b;
  }
};
struct Edge {
  int a, b, c;
  int id;
  Edge(int a = 0, int b = 0, int c = 0, int id = 0)
      : a(a), b(b), c(c), id(id) {}
  bool operator<(const Edge& b) const { return c < b.c; }
};
vector<Edge> e;
vector<int> res;
vector<int> in_tree;
vector<vector<pair<int, int> > > v;
int p[MAXN][MAXLOG];
int getmax_arr[MAXN][MAXLOG];
int setmin_arr[MAXN][MAXLOG];
int p_edge_id[MAXN];
int d[MAXN];
int raise(int a, int h) {
  for (int i = 0; i < MAXLOG; i++)
    if ((h >> i) & 1) a = p[a][i];
  return a;
}
int lca(int a, int b) {
  if (d[a] < d[b]) swap(a, b);
  a = raise(a, d[a] - d[b]);
  if (a == b) return a;
  for (int i = MAXLOG; i >= 0; i--)
    if (p[a][i] != p[b][i]) {
      a = p[a][i];
      b = p[b][i];
    }
  return p[a][0];
}
int get_max(int a, int h) {
  int res = 0;
  for (int i = 0; i < MAXLOG; i++)
    if ((h >> i) & 1) {
      res = max(res, getmax_arr[a][i]);
      a = p[a][i];
    }
  return res;
}
void set_min(int a, int h, int v) {
  for (int i = 0; i < MAXLOG; i++)
    if ((h >> i) & 1) {
      setmin_arr[a][i] = min(setmin_arr[a][i], v);
      a = p[a][i];
    }
}
int get_max_from_to(int from, int to) {
  int l = lca(from, to);
  return max(get_max(from, d[from] - d[l]), get_max(to, d[to] - d[l]));
}
void set_min_from_to(int from, int to, int v) {
  int l = lca(from, to);
  set_min(from, d[from] - d[l], v);
  set_min(to, d[to] - d[l], v);
}
void fill_p(int cur, int par, int par_edge, int curd) {
  d[cur] = curd;
  p[cur][0] = par;
  p_edge_id[cur] = par_edge;
  getmax_arr[cur][0] = e[par_edge].c;
  setmin_arr[cur][0] = INF;
  for (int i = 1; i < MAXLOG; i++) {
    p[cur][i] = p[p[cur][i - 1]][i - 1];
    getmax_arr[cur][i] =
        max(getmax_arr[cur][i - 1], getmax_arr[p[cur][i - 1]][i - 1]);
    setmin_arr[cur][i] = INF;
  }
  for (int i = 0; i < (v[cur].size()); i++)
    if (v[cur][i].first != par)
      fill_p(v[cur][i].first, cur, v[cur][i].second, curd + 1);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  DSU dsu(n);
  v.resize(n);
  vector<Edge> esorted;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a--;
    b--;
    e.push_back(Edge(a, b, c, i));
    esorted.push_back(Edge(a, b, c, i));
  }
  sort(esorted.begin(), esorted.end());
  in_tree.resize(m);
  for (Edge& e : esorted) {
    int a = e.a;
    int b = e.b;
    int c = e.c;
    int i = e.id;
    if (dsu.get(a) != dsu.get(b)) {
      dsu.unite(a, b);
      v[a].push_back(make_pair(b, i));
      v[b].push_back(make_pair(a, i));
      in_tree[i] = true;
    } else
      in_tree[i] = false;
  }
  fill_p(0, 0, 0, 0);
  res.resize(m, INF);
  for (int i = 0; i < m; i++) {
    if (in_tree[i]) continue;
    int val = get_max_from_to(e[i].a, e[i].b);
    res[e[i].id] = val;
    set_min_from_to(e[i].a, e[i].b, e[i].c);
  }
  for (int i = MAXLOG - 1; i > 0; i--) {
    for (int j = 0; j < n; j++) {
      setmin_arr[j][i - 1] = min(setmin_arr[j][i - 1], setmin_arr[j][i]);
      setmin_arr[p[j][i - 1]][i - 1] =
          min(setmin_arr[p[j][i - 1]][i - 1], setmin_arr[j][i]);
    }
  }
  for (int i = 1; i < n; i++)
    res[p_edge_id[i]] = min(res[p_edge_id[i]], setmin_arr[i][0]);
  for (int i = 0; i < m; i++) printf("%d ", res[i] == INF ? -1 : res[i] - 1);
  puts("");
  return 0;
}
