#include <bits/stdc++.h>
using namespace std;
int n;
int val[200002];
int has[200002];
vector<int> v[200002];
int fa[200002];
int dep[200002];
int star[200002];
int en[200002];
int sz[200002];
int son[200002];
int od;
inline void dfs(int b, int pr = -1, int d = 0) {
  dep[b] = d;
  fa[b] = pr;
  star[b] = od++;
  son[b] = -1;
  for (int go : v[b]) {
    dfs(go, b, d + 1);
    if (son[b] == -1) son[b] = go;
    if (sz[go] > sz[son[b]]) {
      son[b] = go;
    }
    sz[b] += sz[go];
  }
  en[b] = od;
}
int f2[200002];
inline void dfs2(int b, int tp = 0) {
  f2[b] = tp;
  if (son[b] != -1) dfs2(son[b], tp);
  for (int go : v[b]) {
    if (go == son[b]) continue;
    dfs2(go, go);
  }
}
inline int lca(int a, int b) {
  if (dep[f2[a]] < dep[f2[b]]) swap(a, b);
  while (f2[a] != f2[b]) {
    a = fa[f2[a]];
    if (dep[f2[a]] < dep[f2[b]]) swap(a, b);
  }
  return a;
}
struct st {
  int l;
  int r;
  bool emp;
  st(bool ep = false) {
    l = r = -1;
    emp = ep;
  }
};
int nd[5];
bool cmp(int a, int b) { return dep[a] > dep[b]; }
inline bool on_path(int a, int b, int c) {
  if (dep[a] > dep[b]) swap(a, b);
  if (star[a] <= star[c] && star[c] < en[a]) {
    if (star[c] <= star[b] && star[b] < en[c]) return true;
  }
  return false;
}
st operator+(const st a, const st b) {
  if (a.emp) return b;
  if (b.emp) return a;
  if (b.l == -1) return st();
  if (a.l == -1) return st();
  nd[0] = a.l;
  nd[1] = a.r;
  nd[2] = b.l;
  nd[3] = b.r;
  sort(nd, nd + 4, cmp);
  for (int i = 1; i < 4; i++) {
    int L = nd[0];
    int R = nd[i];
    int lc = lca(L, R);
    bool ng = false;
    for (int i = 0; i < 4; i++) {
      if (on_path(L, lc, nd[i]) || on_path(R, lc, nd[i])) {
      } else {
        ng = true;
        break;
      }
    }
    if (!ng) {
      st r;
      r.l = L;
      r.r = R;
      return r;
    }
  }
  return st();
}
st seg[200002 * 4];
inline void init(int b, int l, int r) {
  if (l + 1 == r) {
    seg[b].l = seg[b].r = has[l];
    return;
  }
  init(b * 2 + 1, l, (l + r) >> 1);
  init(b * 2 + 2, (l + r) >> 1, r);
  seg[b] = seg[b * 2 + 1] + seg[b * 2 + 2];
}
inline void add(int b, int l, int r, int l1, int l2) {
  if (l <= l1 && l1 < r || l <= l2 && l2 < r) {
    if (l + 1 == r) {
      seg[b].l = seg[b].r = has[l];
      return;
    }
    add(b * 2 + 1, l, (l + r) >> 1, l1, l2);
    add(b * 2 + 2, (l + r) >> 1, r, l1, l2);
    seg[b] = seg[b * 2 + 1] + seg[b * 2 + 2];
  }
}
inline int query(int b, int l, int r, st z = st(true)) {
  if (l + 1 == r) {
    st u = z + seg[b];
    if (u.l != -1) return r;
    return l;
  }
  st u = z + seg[b * 2 + 1];
  if (u.l != -1) {
    if (l + 1 == r) return r;
    return query(b * 2 + 2, (l + r) >> 1, r, u);
  } else {
    if (l + 1 == r) return l;
    return query(b * 2 + 1, l, (l + r) >> 1, z);
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    has[a] = i;
    val[i] = a;
  }
  for (int i = 1; i < n; i++) {
    int a;
    scanf("%d", &a);
    a--;
    v[a].push_back(i);
  }
  dfs(0);
  dfs2(0);
  init(0, 0, n);
  int q;
  cin >> q;
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int a, b;
      scanf("%d%d", &a, &b);
      a--;
      b--;
      swap(val[a], val[b]);
      has[val[a]] = a;
      has[val[b]] = b;
      add(0, 0, n, val[a], val[b]);
    } else {
      printf("%d\n", query(0, 0, n));
    }
  }
  return 0;
}
