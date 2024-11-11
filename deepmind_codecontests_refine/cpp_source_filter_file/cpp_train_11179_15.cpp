#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[20000], r[20000];
int main() {
  cin >> n >> k;
  int x = 1;
  while (x <= n - 1) {
    x *= 2;
  }
  x /= 2;
  int y = n - 1 - x, t = 1;
  for (int i = 0; i < n; i++) {
    a[i] = n - 1 - i;
  }
  for (int it = 0; it < k; it++) {
    for (int i = 0; i < n; i++) {
      if (i == y) {
        if (a[i] - 1) {
          printf("%d ", y + 1);
        } else {
          printf("%d ", n);
        }
        a[i] >>= 1;
        continue;
      }
      if (r[i]) {
        if ((a[i] & 1) && (it)) {
          printf("%d ", y + 1);
        } else {
          printf("%d ", n);
        }
      } else {
        if (a[i] & 1) {
          printf("%d ", n);
          r[i] = 1;
        } else {
          printf("%d ", i + 1);
        }
      }
      a[i] >>= 1;
    }
    printf("\n");
  }
  return 0;
}
