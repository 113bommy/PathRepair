#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, c;
  cin >> r >> c;
  char a[r][c];
  int count = 0, p = 0;
  int row, col;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (a[i][j] == 'B') {
        p = 1;
        int k = j + 1;
        row = i;
        col = j;
        while (a[i][k] == 'B' && k <= c) {
          p++;
          k++;
        }
        count = 1;
        break;
      }
    }
    if (count == 1) break;
  }
  int s = p / 2;
  row = row + s;
  col = col + s;
  cout << row + 1 << " " << col + 1;
  return 0;
}
