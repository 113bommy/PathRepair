#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, n, m, z;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d", &n);
    m = n / 4;
    z = n % 4;
    if (z == 0)
      printf("%d\n", m);
    else if (z == 1) {
      m -= 2;
      (m >= 0) ? printf("%d\n", m + 1) : printf("-1\n");
    } else if (z == 2) {
      m -= 1;
      (m >= 0) ? printf("%d\n", m + 1) : printf("-1\n");
    } else {
      m -= 3;
      (m >= 0) ? printf("%d\n", m + 1) : printf("-1\n");
    }
  }
  return 0;
}
