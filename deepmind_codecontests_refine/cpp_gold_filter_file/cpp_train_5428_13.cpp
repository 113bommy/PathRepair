#include <bits/stdc++.h>
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n > m) std::swap(n, m);
  switch (n) {
    case 1:
      return printf("%d\n", m * n - ((m + 2) / 3)), 0;
    case 2:
      return printf("%d\n", m * n - (m / 2 + 1)), 0;
    case 3:
      switch (m % 4) {
        case 0:
        case 1:
          return printf("%d\n", m * n - (m / 4 * 3 + 1)), 0;
        case 3:
          return printf("%d\n", m * n - ((m + 1) / 4 * 3)), 0;
        case 2:
          return printf("%d\n", m * n - (m / 4 * 3 + 2)), 0;
      }
    case 4:
      switch (m) {
        case 4:
          return printf("%d\n", m * n - (4)), 0;
        case 5:
          return printf("%d\n", m * n - (6)), 0;
        case 6:
        case 7:
          return printf("%d\n", m * n - (7)), 0;
        case 8:
          return printf("%d\n", m * n - (8)), 0;
        case 9:
        case 10:
          return printf("%d\n", m * n - (10)), 0;
      }
    case 5:
      return printf("%d\n", m * n - (m + 1 + m / 4)), 0;
    case 6:
      return printf("%d\n", m * n - (10)), 0;
  }
}
