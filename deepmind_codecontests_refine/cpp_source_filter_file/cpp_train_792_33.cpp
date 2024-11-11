#include <bits/stdc++.h>
int main() {
  int r, c;
  scanf("%d %d", &r, &c);
  int ara[r][c];
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      ara[i][j] = 1;
    }
  }
  char str[r][c + 1];
  for (int i = 0; i < r; i++) {
    scanf(" %[^\n]", str[i]);
  }
  for (int i = 0; i < r; i++) {
    int temp[26] = {0};
    for (int j = 0; j < c; j++) {
      temp[str[i][j] - 'a']++;
    }
    for (int j = 0; j < c; j++) {
      if (temp[str[i][j] - 'a'] > 1) {
        ara[i][j] = 0;
      }
    }
  }
  for (int i = 0; i < c; i++) {
    int temp[26] = {0};
    for (int j = 0; j < r; j++) {
      temp[str[j][i] - 'a']++;
    }
    for (int j = 0; j < c; j++) {
      if (temp[str[j][i] - 'a'] > 1) {
        ara[j][i] = 0;
      }
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (ara[i][j]) {
        printf("%c", str[i][j]);
      }
    }
  }
  printf("\n");
  return 0;
}
