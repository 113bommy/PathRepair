#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int u[101010], v[101010], w[101010], id[101010];
struct UnionFind {
  vector<int> uf;
  UnionFind(int n) : uf(n, -1) {}
  int operator[](int x) {
    if (uf[x] < 0) return x;
    return uf[x] = operator[](uf[x]);
  }
  bool merge(int x, int y) {
    x = operator[](x);
    y = operator[](y);
    if (x == y) return false;
    if (-uf[x] < -uf[y]) swap(x, y);
    uf[x] += uf[y];
    uf[y] = x;
    return true;
  }
};
int solve(int l, int r) {
  UnionFind uf(n * 2);
  for (int i = 0; i < m; i++) {
    if (l <= id[i] && id[i] <= r) {
      if (uf[u[i]] == uf[v[i]]) {
        return w[i];
      } else {
        uf.merge(u[i], v[i] + n);
        uf.merge(u[i] + n, v[i]);
      }
    }
  }
  return -1;
}
int main() {
  cin >> n >> m >> q;
  vector<tuple<int, int, int, int>> wuvi(m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &u[i], &v[i], &w[i]);
    u[i]--;
    v[i]--;
    wuvi[i] = make_tuple(w[i], u[i], v[i], i);
  }
  sort(wuvi.rbegin(), wuvi.rend());
  for (int i = 0; i < m; i++) {
    tie(w[i], u[i], v[i], id[i]) = wuvi[i];
  }
  for (int ii = 0; ii < q; ii++) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--;
    r--;
    printf("%d\n", solve(l, r));
  }
}
