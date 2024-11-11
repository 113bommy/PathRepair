#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int n, q;
int niz[maxn];
int pom[maxn];
vector<int> g[maxn];
int in[maxn];
int out[maxn];
int d[maxn];
int dist[maxn];
int brojac;
void dfs(int v, int p, int duz) {
  d[v] = duz;
  in[v] = ++brojac;
  for (auto u : g[v]) {
    if (u != p) dfs(u, v, duz + 1);
  }
  out[v] = brojac;
}
long long bor1[4 * maxn];
long long lenj1[4 * maxn];
long long bor2[4 * maxn];
long long lenj2[4 * maxn];
long long bor[4 * maxn];
void build(int v, int tl, int tr) {
  if (tl == tr) {
    if (dist[tl] % 2 == 0)
      bor1[v] = niz[tl];
    else
      bor2[v] = niz[tl];
    return;
  }
  int mid = (tl + tr) / 2;
  build(v * 2, tl, mid);
  build(v * 2 + 1, mid + 1, tr);
}
void propagate1(int v, int tl, int tr) {
  if (lenj1[v]) {
    bor1[v] += lenj1[v];
    if (tl != tr) {
      lenj1[v * 2] += lenj1[v];
      lenj1[v * 2 + 1] += lenj1[v];
    }
    lenj1[v] = 0;
  }
}
void lazyupd1(int v, int tl, int tr, int l, int r, long long vre) {
  propagate1(v, tl, tr);
  if (tl > tr || tl > r || tr < l) return;
  if (tl >= l && tr <= r) {
    bor1[v] += vre;
    if (tl != tr) {
      lenj1[v * 2] += vre;
      lenj1[v * 2 + 1] += vre;
    }
    return;
  }
  int mid = (tl + tr) / 2;
  lazyupd1(v * 2, tl, mid, l, r, vre);
  lazyupd1(v * 2 + 1, mid + 1, tr, l, r, vre);
}
int get1(int v, int tl, int tr, int poz) {
  propagate1(v, tl, tr);
  if (tl == tr) return bor1[v];
  int mid = (tl + tr) / 2;
  if (poz <= mid)
    return get1(v * 2, tl, mid, poz);
  else
    return get1(v * 2 + 1, mid + 1, tr, poz);
}
void propagate2(int v, int tl, int tr) {
  if (lenj2[v]) {
    bor2[v] += lenj2[v];
    if (tl != tr) {
      lenj2[v * 2] += lenj2[v];
      lenj2[v * 2 + 1] += lenj2[v];
    }
    lenj2[v] = 0;
  }
}
void lazyupd2(int v, int tl, int tr, int l, int r, long long vre) {
  propagate2(v, tl, tr);
  if (tl > tr | tl > r || tr < l) return;
  if (tl >= l && tr <= r) {
    bor2[v] += vre;
    if (tl != tr) {
      lenj2[v * 2] += vre;
      lenj2[v * 2 + 1] += vre;
    }
    return;
  }
  int mid = (tl + tr) / 2;
  lazyupd2(v * 2, tl, mid, l, r, vre);
  lazyupd2(v * 2 + 1, mid + 1, tr, l, r, vre);
}
int get2(int v, int tl, int tr, int poz) {
  propagate2(v, tl, tr);
  if (tl == tr) return bor2[v];
  int mid = (tl + tr) / 2;
  if (poz <= mid)
    return get2(v * 2, tl, mid, poz);
  else
    return get2(v * 2 + 1, mid + 1, tr, poz);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> pom[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, -1, 0);
  for (int i = 1; i <= n; i++) {
    niz[in[i]] = pom[i];
    dist[in[i]] = d[i];
  }
  build(1, 1, n);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int v, val;
      cin >> v >> val;
      if (dist[in[v]] % 2 == 0) {
        lazyupd1(1, 1, n, in[v], out[v], val);
        lazyupd2(1, 1, n, in[v], out[v], -val);
      } else {
        lazyupd2(1, 1, n, in[v], out[v], val);
        lazyupd1(1, 1, n, in[v], out[v], -val);
      }
    }
    if (t == 2) {
      int v;
      cin >> v;
      if (dist[in[v]] % 2 == 0)
        cout << get1(1, 1, n, in[v]) << endl;
      else
        cout << get2(1, 1, n, in[v]) << endl;
    }
  }
  return 0;
}
