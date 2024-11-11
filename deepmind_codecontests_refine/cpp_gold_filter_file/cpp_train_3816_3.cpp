#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, c;
  cin >> r >> c;
  int x[4] = {1, -1, 0, 0};
  int y[4] = {0, 0, 1, -1};
  char grid[r][c];
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> grid[i][j];
    }
  }
  bool b = true;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == 'S') {
        int ii = 0, jj = 0;
        for (int k = 0; k < 4; k++) {
          ii = i + x[k], jj = j + y[k];
          if (ii < r && jj < c && ii > -1 && jj > -1) {
            if (grid[ii][jj] == 'W') {
              cout << "NO";
              return 0;
            } else if (grid[ii][jj] != 'S') {
              grid[ii][jj] = 'D';
            }
          }
        }
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
}
