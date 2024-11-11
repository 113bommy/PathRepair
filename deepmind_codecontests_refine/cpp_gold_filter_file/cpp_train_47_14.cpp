#include <bits/stdc++.h>
int main() {
  int n, x[100000], h[100000], count = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x[i], &h[i]);
  }
  int position = -1000000000;
  for (int i = 0; i < n; i++) {
    if (x[i] - h[i] > position) {
      position = x[i];
      count++;
    } else {
      if (i < n - 1 && (x[i] + h[i] < x[i + 1]) || i == n - 1) {
        position = x[i] + h[i];
        count++;
      } else
        position = x[i];
    }
  }
  printf("%d", count);
  return 0;
}
