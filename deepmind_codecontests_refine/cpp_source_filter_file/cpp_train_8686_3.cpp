#include <bits/stdc++.h>
using namespace std;
char a[101][101];
int main() {
  int n, m;
  cin >> n >> m;
  int cntr = 0;
  char e;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < n; j++) {
        if (j % 2 == 0 && a[i][j] != '-' && a[i][j - 1] != '-') {
          cout << "B";
        }
        if (j % 2 == 1 && a[i][j] != '-' && a[i][j - 1] != '-') {
          cout << "W";
        }
        if (a[i][j] == '-') {
          cntr++;
          cout << "-";
        }
        if (a[i][j - 1] == '-' && a[i][j] != '-') {
          if (j % 2 == 0) {
            cout << "B";
          }
          if (j % 2 == 1) {
            cout << "W";
          }
          cntr = 0;
        }
      }
    }
    if (i % 2 == 1) {
      for (int j = 0; j < n; j++) {
        if (j % 2 == 0 && a[i][j] != '-' && a[i][j - 1] != '-') {
          cout << "W";
        }
        if (j % 2 == 1 && a[i][j] != '-' && a[i][j - 1] != '-') {
          cout << "B";
        }
        if (a[i][j + 1] == '-' && (a[i][j] == 'B' || a[i][j] == 'W')) {
          e = a[i][j];
        }
        if (a[i][j] == '-') {
          cntr++;
          cout << "-";
        }
        if (a[i][j - 1] == '-' && a[i][j] != '-') {
          if (j % 2 == 0) {
            cout << "W";
          }
          if (j % 2 == 1) {
            cout << "B";
          }
          cntr = 0;
        }
      }
    }
    cout << endl;
  }
  return 0;
}
