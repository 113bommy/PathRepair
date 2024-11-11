#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, cx, cy, dx, dy, F1, F2, F;
int x[100010], y[100010], xx[100010], yy[100010];
long long an;
int main() {
  scanf("%d", &n);
  m = (n + 1) / 2;
  for (i = 1; i <= n; i++)
    scanf("%d%d", &x[i], &y[i]), xx[i] = x[i], yy[i] = y[i];
  sort(xx + 1, xx + n + 1);
  sort(yy + 1, yy + n + 1);
  cx = xx[m];
  cy = yy[m];
  dx = xx[m + 1] - xx[m], dy = yy[m + 1] - yy[m];
  if (n & 1) dx = min(dx, xx[m] - xx[m - 1]), dy = min(dy, yy[m] - yy[m - 1]);
  for (i = 1; i <= n; i++) {
    an += abs(x[i] - cx) + abs(y[i] - cy);
    if (x[i] > cx && y[i] <= cy) F1 = 1;
    if (x[i] > cx && y[i] > cy) F2 = 1;
    if (x[i] == cx && y[i] == cy) F = 1;
  }
  if ((F || n % 2 == 0) && F1 && F2) an = max(an - dx, an - dy);
  printf("%I64d\n", an * 2);
  return 0;
}
