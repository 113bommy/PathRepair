#include <bits/stdc++.h>
using namespace std;
char arr[10][10];
int main() {
  int r, c;
  cin >> r >> c;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> arr[i][j];
    }
  }
  int s = 0;
  int count = 0;
  bool flag = false;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (arr[i][j] == 'S') {
        flag = false;
        break;
      } else
        flag = true;
    }
    if (flag) {
      count += c;
      s++;
    }
  }
  int m = 0;
  flag = false;
  for (int i = 0; i < c; ++i) {
    for (int j = 0; j < r; ++j) {
      if (arr[j][i] == 'S') {
        flag = false;
        break;
      } else
        flag = true;
    }
    if (flag) {
      count += r;
      m++;
    }
  }
  cout << count - (s * m);
  return 0;
}
