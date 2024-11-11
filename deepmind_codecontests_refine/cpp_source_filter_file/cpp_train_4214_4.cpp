#include <bits/stdc++.h>
using namespace std;
const int lim = 1000000;
int n;
int a[4];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  if (n == 0) {
    printf("YES\n1\n1\n3\n3\n");
    return 0;
  } else if (n == 1) {
    printf("YES\n");
    printf("%d\n%d\n%d\n", a[0], 3 * a[0], 3 * a[0]);
    return 0;
  } else if (n == 2) {
    sort(a, a + n);
    int x1, x2, x3, x4;
    x1 = a[0];
    x2 = a[1];
    x3 = 4 * a[0] - a[1];
    x4 = 3 * a[1];
    if (x3 > 0 && x3 <= x4 && x3 >= a[0]) {
      printf("YES\n");
      printf("%d\n%d\n", x3, x4);
      return 0;
    }
    if (a[1] == 3 * x1) {
      x4 = a[1];
      printf("YES\n");
      printf("%d\n%d\n", x1, x4);
      return 0;
    }
    x2 = a[0];
    if ((a[0] + a[1]) % 4 == 0) {
      x1 = (a[0] + a[1]) / 4;
      if (3 * x1 >= a[1] && x1 <= a[0] && x1 > 0) {
        printf("YES\n");
        printf("%d\n%d\n", x1, 3 * x1);
        return 0;
      }
    }
    if (a[1] % 3 == 0) {
      x1 = a[1] / 3;
      if (x1 > 0 && x1 <= a[0] && 4 * x1 - a[0] <= a[1] &&
          4 * x1 - a[0] >= x1) {
        printf("YES\n");
        printf("%d\n%d\n", min(x1, 4 * x1 - a[0]), max(x1, 4 * x1 - a[0]));
        return 0;
      }
    }
    printf("NO\n");
    return 0;
  } else if (n == 3) {
    sort(a, a + n);
    int x1, x2, x3, x4;
    x1 = a[0];
    if (a[2] == 3 * x1) {
      x4 = a[2];
      x2 = a[1];
      x3 = 4 * x1 - x2;
      if (x3 > 0 && x3 <= x4 && x3 >= a[0]) {
        printf("YES\n");
        printf("%d\n", x3);
        return 0;
      }
    }
    if (a[1] + a[2] == 4 * x1) {
      if (3 * x1 >= a[2]) {
        printf("YES\n");
        printf("%d\n", 3 * x1);
        return 0;
      }
    }
    if (a[2] % 3 == 0) {
      x1 = a[2] / 3;
      if (x1 > 0 && x1 <= a[0] && a[0] + a[1] == 4 * x1) {
        printf("YES\n");
        printf("%d\n", x1);
        return 0;
      }
    }
    printf("NO\n");
    return 0;
  } else {
    sort(a, a + n);
    int x1, x2, x3, x4;
    x1 = a[0];
    if (a[3] == 3 * x1) {
      if (a[2] + a[1] == 4 * x1) {
        printf("YES\n");
        return 0;
      }
    }
    printf("NO\n");
    return 0;
  }
  return 0;
}
