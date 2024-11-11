#include <bits/stdc++.h>
const double esp = 1e-8;
int ll, v1, v2;
int n, nn;
double a[200010], ans[100010];
double dl, dr, len;
void solve() {
  int i;
  int l, r;
  dl = 0;
  dr = len;
  l = r = 1;
  while (a[l] - esp < dl) l++;
  while (a[r] < dr) r++;
  while (l <= n + 1) {
    if (a[r] - dr < a[l] - dl) {
      if (r > n + 1)
        ans[r - l - 1] += a[r] - dr;
      else
        ans[r - l] += a[r] - dr;
      dl += a[r] - dr;
      dr = a[r];
      r++;
    } else {
      if (r > n + 1)
        ans[r - l - 1] += a[l] - dl;
      else
        ans[r - l] += a[l] - dl;
      dr += a[l] - dl;
      dl = a[l];
      l++;
    }
  }
  for (i = 0; i <= n; i++) printf("%.15lf\n", ans[i] / 2.0 / (double)ll);
}
int main() {
  int i, j, nn;
  scanf("%d%d%d%d", &n, &ll, &v1, &v2);
  for (i = 1; i <= n; i++) {
    scanf("%lf", &a[i]);
  }
  a[n + 1] = 2.0 * ll;
  for (i = 1; i <= n; i++) {
    if (a[i] < ll)
      a[i + n + 1] = a[i] + 2.0 * ll;
    else
      break;
  }
  nn = n + i;
  a[nn + 1] = 1e10;
  len = (double)ll - (double)v1 * ll / (v1 + v2 + 0.0);
  solve();
  return 0;
}
