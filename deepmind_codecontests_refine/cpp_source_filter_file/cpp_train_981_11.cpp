#include <bits/stdc++.h>
using namespace std;
char field[2002][2002];
int comeaross[2002];
int main() {
  int row, col, spider;
  cin >> row >> col >> spider;
  while (getchar() != '\n') continue;
  for (int i = 0; i < row; ++i) gets(field[i]);
  memset(comeaross, 0, sizeof(comeaross));
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      switch (field[i][j]) {
        case 'U':
          if (i % 2 == 1) comeaross[j] += 1;
          break;
        case 'L':
          if (j - i < col && j - i >= 0) comeaross[j - i] += 1;
          break;
        case 'R':
          if (j + i < col && j + i >= 0) comeaross[j + i] += 1;
          break;
        default:
          break;
      }
    }
  }
  for (int i = 0; i < col; ++i) {
    if (i < col - 1)
      printf("%d ", comeaross[i]);
    else
      printf("%d\n", comeaross[i]);
  }
  return 0;
}
