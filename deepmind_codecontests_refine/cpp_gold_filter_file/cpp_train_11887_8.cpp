#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int x, y, z;
  scanf("%d", &n);
  int a[101000];
  int b[101000];
  b[0] = 2 * n;
  a[0] = 2 * n - 1;
  if (n % 2 == 0) {
    printf("NO");
  } else {
    printf("YES\n");
    int m = n - 1;
    m = m / 2;
    for (x = 1; x <= m; x++) {
      a[2 * x - 1] = 4 * x;
      a[2 * x] = 4 * x - 3;
      b[2 * x - 1] = 4 * x - 1;
      b[2 * x] = 4 * x - 2;
    }
    for (x = 0; x < n; x++) {
      printf("%d ", a[x]);
    }
    for (x = 0; x < n; x++) {
      printf("%d ", b[x]);
    }
  }
  return 0;
}
