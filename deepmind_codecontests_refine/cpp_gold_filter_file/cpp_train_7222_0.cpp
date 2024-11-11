#include <bits/stdc++.h>
using namespace std;
int main() {
  int flag = 0;
  char arr[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> arr[i][j];
    }
  }
  int h = 0, d = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      h = 0;
      d = 0;
      if (arr[i][j] == '#') {
        h += 1;
      } else {
        d += 1;
      }
      if (arr[i][j + 1] == '#') {
        h += 1;
      } else {
        d += 1;
      }
      if (arr[i + 1][j] == '#') {
        h += 1;
      } else {
        d += 1;
      }
      if (arr[i + 1][j + 1] == '#') {
        h += 1;
      } else {
        d += 1;
      }
      if (h >= 3 || d >= 3) {
        flag = 1;
        break;
      }
    }
  }
  if (flag == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
