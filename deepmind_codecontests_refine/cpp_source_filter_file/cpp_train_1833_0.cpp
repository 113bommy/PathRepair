#include <bits/stdc++.h>
using namespace std;
struct sofa {
  int x1, y1, x2, y2;
} p[100010];
int d, n, m;
int xsa[100010], ysa[100010], xsb[100010], ysb[100010];
int xa[100010], ya[100010], xb[100010], yb[100010];
int ql, qr, qt, qb;
int sl, sr, st, sb;
int main() {
  scanf("%d", &d);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < d; i++) {
    scanf("%d%d%d%d", &p[i].x1, &p[i].y1, &p[i].x2, &p[i].y2);
    if (p[i].x1 == p[i].x2) {
      ya[min(p[i].y1, p[i].y2)]++;
      xa[p[i].x1]++;
      xb[p[i].x1]++;
      yb[max(p[i].y1, p[i].y2)]++;
    }
    if (p[i].y1 == p[i].y2) {
      xb[max(p[i].x1, p[i].x2)]++;
      yb[p[i].y1]++;
      ya[p[i].y1]++;
      xa[min(p[i].x1, p[i].x2)]++;
    }
  }
  for (int i = 1; i <= n; i++) xsa[i] = xsa[i - 1] + xa[i];
  for (int i = n; i >= 1; i--) xsb[i] = xsb[i + 1] + xb[i];
  for (int i = 1; i <= m; i++) ysa[i] = ysa[i - 1] + ya[i];
  for (int i = m; i >= 1; i--) ysb[i] = ysb[i + 1] + yb[i];
  scanf("%d%d%d%d", &ql, &qr, &qt, &qb);
  for (int i = 0; i < d; i++) {
    if (p[i].x1 == p[i].x2)
      sl = xsa[p[i].x1 - 1];
    else
      sl = xsa[min(p[i].x1, p[i].x2)] - 1;
    if (sl != ql) continue;
    if (p[i].x1 == p[i].x2)
      sr = xsb[p[i].x1 + 1];
    else
      sr = xsb[min(p[i].x1, p[i].x2)] - 1;
    if (sr != qr) continue;
    if (p[i].y1 == p[i].y2)
      st = ysa[p[i].y1 - 1];
    else
      st = ysa[min(p[i].y1, p[i].y2)] - 1;
    if (st != qt) continue;
    if (p[i].y1 == p[i].y2)
      sb = ysb[p[i].y1 + 1];
    else
      sb = ysb[min(p[i].y1, p[i].y2)] - 1;
    if (sb != qb) continue;
    printf("%d\n", i + 1);
    return 0;
  }
  printf("-1\n");
  return 0;
}
