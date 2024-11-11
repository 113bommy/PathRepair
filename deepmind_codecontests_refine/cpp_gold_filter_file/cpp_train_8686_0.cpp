#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < m; j++) {
        if (j % 2 == 0) {
          if (a[i][j] == '-') {
            cout << '-';
          } else {
            cout << 'B';
          }
        } else {
          if (a[i][j] == '-') {
            cout << '-';
          } else {
            cout << 'W';
          }
        }
      }
      cout << endl;
    } else {
      for (int j = 0; j < m; j++) {
        if (j % 2 == 0) {
          if (a[i][j] == '-') {
            cout << '-';
          } else {
            cout << 'W';
          }
        } else {
          if (a[i][j] == '-') {
            cout << '-';
          } else {
            cout << 'B';
          }
        }
      }
      cout << endl;
    }
  }
  return 0;
}
