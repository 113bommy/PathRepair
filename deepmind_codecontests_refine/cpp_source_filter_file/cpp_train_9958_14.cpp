#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  long long x[100006], y[100006];
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < n; i++) {
      scanf("%lld", &x[i]);
    }
    for (int i = 0; i < m; i++) {
      scanf("%lld", &y[i]);
    }
    int first = 1;
    int p1 = 0, p2 = 0, ans = 0;
    long long sum1 = 0, sum2 = 0;
    while (p1 < n && p2 < m) {
      if (first) {
        first = 0;
        sum1 += x[p1];
        sum2 += y[p2];
      }
      if (sum1 > sum2) {
        p2++;
        sum2 += y[p2];
      } else if (sum1 < sum2) {
        p1++;
        sum1 += x[p1];
      } else {
        ans++;
        p1++;
        p2++;
        sum1 = sum2 = 0;
        sum1 += x[p1];
        sum2 += y[p2];
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
