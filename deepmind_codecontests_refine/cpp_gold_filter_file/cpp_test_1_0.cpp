#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const double eps = 1e-6, pi = acos(-1);
int i, k, n;
double l, r;
int x[maxn], y[maxn];
struct node {
  double pos;
  int num;
} a[4 * maxn];
bool cmp(node x, node y) { return x.pos < y.pos; }
bool check(double r) {
  int sum = 0, tot = 0;
  for (i = 1; i <= n; i++) {
    double d = sqrt(1.0 * x[i] * x[i] + 1.0 * y[i] * y[i]);
    if (d >= 2 * r + eps) continue;
    double alpha = y[i] >= 0 ? atan2(y[i], x[i]) : atan2(y[i], x[i]) + 2 * pi;
    double beita = acos(d / (2 * r));
    if (alpha - beita < eps) {
      a[++tot] = (node){0, 1};
      a[++tot] = (node){alpha + beita, -1};
      a[++tot] = (node){alpha - beita + 2 * pi, 1};
      a[++tot] = (node){2 * pi, -1};
    } else if (alpha + beita <= 2 * pi + eps) {
      a[++tot] = (node){alpha - beita, 1};
      a[++tot] = (node){alpha + beita, -1};
    } else {
      a[++tot] = (node){0, 1};
      a[++tot] = (node){alpha + beita - 2 * pi, -1};
      a[++tot] = (node){alpha - beita, 1};
      a[++tot] = (node){2 * pi, -1};
    }
  }
  sort(a + 1, a + tot + 1, cmp);
  for (i = 1; i <= tot; i++) {
    sum += a[i].num;
    if (sum >= k) return true;
  }
  return false;
}
int main() {
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> x[i] >> y[i];
  l = 0, r = 2e5;
  while (r - l > 1e-5) {
    double mid = (l + r) / 2;
    if (check(mid) == true)
      r = mid;
    else
      l = mid;
  }
  printf("%.5lf", r);
  return 0;
}
