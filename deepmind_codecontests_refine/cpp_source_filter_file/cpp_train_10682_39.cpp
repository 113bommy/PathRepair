#include <bits/stdc++.h>
int main() {
  unsigned long t, k, n;
  while (~scanf("%lu%lu%lu", &n, &k, &t)) {
    if (t <= k) {
      printf("%lu\n", t);
    } else if (t <= n) {
      printf("%lu\n", k);
    } else {
      printf("%lu\n", 2 * n - k - t);
    }
  }
}
