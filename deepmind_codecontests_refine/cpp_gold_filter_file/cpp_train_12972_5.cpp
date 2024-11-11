#include <bits/stdc++.h>
using namespace std;
struct aaa {
  int x, y;
} a[2502];
int n;
double ans, f[2502][2502][2];
double sqr(double x) { return x * x; }
double dis(int x, int y) {
  return sqrt(sqr(a[x].x - a[y].x) + sqr(a[x].y - a[y].y));
}
int main() {
  int i, j, l, ii, jj;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d%d", &a[i].x, &a[i].y);
  for (l = 1; l < n; l++)
    for (i = 0; i < n; i++) {
      j = (i + l - 1) % n;
      ii = (i - 1 + n) % n;
      jj = (j + 1) % n;
      f[l + 1][ii][0] = max(f[l + 1][ii][0], max(f[l][i][0] + dis(i, ii),
                                                 f[l][i][1] + dis(j, ii)));
      f[l + 1][i][1] = max(f[l + 1][i][1], max(f[l][i][0] + dis(i, jj),
                                               f[l][i][1] + dis(j, jj)));
    }
  for (i = 0; i < n; i++) ans = max(ans, max(f[n][i][0], f[n][i][1]));
  printf("%.10lf", ans);
}
