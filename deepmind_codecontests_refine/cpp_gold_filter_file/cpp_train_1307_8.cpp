#include <bits/stdc++.h>
using namespace std;
int m, n, J[2][2], temp[20][20][2], out[2][2];
char r[20][20][5];
bool b[15][4];
int ref1(char c) {
  if (c == 'T') return 8;
  if (c == 'J') return 9;
  if (c == 'Q') return 10;
  if (c == 'K') return 11;
  if (c == 'A') return 12;
  return c - '2';
}
int ref2(char c) {
  if (c == 'C') return 0;
  if (c == 'D') return 1;
  if (c == 'H') return 2;
  if (c == 'S') return 3;
}
char nref1(int z) {
  if (z == 8) return 'T';
  if (z == 9) return 'J';
  if (z == 10) return 'Q';
  if (z == 11) return 'K';
  if (z == 12) return 'A';
  return z + '2';
}
char nref2(int z) {
  if (z == 0) return 'C';
  if (z == 1) return 'D';
  if (z == 2) return 'H';
  if (z == 3) return 'S';
}
bool check1(int x, int y) {
  char c = r[x][y][1];
  for (int i = x - 2; i <= x; i++) {
    for (int j = y - 2; j <= y; j++) {
      if (r[i][j][1] != c) {
        return false;
      }
    }
  }
  return true;
}
bool check2(int x, int y) {
  bool bb[15];
  for (int i = 0; i < 13; i++) {
    bb[i] = true;
  }
  for (int i = x - 2; i <= x; i++) {
    for (int j = y - 2; j <= y; j++) {
      if (bb[ref1(r[i][j][0])]) {
        bb[ref1(r[i][j][0])] = false;
      } else {
        return false;
      }
    }
  }
  return true;
}
bool check() {
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      temp[i][j][0] = -1;
    }
  }
  for (int i = 3; i <= m; i++) {
    for (int j = 3; j <= n; j++) {
      if ((check1(i, j)) || (check2(i, j))) {
        if (temp[i - 3][n][0] != -1) {
          out[0][0] = temp[i - 3][n][0] - 2;
          out[0][1] = temp[i - 3][n][1] - 2;
          out[1][0] = i - 2;
          out[1][1] = j - 2;
          return true;
        }
        if (temp[i][j - 3][0] != -1) {
          out[0][0] = temp[i][j - 3][0] - 2;
          out[0][1] = temp[i][j - 3][1] - 2;
          out[1][0] = i - 2;
          out[1][1] = j - 2;
          return true;
        }
        temp[i][j][0] = i;
        temp[i][j][1] = j;
      } else if (temp[i - 1][j][0] != -1) {
        temp[i][j][0] = temp[i - 1][j][0];
        temp[i][j][1] = temp[i - 1][j][1];
      } else if (temp[i][j - 1][0] != -1) {
        temp[i][j][0] = temp[i][j - 1][0];
        temp[i][j][1] = temp[i][j - 1][1];
      }
    }
  }
  return false;
}
void solve1() {
  for (int i = 0; i < 13; i++) {
    for (int j = 0; j < 4; j++) {
      if (b[i][j]) {
        sprintf(r[J[0][0]][J[0][1]], "%c%c", nref1(i), nref2(j));
        if (check()) {
          printf(
              "Solution exists.\nReplace J1 with %s.\nPut the first square to "
              "(%d, %d).\nPut the second square to (%d, %d).\n",
              r[J[0][0]][J[0][1]], out[0][0], out[0][1], out[1][0], out[1][1]);
          return;
        }
      }
    }
  }
  printf("No solution.\n");
}
void solve2() {
  for (int i = 0; i < 13; i++) {
    for (int j = 0; j < 4; j++) {
      if (b[i][j]) {
        sprintf(r[J[1][0]][J[1][1]], "%c%c", nref1(i), nref2(j));
        if (check()) {
          printf(
              "Solution exists.\nReplace J2 with %s.\nPut the first square to "
              "(%d, %d).\nPut the second square to (%d, %d).\n",
              r[J[1][0]][J[1][1]], out[0][0], out[0][1], out[1][0], out[1][1]);
          return;
        }
      }
    }
  }
  printf("No solution.\n");
}
void solve12() {
  for (int i = 0; i < 13; i++) {
    for (int j = 0; j < 4; j++) {
      if (b[i][j]) {
        sprintf(r[J[0][0]][J[0][1]], "%c%c", nref1(i), nref2(j));
        for (int k = 0; k < 13; k++) {
          for (int l = 0; l < 4; l++) {
            if ((b[k][l]) && ((k != i) || (l != j))) {
              sprintf(r[J[1][0]][J[1][1]], "%c%c", nref1(k), nref2(l));
              if (check()) {
                printf(
                    "Solution exists.\nReplace J1 with %s and J2 with %s.\nPut "
                    "the first square to (%d, %d).\nPut the second square to "
                    "(%d, %d).\n",
                    r[J[0][0]][J[0][1]], r[J[1][0]][J[1][1]], out[0][0],
                    out[0][1], out[1][0], out[1][1]);
                return;
              }
            }
          }
        }
      }
    }
  }
  printf("No solution.\n");
}
int main() {
  J[0][0] = J[0][1] = -1;
  J[1][0] = J[1][1] = -1;
  for (int i = 0; i < 13; i++) {
    for (int j = 0; j < 4; j++) {
      b[i][j] = true;
    }
  }
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%s", r[i][j]);
      if ((r[i][j][0] == 'J') && (r[i][j][1] <= '2')) {
        J[r[i][j][1] - '1'][0] = i;
        J[r[i][j][1] - '1'][1] = j;
      } else {
        b[ref1(r[i][j][0])][ref2(r[i][j][1])] = false;
      }
    }
  }
  if (J[0][0] == -1) {
    if (J[1][0] == -1) {
      if (check()) {
        printf(
            "Solution exists.\nThere are no jokers.\nPut the first square to "
            "(%d, %d).\nPut the second square to (%d, %d).\n",
            out[0][0], out[0][1], out[1][0], out[1][1]);
      } else {
        printf("No solution.\n");
      }
    } else {
      solve2();
    }
  } else {
    if (J[1][0] == -1) {
      solve1();
    } else {
      solve12();
    }
  }
  return 0;
}
