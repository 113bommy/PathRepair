#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j;
  char a[11];
  char arr[11][11];
  char b[11];
  for (i = 1; i < 10; i++)
    for (j = 1; j < 10; j++) cin >> arr[i][j];
  int x, y, flag = 0;
  cin >> x >> y;
  if (x == 3 || x == 6 || x == 9) {
    if (y % 3 == 0) {
      for (i = 7; i <= 9; i++) {
        for (j = 7; j <= 9; j++) {
          if (arr[i][j] == '.') {
            flag = 1;
            arr[i][j] = '!';
          }
        }
      }
      if (flag == 0) {
        for (i = 1; i <= 9; i++) {
          for (j = 1; j <= 9; j++)
            if (arr[i][j] == '.') arr[i][j] = '!';
        }
      }
    }
    if (y % 3 == 1) {
      for (i = 7; i <= 9; i++) {
        for (j = 1; j <= 3; j++) {
          if (arr[i][j] == '.') {
            flag = 1;
            arr[i][j] = '!';
          }
        }
      }
      if (flag == 0) {
        for (i = 1; i <= 9; i++) {
          for (j = 1; j <= 9; j++)
            if (arr[i][j] == '.') arr[i][j] = '!';
        }
      }
    }
    if (y % 3 == 2) {
      for (i = 7; i <= 9; i++) {
        for (j = 4; j <= 6; j++) {
          if (arr[i][j] == '.') {
            flag = 1;
            arr[i][j] = '!';
          }
        }
      }
      if (flag == 0) {
        for (i = 1; i <= 9; i++) {
          for (j = 1; j <= 9; j++)
            if (arr[i][j] == '.') arr[i][j] = '!';
        }
      }
    }
  }
  if (x == 1 || x == 4 || x == 7) {
    if (y % 3 == 0) {
      for (i = 1; i <= 3; i++) {
        for (j = 7; j <= 9; j++) {
          if (arr[i][j] == '.') {
            flag = 1;
            arr[i][j] = '!';
          }
        }
      }
      if (flag == 0) {
        for (i = 1; i <= 9; i++) {
          for (j = 1; j <= 9; j++)
            if (arr[i][j] == '.') arr[i][j] = '!';
        }
      }
    }
    if (y % 3 == 1) {
      for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 3; j++) {
          if (arr[i][j] == '.') {
            flag = 1;
            arr[i][j] = '!';
          }
        }
      }
      if (flag == 0) {
        for (i = 1; i <= 9; i++) {
          for (j = 1; j <= 9; j++)
            if (arr[i][j] == '.') arr[i][j] = '!';
        }
      }
    }
    if (y % 3 == 2) {
      for (i = 1; i <= 3; i++) {
        for (j = 4; j <= 6; j++) {
          if (arr[i][j] == '.') {
            flag = 1;
            arr[i][j] = '!';
          }
        }
      }
      if (flag == 0) {
        for (i = 1; i <= 9; i++) {
          for (j = 1; j <= 9; j++)
            if (arr[i][j] == '.') arr[i][j] = '!';
        }
      }
    }
  }
  if (x == 2 || x == 5 || x == 8) {
    if (y % 3 == 0) {
      for (i = 4; i <= 6; i++) {
        for (j = 7; j <= 19; j++) {
          if (arr[i][j] == '.') {
            flag = 1;
            arr[i][j] = '!';
          }
        }
      }
      if (flag == 0) {
        for (i = 1; i <= 9; i++) {
          for (j = 1; j <= 9; j++)
            if (arr[i][j] == '.') arr[i][j] = '!';
        }
      }
    }
    if (y % 3 == 1) {
      for (i = 4; i <= 6; i++) {
        for (j = 1; j <= 3; j++) {
          if (arr[i][j] == '.') {
            flag = 1;
            arr[i][j] = '!';
          }
        }
      }
      if (flag == 0) {
        for (i = 1; i <= 9; i++) {
          for (j = 1; j <= 9; j++)
            if (arr[i][j] == '.') arr[i][j] = '!';
        }
      }
    }
    if (y % 3 == 2) {
      for (i = 4; i <= 6; i++) {
        for (j = 4; j <= 6; j++) {
          if (arr[i][j] == '.') {
            flag = 1;
            arr[i][j] = '!';
          }
        }
      }
      if (flag == 0) {
        for (i = 1; i <= 9; i++) {
          for (j = 1; j <= 9; j++)
            if (arr[i][j] == '.') arr[i][j] = '!';
        }
      }
    }
  }
  for (i = 1; i < 10; i++) {
    for (j = 1; j < 10; j++) {
      cout << arr[i][j];
      if (j % 3 == 0) cout << " ";
    }
    cout << endl;
    if (i % 3 == 0) cout << endl;
  }
  return 0;
}
