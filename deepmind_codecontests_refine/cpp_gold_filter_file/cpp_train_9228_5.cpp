#include <bits/stdc++.h>
int main() {
  int n;
  int seq[200001];
  scanf("%d", &n);
  int high = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &seq[i]);
    high = std::max(high, seq[i]);
  }
  int width = -1;
  for (int i = 1; i < n; i++) {
    int dist = abs(seq[i] - seq[i - 1]);
    if (dist < 1) {
      printf("NO\n");
      return 0;
    } else if (dist == 1) {
      continue;
    } else if (width == -1) {
      width = dist;
    } else if (dist != width) {
      printf("NO\n");
      return 0;
    }
  }
  if (width == -1) width = 1;
  int w = width;
  int h = high / width + (high % width == 0 ? 0 : 1);
  for (int i = 1; i < n; i++) {
    int dist = abs(seq[i] - seq[i - 1]);
    if (dist == 1 && w > 1) {
      int row1 = (seq[i - 1] - 1) / width;
      int row2 = (seq[i] - 1) / width;
      if (row1 != row2) {
        printf("NO\n");
        return 0;
      }
    }
  }
  printf("YES\n");
  printf("%d %d\n", h, w);
  return 0;
}
