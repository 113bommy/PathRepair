#include <bits/stdc++.h>
using namespace std;
int T;
int main() {
  cin >> T;
  while (T--) {
    int c, r;
    cin >> r >> c;
    char grid[65][65];
    int cnt = 0;
    bool corner = false, edge = false;
    int colcnts[65], rowcnts[65];
    fill(colcnts, colcnts + c + 1, 0);
    fill(rowcnts, rowcnts + r + 1, 0);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin >> grid[i][j];
        if (grid[i][j] == 'A') {
          cnt++;
          rowcnts[i]++;
          colcnts[j]++;
          if (j == 0 || j == c - 1 || i == 0 || i == r - 1) {
            edge = true;
          }
          if ((i == 0 || i == r - 1) && (j == 0 || j == c - 1)) {
            corner = true;
          }
        }
      }
    }
    bool full = false;
    if (cnt == 0) {
      cout << "MORTAL" << endl;
      continue;
    }
    if (cnt == r * c) {
      cout << "0" << endl;
      continue;
    }
    if (colcnts[0] == r || colcnts[c - 1] == r || rowcnts[0] == c ||
        rowcnts[r - 1] == c) {
      cout << "1" << endl;
      continue;
    }
    for (int i = 0; i < c; i++) {
      if (colcnts[i] == r) {
        full = true;
      }
    }
    for (int i = 0; i < r; i++) {
      if (rowcnts[i] == c) {
        full = true;
      }
    }
    if (full) {
      cout << "2" << endl;
      continue;
    }
    if (corner) {
      cout << "2" << endl;
      continue;
    }
    if (edge) {
      cout << "3" << endl;
      continue;
    }
    cout << "4" << endl;
  }
  return 0;
}
