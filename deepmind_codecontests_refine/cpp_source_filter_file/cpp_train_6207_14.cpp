#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  string str[10];
  if (n == 2) {
    cout << "aa" << endl;
    cout << "bb" << endl;
    cout << "cc" << endl;
    cout << "dd" << endl;
    return 0;
  }
  for (i = 0; i < 4; i++)
    for (j = 0; j < n; j++) str[i] += " ";
  if (n % 2 == 0) {
    str[0][0] = 'a';
    str[1][0] = 'a';
    str[0][n - 1] = 'b';
    str[1][n - 1] = 'b';
  } else {
    str[0][0] = 'a';
    str[1][0] = 'a';
    str[2][n - 1] = 'b';
    str[3][n - 1] = 'b';
  }
  for (i = 0; i < n - 1; i++) {
    if (i % 4 == 0) {
      str[2][i] = 'c';
      str[3][i] = 'd';
      str[2][i + 1] = 'c';
      str[3][i + 1] = 'd';
    }
    if (i % 4 == 1) {
      str[0][i] = 'e';
      str[1][i] = 'f';
      str[0][i + 1] = 'e';
      str[1][i + 1] = 'f';
    }
    if (i % 4 == 2) {
      str[2][i] = 'g';
      str[3][i] = 'h';
      str[2][i + 1] = 'g';
      str[3][i + 1] = 'h';
    }
    if (i % 4 == 0) {
      str[2][i] = 'i';
      str[3][i] = 'j';
      str[2][i + 1] = 'i';
      str[3][i + 1] = 'j';
    }
  }
  for (i = 0; i < 4; i++) cout << str[i] << endl;
  return 0;
}
