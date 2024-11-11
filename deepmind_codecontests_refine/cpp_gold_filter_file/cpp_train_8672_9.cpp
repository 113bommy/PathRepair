#include <bits/stdc++.h>
using namespace std;
struct tree {
  int lt, rt;
  double lmax, rmax, max;
} a[600010];
double b[150010], sum[150010];
void init(int lt, int rt, int step) {
  a[step].lt = lt;
  a[step].rt = rt;
  if (lt == rt) {
    a[step].lmax = a[step].rmax = a[step].max =
        max(0.0, (sum[rt] - sum[lt - 1]) / 2 - (b[rt] - b[lt - 1]));
    return;
  }
  int mid = (lt + rt) / 2;
  init(lt, mid, 2 * step);
  init(mid + 1, rt, 2 * step + 1);
  a[step].lmax = max(a[2 * step].lmax, a[2 * step + 1].lmax +
                                           (sum[mid] - sum[lt - 1]) / 2 -
                                           (b[mid] - b[lt - 1]));
  a[step].rmax =
      max(a[2 * step + 1].rmax,
          a[2 * step].rmax + (sum[rt] - sum[mid]) / 2 - (b[rt] - b[mid]));
  a[step].max = max(a[2 * step].max, a[2 * step + 1].max);
  a[step].max = max(a[step].max, a[2 * step].rmax + a[step * 2 + 1].lmax);
}
double query_left(int lt, int rt, int step) {
  if (lt == a[step].lt && a[step].rt == rt) return a[step].lmax;
  if (rt <= a[2 * step].rt) return query_left(lt, rt, 2 * step);
  if (lt > a[2 * step].rt)
    return query_left(lt, rt, 2 * step + 1);
  else {
    double ma1 = query_left(lt, a[2 * step].rt, 2 * step);
    double ma2 = query_left(a[2 * step + 1].lt, rt, 2 * step + 1) +
                 (sum[a[2 * step].rt] - sum[lt - 1]) / 2 -
                 (b[a[2 * step].rt] - b[lt - 1]);
    return max(ma1, ma2);
  }
}
double query_right(int lt, int rt, int step) {
  if (lt == a[step].lt && a[step].rt == rt) return a[step].rmax;
  if (rt <= a[2 * step].rt) return query_right(lt, rt, 2 * step);
  if (lt > a[2 * step].rt)
    return query_right(lt, rt, 2 * step + 1);
  else {
    double ma1 = query_right(a[2 * step + 1].lt, rt, 2 * step + 1);
    double ma2 = query_right(lt, a[2 * step].rt, 2 * step) +
                 (sum[rt] - sum[a[2 * step].rt]) / 2 -
                 (b[rt] - b[a[2 * step].rt]);
    return max(ma1, ma2);
  }
}
double query(int lt, int rt, int step) {
  if (lt == a[step].lt && a[step].rt == rt) return a[step].max;
  if (rt <= a[2 * step].rt) return query(lt, rt, 2 * step);
  if (lt > a[2 * step].rt)
    return query(lt, rt, 2 * step + 1);
  else {
    double ma1 = query(lt, a[2 * step].rt, step * 2);
    double ma2 = query(a[2 * step + 1].lt, rt, 2 * step + 1);
    double lma = query_left(a[2 * step + 1].lt, rt, 2 * step + 1);
    double rma = query_right(lt, a[2 * step].rt, 2 * step);
    return max(max(ma1, ma2), lma + rma);
  }
}
int main() {
  int n, m, i, j, k, c;
  scanf("%d%d%d", &n, &m, &c);
  memset(b, 0, sizeof(b));
  memset(sum, 0, sizeof(sum));
  for (i = 1; i <= n; i++) {
    scanf("%lf", &sum[i]);
  }
  for (i = 2; i <= n; i++) {
    scanf("%lf", &b[i]);
  }
  for (i = 2; i <= n; i++) {
    b[i] = c * 1.0 * b[i] / 100 + b[i - 1];
  }
  int x, y;
  double ans = 0;
  init(1, n, 1);
  while (m--) {
    scanf("%d%d", &x, &y);
    x++;
    ans += query(x, y, 1);
  }
  printf("%.10lf\n", ans);
  return 0;
}
