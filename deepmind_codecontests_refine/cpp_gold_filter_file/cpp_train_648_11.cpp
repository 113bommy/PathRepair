#include <bits/stdc++.h>
using namespace std;
long long int xtree[4000009];
void xupdate(long long int v, long long int tl, long long int tr,
             long long int pos, long long int val) {
  if (tl == tr)
    xtree[v] = max(xtree[v], val);
  else {
    long long int tm = (tl + tr) / 2;
    if (pos <= tm)
      xupdate((2 * v), tl, tm, pos, val);
    else
      xupdate((2 * v) + 1, tm + 1, tr, pos, val);
    xtree[v] = max(xtree[(2 * v)], xtree[(2 * v) + 1]);
  }
}
long long int xquery(long long int v, long long int tl, long long int tr,
                     long long int l, long long int r) {
  if (l > r) return 0;
  if ((l == tl) && (r == tr)) return xtree[v];
  long long int tm = (tl + tr) / 2;
  return max(xquery(2 * v, tl, tm, l, min(r, tm)),
             xquery((2 * v) + 1, tm + 1, tr, max(l, tm + 1), r));
}
long long int ytree[4000009];
void yupdate(long long int v, long long int tl, long long int tr,
             long long int pos, long long int val) {
  if (tl == tr) {
    if (val == 1000000000000000007)
      ytree[v] = 1000000000000000007;
    else
      ytree[v] = min(ytree[v], val);
  } else {
    long long int tm = (tl + tr) / 2;
    if (pos <= tm)
      yupdate((2 * v), tl, tm, pos, val);
    else
      yupdate((2 * v) + 1, tm + 1, tr, pos, val);
    if (val == 1000000000000000007)
      ytree[v] = 1000000000000000007;
    else
      ytree[v] = min(ytree[(2 * v)], ytree[(2 * v) + 1]);
  }
}
long long int yquery(long long int v, long long int tl, long long int tr,
                     long long int l, long long int r) {
  if (l > r) return 1000000000000000007;
  if ((l == tl) && (r == tr)) return ytree[v];
  long long int tm = (tl + tr) / 2;
  return min(yquery(2 * v, tl, tm, l, min(r, tm)),
             yquery((2 * v) + 1, tm + 1, tr, max(l, tm + 1), r));
}
void solve() {
  long long int b = 0;
  long long int n, m, q;
  cin >> n >> m >> q;
  for (long long int i = 0; i <= m; i++) {
    yupdate(1, 1, m, i, 1000000000000000007);
  }
  long long int x, y;
  for (long long int i = 0; i < q; i++) {
    cin >> x >> y;
    y = (y + 1) / 2;
    if (x % 2 == 0) {
      xupdate(1, 1, m, y, x);
    } else {
      yupdate(1, 1, m, y, x);
    }
    long long int q1 = xquery(1, 1, m, y, m);
    long long int q2 = yquery(1, 1, m, 1, y);
    if (q1 > q2) b = 1;
    if (b)
      cout << "NO";
    else
      cout << "YES";
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  for (long long int i = 0; i < t; i++) {
    solve();
  }
}
