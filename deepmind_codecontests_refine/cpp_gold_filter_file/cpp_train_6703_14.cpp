#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005][2];
int dp1[1005][1005][2];
int a[1005][1005][2];
int pre[1005][1005];
int n;
char ss[2005];
void print(int x, int y) {
  int i = 1, j = 1;
  for (i = 1; i < x; i++) printf("R");
  for (j = 1; j <= n - 1; j++) printf("D");
  while (i <= n - 1) {
    printf("R");
    i++;
  }
  printf("\n");
}
void print() {
  int cnt = 0, i;
  int x = n;
  int y = n;
  while (x != 1 || y != 1) {
    if (pre[x][y] == 0) {
      ss[cnt++] = 'R';
      y--;
    } else {
      ss[cnt++] = 'D';
      x--;
    }
  }
  for (i = cnt - 1; i >= 0; i--) printf("%c", ss[i]);
  printf("\n");
}
void print(int x) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) printf("%d ", dp[i][j][x]);
    printf("\n");
  }
  printf("\n");
}
void print3() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) printf("%d ", pre[i][j]);
    printf("\n");
  }
  printf("\n");
}
void prev(int x) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (i == 1 && j == 1) continue;
      if (i == 1) {
        pre[i][j] = 0;
        continue;
      }
      if (j == 1) {
        pre[i][j] = 1;
        continue;
      }
      if (dp[i][j - 1][x] < dp[i - 1][j][x])
        pre[i][j] = 0;
      else
        pre[i][j] = 1;
    }
}
int main() {
  int i, j, x, y, tt, t, sx, sy;
  while (scanf("%d", &n) != EOF) {
    bool flag = false;
    sx = sy = 0;
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        scanf("%d", &tt);
        x = 0;
        y = 0;
        if (tt == 0) {
          flag = true;
          sx = i;
          sy = j;
          continue;
        }
        while (tt % 5 == 0) x++, tt /= 5;
        while (tt % 2 == 0) y++, tt /= 2;
        a[i][j][0] = x;
        a[i][j][1] = y;
      }
    }
    for (t = 0; t < 2; t++)
      for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
          if (i == 1 && j == 1) {
            dp[i][j][t] = a[i][j][t];
            continue;
          }
          if (i == 1) {
            dp[i][j][t] = dp[i][j - 1][t] + a[i][j][t];
            continue;
          }
          if (j == 1) {
            dp[i][j][t] = dp[i - 1][j][t] + a[i][j][t];
            continue;
          }
          dp[i][j][t] = min(dp[i - 1][j][t], dp[i][j - 1][t]) + a[i][j][t];
        }
    if (flag) {
      printf("%d\n", min(1, min(dp[n][n][0], dp[n][n][1])));
      if ((min(dp[n][n][0], dp[n][n][1])) < 1) {
        if (dp[n][n][0] < dp[n][n][1])
          prev(0);
        else
          prev(1);
        print();
      } else {
        print(sy, sx);
      }
    } else {
      printf("%d\n", min(dp[n][n][0], dp[n][n][1]));
      if (dp[n][n][0] < dp[n][n][1])
        prev(0);
      else
        prev(1);
      print();
    }
  }
  return 0;
}
