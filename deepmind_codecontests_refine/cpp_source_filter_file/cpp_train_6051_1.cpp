#include <bits/stdc++.h>
int n, queries;
int p[1 + 200000];
std::vector<int> G[1 + 200000];
int v[1 + 2 * 200000], last;
int f[1 + 1 * 200000];
int d[1 + 1 * 200000];
void dfs(int node, int papa) {
  d[node] = 1 + d[papa];
  f[node] = ++last;
  v[last] = node;
  for (auto y : G[node])
    if (y != papa) {
      dfs(y, node);
      v[++last] = node;
    }
}
int lg[1 + 200000];
int rmq[1 + 20][1 + 200000];
void buildRMQ() {
  lg[1] = 0;
  for (int i = 2; i <= last; i++) lg[i] = 1 + lg[i / 2];
  for (int i = 1; i <= last; i++) rmq[0][i] = v[i];
  for (int i = 1; (1 << i) <= last; i++)
    for (int j = 1; j + (1 << i) - 1 <= last; j++) {
      if (d[rmq[i - 1][j]] < d[rmq[i - 1][j + (1 << (i - 1))]])
        rmq[i][j] = rmq[i - 1][j];
      else
        rmq[i][j] = rmq[i - 1][j + (1 << (i - 1))];
    }
}
int lca(int u, int v) {
  int a = f[u], b = f[v];
  if (a > b) std::swap(a, b);
  if (d[rmq[lg[b - a + 1]][a]] <
      d[rmq[lg[b - a + 1]][b - (1 << lg[b - a + 1]) + 1]])
    return rmq[lg[b - a + 1]][a];
  else
    return rmq[lg[b - a + 1]][b - (1 << lg[b - a + 1]) + 1];
}
std::pair<int, int> Insert(std::pair<int, int> x, int w) {
  int u = x.first, v = x.second;
  if (d[u] > d[v]) std::swap(u, v);
  int l = lca(u, v);
  if (l == u) {
    if (lca(l, w) == w)
      return {w, v};
    else if (lca(l, w) == l) {
      if (lca(w, v) == l)
        return {w, v};
      else if (lca(w, v) == w)
        return {l, v};
      else if (lca(w, v) == v)
        return {l, w};
      else
        return {-1, -1};
    } else
      return {w, v};
  } else {
    if (lca(l, w) != l)
      return {-1, -1};
    else if (lca(u, w) == l) {
      if (lca(v, w) == l) {
        if (w == l) return {u, v};
        return {-1, -1};
      } else if (lca(v, w) == w)
        return {u, v};
      else if (lca(v, w) == v)
        return {u, w};
      else
        return {-1, -1};
    } else {
      if (lca(u, w) == w)
        return {u, v};
      else if (lca(u, w) == u)
        return {w, v};
      else
        return {-1, -1};
    }
  }
}
std::pair<int, int> Union(std::pair<int, int> x, std::pair<int, int> y) {
  if (x == std::make_pair(-1, -1)) return x;
  if (y == std::make_pair(-1, -1)) return y;
  if (x == std::make_pair(0, 0)) return y;
  if (y == std::make_pair(0, 0)) return x;
  x = Insert(x, y.first);
  if (x.first != -1)
    x = Insert(x, y.second);
  else
    return {-1, -1};
  if (x.first == -1) return {-1, -1};
  return x;
}
bool valid[1 + 4 * 200000];
std::pair<int, int> aint[1 + 4 * 200000];
int poz;
std::pair<int, int> val;
void update(int p, int st, int dr) {
  if (st == dr)
    aint[p] = val, valid[p] = true;
  else {
    int m = (st + dr) / 2;
    if (poz <= m)
      update(2 * p, st, m);
    else
      update(2 * p + 1, m + 1, dr);
    aint[p] = Union(aint[2 * p], aint[2 * p + 1]);
    if (aint[p].first == -1)
      valid[p] = false;
    else
      valid[p] = true;
  }
}
int ans;
std::pair<int, int> tmp;
void query(int p, int st, int dr) {
  if (st == dr) {
    if (Union(tmp, aint[p]).first != -1)
      ans = st;
    else
      ans = st - 1;
  } else {
    int m = (st + dr) / 2;
    if (Union(tmp, aint[2 * p]).first != -1) {
      tmp = Union(tmp, aint[2 * p]);
      query(2 * p + 1, m + 1, dr);
    } else {
      query(2 * p, st, m);
    }
  }
}
int main() {
  FILE *fi, *fo;
  fi = stdin;
  fo = stdout;
  fscanf(fi, "%d", &n);
  for (int i = 1; i <= n; i++) {
    fscanf(fi, "%d", &p[i]);
    p[i]++;
  }
  for (int i = 2; i <= n; i++) {
    int x;
    fscanf(fi, "%d", &x);
    G[x].push_back(i);
  }
  dfs(1, 0);
  buildRMQ();
  for (int i = 1; i <= 4 * n; i++) valid[i] = false, aint[i] = {-1, -1};
  for (int i = 1; i <= n; i++) {
    poz = p[i], val = {i, i};
    update(1, 1, n);
  }
  fscanf(fi, "%d", &queries);
  for (int z = 1; z <= queries; z++) {
    int tip;
    fscanf(fi, "%d", &tip);
    if (tip == 1) {
      int a, b;
      fscanf(fi, "%d%d", &a, &b);
      poz = p[a], val = {b, b}, update(1, 1, n);
      poz = p[b], val = {a, a}, update(1, 1, n);
      std::swap(p[a], p[b]);
    } else {
      ans = 0, tmp = {0, 0}, query(1, 1, n);
      fprintf(fo, "%d\n", ans);
    }
  }
  return 0;
}
