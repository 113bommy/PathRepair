#include <bits/stdc++.h>
using namespace std;
int a[100007];
int main() {
  int n, l, x, y;
  scanf("%d %d %d %d", &n, &l, &x, &y);
  int b, g;
  b = g = 0;
  for (int i = 0; i <= n - 1; ++i) {
    scanf("%d", a + i);
    if (binary_search(a, a + i, a[i] - x)) b = 1;
    if (binary_search(a, a + i, a[i] - y)) g = 1;
  }
  if (b && g) {
    printf("0\n");
    return 0;
  }
  if (!b && !g) {
    for (int i = 0; i <= n - 1; ++i) {
      int mrk1 = a[i] + x;
      int mrk2 = a[i] - x;
      int mrk3 = a[i] + y;
      int mrk4 = a[i] - y;
      bool ansrd = 0;
      if ((binary_search(a, a + n, mrk1 - y) ||
           binary_search(a, a + n, mrk1 + y)) &&
          (mrk1 >= 0 && mrk1 <= l)) {
        printf("1\n");
        printf("%d\n", mrk1);
        ansrd = 1;
      } else if ((binary_search(a, a + n, mrk2 - y) ||
                  binary_search(a, a + n, mrk2 + y)) &&
                 (mrk2 >= 0 && mrk2 <= l)) {
        printf("1\n");
        printf("%d\n", mrk2);
        ansrd = 1;
      } else if ((binary_search(a, a + n, mrk3 - x) ||
                  binary_search(a, a + n, mrk3 + x)) &&
                 (mrk3 >= 0 && mrk3 <= l)) {
        printf("1\n");
        printf("%d %d\n", mrk3, l);
        ansrd = 1;
      } else if ((binary_search(a, a + n, mrk4 - x) ||
                  binary_search(a, a + n, mrk4 + x)) &&
                 (mrk4 >= 0 && mrk4 <= l)) {
        printf("1\n");
        printf("%d\n", mrk4);
        ansrd = 1;
      }
      if (ansrd) return 0;
    }
  }
  if (!b && !g) {
    printf("2\n");
    printf("%d %d\n", x, y);
    return 0;
  }
  if (!g) {
    printf("1\n");
    printf("%d\n", y);
  }
  if (!b) {
    printf("1\n");
    printf("%d\n", x);
  }
  return 0;
}
