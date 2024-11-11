#include <bits/stdc++.h>
using namespace std;
int mat[6][4];
bool ve[6];
bool fun() {
  if (mat[0][0] == mat[0][2] && mat[0][2] == mat[1][1] &&
      mat[1][1] == mat[1][3] && mat[1][0] == mat[1][2] &&
      mat[1][2] == mat[2][1] && mat[2][1] == mat[2][3] &&
      mat[0][1] == mat[0][3] && mat[0][3] == mat[5][1] &&
      mat[5][1] == mat[5][3] && mat[5][0] == mat[5][2] &&
      mat[5][2] == mat[2][0] && mat[2][0] == mat[2][2])
    return true;
  if (mat[0][0] == mat[0][2] && mat[0][2] == mat[5][0] &&
      mat[5][0] == mat[5][2] && mat[0][1] == mat[0][3] &&
      mat[0][3] == mat[1][0] && mat[1][0] == mat[1][2] &&
      mat[1][1] == mat[1][3] && mat[1][3] == mat[2][0] &&
      mat[2][0] == mat[2][2] && mat[2][1] == mat[2][3] &&
      mat[2][3] == mat[5][1] && mat[5][1] == mat[5][3])
    return true;
  return false;
}
bool fun2() {
  if (mat[3][0] == mat[3][1] && mat[3][1] == mat[1][2] &&
      mat[1][2] == mat[1][3] && mat[1][0] == mat[1][1] &&
      mat[1][1] == mat[4][2] && mat[4][2] == mat[4][3] &&
      mat[4][0] == mat[4][1] && mat[4][1] == mat[5][2] &&
      mat[5][2] == mat[5][3] && mat[5][0] == mat[5][1] &&
      mat[5][1] == mat[3][2] && mat[3][2] == mat[3][3])
    return true;
  if (mat[1][0] == mat[1][1] && mat[1][1] == mat[3][2] &&
      mat[3][2] == mat[3][3] && mat[1][2] == mat[1][3] &&
      mat[1][3] == mat[4][0] && mat[4][0] == mat[4][1] &&
      mat[4][2] == mat[4][3] && mat[4][3] == mat[5][0] &&
      mat[5][0] == mat[5][1] && mat[5][2] == mat[5][3] &&
      mat[5][3] == mat[3][0] && mat[3][0] == mat[3][1])
    return true;
  return false;
}
bool fun3() {
  if (mat[0][2] == mat[0][3] && mat[0][3] == mat[4][1] &&
      mat[4][1] == mat[4][3] && mat[4][0] == mat[4][2] &&
      mat[4][2] == mat[2][2] && mat[2][2] == mat[2][3] &&
      mat[2][0] == mat[2][1] && mat[2][1] == mat[3][0] &&
      mat[3][0] == mat[3][2] && mat[3][1] == mat[3][3] &&
      mat[3][3] == mat[0][0] && mat[0][0] == mat[0][1])
    return true;
  if (mat[0][2] == mat[0][3] && mat[0][3] == mat[3][0] &&
      mat[3][0] == mat[3][2] && mat[3][1] == mat[3][3] &&
      mat[3][3] == mat[2][2] && mat[2][2] == mat[2][3] &&
      mat[2][0] == mat[2][1] && mat[2][1] == mat[4][1] &&
      mat[4][1] == mat[4][3] && mat[4][0] == mat[4][2] &&
      mat[4][2] == mat[0][0] && mat[0][0] == mat[0][1])
    return true;
  return false;
}
int main() {
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 4; j++) cin >> mat[i][j];
  int cont = 0;
  for (int i = 0; i < 6; i++) {
    bool fl = true;
    int a = mat[i][0];
    for (int j = 0; j < 4; j++) {
      if (mat[i][j] != a) {
        fl = false;
        break;
      }
    }
    if (fl) {
      cont++;
      ve[i] = 1;
    }
  }
  if (cont == 2) {
    if ((ve[0] == 1 && ve[2] == 1) || (ve[1] == 1 && ve[5] == 1) ||
        (ve[3] == 1 && ve[4] == 1)) {
      if (ve[0] == 1 && ve[2] == 1) {
        if (fun2()) {
          cout << "yes";
        } else {
          cout << "no";
        }
      }
      if (ve[1] == 1 && ve[5] == 1) {
        if (fun3()) {
          cout << "yes";
        } else {
          cout << "no";
        }
      }
      if (ve[3] == 1 && ve[4] == 1) {
        if (fun()) {
          cout << "yes";
        } else {
          cout << "no";
        }
      }
    } else
      cout << "no";
  } else {
    if (cont == 6)
      cout << "yes";
    else
      cout << "no";
  }
  return 0;
}
