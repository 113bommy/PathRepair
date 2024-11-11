#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int i, j, ara[9][9];
    char str[10][11];
    for (i = 0; i < 9; i++) {
      scanf("%s", str[i]);
    }
    for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
        ara[i][j] = str[i][j] - '0';
      }
    }
    ara[0][0] = ara[0][0] + 1;
    if (ara[0][0] == 10) ara[0][0] = 1;
    ara[1][3] = ara[1][3] + 1;
    if (ara[1][3] == 10) ara[1][3] = 1;
    ara[2][8] = ara[2][8] + 1;
    if (ara[2][8] == 10) ara[2][8] = 1;
    ara[3][1] = ara[3][1] + 1;
    if (ara[3][1] == 10) ara[3][1] = 1;
    ara[4][4] = ara[4][4] + 1;
    if (ara[4][4] == 10) ara[4][4] = 1;
    ara[5][7] = ara[5][7] + 1;
    if (ara[5][7] == 10) ara[5][7] = 1;
    ara[6][2] = ara[6][2] + 1;
    if (ara[6][2] == 10) ara[6][2] = 1;
    ara[7][5] = ara[7][5] + 1;
    if (ara[7][5] == 10) ara[7][5] = 1;
    ara[8][6] = ara[8][6] + 1;
    if (ara[8][6] == 10) ara[8][6] = 1;
    for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
        printf("%d", ara[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
