#include <bits/stdc++.h>
int main(void) {
  int r, c;
  char in[30][30];
  int ans = 0;
  scanf("%d %d", &r, &c);
  for (int i = 0; i < r; i++) {
    scanf("%s", in[i]);
  }
  for (int i = 0; i < r; i++) {
    int flag = 0;
    for (int j = 0; j < c; j++) {
      if (in[i][j] == 'S') flag = 1;
    }
    if (flag == 0) {
      for (int j = 0; j < c; j++) {
        if (in[i][j] == '.') {
          ans++;
          in[i][j] = 'x';
        }
      }
    }
  }
  for (int j = 0; j < c; j++) {
    int flag = 0;
    for (int i = 0; i < r; i++) {
      if (in[i][j] == 'S') flag = 1;
    }
    if (flag == 0) {
      for (int i = 0; i < r; i++) {
        if (in[i][j] == '.') {
          ans++;
          in[i][j] = 'x';
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
