#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    long long L = 0, R = n, ans = -1;
    while (L <= R) {
      int mid = (L + R) >> 1;
      long long sum1 = mid * m;
      double current = 1, sum_num = 1;
      for (int i = 1; i <= mid && sum_num < n - eps; i++) {
        current = current * (mid - i + 1) / i;
        if (current * i > sum1) {
          sum_num += floor(sum1 / i);
          break;
        } else {
          sum1 -= current * i;
          sum_num += current;
        }
      }
      if (sum_num >= n - eps)
        ans = mid, R = mid - 1;
      else
        L = mid + 1;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
