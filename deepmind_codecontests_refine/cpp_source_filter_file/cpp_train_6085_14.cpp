#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n == 0) {
    printf("0 1\n%d %d\n0 0\n0 %d\n", n, m, m - 1);
  } else if (m == 0) {
    printf("1 0\n%d %d\n0 0\%d 0\n", n, m, n - 1);
  } else if (m > n) {
    if (2.0 * sqrt(m * m + (n - 1) * (n - 1)) + sqrt(n * n + m * m) >
        2 * sqrt(n * n + m * m) + m)
      printf("%d %d\n0 0\n%d %d\n1 0\n", n - 1, m, n, m);
    else
      printf("%d %d\n0 0\n0 %d\n%d 0\n", n, m, m, n);
  } else {
    if (2.0 * sqrt(n * n + (m - 1) * (m - 1)) + sqrt(n * n + m * m) >
        2 * sqrt(n * n + m * m) + n)
      printf("0 1\n%d %d\n0 0\n%d %d\n", n, m, n, m - 1);
    else
      printf("%d %d\n0 0\n%d 0\n0 %d\n", n, m, n, m);
  }
  return 0;
}
