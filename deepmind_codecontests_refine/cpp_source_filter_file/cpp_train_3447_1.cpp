#include <bits/stdc++.h>
using namespace std;
const int LG = 18;
const int MX_N = 100005;
int n, q;
vector<int> G[MX_N];
struct SegTree {
  pair<int, int> seg1[MX_N * 4], seg2[MX_N * 4];
  void Merge(int nd, int lft, int rgt) {
    seg1[nd] = min(seg1[lft], seg1[rgt]);
    seg2[nd] = max(seg2[lft], seg2[rgt]);
  }
  void Bld(int* a, int nd = 1, int l = 1, int r = n) {
    if (l == r) {
      seg1[nd] = seg2[nd] = {a[l], l};
      return;
    }
    int mid = l + (r - l) / 2, lft = nd << 1, rgt = lft | 1;
    Bld(a, lft, l, mid);
    Bld(a, rgt, mid + 1, r);
    Merge(nd, lft, rgt);
  }
  pair<int, int> QryMN(int L, int R, int nd = 1, int l = 1, int r = n) {
    if (l > R or r < L) return {INT_MAX, INT_MAX};
    if (l >= L and r <= R) return seg1[nd];
    int mid = l + (r - l) / 2, lft = nd << 1, rgt = lft | 1;
    return min(QryMN(L, R, lft, l, mid), QryMN(L, R, rgt, mid + 1, r));
  }
  pair<int, int> QryMX(int L, int R, int nd = 1, int l = 1, int r = n) {
    if (l > R or r < L) return {INT_MIN, INT_MIN};
    if (l >= L and r <= R) return seg2[nd];
    int mid = l + (r - l) / 2, lft = nd << 1, rgt = lft | 1;
    return max(QryMX(L, R, lft, l, mid), QryMX(L, R, rgt, mid + 1, r));
  }
};
int clk, par[MX_N][LG];
int st[MX_N], h[MX_N];
void dfs(int u = 1, int p = 0) {
  st[u] = ++clk;
  par[u][0] = p;
  h[u] = h[p] + 1;
  for (int i = 1; i < LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
  for (auto& v : G[u])
    if (v != p) dfs(v, u);
}
int LCA(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  for (int i = LG - 1; i >= 0; i--)
    if (h[par[u][i]] >= h[v]) u = par[u][i];
  if (u == v) return u;
  for (int i = LG - 1; i >= 0; i--)
    if (par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
  return par[u][0];
}
SegTree sg;
int calc(int lca, int bd, int& res, int& bad) {
  if (res < h[lca]) res = h[lca], bad = bd;
}
void solution(int l, int r, int& res, int& bad) {
  pair<int, int> mnD = sg.QryMN(l, r);
  pair<int, int> mxD = sg.QryMX(l, r);
  int L = mnD.second;
  int R = mxD.second;
  pair<int, int> tmp;
  if (L == l) {
    tmp = sg.QryMN(l + 1, r);
    calc(LCA(tmp.second, R), L, res, bad);
  } else if (L == r) {
    tmp = sg.QryMN(l, r - 1);
    calc(LCA(tmp.second, R), L, res, bad);
  } else {
    tmp = min(sg.QryMN(l, L - 1), sg.QryMN(L + 1, r));
    calc(LCA(tmp.second, R), L, res, bad);
  }
  if (R == l) {
    tmp = sg.QryMX(l + 1, r);
    calc(LCA(tmp.second, L), R, res, bad);
  } else if (R == r) {
    tmp = sg.QryMX(l, r - 1);
    calc(LCA(tmp.second, L), R, res, bad);
  } else {
    tmp = max(sg.QryMX(l, R - 1), sg.QryMX(R + 1, r));
    calc(LCA(tmp.second, L), R, res, bad);
  }
}
int main() {
  scanf("%d %d", &n, &q);
  for (int i = 2, p; i <= n; i++) {
    scanf("%d", &p);
    G[p].push_back(i);
  }
  dfs();
  sg.Bld(st);
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    if (r - l == 1) {
      int hh = max(h[l], h[r]);
      int nn = ((hh == h[l]) ? l : r);
      printf("%d %d\n", nn, hh - 1);
      continue;
    }
    int res = 0, bad = 0;
    solution(l, r, res, bad);
    printf("%d %d\n", bad, res - 1);
  }
  return 0;
}
