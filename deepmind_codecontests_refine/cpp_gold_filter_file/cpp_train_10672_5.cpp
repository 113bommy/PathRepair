#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, pri;
  scanf("%d%d", &n, &pri);
  int l[100005], r[100005], num[100005];
  double p[100005];
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &l[i], &r[i]);
    p[i] = 1.0000000000000 / (r[i] - l[i] + 1);
    num[i] = r[i] / pri - l[i] / pri;
    if (l[i] % pri == 0) num[i]++;
    p[i] = p[i] * num[i];
  }
  double sum = 0;
  for (int i = 1; i <= n - 1; i++) {
    double t = 2000 * 1.000000000 * p[i] * p[i + 1] +
               2000 * 1.0000000000 * p[i] * (1 - p[i + 1]) +
               2000 * 1.000000000 * (p[i + 1]) * (1 - p[i]);
    sum += t;
  }
  double t = 2000 * 1.000000000000000 * (p[n]) * (1 - p[1]) +
             2000 * 1.0000000000 * (p[1]) * (1 - p[n]) +
             2000 * 1.0000000000000 * p[1] * p[n];
  sum += t;
  printf("%.9lf\n", sum);
  return 0;
}
