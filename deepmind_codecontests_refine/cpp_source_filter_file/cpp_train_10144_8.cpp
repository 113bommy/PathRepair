#include <bits/stdc++.h>
using namespace std;
int n, m, T;
int tp, tu, td;
int a[303][303];
int sh1[303][303], sh2[303][303];
int sv1[303][303], sv2[303][303];
inline int get(int a, int b) { return a == b ? tp : (a < b ? tu : td); }
inline int getH(int r, int c1, int c2, int d) {
  if (c1 > c2) swap(c1, c2);
  if (d > 0) return sh1[r][c2] - sh1[r][c1];
  return sh2[r][c1] - sh2[r][c2];
}
inline int getV(int c, int r1, int r2, int d) {
  if (r1 > r2) swap(r1, r2);
  if (d > 0) return sv1[r2][c] - sv1[r1][c];
  return sv2[r1][c] - sv2[r2][c];
}
void calHV() {
  memset(sh1, 0, sizeof(sh1));
  memset(sh2, 0, sizeof(sh2));
  memset(sv1, 0, sizeof(sv1));
  memset(sv2, 0, sizeof(sv2));
  for (int i = (1), _b = (n); i <= _b; i++) {
    sh1[i][1] = 0;
    for (int j = (2), _b = (m); j <= _b; j++) {
      sh1[i][j] = sh1[i][j - 1] + get(a[i][j - 1], a[i][j]);
    }
    sh2[i][m] = 0;
    for (int j = (m - 1), _b = (1); j >= _b; j--)
      sh2[i][j] = sh2[i][j + 1] + get(a[i][j + 1], a[i][j]);
  }
  for (int j = (1), _b = (m); j <= _b; j++) {
    sv1[1][j] = 0;
    for (int i = (2), _b = (n); i <= _b; i++) {
      sv1[i][j] = sv1[i - 1][j] + get(a[i - 1][j], a[i][j]);
    }
    sv2[n][j] = 0;
    for (int i = (n - 1), _b = (1); i >= _b; i--) {
      sv2[i][j] = sv2[i + 1][j] + get(a[i + 1][j], a[i][j]);
    }
  }
}
int bestValue = 1000111222;
int bx1, by1, bx2, by2;
int get(int x1, int y1, int x2, int y2) {
  return getH(x1, y1, y2, 1) + getH(x2, y1, y2, -1) + getV(y2, x1, x2, 1) +
         getV(y1, x1, x2, -1);
}
struct Item {
  int col, value;
  bool operator==(const Item &item) const {
    return value == item.value && col == item.col;
  }
  bool operator<(const Item &item) const {
    return value == item.value ? col < item.col : value < item.value;
  }
  bool operator>(const Item &item) const {
    return value == item.value ? col > item.col : value > item.value;
  }
} staticCols[303];
void solve() {
  set<Item>::iterator it;
  for (int r1 = (1), _b = (n); r1 <= _b; r1++) {
    for (int r2 = (r1 + 2), _b = (n); r2 <= _b; r2++) {
      set<Item> cols;
      for (int j = (2), _b = (m); j <= _b; j++) {
        staticCols[j].col = j;
        staticCols[j].value = get(r1, 1, r2, j);
        cols.insert(staticCols[j]);
      }
      int value;
      Item item;
      for (int j = (1), _b = (m - 2); j <= _b; j++) {
        int x1 = getH(r1, 1, j, 1);
        int x2 = getH(r2, 1, j, -1);
        int y1 = getV(1, r1, r2, -1);
        int y2 = getV(j, r1, r2, 1);
        cols.erase(staticCols[j + 1]);
        item.col = -1000;
        item.value = T + x1 + x2 + y1 - y2;
        it = cols.lower_bound(item);
        if (it != cols.end()) {
          value = get(r1, j, r2, it->col);
          if (abs(value - T) < bestValue) {
            bestValue = abs(value - T);
            bx1 = r1;
            bx2 = r2;
            by1 = j;
            by2 = it->col;
          }
        }
        it = cols.upper_bound(item);
        if (it != cols.begin()) it--;
        value = get(r1, j, r2, it->col);
        if (abs(value - T) < bestValue) {
          bestValue = abs(value - T);
          bx1 = r1;
          bx2 = r2;
          by1 = j;
          by2 = it->col;
        }
      }
    }
  }
}
int main() {
  scanf("%d %d %d", &n, &m, &T);
  scanf("%d %d %d", &tp, &tu, &td);
  for (int i = (1), _b = (n); i <= _b; i++)
    for (int j = (1), _b = (m); j <= _b; j++) {
      scanf("%d", &a[i][j]);
    }
  calHV();
  solve();
  printf("%d %d %d %d\n", bx1, by1, bx2, by2);
  return 0;
}
