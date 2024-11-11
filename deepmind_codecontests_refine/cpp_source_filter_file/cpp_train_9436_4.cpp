#include <bits/stdc++.h>
int conveniences[6][3][2];
int main() {
  char seating[6][3][2];
  int max = 1 << sizeof(int) * 8 - 1, x = -1, y = -1, z = -1;
  int val = 4;
  for (int i = 0; i < 6; i++) {
    if (i % 2 == 0) val--;
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 2; k++)
        conveniences[i][j][k] = (j % 2 == 0) ? val : val + 1;
  }
  char *ind, temp[9];
  for (int i = 0; i < 6; i++) {
    gets(temp);
    ind = temp;
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 2; k++) {
        seating[i][j][k] = *ind;
        ind++;
        if (seating[i][j][k] == '.' && max < conveniences[i][j][k]) {
          max = conveniences[i][j][k];
          x = i;
          y = j;
          z = k;
        }
      }
      ++ind;
    }
  }
  seating[x][y][z] = 'p';
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 2; k++) printf("%c", seating[i][j][k]);
      if (j != 2) printf("-");
    }
    printf("\n");
  }
  return 0;
}
