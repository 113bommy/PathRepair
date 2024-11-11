#include <bits/stdc++.h>
using namespace std;
const int N = 2000020, D = N * 4;
int n, vx, vy, sv[N * 2], svt, an;
long long ans;
struct item {
  int d, l, r, h;
} a[N];
int tag[D], mi[D];
int query(int d, int lt, int rt, int lq, int rq) {
  if (lq <= lt && rt <= rq) return mi[d];
  int ret = 1e9, md = (lt + rt) >> 1;
  if (lq <= md) ret = min(ret, query(d << 1 | 0, lt, md, lq, rq));
  if (md < rq) ret = min(ret, query(d << 1 | 1, md + 1, rt, lq, rq));
  return max(ret, tag[d]);
}
void modify(int d, int lt, int rt, int lq, int rq, int h) {
  if (lq <= lt && rt <= rq) {
    tag[d] = max(tag[d], h);
    mi[d] = max(mi[d], h);
    return;
  }
  int md = (lt + rt) >> 1;
  if (lq <= md) modify(d << 1 | 0, lt, md, lq, rq, h);
  if (md < rq) modify(d << 1 | 1, md + 1, rt, lq, rq, h);
  mi[d] = max(tag[d], min(mi[d << 1 | 0], mi[d << 1 | 1]));
}
bool cmp_d(const item& a, const item& b) { return a.d < b.d; }
int main() {
  scanf("%d%d%d", &n, &vx, &vy);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      int h;
      scanf("%d", &h);
      int d = 1e9, l = 1e9, r = -1e9;
      for (int ii = i - 1; ii <= i; ++ii)
        for (int jj = j - 1; jj <= j; ++jj) {
          int ndis = ii * vx + jj * vy;
          int npos = ii * -vy + jj * vx;
          d = min(d, ndis);
          l = min(l, npos);
          r = max(r, npos);
        }
      a[++an] = (item){d, l, r, h};
      sv[svt++] = l, sv[svt++] = r;
    }
  sort(sv, sv + svt);
  svt = unique(sv, sv + svt) - sv;
  sort(a + 1, a + an + 1, cmp_d);
  for (int i = 1; i <= an; ++i) {
    int l = lower_bound(sv, sv + svt, a[i].l) - sv;
    int r = lower_bound(sv, sv + svt, a[i].r) - sv - 1;
    int maxh = query(1, 0, svt, l, r);
    ans += max(a[i].h - maxh, 0);
    modify(1, 0, svt, l, r, a[i].h);
  }
  printf("%d\n", ans);
}
