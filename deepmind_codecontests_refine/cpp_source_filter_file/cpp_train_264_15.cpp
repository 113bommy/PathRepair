#include <bits/stdc++.h>
using namespace std;
int n, m, a[5][5], sum, add, ex;
char c[5][5];
int main() {
  for (int i = 1; i <= 4; i++)
    for (int j = 1; j <= 4; j++) {
      cin >> c[i][j];
      if (c[i][j] == 'x') {
        a[i][j] = 4;
        sum++;
      } else if (c[i][j] == 'o') {
        a[i][j] = 1;
        add++;
      }
    }
  if (sum == add)
    ex = 8;
  else
    ex = 2;
  for (int i = 1; i <= 4; i++)
    for (int j = 1; j <= 2; j++)
      if (a[i][j] + a[i][j + 1] + a[i][j + 2] == ex) {
        cout << "YES";
        return 0;
      }
  for (int i = 1; i <= 2; i++)
    for (int j = 1; j <= 4; j++)
      if (a[i][j] + a[i + 1][j] + a[i + 2][j] == ex) {
        cout << "YES";
        return 0;
      }
  if (a[1][1] + a[2][2] + a[3][3] == ex) {
    cout << "YES";
    return 0;
  }
  if (a[2][2] + a[3][3] + a[4][4] == ex) {
    cout << "YES";
    return 0;
  }
  if (a[1][4] + a[2][3] + a[3][2] == ex) {
    cout << "YES";
    return 0;
  }
  if (a[2][3] + a[3][2] + a[4][1] == ex) {
    cout << "YES";
    return 0;
  }
  if (a[3][1] + a[2][2] + a[1][3] == ex) {
    cout << "YES";
    return 0;
  }
  if (a[4][2] + a[3][3] + a[2][4] == ex) {
    cout << "YES";
    return 0;
  }
  if (a[2][2] + a[3][3] + a[4][4] == ex) {
    cout << "YES";
    return 0;
  }
  if (a[1][2] + a[2][3] + a[3][4] == ex) {
    cout << "YES";
    return 0;
  }
  cout << "NO";
  return 0;
}
