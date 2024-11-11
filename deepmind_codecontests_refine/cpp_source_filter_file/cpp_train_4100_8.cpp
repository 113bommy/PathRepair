#include <bits/stdc++.h>
const double eps = 1E-10;
int main() {
  int N, i;
  double length, amount, temp, ans;
  scanf("%d", &N);
  ans = 0;
  for (i = 0; i < N; ++i) {
    scanf("%lf%lf", &length, &amount);
    temp = length + log(amount) / log(4);
    if (fabs(amount - 1) < eps) temp += eps;
    if (i == 0 || ans < temp) ans = temp;
  }
  printf("%.0lf", ceil(ans));
  return 0;
}
