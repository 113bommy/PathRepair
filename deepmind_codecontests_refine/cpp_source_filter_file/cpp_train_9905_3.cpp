#include <bits/stdc++.h>
char a[5001];
char c[5001];
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
int main() {
  int n00 = 0, n01 = 0, n10 = 0, n11 = 0;
  int x00, x01, x10, x11;
  int n, n_2;
  scanf("%d", &n);
  n_2 = n / 2;
  scanf("%s", a);
  scanf("%s", c);
  for (int i = 0; i < n; ++i) {
    if (a[i] == '0') {
      if (c[i] == '0') {
        n00++;
      } else {
        n01++;
      }
    } else {
      if (c[i] == '0') {
        n10++;
      } else {
        n11++;
      }
    }
  }
  fprintf(stderr, "%d, %d, %d, %d\n", n00, n01, n10, n11);
  bool possible = false;
  for (x11 = 0; x11 <= n11; ++x11) {
    for (x01 = 0; x01 <= n01; ++x01) {
      x10 = n10 + n11 - 2 * x11 - x01;
      x00 = n_2 - x01 - x10 - x11;
      if (0 <= x00 && x00 <= n00 && 0 <= x10 && x10 <= n10) {
        possible = true;
        break;
      }
    }
    if (possible) {
      break;
    }
  }
  if (possible) {
    fprintf(stderr, "possible\n");
    fprintf(stderr, "%d, %d, %d, %d\n", x00, x01, x10, x11);
  } else {
    fprintf(stderr, "impossible\n");
  }
  if (possible) {
    for (int i = 0; i < n; ++i) {
      if (a[i] == '0' && c[i] == '0' && x00) {
        x00--;
        printf("%d ", i + 1);
      } else if (a[i] == '0' && c[i] == '1' && x01) {
        x01--;
        printf("%d ", i + 1);
      } else if (a[i] == '1' && c[i] == '0' && x10) {
        x10--;
        printf("%d ", i + 1);
      } else if (a[i] == '1' && c[i] == '1' && x11) {
        x11--;
        printf("%d ", i + 1);
      }
    }
    printf("\n");
  } else {
    printf("-1\n");
  }
  return 0;
}
