#include <bits/stdc++.h>
const double eps = 1e-9;
const int int_inf = 2000000000;
const long long i64_inf = 1000000000000000000ll;
const double pi = acos(-1.0);
using namespace std;
struct vertex {
  int ntr, id;
  vector<pair<int, int> > c;
  vertex(){};
};
struct fenvick {
  int sz;
  vector<int> tree;
  void inc(int i, int d) {
    for (; i < sz; i = ((i + 1) | i)) tree[i] += d;
  };
  int sum(int r) {
    int res = 0;
    for (; r >= 0; r = ((r + 1) & r) - 1) res += tree[r];
    return res;
  };
  int sum(int l, int r) { return sum(r) - sum(l - 1); };
  fenvick(int _sz) {
    tree.assign(_sz + 10, 0);
    sz = _sz + 10;
  };
};
vector<fenvick> tr;
vertex g[100500];
int root;
pair<int, int> edges[100500];
int n, m;
void dfs(int v, int par, int ntr, int id) {
  g[v].ntr = ntr;
  g[v].id = id;
  if ((int)g[v].c.size() == 1) {
    tr.push_back(fenvick(id + 1));
    return;
  }
  for (int i = 0; i < (int)(int)g[v].c.size(); i++)
    if (g[v].c[i].first != par)
      edges[g[v].c[i].second] = make_pair(ntr, id + 1),
      dfs(g[v].c[i].first, v, ntr, id + 1);
}
int go(int a, int b) {
  if (a == b) return 0;
  if (b == root) swap(a, b);
  if (a == root) {
    if (tr[g[b].ntr].sum(g[b].id) == 0) return g[b].id + 1;
    return -1;
  }
  if (g[a].ntr == g[b].ntr) {
    int tree = g[a].ntr;
    if (g[a].id > g[b].id) swap(a, b);
    if (tr[tree].sum(g[a].id, g[b].id) == 0) return g[b].id - g[a].id;
    return -1;
  }
  if (tr[g[a].ntr].sum(g[a].id) + tr[g[b].ntr].sum(g[b].id) == 0)
    return g[a].id + g[b].id + 2;
  return -1;
}
int main() {
  cin >> n;
  int ma = 0;
  for (int i = 0; i < (int)n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    g[u].c.push_back(make_pair(v, i));
    g[v].c.push_back(make_pair(u, i));
    if ((int)g[u].c.size() >= (int)g[ma].c.size()) ma = u;
    if ((int)g[v].c.size() >= (int)g[ma].c.size()) ma = v;
  }
  root = ma;
  int ntree = 0;
  for (int i = 0; i < (int)(int)g[root].c.size(); i++)
    dfs(g[root].c[i].first, root, ntree, 0),
        edges[g[root].c[i].second] = make_pair(ntree, 0), ntree++;
  int m;
  cin >> m;
  int type;
  for (int i = 0; i < (int)m; i++) {
    scanf("%d", &type);
    if (type == 1) {
      int id;
      scanf("%d", &id);
      id--;
      tr[edges[id].first].inc(edges[id].second, -1);
    } else if (type == 2) {
      int id;
      scanf("%d", &id);
      id--;
      tr[edges[id].first].inc(edges[id].second, 1);
    } else {
      int a, b;
      scanf("%d%d", &a, &b);
      printf("%d\n", go(a - 1, b - 1));
    }
  }
  return 0;
}
