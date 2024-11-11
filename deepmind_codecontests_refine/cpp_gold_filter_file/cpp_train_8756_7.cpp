#include <bits/stdc++.h>
using namespace std;
int p[200000], pos[200000];
vector<int> adjList[200000];
int parent[200000][18], depth[200000], disc[200000], disc2[200000], logn,
    num = 0, num2 = 0;
int sparse[400005][19], logg[400005];
int doDFS(int u) {
  int i;
  disc[u] = num++, disc2[u] = num2++, sparse[num2 - 1][0] = depth[u];
  for (i = 0; i < adjList[u].size(); i++)
    doDFS(adjList[u][i]), sparse[num2++][0] = depth[u];
  return 0;
}
int lca(int u, int v) {
  int i;
  if (depth[u] < depth[v]) swap(u, v);
  for (i = logn - 1; i >= 0; i--) {
    if ((parent[u][i] != -1) && (depth[parent[u][i]] >= depth[v]))
      u = parent[u][i];
  }
  if (u == v) return u;
  for (i = logn - 1; i >= 0; i--) {
    if (parent[u][i] != parent[v][i]) u = parent[u][i], v = parent[v][i];
  }
  return parent[u][0];
}
int query(int l, int r) {
  int x = logg[r - l + 1];
  return min(sparse[l][x], sparse[r - (1 << x) + 1][x]);
}
int dist(pair<int, int> uu, pair<int, int> vv) {
  int u = uu.second, v = vv.second;
  return depth[u] + depth[v] - 2 * query(disc2[u], disc2[v]);
}
pair<int, int> tree[1 << 19];
pair<int, int> x[4];
int d[4][4];
pair<int, int> com(pair<int, int> a, pair<int, int> b) {
  if (a == make_pair(-1, -1))
    return make_pair(-1, -1);
  else if (b == make_pair(-1, -1))
    return make_pair(-1, -1);
  int i, j;
  x[0].second = a.first, x[1].second = a.second, x[2].second = b.first,
  x[3].second = b.second;
  for (i = 0; i < 4; i++) x[i].first = disc[x[i].second];
  sort(x, x + 4);
  for (i = 0; i < 4; i++) {
    for (j = i + 1; j < 4; j++) d[i][j] = dist(x[i], x[j]);
  }
  int c = d[0][1] + d[1][2] + d[2][3] + d[0][3];
  for (i = 0; i < 4; i++) {
    for (j = i + 1; j < 4; j++) {
      if (2 * d[i][j] == c) return make_pair(x[i].second, x[j].second);
    }
  }
  return make_pair(-1, -1);
}
int build(int s, int e, int i) {
  if (s == e) {
    tree[i] = make_pair(pos[s], pos[s]);
    return 0;
  }
  int mid = (s + e) / 2;
  build(s, mid, 2 * i + 1), build(mid + 1, e, 2 * i + 2);
  tree[i] = com(tree[2 * i + 1], tree[2 * i + 2]);
  return 0;
}
int update(int s, int e, int ai, int i) {
  if ((s > ai) || (e < ai))
    return 0;
  else if (s == e) {
    tree[i] = make_pair(pos[s], pos[s]);
    return 0;
  }
  int mid = (s + e) / 2;
  update(s, mid, ai, 2 * i + 1), update(mid + 1, e, ai, 2 * i + 2);
  tree[i] = com(tree[2 * i + 1], tree[2 * i + 2]);
  return 0;
}
int query(int s, int e, int i, pair<int, int> p) {
  if (s == e) {
    pair<int, int> q = com(p, tree[i]);
    if (q != make_pair(-1, -1))
      return s + 1;
    else
      return s;
  }
  int mid = (s + e) / 2;
  pair<int, int> q = com(p, tree[2 * i + 1]);
  if (q != make_pair(-1, -1))
    return query(mid + 1, e, 2 * i + 2, q);
  else
    return query(s, mid, 2 * i + 1, p);
}
int main() {
  int i, j;
  int n, q, d, t, u, v;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &p[i]), pos[p[i]] = i;
  parent[0][0] = -1, depth[0] = 0;
  for (i = 0; i < n - 1; i++) {
    scanf("%d", &d);
    adjList[d - 1].push_back(i + 1), parent[i + 1][0] = d - 1,
                                                depth[i + 1] = depth[d - 1] + 1;
  }
  for (i = 1; (1 << i) < n; i++) {
    for (j = 0; j < n; j++) {
      if (parent[j][i - 1] != -1)
        parent[j][i] = parent[parent[j][i - 1]][i - 1];
      else
        parent[j][i] = -1;
    }
  }
  doDFS(0);
  logg[1] = 0;
  for (i = 2; i <= num2; i++) logg[i] = logg[i / 2] + 1;
  for (i = 1; (1 << i) < num2; i++) {
    for (j = 0; j <= num2 - (1 << i); j++)
      sparse[j][i] = min(sparse[j][i - 1], sparse[j + (1 << (i - 1))][i - 1]);
  };
  ;
  logn = i;
  int pt = -1, pans;
  build(0, n - 1, 0);
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d %d", &u, &v), u--, v--;
      swap(p[u], p[v]), swap(pos[p[u]], pos[p[v]]);
      update(0, n - 1, p[u], 0), update(0, n - 1, p[v], 0);
    } else if (t == 2) {
      if (pt == 2)
        printf("%d\n", pans);
      else {
        pans = query(0, n - 1, 0, make_pair(pos[0], pos[0]));
        printf("%d\n", pans);
        ;
      }
    }
    pt = t;
  }
  return 0;
}
