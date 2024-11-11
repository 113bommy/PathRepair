#include <bits/stdc++.h>
using namespace std;
int main() {
  long unsigned int n, m;
  uint64_t k;
  scanf("%lu %lu %I64d", &n, &m, &k);
  if (k <= n - 1) {
    printf("%I64d %d", 1 + k, 1);
  } else {
    if (m == 2) {
      printf("%I64d %d", n - (k + 2 - n - m), 2);
    } else {
      if (k <= n + m - 2) {
        printf("%lu %I64d", n, 1 + k - n + 1);
      } else {
        long unsigned int y, x = n - 1 - (k + 1 - n - m) / (m - 1);
        if ((n - x) % 2 == 0) {
          y = 2 + (k - n - m + 1) % (m - 1);
        } else {
          y = m - (k - n - m + 1) % (m - 1);
        }
        printf("%lu %lu", x, y);
      }
    }
  }
  return 0;
}
