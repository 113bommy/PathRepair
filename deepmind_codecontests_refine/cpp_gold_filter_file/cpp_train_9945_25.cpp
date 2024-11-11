#include <bits/stdc++.h>
using namespace std;
int main(void) {
  char str[10];
  int mat[2][2], des[2][2];
  memset(mat, 0, sizeof(mat));
  memset(des, 0, sizeof(des));
  for (int i = 0; i < 2; i++) {
    gets(str);
    if (str[0] != 'X') mat[i][0] = str[0] - 'A' + 1;
    if (str[1] != 'X') mat[i][1] = str[1] - 'A' + 1;
  }
  for (int i = 0; i < 2; i++) {
    gets(str);
    if (str[0] != 'X') des[i][0] = str[0] - 'A' + 1;
    if (str[1] != 'X') des[i][1] = str[1] - 'A' + 1;
  }
  int xdir[][2] = {{0, 1}, {0, 1}};
  int ydir[][2] = {{1, 1}, {0, 0}};
  for (int i = 0; i < 30; i++) {
    bool flag = false;
    int j, k;
    for (j = 0; j < 2; j++) {
      for (k = 0; k < 2; k++) {
        if (mat[j][k] == 0) {
          flag = true;
          break;
        }
      }
      if (flag) break;
    }
    int x = xdir[j][k], y = ydir[j][k];
    mat[j][k] = mat[x][y];
    mat[x][y] = 0;
    flag = false;
    for (j = 0; j < 2; j++) {
      for (k = 0; k < 2; k++) {
        if (mat[j][k] != des[j][k]) {
          flag = true;
          break;
        }
      }
      if (flag) break;
    }
    if (!flag) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
