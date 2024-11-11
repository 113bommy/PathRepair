#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int LG = 21;
const int SS = N * (LG + 4);
int seg[SS], L[SS], R[SS];
int used, n, m, empt;
int a[N], root[N];
int x[N], y[N], k[N], l[N], r[N];
vector<int> child[N];
int par[N][LG], d[N];
int build(int s = 0, int e = N) {
  int v = used++;
  if (e - s == 1) return v;
  int mid = (s + e) / 2;
  L[v] = build(s, mid);
  R[v] = build(mid, e);
  return v;
}
int add(int ind, int v, int s = 0, int e = N) {
  if (ind < s || ind >= e) return v;
  int u = used++;
  if (e - s == 1) {
    seg[u] = seg[v];
    seg[u]++;
    return u;
  }
  int mid = (s + e) / 2;
  L[u] = add(ind, L[v], s, mid);
  R[u] = add(ind, R[v], mid, e);
  seg[u] = seg[L[u]] + seg[R[u]];
  return u;
}
int get(int l, int r, int v, int s = 0, int e = N) {
  if (l >= e || r <= s) return 0;
  if (l <= s && e <= r) return seg[v];
  int mid = (s + e) / 2;
  int res = 0;
  res += get(l, r, L[v], s, mid);
  res += get(l, r, R[v], mid, e);
  return res;
}
void dfs(int v, int p) {
  if (p == -1)
    root[v] = add(a[v], empt);
  else
    root[v] = add(a[v], root[p]);
  par[v][0] = p;
  for (auto u : child[v]) {
    d[u] = d[v] + 1;
    dfs(u, v);
  }
}
int get_parent(int v, int a) {
  for (int i = 0; i < LG; i++)
    if ((a >> i) & 1) v = par[v][i];
  return v;
}
int lca(int u, int v) {
  if (d[u] > d[v]) swap(v, u);
  v = get_parent(v, d[v] - d[u]);
  if (v == u) return v;
  for (int i = LG - 1; i >= 0; i--)
    if (par[v][i] != par[u][i]) {
      v = par[v][i];
      u = par[u][i];
    }
  return par[v][0];
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) a[i] = N - 1;
  int tr;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    p--;
    if (p != -1)
      child[p].push_back(i);
    else
      tr = i;
  }
  cin >> m;
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int v;
      cin >> v;
      v--;
      a[v] = i;
    } else {
      cin >> x[cnt] >> y[cnt] >> k[cnt] >> l[cnt];
      x[cnt]--;
      y[cnt]--;
      r[cnt] = i;
      cnt++;
    }
  }
  empt = build();
  dfs(tr, -1);
  for (int i = 1; i < LG; i++)
    for (int j = 0; j < n; j++) par[j][i] = par[par[j][i - 1]][i - 1];
  for (int i = 0; i < cnt; i++) {
    int v = x[i];
    int u = y[i];
    int LCA = lca(v, u);
    int PLCA;
    int v2r = get(l[i], r[i], root[par[v][0]]);
    int u2r = get(l[i], r[i], root[par[u][0]]);
    int goodLCA = 1;
    if ((a[LCA] >= l[i] && a[LCA] < r[i]) || LCA == v || LCA == u) goodLCA = 0;
    int Left;
    if (v == LCA || par[v][0] == LCA)
      Left = 0;
    else {
      Left = d[v] - d[LCA] - 1;
      Left -= v2r;
      Left += get(l[i], r[i], root[LCA]);
    }
    int Right;
    if (u == LCA || par[u][0] == LCA)
      Right = 0;
    else {
      Right = d[u] - d[LCA] - 1;
      Right -= u2r;
      Right += get(l[i], r[i], root[LCA]);
    }
    if (Left >= k[i]) {
      int s = 0;
      int e = d[v] - d[LCA] - 1;
      while (e - s > 1) {
        int mid = (s + e) / 2;
        int w = get_parent(v, mid);
        int cnt = d[v] - d[w];
        cnt -= v2r;
        cnt += get(l[i], r[i], root[w]);
        if (cnt >= k[i])
          e = mid;
        else
          s = mid;
      }
      cout << get_parent(v, e) + 1 << "\n";
      continue;
    }
    k[i] -= Left;
    if (goodLCA >= k[i]) {
      cout << LCA + 1 << "\n";
      continue;
    }
    k[i] -= goodLCA;
    if (Right >= k[i]) {
      int s = 0;
      int e = d[u] - d[LCA] - 1;
      while (e - s > 1) {
        int mid = (s + e) / 2;
        int w = get_parent(u, mid + 1);
        int cnt = d[u] - d[w] - 1;
        cnt -= u2r;
        cnt += get(l[i], r[i], root[w]);
        cnt = Right - cnt;
        if (cnt >= k[i])
          s = mid;
        else
          e = mid;
      }
      cout << get_parent(u, s + 1) + 1 << "\n";
      continue;
    }
    cout << "-1\n";
  }
  return 0;
}
