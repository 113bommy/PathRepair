#include <bits/stdc++.h>
void solve(const int n, const int m, const int cl, const int ce, const int v,
           const int *ll, const int *e) {
  int x, y, p, q;
  scanf("%d%d%d%d", &x, &y, &p, &q);
  if (x == p) {
    printf("%d\n", ((y - q) > (0) ? (y - q) : -(y - q)));
    return;
  }
  if (y > q) {
    int swap = y;
    y = q;
    q = swap;
  }
  int min = n + 2 * m;
  if (cl > 0) {
    int l = 0;
    int r = cl;
    while (l + 1 < r) {
      int m = (l + r) / 2;
      if (ll[m] >= y) {
        r = m;
      } else {
        l = m;
      }
    }
    min = ((min) < (((ll[l] - y) > (0) ? (ll[l] - y) : -(ll[l] - y)) +
                    ((x - p) > (0) ? (x - p) : -(x - p)) +
                    ((ll[l] - q) > (0) ? (ll[l] - q) : -(ll[l] - q)))
               ? (min)
               : (((ll[l] - y) > (0) ? (ll[l] - y) : -(ll[l] - y)) +
                  ((x - p) > (0) ? (x - p) : -(x - p)) +
                  ((ll[l] - q) > (0) ? (ll[l] - q) : -(ll[l] - q))));
    if (r < cl)
      min = ((min) < (((ll[r] - y) > (0) ? (ll[r] - y) : -(ll[r] - y)) +
                      ((x - p) > (0) ? (x - p) : -(x - p)) +
                      ((ll[r] - q) > (0) ? (ll[r] - q) : -(ll[r] - q)))
                 ? (min)
                 : (((ll[r] - y) > (0) ? (ll[r] - y) : -(ll[r] - y)) +
                    ((x - p) > (0) ? (x - p) : -(x - p)) +
                    ((ll[r] - q) > (0) ? (ll[r] - q) : -(ll[r] - q))));
  }
  if (ce > 0) {
    int l = 0;
    int r = ce;
    while (l + 1 < r) {
      int m = (l + r) / 2;
      if (e[m] >= y) {
        r = m;
      } else {
        l = m;
      }
    }
    min = ((min) < (((e[l] - y) > (0) ? (e[l] - y) : -(e[l] - y)) +
                    (((x - p) > (0) ? (x - p) : -(x - p)) + v - 1) / v +
                    ((e[l] - q) > (0) ? (e[l] - q) : -(e[l] - q)))
               ? (min)
               : (((e[l] - y) > (0) ? (e[l] - y) : -(e[l] - y)) +
                  (((x - p) > (0) ? (x - p) : -(x - p)) + v - 1) / v +
                  ((e[l] - q) > (0) ? (e[l] - q) : -(e[l] - q))));
    if (r < cl)
      min = ((min) < (((e[r] - y) > (0) ? (e[r] - y) : -(e[r] - y)) +
                      (((x - p) > (0) ? (x - p) : -(x - p)) + v - 1) / v +
                      ((e[r] - q) > (0) ? (e[r] - q) : -(e[r] - q)))
                 ? (min)
                 : (((e[r] - y) > (0) ? (e[r] - y) : -(e[r] - y)) +
                    (((x - p) > (0) ? (x - p) : -(x - p)) + v - 1) / v +
                    ((e[r] - q) > (0) ? (e[r] - q) : -(e[r] - q))));
  }
  printf("%d\n", min);
  return;
}
void run(void) {
  int n, m, cl, ce, v;
  scanf("%d%d%d%d%d", &n, &m, &cl, &ce, &v);
  int *l = (int *)malloc(sizeof(int) * (cl + 1));
  int i;
  for (i = 0; i < cl; i++) scanf("%d", l + i);
  int *e = (int *)malloc(sizeof(int) * (ce + 1));
  for (i = 0; i < ce; i++) scanf("%d", e + i);
  int q;
  scanf("%d", &q);
  while (q--) {
    solve(n, m, cl, ce, v, l, e);
  }
  return;
}
int main(void) {
  run();
  return 0;
}
