#include <bits/stdc++.h>
using namespace std;
const long N = 300000, mx = 1000000000;
long i, m, n, k, j, w, c[N], xx, yy, w1, w2, l, a[N], b[N], s, r, cc, p1, p2,
    p3, p4;
void qsort(long l, long r) {
  long i, j, m, t;
  i = l;
  j = r;
  m = a[l + rand() % (r - l + 1)];
  while (i <= j) {
    while (a[i] < m) i++;
    while (a[j] > m) j--;
    if (i > j) break;
    t = a[i];
    a[i] = a[j];
    a[j] = t;
    i++;
    j--;
  }
  if (j > l) qsort(l, j);
  if (i < r) qsort(i, r);
}
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  qsort(1, n);
  cin >> m;
  for (i = 1; i <= m; i++) cin >> b[i];
  for (i = 1; i <= m; i++) cin >> c[i];
  w1 = -1;
  w2 = -1;
  for (i = 1; i <= m; i++) {
    l = 1;
    r = n;
    while (l < r) {
      cc = (l + r) / 2;
      if (a[cc] < b[i])
        l = cc + 1;
      else
        r = cc;
    }
    if (a[l] > b[i]) l--;
    p1 = l;
    l = 1;
    r = n;
    while (l < r) {
      cc = (l + r) / 2;
      if (a[cc] < b[i] + 1)
        l = cc + 1;
      else
        r = cc;
    }
    if (a[l] > b[i]) l--;
    if (a[l] == b[i])
      p2 = l;
    else
      p2 = l - 1;
    l = 1;
    r = n;
    while (l < r) {
      cc = (l + r) / 2;
      if (a[cc] < c[i])
        l = cc + 1;
      else
        r = cc;
    }
    if (a[l] > c[i]) l--;
    p3 = l;
    l = 1;
    r = n;
    while (l < r) {
      cc = (l + r) / 2;
      if (a[cc] < c[i] + 1)
        l = cc + 1;
      else
        r = cc;
    }
    if (a[l] > c[i]) l--;
    if (a[l] == c[i])
      p4 = l;
    else
      p4 = l - 1;
    if ((p2 - p1 > w1) or ((p2 - p1 == w1) and (p4 - p3 > w2))) {
      w = i;
      w1 = p2 - p1;
      w2 = p4 - p3;
    }
  }
  cout << w;
}
