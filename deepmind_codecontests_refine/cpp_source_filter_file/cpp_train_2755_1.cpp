#include <bits/stdc++.h>
int main() {
  int hold;
  int heights[100], heights2[100][100], heights3[100][100], selisih[100][100],
      z, c2 = 100;
  int i, j, a, c;
  scanf("%d", &hold);
  for (i = 0; i < hold; i++) {
    scanf("%d", &heights[i]);
  }
  for (i = 1; i < hold - 1; i++) {
    z = 0;
    for (j = 0; j < hold; j++) {
      if (j != 0 && j != hold && j == i) {
        continue;
      } else {
        heights2[i][z] = heights[j];
        z++;
      }
    }
  }
  for (i = 1; i < hold - 1; i++) {
    c = 0;
    for (j = 0; j < hold - 2; j++) {
      selisih[i][j] = heights2[i][j + 1] - heights2[i][j];
      if (selisih[i][j] > c) {
        c = selisih[i][j];
      }
    }
    if (c < c2) {
      c2 = c;
    }
  }
  printf("%d", c2);
  return 0;
}
