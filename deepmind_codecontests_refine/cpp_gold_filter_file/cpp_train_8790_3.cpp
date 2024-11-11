#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, p;
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    if (m < n) {
      p = m;
      m = n;
      n = p;
    }
    if (k > n + m - 2) {
      printf("%d\n", -1);
    } else if (k >= m - 1) {
      printf("%d\n", n / (k - m + 2));
    } else if (k > n - 1) {
      printf("%I64d\n", (long long)m / (k + 1) * n);
    } else if (k <= n - 1) {
      if ((long long)m / (k + 1) * n > (long long)n / (k + 1) * m)
        printf("%I64d\n", (long long)m / (k + 1) * n);
      else
        printf("%I64d\n", (long long)n / (k + 1) * m);
    }
  }
  return 0;
}
