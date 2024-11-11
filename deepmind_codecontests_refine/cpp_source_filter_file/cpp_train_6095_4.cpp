#include <bits/stdc++.h>
using namespace std;
template <class T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <class T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
int n, a[55][55], f[5][55][55];
int cnt(int x, int x1, int y1, int x2, int y2) {
  return f[x][x2][y2] - f[x][x1 - 1][y2] - f[x][x2][y1 - 1] +
         f[x][x1 - 1][y1 - 1];
}
int main() {
  scanf("%d\n", &n);
  for (int i = (1); i <= (n); ++i) {
    for (int j = (1); j <= (n); ++j) {
      char c;
      scanf("%c", &c);
      a[i][j] = c - '0';
      for (int x = (0); x <= (4); ++x)
        f[x][i][j] = f[x][i - 1][j] + f[x][i][j - 1] - f[x][i - 1][j - 1];
      ++f[a[i][j]][i][j];
    }
    scanf("\n");
  }
  for (int x1 = (1); x1 <= (n); ++x1) {
    for (int x2 = (x1); x2 <= (n); ++x2) {
      for (int y1 = (1); y1 <= (n); ++y1) {
        for (int y2 = (y1); y2 <= (n); ++y2) {
          bool ok = (cnt(4, x1, y1, x2, y2) == (x2 - x1 + 1) * (y2 - y1 + 1));
          if (x1 > 1) ok &= (cnt(2, x1 - 1, y1, x1 - 1, y2) == y2 - y1 + 1);
          if (x2 < n) ok &= (cnt(2, x2 + 1, y1, x2 + 1, y2) == y2 - y1 + 1);
          if (y1 > 1) ok &= (cnt(2, x1, y1 - 1, x2, y1 - 1) == x2 - x1 + 1);
          if (y2 < n) ok &= (cnt(2, x1, y2 + 1, x2, y2 + 1) == x2 - x1 + 1);
          if (x1 > 1 && y1 > 1) ok &= (a[x1 - 1][y1 - 1] == 1);
          if (x1 > 1 && y2 < n) ok &= (a[x1 - 1][y2 + 1] == 1);
          if (x2 < n && y1 > 1) ok &= (a[x2 + 1][y1 - 1] == 1);
          if (x2 < n && y2 < n) ok &= (a[x2 + 1][y2 + 1] == 1);
          int u1 = max(1, x1 - 1), u2 = min(n, x2 + 1), v1 = min(1, y1 - 1),
              v2 = max(n, y2 + 1);
          ok &= (cnt(0, 1, 1, n, n) - cnt(0, u1, v1, u2, v2) ==
                 n * n - (u2 - u1 + 1) * (v2 - v1 + 1));
          if (ok) {
            puts("YES");
            return 0;
          }
        }
      }
    }
  }
  puts("NO");
  return 0;
}
