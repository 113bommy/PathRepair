#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int INF = 1000000005;
struct P {
  int L, R, l, r, dp;
  P(int a, int b, int c, int d, int e) : L(a), R(b), l(c), r(d), dp(e) {}
  bool operator<(const P &x) const {
    if (l == x.l) return r < x.r;
    return l < x.l;
  }
};
set<P> lzs;
struct sg {
  int l, r, h;
} data[N];
bool cmp(sg x, sg y) {
  if (x.h == y.h) return x.l < y.l;
  return x.h > y.h;
}
int main() {
  int n, i, t;
  scanf("%d%d", &n, &t);
  data[0].h = INF;
  data[0].l = -INF;
  data[0].r = INF;
  for (i = 1; i <= n; i++) {
    scanf("%d%d%d", &data[i].h, &data[i].l, &data[i].r);
  }
  sort(data + 1, data + n + 1, cmp);
  data[n + 1].h = -1;
  data[n + 1].l = -INF + 1;
  data[n + 1].r = INF;
  lzs.insert(P(data[0].l, data[0].r, data[0].l, data[0].r, INF + INF));
  for (i = 1; i <= n + 1; i++) {
    P now(data[i].l, data[i].r, data[i].l, data[i].r, 0);
    set<P>::iterator it = lzs.lower_bound(now), pre;
    it--;
    for (; it != lzs.end();) {
      if (it->l >= data[i].r) break;
      if (it->r <= data[i].l || (it->r < it->R && data[i].r > it->r) ||
          (it->l > it->L && data[i].l < it->l))
        ;
      else {
        int ll = ((data[i].l) > (it->l) ? (data[i].l) : (it->l)),
            rr = ((data[i].r) < (it->r) ? (data[i].r) : (it->r)),
            tmp = ((it->dp) < (rr - ll) ? (it->dp) : (rr - ll));
        if (now.dp < tmp) now.dp = tmp;
      }
      if (it->r > data[i].l) {
        if (it->l < data[i].l) {
          lzs.insert(P(it->L, it->R, it->l, data[i].l, it->dp));
        }
        if (it->r > data[i].r) {
          lzs.insert(P(it->L, it->R, data[i].r, it->r, it->dp));
        }
        pre = it;
        it++;
        lzs.erase(*pre);
      } else
        it++;
    }
    lzs.insert(now);
    if (i == n + 1) printf("%d\n", now.dp);
  }
  return 0;
}
