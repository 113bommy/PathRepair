#include <bits/stdc++.h>
int main() {
  int n, i, j, k, max = -1;
  scanf("%d", &n);
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  for (i = 0; a * i < n; i++) {
    for (j = 0; a * i + b * j < n; j++) {
      k = (n - a * i - b * j) / c;
      if ((a * i + b * j + c * k) == n && (i + j + k > max)) max = i + j + k;
    }
  }
  printf("%d", max);
  return 0;
}
