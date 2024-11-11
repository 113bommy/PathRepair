#include <bits/stdc++.h>
using namespace std;
struct unit {
  long long t, v, m;
  unit(int _t, int _v, int _m) : t(_t), v(_v), m(_m) {}
  bool operator<(const unit &cmp) const { return t < cmp.t; }
};
long long init[100000], v[100000], up[100000];
int n, m;
struct seg {
  int l, r, cur;
  seg *lt, *rt;
  vector<unit> p;
  seg(int _l, int _r) : l(_l), r(_r), cur(-1), lt(NULL), rt(NULL) {
    for (int i = l; i < r; i++)
      p.push_back(unit(v[i] ? up[i] / v[i] : 1000000, v[i], up[i]));
    sort(p.begin(), p.end());
    for (int i = 1; i < r - l; i++) p[i].m += p[i - 1].m;
    for (int i = r - l - 2; i >= 0; i--) p[i].v += p[i + 1].v;
    if (r - l > 1) {
      int mid = (r + l) >> 1;
      lt = new seg(l, mid);
      rt = new seg(mid, r);
    }
  }
  long long query(int ll, int rr, int now) {
    if (ll <= l && rr >= r && cur > -2) {
      long long res = 0;
      if (cur == -1) {
        for (int i = l; i < r; i++) res += min(up[i], init[i] + v[i] * now);
      } else {
        int d = now - cur;
        if (d <= p[0].t)
          res = p[0].v * d;
        else if (d > p.back().t)
          res = p.back().m;
        else {
          auto x = lower_bound(p.begin(), p.end(), unit(d, -1, -1));
          res = x->v * d + (--x)->m;
        }
      }
      cur = now;
      return res;
    } else {
      long long res = 0;
      if (cur >= 0) lt->cur = rt->cur = cur;
      int mid = (l + r) >> 1;
      if (ll < mid) res += lt->query(ll, rr, now);
      if (rr > mid) res += rt->query(ll, rr, now);
      if (ll <= l && r <= rr)
        cur = now;
      else if (lt->cur == rt->cur)
        cur = lt->cur;
      else
        cur = -2;
      return res;
    }
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> init[i] >> up[i] >> v[i];
  seg T(0, n);
  cin >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << T.query(b - 1, c, a) << endl;
  }
  return 0;
}
