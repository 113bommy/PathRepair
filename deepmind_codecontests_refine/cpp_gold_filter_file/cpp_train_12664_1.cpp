#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5;
int a[maxn + 5];
long long sum[maxn + 5], b[maxn + 5];
double c[maxn + 5];
int main() {
  int type, x, q, num = 0;
  double max1 = 0;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d", &x);
      num++;
      a[num] = x;
      sum[num] = sum[num - 1] + a[num];
      b[num - 1] = 1LL * num * a[num] - sum[num - 1];
      int pos1 = lower_bound(b + 1, b + num, a[num]) - b;
      int pos2 = upper_bound(b + 1, b + num, a[num]) - b - 1;
      c[num] = a[num] - (a[num] + sum[pos1]) * 1.0 / (pos1 + 1);
      c[num] = max(c[num], a[num] - (a[num] + sum[pos2]) * 1.0 / (pos2 + 1));
      if (c[num] > max1) max1 = c[num];
    } else if (type == 2) {
      printf("%.10f\n", max1);
    }
  }
  return 0;
}
