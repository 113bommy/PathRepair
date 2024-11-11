#include <bits/stdc++.h>
using namespace std;
int n;
bool sab(int a[10][10], int b[10][10]) {
  int i, j;
  bool flag = true;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[i][j] != b[i][j]) {
        flag = false;
        break;
      }
    }
    if (flag == false) break;
  }
  if (flag == false) {
    flag = true;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (a[i][j] != b[n - 1 - j][i]) {
          flag = false;
          break;
        }
      }
      if (flag == false) {
        break;
      }
    }
  }
  if (flag == false) {
    flag = true;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (a[i][j] != b[n - 1 - i][n - 1 - j]) {
          flag = false;
          break;
        }
      }
      if (flag == false) {
        break;
      }
    }
  }
  if (flag == false) {
    flag = true;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (a[i][j] != b[j][n - 1 - i]) {
          flag = false;
          break;
        }
      }
      if (flag == false) break;
    }
  }
  return flag;
}
int main() {
  cin >> n;
  string str[n], str1[n];
  int a[10][10], b[10][10], vf[10][10], hf[10][10];
  int i, j;
  for (i = 0; i < n; i++) cin >> str[i];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (str[i].at(j) == 'X')
        a[i][j] = 1;
      else
        a[i][j] = 0;
    }
  }
  for (i = 0; i < n; i++) cin >> str1[i];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (str1[i].at(j) == 'X')
        b[i][j] = 1;
      else
        b[i][j] = 0;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n / 2; j++) {
      vf[i][j] = b[i][n - 1 - j];
      vf[i][n - 1 - j] = b[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n / 2; j++) {
      hf[j][i] = b[n - 1 - j][i];
      hf[n - 1 - j][i] = b[j][i];
    }
  }
  bool aa = sab(a, b), bb = sab(a, vf), cc = sab(a, hf);
  if (aa || bb || cc) {
    cout << "Yes" << endl;
  } else
    cout << "No" << endl;
  return 0;
}
