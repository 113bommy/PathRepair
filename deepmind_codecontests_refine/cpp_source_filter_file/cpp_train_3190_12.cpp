#include <bits/stdc++.h>
using namespace std;
int main() {
  char arr[15][15];
  char c;
  int x = 0, y = 0;
  while (cin >> c) {
    if (c == 'x' || c == 'o' || c == '.') {
      arr[x][y++] = c;
      if (y >= 9) {
        y -= 9;
        x += 1;
      }
    }
    if (x == 9) break;
  }
  cin >> x >> y;
  x = (x - 1) % 3;
  y = (y - 1) % 3;
  x *= 3;
  y *= 3;
  int sol = 0;
  for (int i = x; i < x + 3; i++) {
    for (int j = y; j < y + 3; j++) {
      if (arr[i][j] == '.') {
        arr[i][j] = '!';
        sol = 1;
      }
    }
  }
  if (sol) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cout << arr[i][j];
        if (j % 3 == 2 && j != 8) cout << ' ';
      }
      if (i % 3 == 3 && i != 8) {
        cout << endl;
      }
      cout << endl;
    }
  } else {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (arr[i][j] == '.')
          cout << '!';
        else
          cout << arr[i][j];
        if (j % 3 == 2 && j != 8) cout << ' ';
      }
      if (i % 3 == 3 && i != 8) {
        cout << endl;
      }
      cout << endl;
    }
  }
  return 0;
}
