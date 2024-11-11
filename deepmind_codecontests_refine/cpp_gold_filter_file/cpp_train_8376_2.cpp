#include <bits/stdc++.h>
using namespace std;
int b[305];
int a[305][500];
int x;
int main() {
  int n;
  scanf("%d", &n);
  memset(a, 0, sizeof(0));
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
  }
  int x = b[1];
  int d, p;
  d = x / 9;
  p = x % 9;
  if (p) {
    a[1][0] = d + 1;
    a[1][1] = p;
    for (int i = 1; i < a[1][0]; i++) a[1][i] = 9;
    a[1][a[1][0]] = p;
  } else {
    a[1][0] = d;
    for (int i = 1; i <= a[1][0]; i++) a[1][i] = 9;
  }
  for (int i = 2; i <= n; i++) {
    if (b[i] > b[i - 1]) {
      for (int j = 0; j <= a[i - 1][0]; j++) a[i][j] = a[i - 1][j];
      int t = 0;
      x = b[i] - b[i - 1];
      for (int j = 1; j <= a[i - 1][0]; j++) {
        if (a[i][j] < 9) {
          if (x >= 9 - a[i][j])
            x -= (9 - a[i][j]), a[i][j] = 9;
          else {
            a[i][j] = a[i][j] + x;
            x = 0;
            break;
          }
        }
      }
      if (x) {
        for (int j = a[i - 1][0] + 1;; j++) {
          t++;
          if (x >= 9)
            a[i][j] = 9, x -= 9;
          else {
            a[i][j] = x;
            x = 0;
            break;
          }
        }
      }
      a[i][0] = a[i - 1][0] + t;
    } else if (b[i] == b[i - 1]) {
      for (int j = 0; j <= a[i - 1][0]; j++) a[i][j] = a[i - 1][j];
      bool flag = false;
      int sum = a[i][1];
      for (int j = 2; j <= a[i][0] + 1; j++) {
        if (a[i][j] < 9 && sum > 0) {
          a[i][j]++;
          sum--;
          for (int k = 1; k < j; k++) a[i][k] = 0;
          for (int k = 1; k < j; k++) {
            if (sum >= 9)
              a[i][k] = 9, sum -= 9;
            else
              a[i][k] = sum, sum = 0;
          }
          if (j > a[i][0]) a[i][0]++;
          break;
        }
        sum += a[i][j];
      }
    } else {
      x = b[i - 1] - b[i] + 1;
      for (int j = 0; j <= a[i - 1][0]; j++) a[i][j] = a[i - 1][j];
      for (int j = 1; j <= a[i][0]; j++) {
        if (a[i][j] >= x) {
          a[i][j] -= x;
          x = 0;
          for (j += 1;; j++) {
            if (a[i][j] < 9) {
              a[i][j]++;
              int sum = 0;
              for (int k = 1; k < j; k++) {
                sum += a[i][k];
              }
              for (int k = 1; k < j; k++) {
                if (sum >= 9)
                  a[i][k] = 9, sum -= 9;
                else
                  a[i][k] = sum, sum = 0;
              }
              if (j > a[i][0]) a[i][0]++;
              break;
            }
          }
          break;
        } else {
          x -= a[i][j];
          a[i][j] = 0;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = a[i][0]; j >= 1; j--) printf("%d", a[i][j]);
    printf("\n");
  }
}
