#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
struct node {
  double a, b;
} e[100010];
int n;
double getl(node X, node Y) {
  double d1 = (X.a - Y.a) * (X.a - Y.a);
  double d2 = (X.b - Y.b) * (X.b - Y.b);
  return sqrt(d1 + d2);
}
double getlength(node A, node B, node C, double &temp) {
  double a = getl(A, C);
  double b = getl(B, C);
  double c = getl(A, B);
  temp = max(a, b);
  if (a * a >= b * b + c * c) return b;
  if (b * b >= a * a + c * c) return a;
  double pp = (a + b + c) / 2;
  double s = (pp - a) * (pp - b) * (pp - c) * pp;
  s = sqrt(s);
  double d = s * 2 / c;
  return d;
}
int main() {
  node t;
  int i, j;
  while (cin >> n) {
    cin >> t.a >> t.b;
    for (i = 0; i < n; i++) cin >> e[i].a >> e[i].b;
    double maxn = -(double)10000000;
    ;
    double minx = (double)10000000;
    ;
    double temp;
    for (i = 0; i < n; i++) {
      minx = min(minx, getlength(e[i], e[(i + 1) % n], t, temp));
      maxn = max(maxn, temp);
    }
    double ans = PI * (maxn * maxn - minx * minx);
    printf("%.10lf\n", ans);
  }
  return 0;
}
