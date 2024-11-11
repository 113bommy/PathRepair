#include <bits/stdc++.h>
using namespace std;
bool chess[5][5] = {false};
int row[5] = {0}, col[5] = {0};
int can0() {
  for (int i = 3; i >= 1; i--) {
    for (int j = 1; j <= 4; j++) {
      if (chess[i][j] == false && chess[i + 1][j] == false) {
        chess[i][j] = true;
        chess[i + 1][j] = true;
        col[j] += 2;
        row[i]++;
        row[i + 1]++;
        return i * 10 + j;
      }
    }
  }
  return 0;
}
int can1() {
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 3; j++) {
      if (chess[i][j] == false && chess[i][j + 1] == false) {
        chess[i][j] = true;
        chess[i][j + 1] = true;
        row[i] += 2;
        col[j]++;
        col[j + 1]++;
        return i * 10 + j;
      }
    }
  }
  return 0;
}
void pd() {
  for (int i = 1; i <= 4; i++) {
    if (row[i] == 4) {
      for (int j = 1; j <= 4; j++) {
        chess[i][j] = false;
        col[j]--;
      }
      row[i] = 0;
    }
  }
  for (int i = 1; i <= 4; i++) {
    if (col[i] == 4) {
      for (int j = 1; j <= 4; j++) {
        chess[j][i] = false;
        row[j]--;
      }
      col[i] = 0;
    }
  }
}
int main(void) {
  char s[1010];
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      int a = can0();
      printf("%d %d\n", a / 10, a % 10);
      pd();
    }
    if (s[i] == '1') {
      int a = can1();
      printf("%d %d\n", a / 10, a % 10);
      pd();
    }
  }
  return 0;
}
