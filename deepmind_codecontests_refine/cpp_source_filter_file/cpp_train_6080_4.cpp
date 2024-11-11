#include <bits/stdc++.h>
using namespace std;
const int N = 30000 + 5;
const int M = 30;
char s[10];
int n, h, i, j, k;
int mn, nm;
int in;
double res, pr[M + 5];
double dx[4][M + 5][M + 5];
double dy[4][M + 5][M + 5];
double su[M + 5];
int main() {
  scanf("%s", s);
  scanf("%d%d", &n, &h);
  pr[0] = 1;
  pr[h + 1] = 1;
  for (i = 1; i <= h; ++i) {
    pr[i] = pr[i - 1] / 2;
    pr[h + 1] = pr[h + 1] - pr[i];
  }
  for (i = 1; i <= h + 1; ++i) {
    su[i] = su[i - 1] + pr[i];
  }
  if (s[0] == 'A') {
    mn = 0;
    for (i = 0; i <= h; ++i) {
      for (j = 0; j <= i; ++j) {
        dx[mn][j][i] = pr[i + 1];
        dy[mn][j][i] = 0;
      }
    }
    for (i = 2; i < n; ++i) {
      nm = mn ^ 1;
      for (j = 0; j <= h; ++j) {
        for (k = 0; k <= j; ++k) {
          dx[nm][j][k] = 0;
          dy[nm][j][k] = 0;
        }
      }
      for (j = 0; j <= h; ++j) {
        for (k = 0; k <= j; ++k) {
          dx[nm][j][j] += pr[j + 1] * dx[mn][k][k];
          dy[nm][j][j] += pr[j + 1] * (dx[mn][k][k] * (1 << k) + dy[mn][k][k]);
        }
        for (k = j + 1; k <= h; ++k) {
          dx[nm][j][k] = pr[j + 1] * dx[mn][j][k];
          dy[nm][j][k] = pr[j + 1] * (dx[mn][j][k] * (1 << j) + dy[mn][j][k]);
        }
      }
      for (j = 0; j <= h; ++j) {
        for (k = h - 1; k >= 0; --k) {
          dx[nm][k][j] += dx[nm][k + 1][j];
          dy[nm][k][j] = dy[nm][k][j] + dy[nm][k + 1][j];
        }
        for (k = h; k > 0; --k) {
          dx[nm][k][j] += su[k] * dx[mn][k][j];
          dy[nm][k][j] += su[k] * dy[mn][k][j];
        }
      }
      mn = nm;
    }
    nm = mn ^ 1;
    for (j = 0; j <= h; ++j) {
      for (k = 0; k <= h; ++k) {
        dx[nm][j][k] = 0;
        dy[nm][j][k] = 0;
      }
    }
    for (j = 0; j <= h; ++j) {
      for (k = 0; k <= j; ++k) {
        dx[nm][j][j] = dx[nm][j][j] + pr[j + 1] * dx[mn][k][k];
        dy[nm][j][j] =
            dy[nm][j][j] + pr[j + 1] * (dx[mn][k][k] * (1 << k) + dy[mn][k][k]);
      }
      for (k = j + 1; k <= h; ++k) {
        dx[nm][j][k] = pr[j + 1] * dx[mn][j][k];
        dy[nm][j][k] = pr[j + 1] * (dx[mn][j][k] * (1 << j) + dy[mn][j][k]);
      }
    }
    res = 1;
    for (j = 0; j <= h; ++j) {
      for (k = 0; k <= j; ++k) {
        res += dy[nm][k][j];
      }
    }
    printf("%.6lf\n", res);
  } else {
    printf("%d\n", n);
  }
  return 0;
}
