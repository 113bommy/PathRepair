#include <bits/stdc++.h>
struct Point {
  int x, y, num;
};
bool cmpx(const Point &a, const Point &b) {
  return a.x == b.x ? a.y < b.y : a.x < b.x;
}
bool cmpy(const Point &a, const Point &b) {
  return a.y == b.y ? a.x < b.x : a.y < b.y;
}
struct KDtree {
  struct Node {
    int xl, xr, yl, yr, minn;
  };
  int n;
  std::vector<Node> v;
  std::vector<int> mp;
  KDtree(int n_, Point *arr) : n(1), mp(n_) {
    while (n < n_) {
      n <<= 1;
    }
    v.resize(n << 1);
    build(arr, 0, n_, 1, 0);
    n = n_;
  }
  void build(Point *p, int l, int r, int k, bool d) {
    if (l == r - 1) {
      v[k] = {p[l].x, p[l].x, p[l].y, p[l].y, p[l].num};
      mp[p[l].num] = l;
      return;
    }
    int mid = (l + r) >> 1;
    std::nth_element(p + l, p + mid, p + r, d ? cmpx : cmpy);
    build(p, l, mid, k << 1, !d);
    build(p, mid, r, k << 1 | 1, !d);
    v[k].xl = std::min(v[k << 1].xl, v[k << 1 | 1].xl);
    v[k].xr = std::max(v[k << 1].xr, v[k << 1 | 1].xr);
    v[k].yl = std::min(v[k << 1].yl, v[k << 1 | 1].yl);
    v[k].yr = std::max(v[k << 1].yr, v[k << 1 | 1].yr);
    v[k].minn = std::min(v[k << 1].minn, v[k << 1 | 1].minn);
  }
  void query(Node &nd, int k = 1) {
    if (nd.minn <= v[k].minn || nd.xl > v[k].xr || nd.xr < v[k].xl ||
        nd.yl > v[k].yr || nd.yr < v[k].yl)
      return;
    if (nd.xl <= v[k].xl && nd.xr >= v[k].xr && nd.yl <= v[k].yl &&
        nd.yr >= v[k].yr) {
      nd.minn = v[k].minn;
      return;
    }
    if (v[k << 1].minn < v[k << 1 | 1].minn) {
      query(nd, k << 1);
      query(nd, k << 1 | 1);
    } else {
      query(nd, k << 1 | 1);
      query(nd, k << 1);
    }
  }
  void remove(int num) {
    int loc = mp[num];
    remove(loc, 0, n, 1);
  }
  void remove(int loc, int l, int r, int k) {
    if (l == r - 1) {
      assert(loc == l);
      v[k].minn = 2147483647;
      return;
    }
    int mid = (l + r) >> 1;
    if (loc < mid)
      remove(loc, l, mid, k << 1);
    else
      remove(loc, mid, r, k << 1 | 1);
    v[k].minn = std::min(v[k << 1].minn, v[k << 1 | 1].minn);
  }
};
int xl[100010], xr[100010], yl[100010], yr[100010], z[100010], r[100010],
    ans[100010];
Point p[100010];
int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d %d %d", &xl[i], &xr[i], &yl[i], &yr[i], &z[i]);
    r[i] = i;
  }
  std::sort(r, r + n, [](int x, int y) { return z[x] < z[y]; });
  scanf("%d", &m);
  for (int i = 0, x, y; i < m; ++i) {
    scanf("%d %d", &x, &y);
    p[i] = {x, y, i};
  }
  KDtree t(m, p);
  for (int i = 0; i < n; ++i) {
    KDtree::Node nd = {xl[r[i]], xr[r[i]], yl[r[i]], yr[r[i]], 2147483647};
    t.query(nd);
    if (nd.minn != 2147483647) {
      ans[nd.minn] = r[i] + 1;
      t.remove(nd.minn);
    }
  }
  for (int i = 0; i < m; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
