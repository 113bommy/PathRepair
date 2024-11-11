#include <bits/stdc++.h>
unsigned O[33];
int main() {
  unsigned i = -1, j, k, n, r;
  char c;
  for (scanf("%u", &n); ++i < n; O[c ^ 64] = 1)
    while ((c = getchar()) < 'A')
      ;
  for (j = k = 0, i = -1; ++i < 33;) {
    if (O[i] > k) k = O[i], j = 0;
    if (O[i] == k) ++j;
  }
  for (r = 1;; j = j * (long long unsigned)j % 1000000007) {
    if (n & 1) r = r * (long long unsigned)j % 1000000007;
    if (!(n >>= 1)) break;
  }
  printf("%u\n", r);
  return 0;
}
