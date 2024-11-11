#include <bits/stdc++.h>
int main() {
  int n, i, j, x = 0, min, min1;
  scanf("%d", &n);
  int row1[n - 1], row2[n - 1], sum1[n - 1], sum2[n - 1];
  int b[n];
  for (i = 0; i < n - 1; i++) {
    scanf("%d", &row1[i]);
    x = x + row1[i];
    sum1[i] = x;
  }
  x = 0;
  for (i = 0; i < n - 1; i++) {
    scanf("%d", &row2[i]);
    x = x + row2[i];
    sum2[i] = x;
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  min = b[0] + sum2[n - 2];
  min1 = sum1[n - 2] + b[n - 1];
  for (i = 0; i < n - 2; i++) {
    x = sum1[i] + b[i + 1] + sum2[n - 2] - sum2[i];
    if (x < min && x < min1) {
      if (min < min1) {
        min1 = x;
      } else {
        min = x;
      }
    } else if (x < min && x > min1) {
      min = x;
    } else if (x < min1 && x > min) {
      min1 = x;
    }
  }
  printf("%d", min + min1);
}
