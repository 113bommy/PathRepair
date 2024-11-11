#include <bits/stdc++.h>
int main() {
  long long n, sum, k, d;
  int i;
  scanf("%lld", &n);
  i = 1;
  sum = 5;
  while (sum < n) {
    sum += 5 * pow(2, i);
    i++;
  }
  k = pow(2, i - 1);
  d = sum - n;
  if (d <= k) {
    printf("%s", "Howard");
  } else {
    if (d <= 2 * k) {
      printf("%s", "Rajech");
    } else {
      if (d <= 3 * k) {
        printf("%s", "Penny");
      } else {
        if (d <= 4 * k) {
          printf("%s", "Leonard");
        } else {
          printf("%s", "Sheldon");
        }
      }
    }
  }
  return 0;
}
