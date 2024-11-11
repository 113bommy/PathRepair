#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
struct node {
  long long u = -1, v = -1, can = 0;
};
node tree[4 * N];
long long up[N][20];
vector<long long> g[N];
long long p[N];
long long tin[N];
long long tout[N];
long long bac[N];
long long t;
void dfs(long long v, long long pp = 0) {
  up[v][0] = pp;
  tin[v] = ++t;
  bac[p[v]] = v;
  for (long long i = 1; i < 20; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
  for (long long u : g[v]) dfs(u, v);
  tout[v] = ++t;
}
bool is_par(long long v, long long u) {
  return tin[v] <= tin[u] && tout[v] >= tout[u];
}
long long lca(long long u, long long v) {
  if (is_par(u, v)) return u;
  if (is_par(v, u)) return v;
  for (long long i = 19; i > -1; --i)
    if (!is_par(up[v][i], u)) v = up[v][i];
  return up[v][0];
}
node relax(node a, node b) {
  vector<long long> v(4);
  v[0] = (a.v);
  v[1] = (a.u);
  node res;
  if (a.can == 0 || b.can == 0) return res;
  v[2] = (b.v);
  v[3] = b.u;
  for (long long i = 0; i < 4; ++i)
    for (long long j = i + 1; j < 4; ++j) {
      long long lc = lca(v[i], v[j]);
      long long chk = 0;
      for (long long k = 0; k < 4; ++k)
        if (k != i && k != j) {
          if (is_par(lc, v[k]) && is_par(v[k], v[i]))
            ++chk;
          else if (is_par(lc, v[k]) && is_par(v[k], v[j]))
            ++chk;
        }
      if (chk == 2) {
        res.can = 1;
        res.v = v[i];
        res.u = v[j];
        return res;
      }
    }
  return res;
}
void build(long long i, long long l, long long r) {
  if (l == r) {
    tree[i].can = 1;
    tree[i].v = bac[l];
    tree[i].u = tree[i].v;
    return;
  }
  long long m = (l + r) / 2;
  build(2 * i, l, m);
  build(2 * i + 1, m + 1, r);
  tree[i] = relax(tree[2 * i], tree[2 * i + 1]);
}
void upd(long long i, long long l, long long r, long long pos) {
  if (l == r) {
    tree[i].can = 1;
    tree[i].v = bac[l];
    tree[i].u = bac[l];
    return;
  }
  long long m = (l + r) / 2;
  if (pos <= m)
    upd(2 * i, l, m, pos);
  else
    upd(2 * i + 1, m + 1, r, pos);
  tree[i] = relax(tree[2 * i], tree[2 * i + 1]);
}
long long get(long long i, long long l, long long r, node c) {
  if (l == r) {
    node tmp = relax(tree[i], c);
    return tmp.can;
  }
  long long m = (l + r) / 2;
  node tmp;
  tmp = relax(c, tree[2 * i]);
  if (tmp.can) {
    return (m - l + 1) + get(2 * i + 1, m + 1, r, tmp);
  } else
    return get(2 * i, l, m, c);
}
void print(long long i, long long l, long long r) {
  cout << i << " " << l << " " << r << " " << tree[i].v << " " << tree[i].u
       << " " << tree[i].can << endl;
  if (l != r) {
    long long m = (l + r) / 2;
    print(2 * i, l, m);
    print(2 * i + 1, m + 1, r);
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    cin >> p[i];
  }
  for (long long i = 1; i < n; ++i) {
    long long d;
    cin >> d;
    --d;
    g[d].push_back(i);
  }
  dfs(0);
  build(1, 0, n - 1);
  long long q;
  cin >> q;
  for (long long i = 0; i < q; ++i) {
    long long t;
    cin >> t;
    if (t == 2) {
      node tmp;
      tmp.can = 1;
      tmp.v = bac[0];
      tmp.u = bac[0];
      cout << get(1, 0, n - 1, tmp) << "\n";
    } else {
      long long u, v;
      cin >> u >> v;
      --u;
      --v;
      swap(p[v], p[u]);
      bac[p[v]] = v;
      bac[p[u]] = u;
      upd(1, 0, n - 1, p[u]);
      upd(1, 0, n - 1, p[v]);
    }
  }
  return 0;
}
