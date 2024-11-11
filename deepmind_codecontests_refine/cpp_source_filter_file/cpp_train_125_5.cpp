#include <bits/stdc++.h>
using namespace std;
long long x, y, c, n;
char s[51][51];
int b[2500][13];
int which(int px, int py) {
  for (int i = 0; i < c; i++)
    if (px >= b[i][9] && py >= b[i][10] && px <= b[i][11] && py <= b[i][12])
      return i;
  return -1;
}
void walk(int px, int py) {
  int i, ex;
  char cc = s[px][py];
  b[c][8] = cc - '0';
  b[c][9] = px;
  b[c][10] = py;
  for (i = px; i < x; i++)
    if (s[i][py] != cc) break;
  ex = b[c][11] = i - 1;
  for (i = py; i < y; i++)
    if (s[ex][i] != cc) break;
  b[c][12] = i - 1;
  c++;
}
void neighb(int bi) {
  int bx = b[bi][9];
  int by = b[bi][10];
  int ex = b[bi][11];
  int ey = b[bi][12];
  if (ey == y - 1) {
    b[bi][0] = -1;
    b[bi][1] = -1;
  } else {
    b[bi][0] = which(bx, ey + 1);
    b[bi][1] = which(ex, ey + 1);
  }
  if (ex == x - 1) {
    b[bi][2] = -1;
    b[bi][3] = -1;
  } else {
    b[bi][2] = which(ex + 1, ey);
    b[bi][3] = which(ex + 1, by);
  }
  if (ey == 0) {
    b[bi][4] = -1;
    b[bi][5] = -1;
  } else {
    b[bi][4] = which(ex, ey - 1);
    b[bi][5] = which(bx, ey - 1);
  }
  if (ex == 0) {
    b[bi][6] = -1;
    b[bi][7] = -1;
  } else {
    b[bi][6] = which(ex - 1, by);
    b[bi][7] = which(ex - 1, ey);
  }
}
int main() {
  cin >> x >> n;
  cin.getline(s[0], 1);
  for (int i = 0; i < x; i++) cin.getline(s[i], 51);
  y = strlen(s[0]);
  for (int i = 0; i < x; i++)
    for (int j = 0; j < y; j++) {
      if (s[i][j] == '0') continue;
      if (i > 0 && (s[i - 1][j] == s[i][j]) ||
          j > 0 && (s[i][j - 1] == s[i][j]))
        continue;
      walk(i, j);
    }
  for (int i = 0; i < c; i++) neighb(i);
  int bp = 0, dp = 0, cp = 0;
  for (int i = 0; i < n; i++) {
    if (b[bp][dp + cp] < 0) {
      if (cp) dp = (dp + 2) % 8;
      cp = 1 - cp;
    } else {
      bp = b[bp][dp + cp];
    }
  }
  cout << b[bp][8];
  return 0;
}
