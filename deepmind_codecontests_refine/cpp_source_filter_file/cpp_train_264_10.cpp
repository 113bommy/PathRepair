#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  char arr[5][5];
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      cin >> arr[i][j];
    }
  bool flg = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      if (arr[i][j] == 'x' and arr[i][j + 1] == 'x' and arr[i][j + 2] == 'x')
        flg = 1;
      if (arr[i][j] == '.' and arr[i][j + 1] == 'x' and arr[i][j + 2] == 'x')
        flg = 1;
      if (arr[i][j] == 'x' and arr[i][j + 1] == '.' and arr[i][j + 2] == 'x')
        flg = 1;
      if (arr[i][j] == 'x' and arr[i][j + 1] == 'x' and arr[i][j + 2] == '.')
        flg = 1;
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
      if (arr[i][j] == 'x' and arr[i + 1][j] == 'x' and arr[i + 2][j] == 'x')
        flg = 1;
      if (arr[i][j] == '.' and arr[i + 1][j] == 'x' and arr[i + 2][j] == 'x')
        flg = 1;
      if (arr[i][j] == 'x' and arr[i + 1][j] == '.' and arr[i + 2][j] == 'x')
        flg = 1;
      if (arr[i][j] == 'x' and arr[i + 1][j] == 'x' and arr[i + 2][j] == '.')
        flg = 1;
      if (arr[i][j] == 'x' and arr[i + 1][j + 1] == 'x' and
          arr[i + 2][j + 2] == 'x')
        flg = 1;
      if (arr[i][j] == '.' and arr[i + 1][j + 1] == 'x' and
          arr[i + 2][j + 2] == 'x')
        flg = 1;
      if (arr[i][j] == 'x' and arr[i + 1][j + 1] == '.' and
          arr[i + 2][j + 2] == 'x')
        flg = 1;
      if (arr[i][j] == 'x' and arr[i + 1][j + 1] == 'x' and
          arr[i + 2][j + 2] == '.')
        flg = 1;
      if (arr[i][j] == 'x' and arr[i - 1][j - 1] == 'x' and
          arr[i - 2][j - 2] == 'x')
        flg = 1;
      if (arr[i][j] == '.' and arr[i - 1][j - 1] == 'x' and
          arr[i - 2][j - 2] == 'x')
        flg = 1;
      if (arr[i][j] == 'x' and arr[i - 1][j - 1] == '.' and
          arr[i - 2][j - 2] == 'x')
        flg = 1;
      if (arr[i][j] == 'x' and arr[i - 1][j - 1] == 'x' and
          arr[i - 2][j - 2] == '.')
        flg = 1;
    }
  }
  cout << ((flg) ? "YES" : "NO") << endl;
  return 0;
}
