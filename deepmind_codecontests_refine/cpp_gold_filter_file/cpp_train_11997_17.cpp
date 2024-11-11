#include <bits/stdc++.h>
using namespace std;
char field[100][100];
int memo[60][60][4][4];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void) {
  int nRows;
  int nTurns;
  cin >> nRows >> nTurns;
  int nCols;
  for (int i = 0; i < (int)(60); ++i)
    for (int j = 0; j < (int)(60); ++j) {
      field[i][j] = '0';
    }
  for (int i = 0; i < (int)(nRows); ++i) {
    cin >> &field[i + 1][1];
    nCols = strlen(field[i + 1]);
    field[i + 1][nCols++] = '0';
    field[i + 1][nCols + 1] = '\0';
  }
  memset(memo, -1, sizeof(memo));
  int ci = 1;
  int cj = 1;
  int dir = 0;
  int lr = 3;
  int t = 0;
  for (; nTurns > 0;) {
    if (memo[ci][cj][dir][lr] >= 0) {
      nTurns %= t - memo[ci][cj][dir][lr];
      t = 0;
      memset(memo, -1, sizeof(memo));
    } else {
      memo[ci][cj][dir][lr] = t++;
      int ni = ci;
      int nj = cj;
      int d1 = (dir + lr) % 4;
      while (field[ni + dy[d1]][nj + dx[d1]] == field[ci][cj]) {
        ni += dy[d1];
        nj += dx[d1];
      }
      while (field[ni][nj] == field[ci][cj]) {
        ni += dy[dir];
        nj += dx[dir];
      }
      if (field[ni][nj] != '0') {
        ci = ni;
        cj = nj;
      } else {
        if (lr == 3) {
          lr = 1;
        } else {
          lr = 3;
          dir = (dir + 1) % 4;
        }
      }
      nTurns--;
    }
  }
  cout << field[ci][cj] << endl;
  return 0;
}
