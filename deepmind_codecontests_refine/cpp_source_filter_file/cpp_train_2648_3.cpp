#include <bits/stdc++.h>
int ni() {
  int n1;
  scanf("%d", &n1);
  return n1;
}
int p[4][2];
const int WIN = 0;
const int DRAW = 1;
const int LOSE = 2;
int res(int a1, int d1, int a2, int d2) {
  if (a1 > d2 && d1 > a2) return WIN;
  if (a1 <= d2 && d1 <= a2) return LOSE;
  return DRAW;
}
int main() {
  for (int(i) = 0; (i) < (4); (i)++)
    for (int(j) = 0; (j) < (2); (j)++) p[i][j] = ni();
  bool win = false;
  bool draw = false;
  {
    int res1 = res(p[0][0], p[1][1], p[2][0], p[3][1]);
    int res2 = res(p[0][0], p[1][1], p[3][0], p[2][1]);
    if (res1 == LOSE || res2 == LOSE) {
    } else if (res1 == DRAW || res2 == DRAW) {
      draw = true;
    } else {
      win = true;
    }
  }
  {
    int res1 = res(p[1][0], p[0][1], p[2][0], p[3][1]);
    int res2 = res(p[1][0], p[0][1], p[3][0], p[2][1]);
    if (res1 == LOSE || res2 == LOSE) {
    } else if (res1 == DRAW || res2 == DRAW) {
      draw = true;
    } else {
      win = true;
    }
  }
  if (win) {
    puts("Team 1");
  } else if (draw) {
    puts("Draw");
  } else {
    puts("Team 2");
  }
  return 0;
}
