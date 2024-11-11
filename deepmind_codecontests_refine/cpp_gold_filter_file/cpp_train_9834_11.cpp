#include <bits/stdc++.h>
using namespace ::std;
int main() {
  int k;
  scanf("%d", &k);
  char matrix[4][11];
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 11; j++) {
      if (i == 2 && j != 0)
        matrix[i][j] = '.';
      else
        matrix[i][j] = '#';
    }
  for (int j = 0; j < 11 && k != 0; j++)
    for (int i = 0; i < 4 && k != 0; i++) {
      if (matrix[i][j] == '#') {
        matrix[i][j] = 'O';
        k--;
      }
    }
  int i, j;
  printf("+------------------------+\n");
  for (i = 0; i < 4; i++) {
    printf("|");
    for (j = 0; j < 11; j++) {
      printf("%c.", matrix[i][j]);
    }
    if (i != 2)
      printf("|");
    else
      printf(".");
    if (i == 0)
      printf("D");
    else
      printf(".");
    printf("|");
    if (i == 0 || i == 3) printf(")");
    printf("\n");
  }
  printf("+------------------------+\n");
  return 0;
}
