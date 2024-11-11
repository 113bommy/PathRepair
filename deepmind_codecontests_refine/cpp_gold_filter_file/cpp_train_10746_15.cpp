#include <bits/stdc++.h>
using namespace std;
int n, i, j = 1, k = 1, l, x, y, z, a[400008], b[400008];
int main() {
  for (scanf("%d", &n); i < n; scanf("%d", a + i++))
    ;
  for (; j < (1 << 25); 1 & l ? z |= j : 0, k = ((j <<= 1) << 1) - 1) {
    for (y = (x = j << 1) | k, x |= j, l = 0, i = n; i--; b[i] = a[i] & k)
      ;
    for (sort(b, b + n), i = n; --i;
         l ^= upper_bound(b, b + i, k - b[i]) - lower_bound(b, b + i, j - b[i]),
                         l ^= upper_bound(b, b + i, y - b[i]) -
                              lower_bound(b, b + i, x - b[i]))
      ;
  }
  printf("%d\n", z), exit(0);
}
