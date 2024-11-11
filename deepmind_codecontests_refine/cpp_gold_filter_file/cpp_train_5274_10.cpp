#include <bits/stdc++.h>
using namespace std;
double cmp(double a, double b) { return a < b; }
int main() {
  double u, a[100010];
  double ans;
  ans = -1;
  int i, j, k, m, n;
  scanf("%d%lf", &n, &u);
  memset(a, 0, sizeof(a));
  for (i = 1; i <= n; i++) scanf("%lf", &a[i]);
  sort(a + 1, a + n + 1, cmp);
  for (i = 1; i < n - 1; i++) {
    int x, y, mid;
    if (a[i + 2] - a[i] > u) continue;
    x = i + 2, y = n;
    while (x < y) {
      mid = (x + y + 1) / 2;
      if (a[mid] - a[i] > u)
        y = mid - 1;
      else
        x = mid;
    }
    ans = max(ans, (a[y] - a[i + 1]) / (a[y] - a[i]));
  }
  if (ans < -0.5)
    printf("-1\n");
  else
    printf("%.10f\n", ans);
  return 0;
}
