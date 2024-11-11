#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 5, m;
  cin >> m;
  int a[n + 1][n + 1];
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < n + 1; j++) {
      a[i][j] = 0;
    }
  }
  int x, y;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    a[x][y] = 1;
    a[y][x] = 1;
  }
  int flag = 0;
  for (int i = 1; i < n + 1; i++) {
    for (int j = i + 1; j < n + 1; j++) {
      if (a[i][j] == 1) {
        for (int k = j + 1; k < n + 1; k++) {
          if (a[i][k] == 1 && a[j][k] == 1) flag = 1;
        }
      } else if (a[i][j] == 0) {
        for (int k = j + 1; k < n + 1; k++) {
          if (a[i][k] == 0 && a[j][k] == 0) flag = 1;
        }
      }
    }
  }
  if (flag == 0) {
    cout << "FAIL"
         << "\n";
  } else {
    cout << "WIN"
         << "\n";
  }
}
