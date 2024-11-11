#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 79, inf = 1e9 + 79;
void upd(int& a, const int& b) { a = min(a, b); }
struct query {
  int r1, r2, c1, c2, i;
};
vector<int> tmin(maxn * 2, inf), id(maxn, -1), val(maxn, -1), a(maxn),
    ans(maxn, inf), cmin(maxn);
int n, q;
void update(int i, int x) {
  tmin[i += maxn] = x;
  for (i = (i >> 1); i > 0; i >>= 1)
    tmin[i] = min(tmin[i << 1], tmin[i << 1 | 1]);
}
int qmin(int l, int r) {
  int ans = inf;
  for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) upd(ans, tmin[l++]);
    if (r & 1) upd(ans, tmin[--r]);
  }
  return ans;
}
void calculate(vector<vector<query> >& qu) {
  int siz = -1;
  for (int r2 = 0; r2 < n; r2++) {
    while (siz > -1 && a[r2] <= val[siz]) siz--;
    siz++, id[siz] = r2, val[siz] = a[r2];
    update(siz, a[r2] - 2 * r2);
    for (query& i : qu[r2]) {
      int idr1 =
          lower_bound(id.begin(), id.begin() + siz + 1, i.r1) - id.begin();
      cmin[i.i] = min(i.c1, val[idr1]);
      upd(ans[i.i], i.r2 - i.r1 + abs(cmin[i.i] - i.c2));
      int cl = lower_bound(val.begin() + idr1, val.begin() + siz + 1, i.c2) -
               val.begin();
      upd(ans[i.i], i.r2 - i.r1 + val[cl] - i.c2 + 1);
      if (cl > idr1)
        upd(ans[i.i], i.r2 - i.r1 + i.c2 - val[cl - 1] + 1);
      else {
        int kr = upper_bound(val.begin(), val.begin() + siz + 1, i.c2) -
                 val.begin() - 1;
        if (kr != -1 && id[kr] <= i.r1)
          upd(ans[i.i],
              i.r2 + i.r1 - id[kr] * 2 + i.c2 - val[kr] + (i.c1 < val[kr]));
        if (kr + 1 < idr1) {
          int li = kr + 1, ri = idr1 - 1,
              mi = upper_bound(val.begin() + li, val.begin() + ri + 1, i.c1) -
                   val.begin();
          upd(ans[i.i], qmin(li, mi - 1) + i.r2 + i.r1 - i.c2);
          upd(ans[i.i], qmin(mi, ri) + i.r2 + i.r1 - i.c2 + 1);
        }
      }
    }
  }
  siz = -1;
  for (int r2 = n - 1; r2 >= 0; r2--) {
    while (siz > -1 && a[r2] <= val[siz]) siz--;
    siz++, id[siz] = r2, val[siz] = a[r2];
    update(siz, a[r2] + 2 * r2);
    for (query& i : qu[r2]) {
      int kr = upper_bound(val.begin(), val.begin() + siz + 1, i.c2) -
               val.begin() - 1;
      if (kr != -1)
        upd(ans[i.i],
            id[kr] * 2 - i.r1 - i.r2 + i.c2 - val[kr] + (cmin[i.i] < val[kr]));
      if (kr < siz) {
        int li = kr + 1, ri = siz,
            mi =
                upper_bound(val.begin() + li, val.begin() + ri + 1, cmin[i.i]) -
                val.begin();
        upd(ans[i.i], qmin(li, mi - 1) - i.r1 - i.r2 - i.c2);
        upd(ans[i.i], qmin(mi, ri) - i.r1 - i.r2 - i.c2 + 1);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> q;
  vector<vector<vector<query> > > qu(2, vector<vector<query> >(n));
  for (int i = 0, r1, c1, r2, c2; i < q; i++) {
    cin >> r1 >> c1 >> r2 >> c2;
    ans[i] = abs(r1 - r2) + c2 + 1;
    if (r1 < r2)
      qu[0][r2 - 1].push_back({r1 - 1, r2 - 1, c1, c2, i});
    else
      qu[1][n - r2].push_back({n - r1, n - r2, c1, c2, i});
  }
  calculate(qu[0]);
  reverse(a.begin(), a.begin() + n);
  calculate(qu[1]);
  for (int i = 0; i < q; i++) cout << ans[i] << "\n";
  return 0;
}
