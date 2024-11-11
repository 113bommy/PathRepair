#include <bits/stdc++.h>
using namespace std;
char a[10][10];
int main() {
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      cin >> a[i][j];
    }
  }
  int x, y;
  cin >> x >> y;
  int flag = 0;
  if (x % 3 == 0 && y % 3 == 0) {
    for (int i = 7; i <= 9; i++) {
      for (int j = 7; j <= 9; j++) {
        if (a[i][j] == '.') {
          flag = 1;
          a[i][j] = '!';
        }
      }
    }
    if (flag == 0) {
      for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
          if (a[i][j] == '.') {
            flag = 1;
            a[i][j] = '!';
          }
        }
      }
    }
  } else if (x % 3 == 0 && y % 3 == 2) {
    for (int i = 7; i <= 9; i++) {
      for (int j = 4; j <= 6; j++) {
        if (a[i][j] == '.') {
          flag = 1;
          a[i][j] = '!';
        }
      }
    }
    if (flag == 0) {
      for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
          if (a[i][j] == '.') {
            flag = 1;
            a[i][j] = '!';
          }
        }
      }
    }
  } else if (x % 3 == 0 && y % 3 == 1) {
    for (int i = 7; i <= 9; i++) {
      for (int j = 1; j <= 3; j++) {
        if (a[i][j] == '.') {
          flag = 1;
          a[i][j] = '!';
        }
      }
    }
    if (flag == 0) {
      for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
          if (a[i][j] == '.') {
            flag = 1;
            a[i][j] = '!';
          }
        }
      }
    }
  } else if (x % 3 == 2 && y % 3 == 0) {
    for (int i = 4; i <= 6; i++) {
      for (int j = 7; j <= 9; j++) {
        if (a[i][j] == '.') {
          flag = 1;
          a[i][j] = '!';
        }
      }
    }
    if (flag == 0) {
      for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
          if (a[i][j] == '.') {
            flag = 1;
            a[i][j] = '!';
          }
        }
      }
    }
  } else if (x % 3 == 2 && y % 3 == 2) {
    for (int i = 4; i <= 6; i++) {
      for (int j = 4; j <= 6; j++) {
        if (a[i][j] == '.') {
          flag = 1;
          a[i][j] = '!';
        }
      }
    }
    if (flag == 0) {
      for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
          if (a[i][j] == '.') {
            flag = 1;
            a[i][j] = '!';
          }
        }
      }
    }
  } else if (x % 3 == 2 && y % 3 == 1) {
    for (int i = 4; i <= 6; i++) {
      for (int j = 1; j <= 3; j++) {
        if (a[i][j] == '.') {
          flag = 1;
          a[i][j] = '!';
        }
      }
    }
    if (flag == 0) {
      for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
          if (a[i][j] == '.') {
            flag = 1;
            a[i][j] = '!';
          }
        }
      }
    }
  } else if (x % 3 == 1 && y % 3 == 3) {
    for (int i = 1; i <= 3; i++) {
      for (int j = 7; j <= 9; j++) {
        if (a[i][j] == '.') {
          flag = 1;
          a[i][j] = '!';
        }
      }
    }
    if (flag == 0) {
      for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
          if (a[i][j] == '.') {
            flag = 1;
            a[i][j] = '!';
          }
        }
      }
    }
  } else if (x % 3 == 1 && y % 3 == 2) {
    for (int i = 1; i <= 3; i++) {
      for (int j = 4; j <= 6; j++) {
        if (a[i][j] == '.') {
          flag = 1;
          a[i][j] = '!';
        }
      }
    }
    if (flag == 0) {
      for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
          if (a[i][j] == '.') {
            flag = 1;
            a[i][j] = '!';
          }
        }
      }
    }
  } else if (x % 3 == 1 && y % 3 == 1) {
    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= 3; j++) {
        if (a[i][j] == '.') {
          flag = 1;
          a[i][j] = '!';
        }
      }
    }
    if (flag == 0) {
      for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
          if (a[i][j] == '.') {
            flag = 1;
            a[i][j] = '!';
          }
        }
      }
    }
  }
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      cout << a[i][j];
      if (j % 3 == 0) {
        cout << " ";
      }
    }
    cout << endl;
    if (i % 3 == 0) {
      cout << endl;
    }
  }
}
