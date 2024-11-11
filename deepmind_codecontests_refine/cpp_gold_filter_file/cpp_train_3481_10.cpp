#include <bits/stdc++.h>
using namespace std;
bool dop(int x, int y) { return (x >= 0) && (y >= 0) && (x <= 7) && (y <= 7); }
int main() {
  char c;
  int a[8][8], b[8][8];
  int posx[4], posy[4];
  int i, j, k, x, y;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      a[i][j] = 0;
      b[i][j] = 0;
    }
  }
  for (i = 0; i < 4; i++) {
    cin >> c >> k;
    posx[i] = c - 'a';
    posy[i] = k - 1;
    b[posx[i]][posy[i]] = 1;
  }
  b[posx[3]][posy[3]] = 0;
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 4; j++) {
      x = posx[i] + dx[j];
      y = posy[i] + dy[j];
      while (dop(x, y) && b[x][y] == 0) {
        a[x][y] = 1;
        x += dx[j];
        y += dy[j];
      }
      if (dop(x, y)) {
        a[x][y] = 1;
      }
    }
  }
  x = posx[2];
  y = posy[2];
  for (i = -1; i < 2; i++) {
    for (j = -1; j < 2; j++) {
      if (dop(x + i, y + j) && (i || j)) {
        a[x + i][y + j] = 1;
      }
    }
  }
  x = posx[3];
  y = posy[3];
  for (i = -1; i < 2; i++) {
    for (j = -1; j < 2; j++) {
      if (dop(x + i, y + j) && a[x + i][y + j] == 0) {
        cout << "OTHER";
        return 0;
      }
    }
  }
  cout << "CHECKMATE";
  return 0;
}
