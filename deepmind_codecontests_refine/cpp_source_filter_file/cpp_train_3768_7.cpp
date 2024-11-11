#include <bits/stdc++.h>
int main() {
  int q;
  int n;
  int sum = 0;
  int temp;
  scanf("%d", &q);
  for (int o = 0; o < q; o++) {
    sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &temp);
      sum += temp;
    }
    if (sum % n == 0) {
      printf("%d", sum / n);
    } else {
      printf("%d", (sum / n) + 1);
    }
  }
  return 0;
}
