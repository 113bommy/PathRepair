#include <bits/stdc++.h>
using namespace std;
int a[200000], q[200000];
int main() {
  int n, t;
  double c;
  scanf("%d%d%lf", &n, &t, &c);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) scanf("%d", &q[i]);
  int curq = 0;
  double mean = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    mean = (mean + (double)a[i] / t) / c;
    sum += a[i];
    if (i - t >= 0) sum -= a[i - t];
    if (curq < m && q[curq] == i + 1) {
      double real = (double)sum / t;
      printf("%.6lf %.6lf %.6lf\n", real, mean, abs(mean - real) / real);
      curq++;
    }
  }
  return 0;
}
