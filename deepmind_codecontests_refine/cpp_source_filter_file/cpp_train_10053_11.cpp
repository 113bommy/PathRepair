#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
const double eps = 1e-8;
int n, a, b, num1[maxn], num2[maxn];
double p[maxn], q[maxn], dp[maxn];
bool ck(double x, double y, int op) {
  double tmp;
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1], num1[i] = num1[i - 1], num2[i] = num2[i - 1];
    tmp = dp[i - 1] + p[i] - x;
    if (tmp > dp[i]) {
      dp[i] = tmp, num1[i] = num1[i - 1] + 1, num2[i] = num2[i - 1];
    }
    tmp = dp[i - 1] + q[i] - y;
    if (tmp > dp[i]) {
      dp[i] = tmp, num1[i] = num1[i - 1], num2[i] = num2[i - 1] + 1;
    }
    tmp = dp[i - 1] + p[i] + q[i] - p[i] * q[i] - x - y;
    if (tmp > dp[i]) {
      dp[i] = tmp, num1[i] = num1[i - 1] + 1, num2[i] = num2[i - 1] + 1;
    }
  }
  if (op == 1)
    return num1[n] <= a;
  else
    return num2[n] <= b;
}
signed main() {
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 1; i <= n; i++) scanf("%lf", p + i);
  for (int i = 1; i <= n; i++) scanf("%lf", q + i);
  double l1 = 0, r1 = 1.0, mid1, l2, r2, mid2;
  while (r1 - l1 > eps) {
    mid1 = (l1 + r1) / 2;
    l2 = 0, r2 = 1.0;
    while (r2 - l2 > eps) {
      mid2 = (l2 + r2) / 2;
      if (ck(mid1, mid2, 2))
        r2 = mid2 - eps;
      else
        l2 = mid2 + eps;
    }
    if (ck(mid1, l2, 1))
      r1 = mid1 - eps;
    else
      l1 = mid1 + eps;
  }
  ck(l1, l2, 1);
  printf("%.5lf\n", dp[n] + l1 * a + l2 * b);
}
