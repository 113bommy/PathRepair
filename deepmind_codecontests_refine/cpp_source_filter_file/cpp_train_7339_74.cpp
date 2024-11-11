#include <bits/stdc++.h>
using namespace std;
int main() {
  char flu[10][10];
  int i, j, k;
  for (i = 0; i < 8; ++i) scanf("%s", flu[i]);
  int temp1 = -1, temp2 = -1;
  for (i = 0; i < 8; ++i) {
    if (temp1 != -1) break;
    for (j = 0; j < 8; ++j) {
      if (temp1 != -1) break;
      if (flu[i][j] == 'W') {
        for (k = i - 1; k >= 0; --k) {
          if (k == 0 && flu[k][j] == '.') {
            temp1 = j;
            break;
          }
          if (flu[k][j] != '.') break;
        }
      }
    }
  }
  for (i = 0; i < 8; ++i) {
    if (temp2 != -1) break;
    for (j = 0; j < 8; ++j) {
      if (temp2 != -1) break;
      if (flu[i][j] == 'B') {
        for (k = i + 1; k < 8; ++k) {
          if (k == 7 && flu[k][j] == '.') {
            temp2 = (7 - j);
            break;
          }
          if (flu[k][j] != '.') break;
        }
      }
    }
  }
  if ((temp1 == -1 && temp2 != -1) || (temp2 < temp1))
    printf("B\n");
  else
    printf("A\n");
  return 0;
}
