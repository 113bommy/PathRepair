#include <bits/stdc++.h>
using namespace std;
int RI() {
  int x;
  scanf("%d", &x);
  return x;
}
const int N = 100000;
int a[N], dp[N], b[N + 1];
int main() {
  int k = RI(), n = RI(), maxb = RI(), t = RI();
  while (k--) {
    for (int i = (0); i < (n); i++) a[i] = RI();
    if (t >= min(maxb, n)) {
      sort(a, a + n);
      printf("%td\n", unique(a, a + n) - a);
    } else {
      int maxdp = 0;
      fill_n(dp, n, 0);
      fill_n(b, n + 1, 0);
      for (int i = (0); i < (t); i++)
        for (int j = (0); j < (n); j++) {
          for (; dp[j] <= maxdp && b[dp[j]] < a[j]; dp[j]++)
            ;
          b[dp[j]] = a[j];
          maxdp = max(maxdp, dp[j]);
        }
      printf("%d\n", maxdp);
    }
  }
}
