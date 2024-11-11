#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-14;
int a[2010], b[2010], c[2010];
struct point {
  long double x, y;
  bool operator<(point a) const {
    return x + eps < a.x || (fabs(x - a.x) <= eps && y + eps < a.y);
  }
} d[2010], f[2010];
bool cmp(point a, point b) { return a.x * b.y + eps < a.y * b.x; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
  for (int i = 1; i <= n; i++) {
    double t = -(long double)(c[i]) / (a[i] * a[i] + b[i] * b[i]);
    d[i].x = t * a[i];
    d[i].y = t * b[i];
  }
  sort(d + 1, d + n + 1);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = i + 1; j <= n; j++)
      if (fabs(d[i].x - d[j].x) < eps && fabs(d[i].y - d[j].y) < eps)
        ans += (n - j);
      else {
        f[++cnt].x = d[j].x - d[i].x;
        f[cnt].y = d[j].y - d[i].y;
      }
    sort(f + 1, f + cnt + 1, cmp);
    int j = 1;
    while (j <= cnt) {
      int k = j;
      while (k <= cnt && fabs(f[k].x * f[j].y - f[j].x * f[k].y) < eps) k++;
      ans = ans + (k - j) * (k - j - 1) / 2;
      j = k;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
