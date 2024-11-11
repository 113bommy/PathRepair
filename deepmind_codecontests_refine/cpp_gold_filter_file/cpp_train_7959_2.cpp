#include <bits/stdc++.h>
int dist(int a, int b) {
  if (a > b) {
    return a - b;
  } else {
    return b - a;
  }
}
int main(void) {
  int N, M;
  int C, H;
  int m[4];
  int cx[8], cy[8];
  int i, j, x, y, max, min, ans, d;
  scanf("%d %d %d", &N, &M, &C);
  m[0] = 0;
  m[1] = -M;
  m[2] = -N;
  m[3] = -M - N - 1;
  for (i = 0; i < C; i++) {
    scanf("%d %d", &x, &y);
    if (x + y > m[0]) {
      m[0] = x + y;
      cx[0] = x;
      cy[0] = y;
      cx[1] = x;
      cy[1] = y;
    } else if (x + y == m[0]) {
      if (cx[0] < x) {
        cx[0] = x;
        cy[0] = y;
      }
      if (cx[1] > x) {
        cx[1] = x;
        cy[1] = y;
      }
    }
    if (x - y > m[1]) {
      m[1] = x - y;
      cx[2] = x;
      cy[2] = y;
      cx[3] = x;
      cy[3] = y;
    } else if (x - y == m[1]) {
      if (cx[2] < x) {
        cx[2] = x;
        cy[2] = y;
      }
      if (cx[3] > x) {
        cx[3] = x;
        cy[3] = y;
      }
    }
    if (-x + y > m[2]) {
      m[2] = -x + y;
      cx[4] = x;
      cy[4] = y;
      cx[5] = x;
      cy[5] = y;
    } else if (-x + y == m[2]) {
      if (cx[4] < x) {
        cx[4] = x;
        cy[4] = y;
      }
      if (cx[5] > x) {
        cx[5] = x;
        cy[5] = y;
      }
    }
    if (-x - y > m[3]) {
      m[3] = -x - y;
      cx[6] = x;
      cy[6] = y;
      cx[7] = x;
      cy[7] = y;
    } else if (-x - y == m[3]) {
      if (cx[6] < x) {
        cx[6] = x;
        cy[6] = y;
      }
      if (cx[7] > x) {
        cx[7] = x;
        cy[7] = y;
      }
    }
  }
  scanf("%d", &H);
  min = M + N + 1;
  for (i = 0; i < H; i++) {
    scanf("%d %d", &x, &y);
    max = 0;
    for (j = 0; j < 8; j++) {
      d = dist(x, cx[j]) + dist(y, cy[j]);
      if (max < d) {
        max = d;
      }
    }
    if (min > max) {
      min = max;
      ans = i + 1;
    }
  }
  printf("%d\n%d\n", min, ans);
}
