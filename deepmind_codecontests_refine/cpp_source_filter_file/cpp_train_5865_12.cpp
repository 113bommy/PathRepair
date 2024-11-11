#include <bits/stdc++.h>
using namespace std;
int n;
double l, v1, v2;
double a[500008], ans[500008];
int main() {
  scanf("%d%lf%lf%lf", &n, &l, &v1, &v2);
  double s = l / (v2 + v1) * v2;
  for (int i = 1; i <= n; i++) scanf("%lf", &a[i]);
  for (int i = 1; i <= n; i++) a[n + i] = a[i] + 2 * l;
  a[0] = 0;
  int cnt = 1, j = 1;
  for (int i = 0; i <= n - 1; i++) {
    cnt--;
    double tmp = a[i];
    while (j <= 2 * n && a[j] - a[i] <= s) j++, cnt++;
    while (j <= 2 * n && a[j] - a[i] - s < a[i + 1] - a[i]) {
      ans[cnt] += (a[j] - tmp - s) / (2 * l);
      tmp += a[j] - tmp - s;
      j++;
      cnt++;
    }
    ans[cnt] += (a[i + 1] - tmp) / (2 * l);
  }
  cnt--;
  double tmp = a[n];
  while (a[j] - a[n] <= s) j++, cnt++;
  while (j <= 2 * n && a[j] - a[n] - s < 2 * l - a[n]) {
    ans[cnt] += (a[j] - tmp - s) / (2 * l);
    tmp += a[j] - tmp - s;
    j++;
    cnt++;
  }
  ans[cnt] += (2 * l - tmp) / (2 * l);
  for (int i = 0; i <= n; i++) printf("%lf\n", ans[i]);
  return 0;
}
