#include <bits/stdc++.h>
using namespace std;
const int K = 20;
const int N = 2e5 + 10;
const int INF = 1e9 + 7;
int n;
int a[N];
pair<int, int> rg[K][N];
pair<int, int> merge(pair<int, int> p1, pair<int, int> p2) {
  return pair<int, int>(min(p1.first, p2.first), max(p1.second, p2.second));
}
struct SegTree {
  pair<int, int> dat[N * 4];
  void build(pair<int, int> rg[], int v = 0, int l = 1, int r = n * 2 + 1) {
    if (l + 1 == r) {
      dat[v] = rg[l];
    } else {
      int mid = (l + r) / 2, chl = v * 2 + 1, chr = v * 2 + 2;
      build(rg, chl, l, mid);
      build(rg, chr, mid, r);
      dat[v] = merge(dat[chl], dat[chr]);
    }
  }
  pair<int, int> query(int L, int R, int v = 0, int l = 1, int r = n * 2 + 1) {
    if (L >= r || l >= R) return pair<int, int>(INF, -INF);
    if (L <= l && r <= R) return dat[v];
    int mid = (l + r) / 2, chl = v * 2 + 1, chr = v * 2 + 2;
    return merge(query(L, R, chl, l, mid), query(L, R, chr, mid, r));
  }
  pair<int, int> trans(pair<int, int> p) {
    return query(p.first, p.second + 1);
  }
} rmq[K];
int len(pair<int, int> p) { return p.second - p.first + 1; }
int solve(int center) {
  pair<int, int> r(center, center);
  int res = 0;
  for (int k = K - 1; k >= 0; k--) {
    pair<int, int> nr = rmq[k].trans(r);
    if (len(nr) < n) {
      r = nr;
      res += 1 << k;
    }
  }
  return res + 1;
}
int main() {
  scanf("%d", &n);
  if (n == 1) return puts("0"), 0;
  for (int i = 1; i <= n; i++) scanf("%d", a + i), a[n + i] = a[i];
  for (int i = 1; i <= 2 * n; i++) {
    rg[0][i] = pair<int, int>(max(1, i - a[i]), min(2 * n, i + a[i]));
  }
  rmq[0].build(rg[0]);
  for (int k = 1; k < K; k++) {
    for (int i = 1; i <= 2 * n; i++) {
      rg[k][i] = rmq[k - 1].trans(rg[k - 1][i]);
    }
    rmq[k].build(rg[k]);
  }
  for (int i = 1; i <= n; i++) {
    int ans = min(solve(i), solve(i + n));
    printf("%d%c", ans, " \n"[i == n]);
  }
}
