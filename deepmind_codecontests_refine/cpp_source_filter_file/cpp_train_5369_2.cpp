#include <bits/stdc++.h>
using namespace std;
char dic[50] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char a[10][10];
char ans[10000][5];
int la;
void U(int y) {
  ans[++la][0] = 'U', ans[la][1] = y + '0';
  char t = a[1][y];
  for (int i = (1); i <= (5); ++i) a[i][y] = a[i + 1][y];
  a[6][y] = t;
}
void D(int y) {
  ans[++la][0] = 'D', ans[la][1] = y + '0';
  char t = a[6][y];
  for (int i = (6); i >= (2); --i) a[i][y] = a[i - 1][y];
  a[1][y] = t;
}
void L(int x) {
  ans[++la][0] = 'L', ans[la][1] = x + '0';
  char t = a[x][1];
  for (int i = (1); i <= (5); ++i) a[x][i] = a[x][i + 1];
  a[x][6] = t;
}
void R(int x) {
  ans[++la][0] = 'R', ans[la][1] = x + '0';
  char t = a[x][6];
  for (int i = (6); i >= (2); --i) a[x][i] = a[x][i - 1];
  a[x][1] = t;
}
void work1(int x, int y) {
  for (int i = 1; i <= (5); ++i) {
    D(y);
    L(x);
    U(y);
    R(x);
    D(y);
  }
}
void work2(int x, int y) {
  for (int i = 1; i <= (5); ++i) {
    R(x);
    D(y);
    L(x);
    U(y);
    R(x);
  }
}
int main() {
  for (int i = 1; i <= (6); ++i) scanf("%s", a[i] + 1);
  for (int i = 1; i <= (6); ++i)
    for (int j = 1; j <= (5); ++j) {
      int x, y;
      for (int p = 1; p <= (6); ++p)
        for (int q = 1; q <= (6); ++q)
          if (a[p][q] == dic[i * 6 + j - 7]) x = p, y = q;
      if (x != i) {
        while (y < 6) {
          R(x);
          ++y;
        }
        while (x > i) {
          U(6);
          --x;
        }
        while (x < i) {
          D(6);
          ++x;
        }
      }
      while (y > j) {
        if (j == 1)
          L(x);
        else
          work1(x, y - 1);
        --y;
      }
    }
  for (int i = 1; i <= (6); ++i) {
    int x(1);
    for (; a[x][6] != dic[i * 6 - 1]; ++x)
      ;
    while (x > i) {
      if (i == 1)
        U(x);
      else
        work2(x - 1, 6);
      --x;
    }
  }
  printf("%d\n", la);
  for (int i = 1; i <= (la); ++i) puts(ans[i]);
  return 0;
}
