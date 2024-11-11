#include <bits/stdc++.h>
int main() {
  char a[110], b[110];
  int sum, sum1 = 0, d;
  scanf("%s %s\n", a, b);
  for (d = 0;; d++) {
    if (a[d] == '\0') {
      break;
    }
    sum = a[d] - b[d];
    if (a[d] > 64 && a[d] < 91 && b[d] > 96 && b[d] < 123 && sum != 32) {
      if (sum < -32) {
        sum1--;
        break;
      }
      if (sum > -32) {
        sum1++;
        break;
      }
    } else if (b[d] > 64 && b[d] < 91 && a[d] > 96 && a[d] < 123 &&
               sum != -32) {
      if (sum < 32) {
        sum1--;
        break;
      }
      if (sum > 32) {
        sum1++;
        break;
      }
    } else if (sum < 26 && sum > 0) {
      sum1++;
      break;
    } else if (sum > -26 && sum < 0) {
      sum1--;
      break;
    }
  }
  printf("%d\n", sum1);
  return 0;
}
