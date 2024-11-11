#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, unsigned long long int> > e[200110];
int parent[200110];
unsigned long long int parent_weight[200110];
int depth[200110];
int sz[200110];
unsigned long long int seg[200110 * 3];
pair<int, int> num[200110];
int tnum[200110];
int lca[200110][19];
pair<int, int> yol[200110];
int st = 1;
inline unsigned long long int carp(unsigned long long int x,
                                   unsigned long long int y) {
  if (x == 0) return 0;
  if (y == 0) return 0;
  unsigned long long int c = x * y;
  if (c / x == y)
    return c;
  else
    return 2000000000000000000LL;
}
unsigned long long int find(int d, int a, int b, int x, int y) {
  if (b < x || y < a) return 1;
  if (x <= a && b <= y) return seg[d];
  return carp(find(d * 2, a, (a + b) / 2, x, y),
              find(d * 2 + 1, (a + b) / 2 + 1, b, x, y));
}
unsigned long long int update(int d, int a, int b, int x,
                              unsigned long long int y) {
  if (b < x || x < a) return seg[d];
  if (a == b && a == x) return seg[d] = y;
  return seg[d] = carp(update(d * 2, a, (a + b) / 2, x, y),
                       update(d * 2 + 1, (a + b) / 2 + 1, b, x, y));
}
int dfs1(int x, int pr, int dep, unsigned long long int yol) {
  sz[x] = 1;
  depth[x] = dep;
  parent_weight[x] = yol;
  parent[x] = pr;
  for (int i = 0; i < e[x].size(); i++) {
    int y = e[x][i].first;
    unsigned long long int c = e[x][i].second;
    if (y == pr) continue;
    sz[x] += dfs1(y, x, dep + 1, c);
  }
  return sz[x];
}
void dfs2(int x, int par, int dontgo) {
  if (par == -1) {
    par = st;
    num[x] = make_pair(st, st);
    tnum[st] = x;
    st++;
  } else {
    tnum[st] = x;
    num[x] = make_pair(st++, par);
  }
  update(1, 1, n + 10, num[x].first, parent_weight[x]);
  for (int i = 0; i < e[x].size(); i++) {
    int y = e[x][i].first;
    if (y == dontgo) continue;
    if (sz[y] > sz[x] / 2) dfs2(y, par, x);
  }
  for (int i = 0; i < e[x].size(); i++) {
    int y = e[x][i].first;
    if (y == dontgo) continue;
    if (sz[y] <= sz[x] / 2) dfs2(y, -1, x);
  }
}
void dfs3(int x, int y, unsigned long long int& c) {
  if (x == y) return;
  int ay = num[y].first;
  while (true) {
    int ax = num[x].first;
    int stx = num[x].second;
    if (stx <= ay && ay <= ax) {
      c /= find(1, 1, n + 10, ay + 1, ax);
      break;
    } else {
      c /= find(1, 1, n + 10, stx + 1, ax);
      c /= parent_weight[tnum[stx]];
      x = parent[tnum[stx]];
    }
  }
}
void MakeLCA() {
  for (int i = 1; i <= n; i++) lca[i][0] = parent[i];
  for (int k = 1; k <= 18; k++)
    for (int i = 1; i <= n; i++) lca[i][k] = lca[lca[i][k - 1]][k - 1];
}
int GetLCA(int x, int y) {
  if (x == y) return x;
  if (depth[x] < depth[y]) swap(x, y);
  for (int k = 18; k >= 0; k--)
    if (lca[x][k] != 0 && depth[lca[x][k]] >= depth[y]) x = lca[x][k];
  if (x == y) return x;
  for (int k = 18; k >= 0; k--)
    if (lca[x][k] != 0 && lca[x][k] != lca[y][k]) x = lca[x][k], y = lca[y][k];
  x = lca[x][0];
  return x;
}
unsigned long long int getans(int x, int y, unsigned long long int c) {
  int lca = GetLCA(x, y);
  dfs3(x, lca, c);
  dfs3(y, lca, c);
  return c;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    int x, y;
    unsigned long long int c;
    scanf("%d%d%I64d", &x, &y, &c);
    e[x].push_back(make_pair(y, c));
    e[y].push_back(make_pair(x, c));
    yol[i] = make_pair(x, y);
  }
  dfs1(1, 0, 1, 0);
  dfs2(1, -1, -1);
  update(1, 1, n + 10, 1, 1);
  MakeLCA();
  while (m--) {
    int t;
    scanf("%d", &t);
    int x, y;
    unsigned long long int c;
    if (t == 1) {
      scanf("%d%d%I64d", &x, &y, &c);
      unsigned long long int cevap = getans(x, y, c);
      printf("%I64d\n", cevap);
    } else {
      scanf("%d%I64d", &x, &c);
      int a1 = yol[x].first;
      int a2 = yol[x].second;
      if (parent[a1] == a2) swap(a1, a2);
      update(1, 1, n + 10, num[a2].first, c);
      parent_weight[a2] = c;
    }
  }
  return 0;
}
