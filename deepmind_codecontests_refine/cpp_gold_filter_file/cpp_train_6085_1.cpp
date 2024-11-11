#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    if (n == 0) {
      printf("%d %d\n", 0, 1);
      printf("%d %d\n", 0, m);
      printf("%d %d\n", 0, 0);
      printf("%d %d\n", 0, m - 1);
    } else if (m == 0) {
      printf("%d %d\n", 1, 0);
      printf("%d %d\n", n, 0);
      printf("%d %d\n", 0, 0);
      printf("%d %d\n", n - 1, 0);
    } else {
      if (n >= m) {
        double d1 = 2 * sqrt(n * n + m * m) + n;
        double d2 = sqrt(n * n + m * m) + 2 * sqrt((m - 1) * (m - 1) + n * n);
        if (d1 > d2) {
          printf("%d %d\n%d %d\n%d %d\n%d %d\n", n, m, 0, 0, n, 0, 0, m);
        } else {
          printf("%d %d\n%d %d\n%d %d\n%d %d\n", 0, 1, n, m, 0, 0, n, m - 1);
        }
      } else {
        double d1 = 2 * sqrt(n * n + m * m) + m;
        double d2 = sqrt(n * n + m * m) + 2 * sqrt((n - 1) * (n - 1) + m * m);
        if (d1 > d2) {
          printf("%d %d\n%d %d\n%d %d\n%d %d\n", n, m, 0, 0, 0, m, n, 0);
        } else {
          printf("%d %d\n%d %d\n%d %d\n%d %d\n", 1, 0, n, m, 0, 0, n - 1, m);
        }
      }
    }
  }
  return 0;
}
