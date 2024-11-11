#include <bits/stdc++.h>
using namespace std;
char num[25];
char pad[10][10];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", num);
  for (int i = 0; i < n; i++) {
    if (num[i] - '0' == 0)
      pad[3][1]++;
    else
      pad[(num[i] - '0' - 1) / 3][(num[i] - '0' - 1) % 3]++;
  }
  int state = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      if (pad[i][j] != 0) {
        if (i - 1 >= 0)
          state = 0;
        else {
          state = 1;
          break;
        }
      }
    }
    if (state == 1) break;
  }
  if (state == 0) {
    printf("NO\n");
    return 0;
  }
  state = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      if (pad[i][j] != 0) {
        if (i + 1 < 3 && !(i == 3 && j == 1) || i == 2 && j == 1)
          state = 0;
        else {
          state = 1;
          break;
        }
      }
    }
    if (state == 1) break;
  }
  if (state == 0) {
    printf("NO\n");
    return 0;
  }
  state = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      if (pad[i][j] != 0) {
        if (j - 1 >= 0 && !(i == 3 && j == 1))
          state = 0;
        else {
          state = 1;
          break;
        }
      }
    }
    if (state == 1) break;
  }
  if (state == 0) {
    printf("NO\n");
    return 0;
  }
  state = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      if (pad[i][j] != 0) {
        if (j + 1 < 3 && !(i == 3 && j == 1))
          state = 0;
        else {
          state = 1;
          break;
        }
      }
    }
    if (state == 1) break;
  }
  if (state == 0) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
}
