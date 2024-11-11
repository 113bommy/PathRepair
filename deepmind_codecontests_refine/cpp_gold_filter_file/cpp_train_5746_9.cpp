#include <bits/stdc++.h>
using namespace std;
const int MX = 100005;
const int MD = 1000000007;
const int MD2 = 1000000009;
int mod_mult(long long a, long long b, int md) { return (a * b) % md; }
int exp(int a, int b, int md) {
  int res = 1;
  while (b) {
    if (b % 2 == 1) res = mod_mult(res, a, md);
    a = mod_mult(a, a, md);
    b /= 2;
  }
  return res;
}
int inv(int a, int md) { return exp(a, md - 2, md); }
pair<int, int> mod(pair<int, int> x) {
  if (x.first >= MD) x.first -= MD;
  if (x.first < 0) x.first += MD;
  if (x.second >= MD2) x.second -= MD2;
  if (x.second < 0) x.second += MD2;
  return x;
}
pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  a.first += b.first;
  a.second += b.second;
  return a;
}
pair<int, int> operator-(pair<int, int> a, pair<int, int> b) {
  a.first -= b.first;
  a.second -= b.second;
  return a;
}
void hwt(pair<int, int> a[1 << 17], bool inverse) {
  for (int len = 1; 2 * len <= (1 << 17); len *= 2) {
    for (int i = 0; i < (1 << 17); i += 2 * len) {
      for (int j = 0; j < len; j++) {
        auto u = a[i + j];
        auto v = a[i + len + j];
        a[i + j] = mod(u + v);
        a[i + len + j] = mod(u - v);
      }
    }
  }
  if (inverse) {
    int x = inv(1 << 17, MD);
    int y = inv(1 << 17, MD2);
    for (int i = 0; i < (1 << 17); i++) {
      a[i].first = mod_mult(a[i].first, x, MD);
      a[i].second = mod_mult(a[i].second, y, MD2);
    }
  }
}
pair<int, int> a[1 << 17];
pair<int, int> b[1 << 17];
vector<pair<int, int>> neigh[MX];
int depth[MX];
int par[MX];
int ww[MX];
void dfs(int v, int p, int d, int w) {
  ww[v] = w;
  par[v] = p;
  depth[v] = d;
  for (auto e : neigh[v]) {
    int u = e.first;
    if (u == p) continue;
    if (!depth[u]) {
      dfs(u, v, d + 1, e.second);
      continue;
    }
    if (depth[u] < depth[v]) {
      memset(b, 0, sizeof b);
      b[e.second].first++;
      b[e.second].second++;
      int x = v;
      while (x != u) {
        b[ww[x]].first++;
        b[ww[x]].second++;
        x = par[x];
      }
      hwt(a, false);
      hwt(b, false);
      for (int i = 0; i < (1 << 17); i++) {
        a[i].first = mod_mult(a[i].first, b[i].first, MD);
        a[i].second = mod_mult(a[i].second, b[i].second, MD2);
      }
      hwt(a, true);
    }
  }
}
int main() {
  int n, m;
  ignore = scanf("%d %d", &n, &m);
  int W = 0;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    ignore = scanf("%d %d %d", &u, &v, &w);
    W ^= w;
    neigh[u].emplace_back(v, w);
    neigh[v].emplace_back(u, w);
  }
  a[0].first = 1;
  a[0].second = 1;
  dfs(1, 0, 1, 0);
  int ans = (1 << 17);
  for (int i = 0; i < (1 << 17); i++) {
    if ((a[i].first || a[i].second) && ans > (i ^ W)) {
      ans = i ^ W;
    }
  }
  printf("%d %d\n", ans, a[ans ^ W].first);
}
