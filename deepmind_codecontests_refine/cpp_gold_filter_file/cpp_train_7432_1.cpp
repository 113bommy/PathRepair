#include <bits/stdc++.h>
using namespace std;
int a[210][210], n, m, s[110];
bool dop(int x, int y) { return (x >= 0 && y >= 0 && x < 2 * n && y < 2 * m); }
void dfs(int x, int y, int cur) {
  s[cur]++;
  a[x][y] = cur;
  if (dop(x + 2, y) && a[x + 1][y] != -1 && a[x + 2][y] != cur) {
    dfs(x + 2, y, cur);
  }
  if (dop(x - 2, y) && a[x - 1][y] != -1 && a[x - 2][y] != cur) {
    dfs(x - 2, y, cur);
  }
  if (dop(x, y + 2) && a[x][y + 1] != -1 && a[x][y + 2] != cur) {
    dfs(x, y + 2, cur);
  }
  if (dop(x, y - 2) && a[x][y - 1] != -1 && a[x][y - 2] != cur) {
    dfs(x, y - 2, cur);
  }
}
void qsort(int first, int last) {
  int i = first, j = last, x = s[(i + j) / 2];
  do {
    while (s[i] < x) {
      i++;
    }
    while (s[j] > x) {
      j--;
    }
    if (i <= j) {
      if (i != j) {
        swap(s[i], s[j]);
      }
      i++;
      j--;
    }
  } while (i <= j);
  if (i < last) {
    qsort(i, last);
  }
  if (j > first) {
    qsort(first, j);
  }
}
int main() {
  int x1, x2, y1, y2, t, i, j;
  cin >> n >> m >> t;
  for (i = 0; i < n * 2; i++) {
    for (j = 0; j < m * 2; j++) {
      a[i][j] = 0;
    }
  }
  for (i = 0; i < t; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {
      if (y1 > y2) {
        swap(y1, y2);
      }
      for (j = y1 * 2; j < y2 * 2; j++) {
        a[x1 * 2][j] = -1;
      }
    } else {
      if (x1 > x2) {
        swap(x1, x2);
      }
      for (j = x1 * 2; j < x2 * 2; j++) {
        a[j][y1 * 2] = -1;
      }
    }
  }
  for (i = 0; i < 100; i++) {
    s[i] = 0;
  }
  int curcol = 1;
  for (i = 1; i < 2 * n; i += 2) {
    for (j = 1; j < 2 * m; j += 2) {
      if (a[i][j] == 0) {
        dfs(i, j, curcol);
        curcol++;
      }
    }
  }
  qsort(1, curcol - 1);
  for (i = 1; i < curcol; i++) {
    cout << s[i] << " ";
  }
  return 0;
}
