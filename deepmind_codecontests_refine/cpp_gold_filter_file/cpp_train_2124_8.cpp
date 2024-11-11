#include <bits/stdc++.h>
int main() {
  int k;
  scanf("%d", &k);
  if (k % 2 == 1) {
    printf("-1");
    return 0;
  }
  float mid = (k - 1.0) / 2;
  char c1 = 'w';
  char c2 = 'b';
  int layer;
  int row;
  int col;
  char chars[k + 1];
  chars[k] = '\0';
  for (layer = 0; layer < k; layer++) {
    for (row = 0; row < k; row++) {
      for (col = 0; col < k; col++) {
        float diff1 = (row > mid) ? (row - mid) : (mid - row);
        float diff2 = (col > mid) ? (col - mid) : (mid - col);
        float which1 = ((diff1) > (diff2) ? (diff1) : (diff2)) / 0.5;
        int which = (int)which1;
        which /= 2;
        if (which % 2 == 1) {
          chars[col] = c1;
        } else {
          chars[col] = c2;
        }
      }
      printf("%s\n", chars);
    }
    printf("\n");
    char tmp = c1;
    c1 = c2;
    c2 = tmp;
  }
  return 0;
}
