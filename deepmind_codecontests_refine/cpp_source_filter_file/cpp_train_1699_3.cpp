#include <bits/stdc++.h>
using namespace std;
int xs[150000], ps[150000];
double profit[150000];
struct range {
  double pref, suff, ret, sum;
};
range operator+(const range &l, const range &r) {
  range ret;
  ret.pref = max(l.pref, l.sum + r.pref);
  ret.suff = max(r.suff, l.suff + r.sum);
  ret.ret = max(l.suff + r.pref, max(l.pref, r.suff));
  ret.sum = l.sum + r.sum;
  return ret;
}
range seg[150000 * 4];
void init(int k, int l, int r) {
  if (r - l == 1) {
    seg[k] = (range){profit[l], profit[l], profit[l], profit[l]};
  } else {
    int mid = (l + r) / 2;
    init(2 * k + 1, l, mid);
    init(2 * k + 2, mid, r);
    seg[k] = seg[2 * k + 1] + seg[2 * k + 2];
  }
}
range query(int k, int l, int r, int x, int y) {
  if (r <= x || y <= l)
    return (range){0.0, 0.0, 0.0, 0.0};
  else if (x <= l && r <= y)
    return seg[k];
  else {
    int mid = (l + r) / 2;
    return query(2 * k + 1, l, mid, x, y) + query(2 * k + 2, mid, r, x, y);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m, c;
  cin >> n >> m >> c;
  for (int i = 0; i < (int)(n); i++) cin >> xs[i];
  for (int i = 0; i < (int)(n - 1); i++) cin >> ps[i];
  for (int i = 0; i < (int)(n - 1); i++)
    profit[i] = (xs[i + 1] - xs[i]) / 2.0 - c * ps[i] / 100.0;
  init(0, 0, n - 1);
  double ret = 0;
  for (int i = 0; i < (int)(m); i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    ret += max(0.0, query(0, 0, n - 1, a, b).ret);
  }
  cout << fixed << setprecision(20) << ret << endl;
  return 0;
}
