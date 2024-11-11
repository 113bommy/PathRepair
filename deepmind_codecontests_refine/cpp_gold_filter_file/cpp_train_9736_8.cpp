#include <bits/stdc++.h>
using namespace std;
int n, A, m, i, x, y, mid, a[200200], mi[200200 << 2], mv[200200 << 2],
    v[200200], p[200200];
double sum, f[200200], g[200200];
void G(int i) {
  f[i] = a[i] >= p[i] ? 0
                      : (double)(v[i] * (a[i] + 1)) / (p[i] + a[i] + 1) -
                            (double)(v[i] * a[i]) / (p[i] + a[i]);
  if (a[i])
    g[i] = a[i] > p[i] ? 0
                       : (double)(v[i] * a[i]) / (p[i] + a[i]) -
                             (double)(v[i] * (a[i] - 1)) / (p[i] + a[i] - 1);
  else
    g[i] = 1e18;
}
void ps(int k) {
  mv[k] = (f[mv[k << 1]] > f[mv[k << 1 | 1]]) ? mv[k << 1] : mv[k << 1 | 1];
  mi[k] = (g[mi[k << 1]] < g[mi[k << 1 | 1]]) ? mi[k << 1] : mi[k << 1 | 1];
}
void bt(int k, int l, int r) {
  if (l == r) {
    mv[k] = mi[k] = l;
    return;
  }
  int mid = l + r >> 1;
  bt(k << 1, l, mid);
  bt(k << 1 | 1, mid + 1, r);
  ps(k);
}
void ex(int k, int l, int r, int x) {
  if (l == r) return;
  int mid = l + r >> 1;
  if (x <= mid)
    ex(k << 1, l, mid, x);
  else
    ex(k << 1 | 1, mid + 1, r, x);
  ps(k);
}
int main() {
  for (scanf("%d%d%d", &n, &A, &m), i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (i = 1; i <= n; i++) scanf("%d", &p[i]), G(i);
  for (bt(1, 1, n), i = 1; i <= A; i++)
    x = mv[1], sum += f[x], a[x]++, G(x), ex(1, 1, n, x);
  for (; m--;) {
    scanf("%d%d", &x, &y);
    if (a[y]) sum -= (double)v[y] * min((double)a[y] / (p[y] + a[y]), 0.5);
    if (x == 1)
      p[y]++;
    else
      p[y]--;
    G(y);
    if (a[y]) sum += (double)v[y] * min((double)a[y] / (p[y] + a[y]), 0.5);
    for (ex(1, 1, n, y); 1;) {
      x = mv[1];
      y = mi[1];
      if (f[x] - g[y] > 0) {
        sum += f[x] - g[y];
        a[x]++;
        G(x);
        a[y]--;
        G(y);
        ex(1, 1, n, x);
        ex(1, 1, n, y);
      } else
        break;
    }
    printf("%.10lf\n", sum);
  }
}
