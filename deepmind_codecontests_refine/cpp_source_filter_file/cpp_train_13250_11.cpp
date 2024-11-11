#include <bits/stdc++.h>
using namespace std;
const int Nmax = 500010;
struct segTree {
  struct Node {
    int even, odd, lazy;
  };
  Node arb[4 * Nmax];
  int euler[Nmax], niv[Nmax];
  void propag(int nod, int st, int dr) {
    if (arb[nod].lazy == 1) {
      swap(arb[nod].even, arb[nod].odd);
      if (st < dr) {
        arb[nod * 2].lazy ^= 1;
        arb[nod * 2 + 1].lazy ^= 1;
      }
      arb[nod].lazy = 0;
    }
  }
  void recalc(int nod) {
    arb[nod].even = max(arb[nod * 2].even, arb[nod * 2 + 1].even);
    arb[nod].odd = max(arb[nod * 2].odd, arb[nod * 2 + 1].odd);
  }
  void init(int nod, int st, int dr) {
    if (st == dr) {
      if (niv[euler[st]] >= 0) {
        arb[nod].even = niv[euler[st]];
        arb[nod].odd = 0;
        arb[nod].lazy = 0;
      } else {
        arb[nod].odd = niv[euler[st]];
        arb[nod].even = 0;
        arb[nod].lazy = 0;
      }
      return;
    }
    int mid = (st + dr) / 2;
    init(nod * 2, st, mid);
    init(nod * 2 + 1, mid + 1, dr);
    recalc(nod);
    arb[nod].lazy = 0;
  }
  void update(int nod, int st, int dr, int left, int right) {
    if (left <= st && dr <= right) {
      arb[nod].lazy ^= 1;
      propag(nod, st, dr);
      return;
    }
    int mid = (st + dr) / 2;
    propag(nod, st, dr);
    if (left <= mid)
      update(nod * 2, st, mid, left, right);
    else
      propag(nod * 2, st, mid);
    if (mid < right)
      update(nod * 2 + 1, mid + 1, dr, left, right);
    else
      propag(nod * 2 + 1, mid + 1, dr);
    recalc(nod);
  }
  int query(int nod, int st, int dr, int left, int right) {
    propag(nod, st, dr);
    if (left <= st && dr <= right) return arb[nod].even;
    int mid = (st + dr) / 2, s = 0;
    if (left <= mid) s = query(nod * 2, st, mid, left, right);
    if (mid < right) s = max(s, query(nod * 2 + 1, mid + 1, dr, left, right));
    return s;
  }
};
struct edge {
  int vec, c, id;
};
vector<edge> v[Nmax];
segTree t;
int nodA, nodB, nivmax, l, first[Nmax], last[Nmax], sum[Nmax], dad[Nmax],
    qry[Nmax], ans[Nmax], n, m;
void dfs(int nod, int lvl, int tata) {
  if (lvl > nivmax) {
    nivmax = lvl;
    nodB = nod;
  }
  for (auto vec : v[nod])
    if (vec.vec != tata) dfs(vec.vec, lvl + 1, nod);
}
void dfs1(int nod, int lvl, int tata) {
  t.euler[++l] = nod;
  first[nod] = l;
  if (sum[nod] % 2)
    t.niv[nod] = -lvl;
  else
    t.niv[nod] = lvl;
  for (auto x : v[nod])
    if (x.vec != tata) {
      dad[x.id] = x.vec;
      sum[x.vec] = sum[nod] + x.c;
      dfs1(x.vec, lvl + 1, nod);
    }
  last[nod] = l;
}
void solve(int root) {
  l = 0;
  sum[root] = 0;
  dfs1(root, 0, 0);
  t.init(1, 1, n);
  for (int i = 1; i <= m; ++i) {
    t.update(1, 1, n, first[dad[qry[i]]], last[dad[qry[i]]]);
    ans[i] = max(ans[i], t.arb[1].even);
  }
}
int main() {
  int x, y, c;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d%d", &x, &y, &c);
    v[x].push_back({y, c, i});
    v[y].push_back({x, c, i});
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) scanf("%d", &qry[i]);
  nivmax = -1;
  dfs(1, 0, 0);
  nodA = nodB;
  nivmax = -1;
  dfs(nodA, 0, 0);
  solve(nodA);
  solve(nodB);
  for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
  return 0;
}
