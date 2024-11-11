#include <bits/stdc++.h>
int main() {
  char pass[81];
  scanf("%s", pass);
  char key[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      scanf(" %c", &key[i][j]);
    }
  }
  for (int j = 0; j <= 9; j++) {
    int mark = 0;
    for (int i = 0; i <= 9; i++) {
      if (pass[i] != key[j][i]) mark = 1;
    }
    if (mark == 0) {
      printf("%d", j);
      break;
    }
  }
  for (int j = 0; j <= 9; j++) {
    int mark = 0;
    for (int i = 0; i <= 9; i++) {
      if (pass[i + 10] != key[j][i]) mark = 1;
    }
    if (mark == 0) {
      printf("%d", j);
      break;
    }
  }
  for (int j = 0; j <= 9; j++) {
    int mark = 0;
    for (int i = 0; i <= 9; i++) {
      if (pass[i + 20] != key[j][i]) mark = 1;
    }
    if (mark == 0) {
      printf("%d", j);
      break;
    }
  }
  for (int j = 0; j <= 9; j++) {
    int mark = 0;
    for (int i = 0; i <= 9; i++) {
      if (pass[i + 30] != key[j][i]) mark = 1;
    }
    if (mark == 0) {
      printf("%d", j);
      break;
    }
  }
  for (int j = 0; j <= 9; j++) {
    int mark = 0;
    for (int i = 0; i <= 9; i++) {
      if (pass[i + 40] != key[j][i]) mark = 1;
    }
    if (mark == 0) {
      printf("%d", j);
      break;
    }
  }
  for (int j = 0; j <= 9; j++) {
    int mark = 0;
    for (int i = 0; i <= 9; i++) {
      if (pass[i + 50] != key[j][i]) mark = 1;
    }
    if (mark == 0) {
      printf("%d", j);
      break;
    }
  }
  for (int j = 0; j <= 9; j++) {
    int mark = 0;
    for (int i = 0; i <= 9; i++) {
      if (pass[i + 60] != key[j][i]) mark = 1;
    }
    if (mark == 0) {
      printf("%d", j);
      break;
    }
  }
  for (int j = 0; j <= 9; j++) {
    int mark = 0;
    for (int i = 0; i <= 9; i++) {
      if (pass[i + 70] != key[j][i]) mark = 1;
    }
    if (mark == 0) {
      printf("%d\n", j);
      break;
    }
  }
  return 0;
}
