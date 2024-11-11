#include <bits/stdc++.h>
using namespace std;
int count(char arr[101][101], int i, int j, int n, int m) {
  int ctr = 0;
  if (i - 1 >= 0 && j - 1 >= 0) {
    if (arr[i - 1][j - 1] == '*') ctr++;
  }
  if (i - 1 >= 0 && j >= 0) {
    if (arr[i - 1][j] == '*') ctr++;
  }
  if (i - 1 >= 0 && j + 1 >= 0 && j + 1 < m) {
    if (arr[i - 1][j + 1] == '*') ctr++;
  }
  if (j - 1 >= 0) {
    if (arr[i][j - 1] == '*') ctr++;
  }
  if (j + 1 < m) {
    if (arr[i][j + 1] == '*') ctr++;
  }
  if (i + 1 < n && j - 1 >= 0) {
    if (arr[i + 1][j - 1] == '*') ctr++;
  }
  if (i + 1 < n && j >= 0) {
    if (arr[i + 1][j] == '*') ctr++;
  }
  if (i + 1 < n && j + 1 < m) {
    if (arr[i + 1][j + 1] == '*') ctr++;
  }
  return ctr;
}
int main() {
  int n, m;
  char arr[101][101];
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> arr[i][j];
  int flag = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == '*')
        continue;
      else if (arr[i][j] == '.') {
        int x = count(arr, i, j, n, m);
        if (x != 0) {
          flag = 1;
          break;
        }
      } else {
        int x = count(arr, i, j, n, m);
        int y;
        if (arr[i][j] == '1') y = 1;
        if (arr[i][j] == '2') y = 2;
        if (arr[i][j] == '3') y = 3;
        if (arr[i][j] == '4') y = 4;
        if (arr[i][j] == '5') y = 5;
        if (arr[i][j] == '6') y = 6;
        if (arr[i][j] == '7') y = 7;
        if (arr[i][j] == '8') y = 8;
        if (y != x) {
          flag = 1;
          break;
        }
      }
    }
  }
  if (flag == 0)
    cout << "YES";
  else
    cout << "NO";
}
