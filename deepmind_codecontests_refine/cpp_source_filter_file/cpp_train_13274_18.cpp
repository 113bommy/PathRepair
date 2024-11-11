#include <bits/stdc++.h>
char a[540][540];
int main() {
  int n;
  scanf("%d", &n);
  a[0][0] = '+';
  a[0][1] = '-';
  a[1][0] = '+';
  a[1][1] = '+';
  if (n == 0) {
    printf("+\n");
    return 0;
  }
  for (int i = 2; i <= n; i++) {
    int k = 1 << (i - 1);
    for (int j = k; j < 2 * k; j++) {
      for (int t = 0; t < k; t++) {
        a[j][t] = a[j - k][t];
      }
    }
    for (int j = 0; j < k; j++) {
      for (int t = 0; t < k; t++) {
        a[j][t + k] = a[j][t];
      }
    }
    for (int j = k; j < 2 * k; j++) {
      for (int t = 0; t < k; t++) {
        if (a[j][t] == '-')
          a[j][t + k] = '+';
        else
          a[j][t + k] = '-';
      }
    }
  }
  int d = 1 << n;
  for (int i = 0; i < d; i++) {
    a[i][d] = '\0';
    printf("%s\n", a[i]);
  }
  return 0;
}
