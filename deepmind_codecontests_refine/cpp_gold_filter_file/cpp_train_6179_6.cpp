#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
struct point {
  int x, y;
};
int board[1015][1015];
int ifsquare(int x, int y) {
  int i, j, con;
  con = 0;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (board[x + i][y + j] != 1) {
        con = 1;
        break;
      }
    }
    if (con == 1) break;
  }
  if (con == 0) return 1;
  con = 0;
  for (i = 0; i < 3; i++) {
    for (j = -1; j < 2; j++) {
      if (board[x + i][y + j] != 1) {
        con = 1;
        break;
      }
    }
    if (con == 1) break;
  }
  if (con == 0) return 1;
  con = 0;
  for (i = 0; i < 3; i++) {
    for (j = -2; j < 1; j++) {
      if (board[x + i][y + j] != 1) {
        con = 1;
        break;
      }
    }
    if (con == 1) break;
  }
  if (con == 0) return 1;
  con = 0;
  for (i = -1; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      if (board[x + i][y + j] != 1) {
        con = 1;
        break;
      }
    }
    if (con == 1) break;
  }
  if (con == 0) return 1;
  con = 0;
  for (i = -1; i < 2; i++) {
    for (j = -1; j < 2; j++) {
      if (board[x + i][y + j] != 1) {
        con = 1;
        break;
      }
    }
    if (con == 1) break;
  }
  if (con == 0) return 1;
  con = 0;
  for (i = -1; i < 2; i++) {
    for (j = -2; j < 1; j++) {
      if (board[x + i][y + j] != 1) {
        con = 1;
        break;
      }
    }
    if (con == 1) break;
  }
  if (con == 0) return 1;
  con = 0;
  for (i = -2; i < 1; i++) {
    for (j = 0; j < 3; j++) {
      if (board[x + i][y + j] != 1) {
        con = 1;
        break;
      }
    }
    if (con == 1) break;
  }
  if (con == 0) return 1;
  con = 0;
  for (i = -2; i < 1; i++) {
    for (j = -1; j < 2; j++) {
      if (board[x + i][y + j] != 1) {
        con = 1;
        break;
      }
    }
    if (con == 1) break;
  }
  if (con == 0) return 1;
  con = 0;
  for (i = -2; i < 1; i++) {
    for (j = -2; j < 1; j++) {
      if (board[x + i][y + j] != 1) {
        con = 1;
        break;
      }
    }
    if (con == 1) break;
  }
  if (con == 0) return 1;
  return 0;
}
int main(void) {
  int n, m, i, j, x, y, rez = -1, ans;
  point mas[10000];
  cin >> n >> m;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) board[i][j] = 0;
  rez = -1;
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    x += 2;
    y += 2;
    mas[i].x = x;
    mas[i].y = y;
    board[x][y] = 1;
    if (ifsquare(x, y)) {
      rez = 1;
      ans = i;
      break;
    }
  }
  if (rez == 1) {
    cout << ans + 1;
  } else
    cout << "-1";
  return 0;
}
