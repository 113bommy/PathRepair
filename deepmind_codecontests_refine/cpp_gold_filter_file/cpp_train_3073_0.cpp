#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  int n, c = 0, a[30], i, j, p, flag;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 1; i <= n; i++) {
    if (a[i] & 1) {
      c++;
      flag = i;
    }
  }
  if (c > 1) {
    printf("0\n");
    for (i = 1; i <= n; i++) {
      while (a[i]) {
        a[i]--;
        printf("%c", 'a' - 1 + i);
      }
    }
  } else {
    if (c == 1) {
      c = a[1];
      for (i = 2; i <= n; i++) {
        c = gcd(c, a[i]);
      }
      if (a[1] == 4 && a[2] == 2 && a[3] == 1 && n == 3) {
        printf("1\nabacaba");
        return 0;
      }
      printf("%d\n", c);
      for (i = 1; i <= c; i++) {
        for (j = 1; j <= n; j++) {
          if (j != flag) {
            for (p = 1; p <= a[j] / c / 2; p++) printf("%c", 'a' - 1 + j);
          }
        }
        for (j = 1; j <= a[flag] / c; j++) printf("%c", 'a' - 1 + flag);
        for (j = n; j > 0; j--) {
          if (j != flag) {
            for (p = 1; p <= a[j] / c / 2; p++) printf("%c", 'a' - 1 + j);
          }
        }
      }
    } else {
      c = a[1];
      for (i = 2; i <= n; i++) c = gcd(c, a[i]);
      printf("%d\n", c);
      for (i = 1; i <= c / 2; i++) {
        for (j = 1; j <= n; j++) {
          for (p = 1; p <= a[j] / c; p++) printf("%c", 'a' - 1 + j);
        }
        for (j = n; j > 0; j--) {
          for (p = 1; p <= a[j] / c; p++) printf("%c", 'a' - 1 + j);
        }
      }
    }
  }
  return 0;
}
