#include <bits/stdc++.h>
using namespace std;
const int N = 6001;
int n, m, k, a, b, x[N], y[N], z[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d", &y[i]);
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) scanf("%d", &z[i]);
  scanf("%d%d", &a, &b);
  sort(x + 1, x + 1 + n);
  sort(y + 1, y + 1 + m);
  sort(z + 1, z + 1 + k);
  double p2 = z[1];
  double r1 = x[n];
  double res = 0;
  for (int i = 1; i <= m; i++) {
    double p1 = y[i];
    double cur = (p1 * b * r1 * r1) / (p1 * b + p2 * a);
    cur = sqrt(cur);
    if (cur - res > 1e-6) res = cur;
  }
  printf("%.7f\n", res);
  return 0;
}
