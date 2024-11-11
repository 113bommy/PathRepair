#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const double eps = 1e-5;
int n, m;
struct Stop {
  int pos, x;
} a[1005];
double f[1005];
double check(double x) {
  for (int i = 1; i <= n; i++) {
    f[i] = sqrt(fabs(a[i].pos - m)) - x * a[i].x;
    for (int j = 1; j < i; j++) {
      f[i] = min(f[i], f[j] + sqrt(fabs(a[i].pos - a[j].pos - m)) - x * a[i].x);
    }
  }
  return f[n];
}
int pre[1005];
int ans[1005];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i].pos, &a[i].x);
  }
  double l = 0, r = sqrt(m) * n + 1;
  while (r - l > eps) {
    double mid = (l + r) / 2;
    if (check(mid) > -eps) {
      l = mid;
    } else {
      r = mid;
    }
  }
  for (int i = 1; i <= n; i++) {
    f[i] = sqrt(fabs(a[i].pos - m)) - l * a[i].x;
    pre[i] = 0;
    for (int j = 1; j < i; j++) {
      if (f[i] >
          f[j] + sqrt(fabs(a[i].pos - a[j].pos - m)) - l * a[i].x + eps) {
        f[i] = f[j] + sqrt(fabs(a[i].pos - a[j].pos - m)) - l * a[i].x;
        pre[i] = j;
      }
    }
  }
  int len = 0;
  int p = n;
  while (p != 0) {
    ans[++len] = p;
    p = pre[p];
  }
  reverse(ans + 1, ans + len + 1);
  for (int i = 1; i <= len; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
