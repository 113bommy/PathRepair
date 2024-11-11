#include <bits/stdc++.h>
char a[10][10];
int i, j, t, p;
bool f;
int main() {
  for (i = 1; i <= 6; i++) {
    for (j = 1; j <= 8; j++) scanf("%c", &a[i][j]);
  }
  f = true;
  if ((a[1][4] == '.') && (f == true)) {
    a[1][4] = 'P';
    f = false;
  }
  if ((a[1][5] == '.') && (f == true)) {
    a[1][5] = 'P';
    f = false;
  }
  if ((a[2][4] == '.') && (f == true)) {
    a[2][4] = 'P';
    f = false;
  }
  if ((a[2][5] == '.') && (f == true)) {
    a[2][5] = 'P';
    f = false;
  }
  if ((a[1][1] == '.') && (f == true)) {
    a[1][1] = 'P';
    f = false;
  }
  if ((a[1][2] == '.') && (f == true)) {
    a[1][2] = 'P';
    f = false;
  }
  if ((a[2][1] == '.') && (f == true)) {
    a[2][1] = 'P';
    f = false;
  }
  if ((a[2][2] == '.') && (f == true)) {
    a[2][2] = 'P';
    f = false;
  }
  if ((a[3][4] == '.') && (f == true)) {
    a[3][4] = 'P';
    f = false;
  }
  if ((a[3][5] == '.') && (f == true)) {
    a[3][5] = 'P';
    f = false;
  }
  if ((a[4][4] == '.') && (f == true)) {
    a[4][4] = 'P';
    f = false;
  }
  if ((a[4][5] == '.') && (f == true)) {
    a[4][5] = 'P';
    f = false;
  }
  if ((a[1][7] == '.') && (f == true)) {
    a[1][7] = 'P';
    f = false;
  }
  if ((a[1][8] == '.') && (f == true)) {
    a[1][8] = 'P';
    f = false;
  }
  if ((a[2][7] == '.') && (f == true)) {
    a[2][7] = 'P';
    f = false;
  }
  if ((a[2][8] == '.') && (f == true)) {
    a[2][8] = 'P';
    f = false;
  }
  if ((a[3][1] == '.') && (f == true)) {
    a[3][1] = 'P';
    f = false;
  }
  if ((a[3][2] == '.') && (f == true)) {
    a[3][2] = 'P';
    f = false;
  }
  if ((a[4][1] == '.') && (f == true)) {
    a[4][1] = 'P';
    f = false;
  }
  if ((a[4][2] == '.') && (f == true)) {
    a[4][2] = 'P';
    f = false;
  }
  if ((a[5][4] == '.') && (f == true)) {
    a[5][4] = 'P';
    f = false;
  }
  if ((a[5][5] == '.') && (f == true)) {
    a[5][5] = 'P';
    f = false;
  }
  if ((a[6][4] == '.') && (f == true)) {
    a[6][4] = 'P';
    f = false;
  }
  if ((a[6][5] == '.') && (f == true)) {
    a[6][5] = 'P';
    f = false;
  }
  if ((a[3][7] == '.') && (f == true)) {
    a[3][7] = 'P';
    f = false;
  }
  if ((a[3][8] == '.') && (f == true)) {
    a[3][8] = 'P';
    f = false;
  }
  if ((a[4][7] == '.') && (f == true)) {
    a[4][7] = 'P';
    f = false;
  }
  if ((a[4][8] == '.') && (f == true)) {
    a[4][8] = 'P';
    f = false;
  }
  if ((a[5][1] == '.') && (f == true)) {
    a[5][1] = 'P';
    f = false;
  }
  if ((a[5][2] == '.') && (f == true)) {
    a[5][2] = 'P';
    f = false;
  }
  if ((a[6][1] == '.') && (f == true)) {
    a[6][1] = 'P';
    f = false;
  }
  if ((a[6][2] == '.') && (f == true)) {
    a[6][2] = 'P';
    f = false;
  }
  if ((a[5][7] == '.') && (f == true)) {
    a[5][7] = 'P';
    f = false;
  }
  if ((a[5][8] == '.') && (f == true)) {
    a[5][8] = 'P';
    f = false;
  }
  if ((a[6][7] == '.') && (f == true)) {
    a[6][7] = 'P';
    f = false;
  }
  if ((a[6][8] == '.') && (f == true)) {
    a[6][8] = 'P';
    f = false;
  }
  for (i = 1; i <= 6; i++) {
    for (j = 1; j <= 8; j++) printf("%1c", a[i][j]);
    printf("\n");
  }
}
