#include <bits/stdc++.h>
using namespace std;
const int MAXD = 100007, MAXN = 100007, MOD = 1000000007;
int main() {
  int d, cntx[2 * MAXN], cnty[2 * MAXN], l[2 * MAXN], r[2 * MAXN], t[2 * MAXN],
      b[2 * MAXN], cntl, cntr, cntt, cntb, n, m;
  pair<int, int> a[MAXD];
  scanf("%d%d%d", &d, &n, &m);
  memset(cntx, 0, 8 * MAXN);
  memset(cnty, 0, 8 * MAXN);
  memset(l, 0, 8 * MAXN);
  memset(r, 0, 8 * MAXN);
  memset(t, 0, 8 * MAXN);
  memset(b, 0, 8 * MAXN);
  for (int i = (0); i < (d); ++i) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    a[i] = make_pair(x1 + x2, y1 + y2);
    ++cntx[x1 + x2];
    ++cnty[y1 + y2];
  }
  scanf("%d%d%d%d", &cntl, &cntr, &cntt, &cntb);
  for (int i = (2); i < (2 * MAXN); ++i) {
    if (i & 1) {
      l[i] = l[i - 1] + cntx[i - 1];
      t[i] = t[i - 1] + cnty[i - 1];
      if (cntx[i]) l[i] += cntx[i] - 1;
      ;
      if (cnty[i]) t[i] += cnty[i] - 1;
    } else {
      l[i] = l[i - 2] + cntx[i - 2] + cntx[i - 1];
      t[i] = t[i - 2] + cnty[i - 2] + cnty[i - 1];
    }
  }
  for (int i = 2 * MAXN - 3; i >= 0; --i) {
    if (i & 1) {
      r[i] = r[i + 1] + cntx[i + 1];
      b[i] = b[i + 1] + cnty[i + 1];
      if (cntx[i]) r[i] += cntx[i] - 1;
      ;
      if (cnty[i]) b[i] += cnty[i] - 1;
    } else {
      r[i] = r[i + 2] + cntx[i + 2] + cntx[i + 1];
      b[i] = b[i + 2] + cnty[i + 2] + cnty[i + 1];
    }
  }
  for (int i = (0); i < (d); ++i) {
    if (l[a[i].first] == cntl && r[a[i].first] == cntr &&
        t[a[i].second] == cntt && b[a[i].second] == cntb) {
      printf("%d", i + 1);
      return 0;
    }
  }
  printf("-1");
  return 0;
}
