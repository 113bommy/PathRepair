#include <bits/stdc++.h>
using namespace std;
struct pnt {
  int x, y;
};
struct pr {
  int d, q;
  pr() {}
  pr(int d, int q) : d(d), q(q) {}
  friend bool operator<(pr a, pr b) {
    if (a.d != b.d) return a.d < b.d;
    return a.q < b.q;
  }
};
const int N = 200000 + 20;
bool ok[N];
int t[4 * N];
void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = -1;
    return;
  }
  int tm = (tl + tr) / 2;
  build(2 * v, tl, tm);
  build(2 * v + 1, tm + 1, tr);
  t[v] = -1;
}
void upd(int v, int tl, int tr, int wh, int vl) {
  while (tl < tr) {
    int tm = (tl + tr) / 2;
    if (wh <= tm) {
      tr = tm;
      v = 2 * v;
    } else {
      tl = tm + 1;
      v = 2 * v + 1;
    }
  }
  t[v] = vl;
  v /= 2;
  while (v >= 1) {
    t[v] = min(t[2 * v], t[2 * v + 1]);
    v >>= 1;
  }
}
const int INF = 1e9 + 7;
int mn(int v, int tl, int tr, int l, int r) {
  if (l > r) return INF;
  if (tl == l && r == tr) return t[v];
  int tm = (tl + tr) / 2;
  return min(mn(2 * v, tl, tm, l, min(tm, r)),
             mn(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
}
int main() {
  int n, m, k, q;
  scanf("%d %d %d %d", &n, &m, &k, &q);
  swap(n, m);
  vector<pnt> lad(k);
  for (int i = 0; i < k; ++i) {
    scanf("%d %d", &lad[i].x, &lad[i].y);
    --lad[i].x;
    --lad[i].y;
  }
  vector<pr> r(q), d(q);
  vector<int> x1(q), x2(q), y1(q), y2(q);
  for (int i = 0; i < q; ++i) {
    scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
    --y1[i];
    --y2[i];
    --x1[i];
    --x2[i];
    r[i].d = x2[i];
    r[i].q = i;
    d[i].d = y2[i];
    d[i].q = i;
  }
  for (int i = 0; i < k; ++i) {
    r.push_back(pr(lad[i].x, -i - 1));
    d.push_back(pr(lad[i].y, -i - 1));
  }
  sort(r.begin(), r.end());
  sort(d.begin(), d.end());
  build(1, 0, n - 1);
  for (int i = 0; i < r.size(); ++i) {
    if (r[i].q < 0)
      upd(1, 0, n - 1, lad[-r[i].q - 1].y, r[i].d);
    else {
      int t = mn(1, 0, n - 1, y1[r[i].q], y2[r[i].q]);
      if (t >= x1[r[i].q]) ok[r[i].q] = true;
    }
  }
  build(1, 0, m - 1);
  for (int i = 0; i < d.size(); ++i) {
    if (r[i].q < 0)
      upd(1, 0, m - 1, lad[-r[i].q - 1].x, r[i].d);
    else {
      int t = mn(1, 0, m - 1, x1[r[i].q], x2[r[i].q]);
      if (t >= y1[r[i].q]) ok[r[i].q] = true;
    }
  }
  for (int i = 0; i < q; ++i) printf((ok[i] ? "YES\n" : "NO\n"));
  return 0;
}
