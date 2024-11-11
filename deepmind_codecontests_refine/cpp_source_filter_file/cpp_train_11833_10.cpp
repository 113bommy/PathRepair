#include <bits/stdc++.h>
using namespace std;
int n;
char C[15][15], B[15][15], res[15][15];
string str;
void xoay() {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      C[i][j] = B[j][n - i + 1];
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) B[i][j] = C[i][j];
}
void lat() {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) C[i][j] = B[i][n - j + 1];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) B[i][j] = C[i][j];
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> str;
    for (int j = 0; j <= str.length() - 1; ++j) {
      B[i][j + 1] = str[j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    cin >> str;
    for (int j = 0; j <= str.length() - 1; ++j) {
      res[i][j + 1] = str[j];
    }
  }
  for (int k = 1; k <= 6; ++k) {
    int kq = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (res[i][j] != B[i][j]) {
          kq = 1;
          break;
        }
    if (kq == 1)
      xoay();
    else {
      cout << "YES";
      return 0;
    }
    if (k == 3) lat();
  }
  cout << "NO";
  return 0;
}
