#include <bits/stdc++.h>
using namespace std;
char a[15][15];
char s[15][15];
char tmp[15][15];
bool change(int n) {
  bool flag1 = 1, flag2 = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] != a[i][j]) {
        flag1 = 0;
      }
      if (s[i][j] != tmp[i][j]) {
        flag2 = 0;
      }
    }
  }
  if (flag1 || flag2) {
    return false;
  }
  flag1 = flag2 = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] != a[n - j - 1][i]) {
        flag1 = 0;
      }
      if (s[i][j] != tmp[n - j - 1][i]) {
        flag2 = 0;
      }
    }
  }
  if (flag1 || flag2) {
    return false;
  }
  flag1 = flag2 = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] != a[n - i - 1][n - j - 1]) {
        flag1 = 0;
      }
      if (s[i][j] != tmp[n - i - 1][n - j - 1]) {
        flag2 = 0;
      }
    }
  }
  if (flag1 || flag2) {
    return false;
  }
  flag1 = flag2 = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] != a[j][n - i - 1]) {
        flag1 = 0;
      }
      if (s[i][j] != tmp[j][n - i - 1]) {
        flag2 = 0;
      }
    }
  }
  if (flag1 || flag2) {
    return false;
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> s[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) tmp[i][j] = a[i][n - i - 1];
  if (change(n)) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}
