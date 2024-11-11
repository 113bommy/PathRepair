#include <bits/stdc++.h>
using namespace std;
int mat[3][3];
int parcrs[3][3];
typedef char nm[3];
nm poz[4] = {"00", "02", "22", "20"};
void functie(int a, int b) {
  int i, x, y;
  for (i = 0; i < 4; i++) {
    x = poz[i][0] - '0';
    y = poz[i][1] - '0';
    if (a != x && b != y) {
      if (mat[x][y] == 1 && mat[a][b] == 1) {
        parcrs[a][b] = parcrs[x][y] = 1;
        return;
      }
    }
  }
}
int main() {
  char a;
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      mat[i][j] = parcrs[i][j] = 0;
    }
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      cin >> a;
      if (a == 'X')
        mat[i][j] = 1;
      else if (a == '.')
        mat[i][j] = 0;
    }
  }
  if (mat[0][0]) functie(0, 0);
  if (mat[0][2]) functie(0, 2);
  if (mat[2][0]) functie(2, 0);
  if (mat[2][2]) functie(2, 2);
  if (mat[1][0] == 1 && mat[1][2] == 1) {
    parcrs[1][0] = 1;
    parcrs[1][2] = 1;
  }
  if (mat[0][1] == 1 && mat[2][1] == 1) {
    parcrs[0][1] = 1;
    parcrs[2][1] = 1;
  }
  if (mat[1][1] == 1) parcrs[1][1] = 1;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (mat[i][j] != parcrs[i][j]) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
}
