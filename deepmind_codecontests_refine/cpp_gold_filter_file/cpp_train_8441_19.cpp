#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const double eps = 1e-10;
const double pi = acos(-1);
int n, sz;
double ang[maxn];
struct node {
  double x, y;
  node(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
} p[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    sz = 0;
    for (int j = 1; j <= n; j++)
      if (j != i) ang[++sz] = atan2(p[j].y - p[i].y, p[j].x - p[i].x);
    sort(ang + 1, ang + sz + 1);
    for (int j = 1, k = 1; j <= sz && ang[j] < eps; j++) {
      while (k <= sz && ang[k] - ang[j] < pi + eps) k++;
      long long a = k - j - 1, b = sz - a - 1;
      ans += (a * (a - 1) / 2) * (b * (b - 1) / 2);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
