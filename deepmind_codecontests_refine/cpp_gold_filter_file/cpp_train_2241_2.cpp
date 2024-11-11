#include <bits/stdc++.h>
char ans[200][200];
int main() {
  int a, b, c, d, n, s[30];
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &n);
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
  printf("YES\n");
  if (b > d) {
    int l = 1, r = 1, dir = 1;
    if (d % 2 == 1) {
      r = a + c;
      dir = -1;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= s[i]; j++) {
        ans[l][r] = 'a' + i - 1;
        if (l <= d) {
          if (r == 1 && dir == -1) {
            l++;
            dir = 1;
          } else if (r == a + c && dir == 1) {
            l++;
            dir = -1;
          } else {
            r += dir;
          }
        } else {
          if (r == 1 && dir == -1) {
            l++;
            dir = 1;
          } else if (r == a && dir == 1) {
            l++;
            dir = -1;
          } else {
            r += dir;
          }
        }
      }
    }
    for (int i = 1; i <= b; i++) {
      for (int j = 1; j <= a + c; j++)
        if (ans[i][j] >= 'a' && ans[i][j] <= 'z')
          printf("%c", ans[i][j]);
        else
          printf(".");
      printf("\n");
    }
  } else {
    int l = 1, r = a + c, dir = -1;
    if (b % 2 == 1) {
      r = 1;
      dir = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= s[i]; j++) {
        ans[l][r] = 'a' + i - 1;
        if (l <= b) {
          if (r == 1 && dir == -1) {
            l++;
            dir = 1;
          } else if (r == a + c && dir == 1) {
            l++;
            dir = -1;
          } else {
            r += dir;
          }
        } else {
          if (r == a + 1 && dir == -1) {
            l++;
            dir = 1;
          } else if (r == a + c && dir == 1) {
            l++;
            dir = -1;
          } else {
            r += dir;
          }
        }
      }
    }
    for (int i = 1; i <= d; i++) {
      for (int j = 1; j <= a + c; j++)
        if (ans[i][j] >= 'a' && ans[i][j] <= 'z')
          printf("%c", ans[i][j]);
        else
          printf(".");
      printf("\n");
    }
  }
}
