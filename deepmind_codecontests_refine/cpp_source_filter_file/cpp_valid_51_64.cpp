#include <bits/stdc++.h>
using namespace std;
int nw[52], d[52], sz[52][52], fa[52];
int getv(int x) { return x == fa[x] ? x : fa[x] = getv(fa[x]); }
bool merge(int x, int y) {
  x = getv(x);
  y = getv(y);
  if (x == y) return false;
  fa[x] = y;
  return true;
}
int random(int n) {
  int he = 0;
  for (int i = 1; i <= n; i++) nw[i] = 0;
  vector<pair<int, int> > ve;
  for (int i = 1; i < n; i++) {
    he += sz[i][n], nw[i] = 1;
    ve.push_back(make_pair(i, n));
  }
  int ans = he;
  nw[n] = n - 1;
  double T = 100 * n;
  while (T > 1e-5) {
    int od = he, i = rand() % (n - 1);
    int oa = ve[i].first, ob = ve[i].second;
    nw[oa] -= 1;
    nw[ob] -= 1;
    he -= sz[oa][ob];
    ve.erase(ve.begin() + i);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 0; i < n - 2; i++) merge(ve[i].first, ve[i].second);
    int a, b;
    while (1) {
      a = rand() % (n - 1) + 1;
      b = rand() % (n - a) + a + 1;
      if (nw[a] < d[a] && nw[b] < d[b] && merge(a, b)) {
        he += sz[a][b];
        ve.push_back(make_pair(a, b));
        nw[a] += 1;
        nw[b] += 1;
        break;
      }
    }
    if (he < ans) ans = he;
    if (he > od && rand() % 10000 >= exp((od - he) / T) * 1e4) {
      he = od;
      ve.pop_back();
      ve.push_back(make_pair(oa, ob));
      nw[a] -= 1;
      nw[b] -= 1;
      nw[oa] += 1;
      nw[ob] += 1;
    }
    T *= 0.99999;
  }
  return ans;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; i++) scanf("%d", &d[i]);
  for (int i = k + 1; i <= n; i++) d[i] = 1e9;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      scanf("%d", &sz[i][j]);
      sz[j][i] = sz[i][j];
    }
  }
  int ans = random(n);
  printf("%d", ans);
  return 0;
}
