#include <bits/stdc++.h>
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n % 2 == 0) {
    if (m > 1) {
      printf("0\n");
      for (int j = 0; j < m; j++) printf("%d %d\n", 1, j + 1);
      for (int j = m - 1; j >= 1; j--) printf("%d %d\n", 2, j + 1);
      for (int i = 2; i < n; i += 2) {
        for (int j = 1; j < m; j++) printf("%d %d\n", i + 1, j + 1);
        for (int j = m - 1; j >= 1; j--) printf("%d %d\n", i + 2, j + 1);
      }
      for (int i = n - 1; i >= 0; i--) printf("%d %d\n", i + 1, 1);
    } else {
      if (n > 2) {
        printf("1\n");
        printf("%d %d 1 1\n", n, m, 1, 1);
      } else
        printf("0\n");
      for (int i = 0; i < n; i++) printf("%d %d\n", 1, i + 1);
      printf("1 1");
    }
  } else if (m % 2 == 0) {
    if (n > 1) {
      printf("0\n");
      for (int j = 0; j < n; j++) printf("%d %d\n", j + 1, 1);
      for (int j = n - 1; j >= 1; j--) printf("%d %d\n", j + 1, 2);
      for (int i = 2; i < m; i += 2) {
        for (int j = 1; j < n; j++) printf("%d %d\n", j + 1, i + 1);
        for (int j = n - 1; j >= 1; j--) printf("%d %d\n", j + 1, i + 2);
      }
      for (int i = m - 1; i >= 0; i--) printf("%d %d\n", 1, i + 1);
    } else {
      if (m > 2) {
        printf("1\n");
        printf("%d %d 1 1\n", n, m, 1, 1);
      } else
        printf("0\n");
      for (int i = 0; i < m; i++) printf("%d %d\n", 1, i + 1);
      printf("1 1");
    }
  } else {
    printf("1\n");
    printf("%d %d 1 1\n", n, m, 1, 1);
    for (int i = 0; i < n - 2; i += 2) {
      for (int j = 0; j < m; j++) printf("%d %d\n", i + 1, j + 1);
      for (int j = m - 1; j >= 0; j--) printf("%d %d\n", i + 2, j + 1);
    }
    for (int j = 0; j < m; j++) printf("%d %d\n", n, j + 1);
    printf("1 1");
  }
}
