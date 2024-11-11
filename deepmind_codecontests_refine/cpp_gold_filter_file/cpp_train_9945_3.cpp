#include <bits/stdc++.h>
using namespace std;
int main() {
  char** a = new char*[2];
  for (int i = 0; i < 2; ++i) a[i] = new char[2];
  int ch = 0;
  for (size_t i = 0; i < 2; i++) {
    for (size_t j = 0; j < 2; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'X') {
        if (i == 0 && j == 0)
          ch = 1;
        else if (i == 0 && j == 1) {
          ch = 2;
        } else if (i == 1 && j == 0) {
          ch = 0;
        } else
          ch = 3;
      }
    }
  }
  char** b = new char*[2];
  for (int i = 0; i < 2; ++i) b[i] = new char[2];
  for (size_t i = 0; i < 2; i++) {
    for (size_t j = 0; j < 2; j++) {
      cin >> b[i][j];
    }
  }
  int c = 0;
  while (true) {
    int o = 0;
    for (size_t i = 0; i < 2; i++) {
      for (size_t j = 0; j < 2; j++) {
        if (a[i][j] == b[i][j]) {
          o++;
        }
      }
    }
    if (o == 4) {
      cout << "YES";
      return 0;
    }
    for (size_t i = 0; i < 2; i++) {
      for (size_t j = 0; j < 2; j++) {
        if (a[i][j] == 'X') {
          if (ch == 0) {
            char temp = a[i][j];
            a[i][j] = a[i - 1][j];
            a[i - 1][j] = temp;
            i = j = 2;
          } else if (ch == 2) {
            char temp = a[i][j];
            a[i][j] = a[i + 1][j];
            a[i + 1][j] = temp;
            i = j = 2;
          } else if (ch == 1) {
            char temp = a[i][j];
            a[i][j] = a[i][j + 1];
            a[i][j + 1] = temp;
            i = j = 2;
          } else {
            char temp = a[i][j];
            a[i][j] = a[i][j - 1];
            a[i][j - 1] = temp;
            i = j = 2;
          }
        }
      }
    }
    if (c > 13) break;
    ch++;
    c++;
    if (ch == 4) ch = 0;
  }
  cout << "NO";
  return 0;
}
