#include <bits/stdc++.h>
using namespace std;
char arr[4][4];
bool isinposition(int i, int j) {
  return (i >= 0 && i <= 3) && (j >= 0 && j <= 3);
}
bool isx(int i, int j, int i2, int j2) {
  return (arr[i][j] == 'x' && arr[i2][j2] == 'x');
}
bool isdot(int i, int j) { return arr[i][j] == '.'; }
int main() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) cin >> arr[i][j];
  }
  bool answer = false;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++)
      answer = (answer | (isx(i, j, i, j + 1) && arr[i][j + 2] == '.'));
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++)
      answer = (answer | (isx(i, j, i, j + 2) && arr[i][j + 1] == '.'));
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++)
      answer = (answer | (isx(i, j + 1, i, j + 2) && arr[i][j] == '.'));
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++)
      answer = (answer | (isx(i, j, i + 1, j) && arr[i + 2][j] == '.'));
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++)
      answer = (answer | (isx(i, j, i + 2, j) && (arr[i + 1][j] == '.')));
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++)
      answer = (answer | (isx(i + 1, j, i + 2, j) && (arr[i][j] == '.')));
  }
  answer = (answer | (isx(0, 0, 1, 1) && arr[2][2] == '.') |
            (isx(0, 0, 2, 2) && arr[1][1] == '.') |
            (isx(0, 1, 1, 2) && arr[2][3] == '.') |
            (isx(0, 1, 2, 3) && arr[1][2] == '.') |
            (isx(1, 1, 2, 2) && arr[3][3] == '.') |
            (isx(1, 2, 2, 3) && arr[0][1] == '.') |
            (isx(1, 0, 2, 1) && arr[3][2] == '.') |
            (isx(1, 0, 3, 2) && arr[2][1] == '.') |
            (isx(2, 1, 3, 2) && arr[1][0] == '0'));
  answer =
      (answer | (isx(1, 1, 2, 2) && isdot(3, 3)) |
       (isx(1, 1, 3, 3) && isdot(2, 2)) | (isx(2, 2, 3, 3) && isdot(1, 1)));
  answer =
      (answer | (isx(0, 3, 1, 2) && isdot(2, 1)) |
       (isx(0, 3, 2, 1) && isdot(1, 2)) | (isx(1, 2, 2, 1) && isdot(0, 3)) |
       (isx(0, 2, 1, 1) && isdot(2, 0)) | (isx(0, 2, 2, 0) && isdot(1, 1)) |
       (isx(1, 1, 2, 0) && isdot(0, 2)) | (isx(1, 3, 2, 2) && isdot(3, 1)) |
       (isx(1, 3, 3, 1) && isdot(2, 2)) | (isx(2, 2, 3, 1) && isdot(1, 3)));
  answer =
      (answer | (isx(1, 2, 2, 1) && isdot(3, 0)) |
       (isx(1, 2, 3, 0) && isdot(2, 1)) | (isx(2, 1, 3, 0) && isdot(1, 2)));
  if (answer)
    cout << "YES";
  else
    cout << "NO";
}
