#include <bits/stdc++.h>
using namespace std;
int A, B;
char picture[50][50];
bool check(int X, int Y) {
  for (int a1 = 0; a1 < A; a1 += X) {
    for (int a2 = 0; a2 < A; a2 += X) {
      for (int b1 = 0; b1 < B; b1 += Y) {
        for (int b2 = 0; b2 < B; b2 += Y) {
          if (a1 == a2 && b1 == b2) {
            continue;
          }
          bool flag = false;
          for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
              flag |= (picture[a1 + i][b1 + j] != picture[a2 + i][b2 + j]);
            }
          }
          if (!flag) {
            return false;
          }
          flag = false;
          for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
              flag |= (picture[a1 + X - i - 1][b1 + Y - j - 1] !=
                       picture[a2 + i][b2 + j]);
            }
          }
          if (!flag) {
            return false;
          }
          if (X != Y) {
            continue;
          }
          flag = false;
          for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
              flag |=
                  (picture[a1 + j][b1 + Y - i - 1] != picture[a2 + i][b2 + j]);
            }
          }
          if (!flag) {
            return false;
          }
          flag = false;
          for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
              flag |=
                  (picture[a1 + X - j - 1][b1 + i] != picture[a2 + i][b2 + i]);
            }
          }
          if (!flag) {
            return false;
          }
        }
      }
    }
  }
  return true;
}
int main() {
  scanf("%d%d", &A, &B);
  for (int i = 0; i < A; i++) {
    scanf("%s", picture[i]);
  }
  pair<int, int> best(A, B);
  int count = 0;
  for (int X = 1; X <= A; X++) {
    for (int Y = 1; Y <= B; Y++) {
      if ((A % X) || (B % Y)) {
        continue;
      }
      if (check(X, Y)) {
        count++;
        if ((X * Y < best.first * best.second) ||
            ((X * Y == best.first * best.second) && X < best.first)) {
          best = pair<int, int>(X, Y);
        }
      }
    }
  }
  printf("%d\n", count);
  printf("%d %d", best.first, best.second);
  return 0;
}
