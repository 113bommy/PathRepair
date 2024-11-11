#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, m, n, res;
  string str;
  cin >> k;
  while (k--) {
    res = -1;
    char grid[65][65];
    cin >> m >> n;
    cin.ignore();
    for (int i = 0; i < m; i++) {
      getline(cin, str);
      for (int j = 0; j < n; j++) grid[i][j] = str[j];
    }
    for (int i = 0; i < m * n; i++) {
      if (grid[i / n][i % n] == 'P') break;
      if (i == m * n - 1) res = 0;
    }
    if (res != -1) {
      cout << res << endl;
      continue;
    }
    for (int i = 0; i < m; i++) {
      if (grid[i][0] == 'P') break;
      if (i == m - 1) res = 1;
    }
    if (res != -1) {
      cout << res << endl;
      continue;
    }
    for (int i = 0; i < m; i++) {
      if (grid[i][n - 1] == 'P') break;
      if (i == m - 1) res = 1;
    }
    if (res != -1) {
      cout << res << endl;
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (grid[0][i] == 'P') break;
      if (i == n - 1) res = 1;
    }
    if (res != -1) {
      cout << res << endl;
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (grid[m - 1][i] == 'P') break;
      if (i == n - 1) res = 1;
    }
    if (res != -1) {
      cout << res << endl;
      continue;
    }
    if (grid[0][0] == 'A' || grid[0][n - 1] == 'A' || grid[m - 1][0] == 'A' ||
        grid[m - 1][n - 1] == 'A')
      res = 2;
    if (res != -1) {
      cout << res << endl;
      continue;
    }
    for (int i = 1; i < m - 1; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 'P') break;
        if (j == n - 1) res = 2;
      }
      if (res != -1) break;
    }
    if (res != -1) {
      cout << res << endl;
      continue;
    }
    for (int i = 1; i < n - 1; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[j][i] == 'P') break;
        if (j == m - 1) res = 2;
      }
      if (res != -1) break;
    }
    if (res != -1) {
      cout << res << endl;
      continue;
    }
    for (int i = 0; i < m + n; i++) {
      if (grid[i / n][i % n] == 'A' &&
          (i / n == 0 || i / n == (m - 1) || i % n == 0 || i % n == (n - 1))) {
        res = 3;
        break;
      }
    }
    if (res != -1) {
      cout << res << endl;
      continue;
    }
    for (int i = 0; i < m * n; i++) {
      if (grid[i / n][i % n] == 'A') {
        res = 4;
        break;
      }
    }
    if (res == 4)
      cout << res << endl;
    else
      cout << "MORTAL" << endl;
  }
}
