#include <bits/stdc++.h>
int main() {
  int n, min = 0, k;
  scanf("%d", &n);
  for (int i = 1; i < 200; i++) {
    k = (pow(2, i) - 1) * pow(2, i - 1);
    if (k > n) {
      printf("%d", min);
      break;
    } else if ((n % k) == 0) {
      min = k;
    }
  }
  return 0;
}
