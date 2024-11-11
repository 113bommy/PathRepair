#include <bits/stdc++.h>
using namespace std;
int chartoint(char c) {
  switch (c) {
    case 'a':
      return 1;
    case 'b':
      return 2;
    case 'c':
      return 3;
    case 'd':
      return 4;
    case 'e':
      return 5;
    case 'f':
      return 6;
    case 'g':
      return 7;
    case 'h':
      return 8;
    default:
      return 0;
  }
}
int main() {
  int board[8][8];
  char pos1[3], pos2[3];
  cin >> pos1;
  cin >> pos2;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      board[i][j] = 0;
    }
  int idx1 = chartoint(pos1[0]);
  int idx2 = atoi(&pos1[1]);
  for (int i = 0; i < 8; i++) {
    board[i][idx1 - 1] = 1;
    board[idx2 - 1][i] = 1;
  }
  if (((idx1 - 1) + 2) < 8) {
    if ((idx2 - 1) - 1 > 0) board[(idx2 - 1) - 1][(idx1 - 1) + 2] = 1;
    if ((idx2 - 1) + 1 < 8) board[(idx2 - 1) + 1][(idx1 - 1) + 2] = 1;
  }
  if (((idx1 - 1) - 2) >= 0) {
    if ((idx2 - 1) - 1 >= 0) board[(idx2 - 1) - 1][(idx1 - 1) - 2] = 1;
    if ((idx2 - 1) + 1 < 8) board[(idx2 - 1) + 1][(idx1 - 1) - 2] = 1;
  }
  if (((idx1 - 1) + 1) < 8) {
    if ((idx2 - 1) - 2 >= 0) board[(idx2 - 1) - 2][(idx1 - 1) + 1] = 1;
    if ((idx2 - 1) + 2 < 8) board[(idx2 - 1) + 2][(idx1 - 1) + 1] = 1;
  }
  if (((idx1 - 1) - 1) >= 0) {
    if ((idx2 - 1) - 2 >= 0) board[(idx2 - 1) - 2][(idx1 - 1) - 1] = 1;
    if ((idx2 - 1) + 2 < 8) board[(idx2 - 1) + 2][(idx1 - 1) - 1] = 1;
  }
  idx1 = chartoint(pos2[0]);
  idx2 = atoi(&pos2[1]);
  board[idx2 - 1][idx1 - 1] = 1;
  if (((idx1 - 1) + 2) < 8) {
    if ((idx2 - 1) - 1 >= 0) board[(idx2 - 1) - 1][(idx1 - 1) + 2] = 1;
    if ((idx2 - 1) + 1 < 8) board[(idx2 - 1) + 1][(idx1 - 1) + 2] = 1;
  }
  if (((idx1 - 1) - 2) >= 0) {
    if ((idx2 - 1) - 1 >= 0) board[(idx2 - 1) - 1][(idx1 - 1) - 2] = 1;
    if ((idx2 - 1) + 1 < 8) board[(idx2 - 1) + 1][(idx1 - 1) - 2] = 1;
  }
  if (((idx1 - 1) + 1) < 8) {
    if ((idx2 - 1) - 2 >= 0) board[(idx2 - 1) - 2][(idx1 - 1) + 1] = 1;
    if ((idx2 - 1) + 2 < 8) board[(idx2 - 1) + 2][(idx1 - 1) + 1] = 1;
  }
  if (((idx1 - 1) - 1) >= 0) {
    if ((idx2 - 1) - 2 >= 0) board[(idx2 - 1) - 2][(idx1 - 1) - 1] = 1;
    if ((idx2 - 1) + 2 < 8) board[(idx2 - 1) + 2][(idx1 - 1) - 1] = 1;
  }
  int count = 0;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      if (board[i][j] != 1) count++;
    }
  cout << count;
}
