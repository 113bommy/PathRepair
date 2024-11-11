#include <bits/stdc++.h>
using namespace std;
vector<string> field(4);
bool check_row(int row) {
  if (field[row][1] == field[row][2] && field[row][1] == 'x' &&
      (field[row][0] == 'x' || field[row][3] == 'x'))
    return true;
  return false;
}
bool check_col(int col) {
  if (field[1][col] == field[2][col] && field[1][col] == 'x' &&
      (field[0][col] == 'x' || field[3][col] == 'x'))
    return true;
  return false;
}
bool check_main_diag() {
  if (field[1][1] == field[2][2] && field[1][1] == 'x' &&
      (field[0][0] == 'x' || field[3][3] == 'x'))
    return true;
  if (field[0][1] == field[1][2] && field[1][2] == field[2][3] &&
      field[2][3] == 'x')
    return true;
  if (field[1][0] == field[2][1] && field[2][1] == field[3][2] &&
      field[3][2] == 'x')
    return true;
  return false;
}
bool check_dop_diag() {
  if (field[2][1] == field[1][2] && field[2][1] == 'x' &&
      (field[0][3] == 'x' && field[3][0] == 'x'))
    return true;
  if (field[2][0] == field[1][1] && field[1][1] == field[0][2] &&
      field[0][2] == 'x')
    return true;
  if (field[3][1] == field[2][2] && field[2][2] == field[1][3] &&
      field[1][3] == 'x')
    return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 0; i < 4; ++i) {
    cin >> field[i];
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (field[i][j] == '.') {
        field[i][j] = 'x';
        for (int k = 0; k < 4; ++k) {
          if (check_col(k) || check_row(k)) {
            cout << "YES" << endl;
            return 0;
          }
        }
        if (check_main_diag() || check_dop_diag()) {
          cout << "YES" << endl;
          return 0;
        }
        field[i][j] = '.';
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
