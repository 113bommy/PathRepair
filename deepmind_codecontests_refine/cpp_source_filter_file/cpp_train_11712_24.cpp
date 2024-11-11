#include <bits/stdc++.h>
using namespace std;
int n, m;
char maze[1111][1111];
int X[1111], Y[1111];
long long func1(int x, int y) { return X[x] * m + Y[y] * n; }
long long func(int x, int y) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      X[i] += abs(i - j);
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      Y[i] += abs(i - j);
    }
  }
  long long ret = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ret += func1(i, j);
    }
  }
  return ret;
}
int x[1111], y[1111];
int row[1111], col[1111];
long long func3(int n, int m, int col[]) {
  long long ret = 0;
  for (int i = 0; i < n; i++)
    if (col[i] != -1) {
      bool g1 = true, g2 = true;
      ret += col[i] * (m - col[i] - 1);
      for (int j = i + 1; j < n && col[j] != -1; j++) {
        if (col[j] < col[j - 1]) g1 = false;
        if (col[j] > col[j - 1]) g2 = false;
        if (g1) ret += col[i] * (m - col[j] - 1);
        if (g2) ret += (m - col[i] - 1) * col[j];
      }
    }
  return ret;
}
int main() {
  int k = 0;
  scanf("%d%d", &n, &m);
  long long ret = func(n, m);
  int tot = n * m;
  memset(col, -1, sizeof(col));
  memset(row, -1, sizeof(row));
  for (int i = 0; i < n; i++) {
    scanf("%s", maze[i]);
    for (int j = 0; j < m; j++) {
      if (maze[i][j] == 'X') {
        row[i] = j, col[j] = i;
        x[k] = i, y[k] = j;
        k++;
        tot--;
        ret -= func1(i, j) * 2;
      }
    }
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      ret += abs(x[i] - x[j]) + abs(y[i] - y[j]);
    }
  }
  ret += func3(n, m, col) * 4;
  ret += func3(m, n, row) * 4;
  printf("%.12lf\n", ret * 1.0 / tot / tot);
  return 0;
}
