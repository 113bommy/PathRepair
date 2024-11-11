#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
struct Nod {
  int v, r, d;
} a[N * N];
int n, m, Q;
int D(int x, int y) { return x * (m + 1) + y; }
int main() {
  scanf("%d%d%d", &n, &m, &Q);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) scanf("%d", &a[D(i, j)].v);
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j)
      a[D(i, j)].r = D(i, j + 1), a[D(i, j)].d = D(i + 1, j);
  while (Q--) {
    int x1, y1, x2, y2, h, w, p1 = 0, p2 = 0;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &h, &w);
    for (int i = 1; i < x1; ++i) p1 = a[p1].r;
    for (int i = 1; i < y1; ++i) p1 = a[p1].d;
    for (int i = 1; i < x2; ++i) p2 = a[p2].r;
    for (int i = 1; i < y2; ++i) p2 = a[p2].d;
    int t1 = p1, t2 = p2;
    for (int i = 1; i <= h; ++i)
      t1 = a[t1].d, t2 = a[t2].d, swap(a[t1].r, a[t2].r);
    for (int i = 1; i <= w; ++i)
      t1 = a[t1].r, t2 = a[t2].r, swap(a[t1].d, a[t2].d);
    t1 = p1, t2 = p2;
    for (int i = 1; i <= w; ++i)
      t1 = a[t1].r, t2 = a[t2].r, swap(a[t1].d, a[t2].d);
    for (int i = 1; i <= h; ++i)
      t1 = a[t1].d, t2 = a[t2].d, swap(a[t1].r, a[t2].r);
  }
  for (int i = 1, p; i <= n; ++i) {
    p = D(i, 0);
    for (int j = 1; j <= m; ++j) printf("%d ", a[p = a[p].r].v);
    puts("");
  }
  return 0;
}
