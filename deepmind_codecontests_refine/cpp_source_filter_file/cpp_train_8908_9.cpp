#include <bits/stdc++.h>
using namespace std;
const int maxn = 60010;
struct node {
  double left, right;
  node(double a, double b) {
    left = a;
    right = b;
  }
  node() { left = right = -1; }
} q[maxn];
int n;
double x[maxn], v[maxn], mi, ma;
node judge(double t) {
  for (int i = 0; i < n; i++) {
    q[i].left = max(mi, x[i] - t * v[i]);
    q[i].right = min(ma, x[i] + t * v[i]);
  }
  node temp(q[0].left, q[0].right);
  for (int i = 1; i < n; i++) {
    temp.left = max(temp.left, q[i].left);
    temp.right = min(temp.right, q[i].right);
  }
  return temp;
}
int main() {
  while (scanf("%d", &n) != EOF) {
    mi = 0x3fffffff;
    ma = -1;
    for (int i = 0; i < n; i++) {
      scanf("%lf", &x[i]);
      mi = min(mi, x[i]);
      ma = max(ma, x[i]);
    }
    for (int i = 0; i < n; i++) scanf("%lf", &v[i]);
    double l = 0, r = 60010;
    while (r - l >= 0.000001) {
      double mid = (l + r) / 2;
      node t = judge(mid);
      if (t.right - t.left > 0)
        r = mid;
      else
        l = mid;
    }
    printf("%lf\n", l);
  }
  return 0;
}
