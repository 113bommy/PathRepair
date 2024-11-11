#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 5e5 + 5;
const int INF = 0x7fffffff;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
int n;
double x[maxn], y[maxn];
double cal(int a, int b, int c) {
  int x0 = x[a], y0 = y[a], x1 = x[b], x2 = x[c], y1 = y[b], y2 = y[c];
  double l = abs((x0 - x1) * (y1 - y2) - (x1 - x2) * (y0 - y1)) /
             sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
  return l / 2;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf", &x[i], &y[i]);
  }
  double ans = 1e9;
  for (int i = 0; i < n; i++) {
    ans = min(ans, cal(i, (i + n - 1) % n, (i + 1) % n));
  }
  printf("%.6f\n", ans);
  return 0;
}
