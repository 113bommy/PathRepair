#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];
int b[1001][1001][4];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((a[i][j - 1] == 1 || b[i][j - 1][0] == 1) && a[i][j] == 0) {
        b[i][j][0] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = m; j >= 0; j--) {
      if ((a[i][j + 1] == 1 || b[i][j + 1][1] == 1) && a[i][j] == 0) {
        b[i][j][1] = 1;
      }
    }
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if ((a[i - 1][j] == 1 || b[i - 1][j][2] == 1) && a[i][j] == 0) {
        b[i][j][2] = 1;
      }
    }
  }
  for (int j = 0; j < m; j++) {
    for (int i = n - 1; i >= 0; i--) {
      if ((a[i + 1][j] == 1 || b[i + 1][j][2] == 1) && a[i][j] == 0) {
        b[i][j][2] = 1;
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 4; k++) {
        if (b[i][j][k] == 1) {
          sum++;
        }
      }
    }
  }
  printf("%d", sum);
  return 0;
}
