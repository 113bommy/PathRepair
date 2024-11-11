#include <bits/stdc++.h>
using namespace std;
int grid[3][3];
void toggle(int i, int j) {
  grid[i][j] ^= 1;
  if (i - 1 >= 0) grid[i - 1][j] ^= 1;
  if (j - 1 >= 0) grid[i][j - 1] ^= 1;
  if (i + 1 < 3) grid[i + 1][j] ^= 1;
  if (j + 1 < 3) grid[i][j + 1] ^= 1;
}
int main() {
  int i, j, x;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      scanf("%d", &x);
      if (x & 1) toggle(i, j);
    }
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d", !grid[i][j]);
    }
    printf("\n");
  }
  return 0;
}
