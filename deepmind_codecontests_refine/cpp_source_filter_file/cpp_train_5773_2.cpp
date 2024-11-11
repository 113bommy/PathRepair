#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n * m == 1) {
    printf("1\n1 1 1 1\n1 1\n1 1");
    return 0;
  }
  if (n == 1 && m != 2) {
    printf("1\n1 %d 1 1\n", m);
    for (int i = 1; i <= n; i++) printf("1 %d\n", i);
    printf("1 1");
    return 0;
  }
  if (m == 1 && n != 2) {
    printf("1\n%d 1 1 1\n", n);
    for (int i = 1; i <= n; i++) printf("%d 1\n", i);
    printf("1 1");
    return 0;
  }
  if (n % 2 == 0) {
    printf("0\n1 1\n");
    for (int i = 1; i <= n / 2; i++) {
      int x = 2, y = i * 2 - 1;
      while (x <= m) {
        printf("%d %d\n", y, x);
        x++;
      }
      x = m;
      y++;
      while (x > 1) {
        printf("%d %d\n", y, x);
        x--;
      }
    }
    for (int i = n; i >= 1; i--) printf("%d 1\n", i);
  } else if (m % 2 == 0) {
    printf("0\n1 1\n");
    for (int i = 1; i <= m / 2; i++) {
      int x = i * 2 - 1, y = 2;
      while (y <= n) {
        printf("%d %d\n", y, x);
        y++;
      }
      x = i * 2;
      y = n;
      while (y > 1) {
        printf("%d %d\n", y, x);
        y--;
      }
    }
    for (int i = m; i >= 1; i--) printf("1 %d\n", i);
  } else {
    printf("1\n%d %d 1 1\n", n, m);
    for (int i = 1; i <= n; i++)
      if (i % 2 == 1)
        for (int j = 1; j <= m; j++) printf("%d %d\n", i, j);
      else
        for (int j = m; j >= 1; j--) printf("%d %d\n", i, j);
    printf("1 1");
  }
  return 0;
}
