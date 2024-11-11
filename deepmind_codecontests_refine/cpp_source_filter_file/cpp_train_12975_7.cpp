#include <bits/stdc++.h>
float f(float y, int x1, int x2, int r) {
  return y + sqrt(4 * r * r - (x1 - x2) * (x1 - x2));
}
int main() {
  int n, r, i, j;
  scanf("%d%d", &n, &r);
  int arr[n];
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  float y[n];
  y[0] = r;
  printf("%d ", r);
  for (i = 1; i < n; i++) {
    float max = 0;
    for (j = 0; j < i; j++) {
      float y1 = y[j];
      int x1 = arr[i], x2 = arr[j];
      if (arr[j] - arr[i] <= r || arr[i] - arr[j] <= r) {
        if (max <= y1 + sqrt(4 * r * r - (x1 - x2) * (x1 - x2)))
          max = y1 + sqrt(4 * r * r - (x1 - x2) * (x1 - x2));
      }
    }
    y[i] = max;
    printf("%0.8f ", max);
  }
  return 0;
}
