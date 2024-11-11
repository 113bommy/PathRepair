#include <bits/stdc++.h>
using namespace std;
long long c[205000];
long long d[205000];
int main() {
  long long n, m, k, l, i, j, r;
  while (~scanf("%I64d", &n)) {
    r = 0;
    l = 1;
    for (i = 1; i <= 10000000; i++) {
      if ((6 * n + i * i * i - i) % (3 * i * i + 3 * i) == 0) {
        long long k = (6 * n + i * i * i - i) / (3 * i * i + 3 * i);
        if (k >= i) {
          if (k == i) r++;
          c[l] = i;
          d[l] = k;
          l++;
        }
      }
    }
    printf("%I64d\n", ((l - 1) * 2 - r));
    for (i = 1; i < l; i++) printf("%I64d %I64d\n", c[i], d[i]);
    for (i = l - 1; i >= 1; i--) {
      if (d[i] == c[i]) continue;
      printf("%I64d %I64d\n", d[i], c[i]);
    }
  }
  return 0;
}
