#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005, inf = 100000000;
int n, nn, i, j, t, vx, vy;
long long ans;
struct seg {
  seg *lc, *rc;
  int res, tag;
  seg() {
    res = tag = 0;
    lc = rc = 0;
  }
  void upd(int l, int r, int L, int R, int Tag) {
    if (L <= l && r <= R) {
      res = max(res, Tag);
      tag = max(tag, Tag);
      return;
    }
    int mid = (l + r) >> 1;
    if (!lc) lc = new seg(), rc = new seg();
    if (L <= mid) lc->upd(l, mid, L, R, Tag);
    if (R > mid) rc->upd(mid + 1, r, L, R, Tag);
    res = max(tag, min(lc->res, rc->res));
  }
  int cal(int l, int r, int L, int R) {
    if (L <= l && r <= R) return res;
    if (!lc) return 0;
    int mid = (l + r) >> 1, ans = inf;
    if (L <= mid) ans = lc->cal(l, mid, L, R);
    if (R > mid) ans = min(ans, rc->cal(mid + 1, r, L, R));
    return max(ans, tag);
  }
} * tree;
struct data {
  int k, l, r, h;
  bool operator<(const data &a) const { return k < a.k; }
} d[maxn];
void init(int x, int y) {
  int i, j, t, l = inf, r = -inf, k = inf;
  scanf("%d", &d[nn].h);
  for (i = x - 1; i <= x; i++)
    for (j = y - 1; j <= y; j++) {
      t = j * vx - i * vy;
      l = min(t, l);
      r = max(t, r);
      t = i * vx + j * vy;
      k = min(t, k);
    }
  d[nn].l = l + inf + 1;
  d[nn].r = r + inf;
  d[nn].k = k;
  nn++;
}
int main() {
  cin >> n >> vx >> vy;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) init(i, j);
  sort(d, d + nn);
  tree = new seg();
  for (i = 0; i < nn; i++) {
    t = tree->cal(0, inf + inf, d[i].l, d[i].r);
    ans += max(0, d[i].h - t);
    tree->upd(0, inf + inf, d[i].l, d[i].r, d[i].h);
  }
  cout << ans << endl;
  return 0;
}
