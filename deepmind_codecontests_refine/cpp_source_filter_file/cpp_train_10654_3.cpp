#include <bits/stdc++.h>
using namespace std;
double a[6][8], x[8], min_;
int h12, h13, h14, h23, h24, h34;
int x1[8];
char ans[4][1000000];
void printans() {
  int d = 0;
  for (int i = 1; i < 8; i++) d += x1[i];
  printf("%d\n", d);
  for (int i = 0; i < d; i++) printf("a");
  printf("\n");
  int i, i0 = 0;
  for (i = i0; i - i0 < x1[1]; i++)
    ans[1][i] = ans[2][i] = 'a', ans[3][i] = 'b';
  i0 = i;
  for (i = i0; i - i0 < x1[2]; i++)
    ans[1][i] = ans[3][i] = 'a', ans[2][i] = 'b';
  i0 = i;
  for (i = i0; i - i0 < x1[3]; i++)
    ans[3][i] = ans[2][i] = 'b', ans[1][i] = 'a';
  i0 = i;
  for (i = i0; i - i0 < x1[4]; i++)
    ans[3][i] = ans[2][i] = 'a', ans[1][i] = 'b';
  i0 = i;
  for (; i - i0 < x1[5]; i++) ans[1][i] = ans[3][i] = 'b', ans[2][i] = 'a';
  i0 = i;
  for (; i - i0 < x1[6]; i++) ans[1][i] = ans[2][i] = 'b', ans[3][i] = 'a';
  i0 = i;
  for (; i - i0 < x1[7]; i++) ans[3][i] = ans[1][i] = ans[2][i] = 'b';
  for (i = 1; i < 4; i++) {
    for (int j = 0; j < d; j++) printf("%c", ans[i][j]);
    printf("\n");
  }
}
double fabs(double x) {
  if (x > 0)
    return x;
  else
    return -x;
}
int main(void) {
  cin >> h12 >> h13 >> h14 >> h23 >> h24 >> h34;
  a[0][3] = a[0][5] = a[0][6] = a[0][4] = 1;
  a[0][7] = h12;
  a[1][1] = a[1][2] = a[1][5] = a[1][6] = 1;
  a[1][7] = h13;
  a[2][0] = a[2][2] = a[2][4] = a[2][6] = 1;
  a[2][7] = h14;
  a[3][1] = a[3][2] = a[3][3] = a[3][4] = 1;
  a[3][7] = h23;
  a[4][0] = a[4][1] = a[4][4] = a[4][5] = 1;
  a[4][7] = h34;
  a[5][0] = a[5][2] = a[5][3] = a[5][5] = 1;
  a[5][7] = h24;
  min_ = 1000000;
  for (int i = 0; i < 6; i++) {
    double t;
    int j = i;
    while (fabs(a[j][i]) < 1E-6 && j < 6) j++;
    for (int k = 0; k < 8; k++) t = a[j][k], a[j][k] = a[i][k], a[i][k] = t;
    j++;
    for (; j < 6; j++) {
      t = a[j][i] / a[i][i];
      for (int k = 0; k < 8; k++) a[j][k] -= a[i][k] * t;
    }
  }
  for (x[7] = 0; x[7] < 100; x[7]++) {
    bool bad = 0;
    for (int i = 5; i >= 0; i--) {
      x[i + 1] = a[i][7];
      for (int j = 6; j > i; j--) x[i + 1] -= a[i][j] * x[j + 1];
      x[i + 1] /= a[i][i];
      if (fabs(x[i + 1] - ((int)x[i + 1])) > 1E-6 || x[i + 1] < 0) bad = 1;
    }
    if (!bad) {
      double s = 0;
      for (int i = 1; i < 8; i++) s += x[i];
      if (s < min_) {
        min_ = s;
        for (int i = 1; i < 8; i++) x1[i] = (int)(x[i] + 0.5);
      }
    }
  }
  if (fabs(min_ - 1000000) < 1E-6)
    cout << -1;
  else
    printans();
}
