#include <bits/stdc++.h>
int up[1000][1000], down[1000][1000], left[1000][1000], right[1000][1000],
    r1[1000 + 1], r2[1000 + 1], n, m, q, i, j, t, x, y, l, r, m1, m2, c, s, ii,
    t1, t2;
bool a[1000][1000];
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      scanf("%d", &x);
      a[i][j] = x;
      if (!a[i][j])
        up[i][j] = i + 1, down[i][j] = i - 1, left[i][j] = j - 1,
        right[i][j] = j + 1;
      else {
        up[i][j] = i && a[i - 1][j] ? up[i - 1][j] : i;
        left[i][j] = j && a[i][j - 1] ? left[i][j - 1] : j;
      }
    }
  for (i = n - 1; ~i; i--)
    for (j = m - 1; ~j; j--)
      if (a[i][j]) {
        down[i][j] = i < n - 1 && a[i + 1][j] ? down[i + 1][j] : i;
        right[i][j] = j < m - 1 && a[i][j + 1] ? right[i][j + 1] : j;
      }
  while (q--) {
    scanf("%d%d%d", &t, &x, &y);
    --x, --y;
    if (t == 1) {
      a[x][y] = !a[x][y];
      if (a[x][y]) {
        up[x][y] = x && a[x - 1][y] ? up[x - 1][y] : x;
        left[x][y] = y && a[x][y - 1] ? left[x][y - 1] : y;
        down[x][y] = x < n - 1 && a[x + 1][y] ? down[x + 1][y] : x;
        right[x][y] = y < m - 1 && a[x][y + 1] ? right[x][y + 1] : y;
      } else
        up[x][y] = x + 1, down[x][y] = x - 1, left[x][y] = y + 1,
        right[x][y] = y - 1;
      for (i = x + 1; i < n && a[i][y]; i++) up[i][y] = up[x][y];
      for (i = x - 1; ~i && a[i][y]; i--) down[i][y] = down[x][y];
      for (j = y + 1; j < m && a[x][j]; j++) left[x][j] = left[x][y];
      for (j = y - 1; ~j && a[x][j]; j--) right[x][j] = right[x][y];
    } else {
      if (!a[x][y])
        puts("0");
      else {
        s = 0;
        m1 = x - up[x][y] + 1;
        m2 = down[x][y] - x + 1;
        t1 = m1, t2 = m2;
        l = left[x][y];
        r = right[x][y];
        for (j = y; j >= l; j--) {
          if (x - up[x][j] + 1 < m1) m1 = x - up[x][j] + 1;
          r1[m1] = j;
          for (ii = m1 + 1; ii < t1; ii++) r1[ii] = j + 1;
          t1 = m1;
          if (down[x][j] - x + 1 < m2) m2 = down[x][j] - x + 1;
          r2[m2] = j;
          for (ii = m2 + 1; ii < t2; ii++) r2[ii] = j + 1;
          t2 = m2;
        }
        for (ii = 1; ii < m1; ii++) r1[ii] = r1[m1];
        for (ii = 1; ii < m2; ii++) r2[ii] = r2[m2];
        m1 = x - up[x][y] + 1;
        m2 = down[x][y] - x + 1;
        t1 = m1, t2 = m2;
        for (j = y; j <= r; j++) {
          if (x - up[x][j] + 1 < m1) m1 = x - up[x][j] + 1;
          if (down[x][j] - x + 1 < m2) m2 = down[x][j] - x + 1;
          for (ii = m1 + 1; ii < t1; ii++) {
            c = ii * (j - r1[ii]);
            if (c > s) s = c;
          }
          t1 = m1;
          for (ii = m2 + 1; ii < t2; ii++) {
            c = ii * (j - r2[ii]);
            if (c > s) s = c;
          }
          t2 = m2;
          c = m1 * (j - r1[m1] + 1);
          if (c > s) s = c;
          c = m2 * (j - r2[m2] + 1);
          if (c > s) s = c;
        }
        for (ii = 1; ii < m1; ii++) {
          c = ii * (y - r1[ii] + 1);
          if (c > s) s = c;
        }
        for (ii = 1; ii < m2; ii++) {
          c = ii * (y - r2[ii] + 1);
          if (c > s) s = c;
        }
        m1 = y - left[x][y] + 1;
        m2 = right[x][y] - y + 1;
        t1 = m1, t2 = m2;
        l = up[x][y];
        r = down[x][y];
        for (i = x; i >= l; i--) {
          if (y - left[i][y] + 1 < m1) m1 = y - left[i][y] + 1;
          r1[m1] = i;
          for (ii = m1 + 1; ii < t1; ii++) r1[ii] = i + 1;
          t1 = m1;
          if (right[i][y] - y + 1 < m2) m2 = right[i][y] - y + 1;
          r2[m2] = i;
          for (ii = m2 + 1; ii < t2; ii++) r2[ii] = i + 1;
          t2 = m2;
        }
        for (ii = 1; ii < m1; ii++) r1[ii] = r1[m1];
        for (ii = 1; ii < m2; ii++) r2[ii] = r2[m2];
        m1 = y - left[x][y] + 1;
        m2 = right[x][y] - y + 1;
        t1 = m1, t2 = m2;
        for (i = x; i <= r; i++) {
          if (y - left[i][y] + 1 < m1) m1 = y - left[i][y] + 1;
          if (right[i][y] - y + 1 < m2) m2 = right[i][y] - y + 1;
          for (ii = m1 + 1; ii < t1; ii++) {
            c = ii * (i - r1[ii]);
            if (c > s) s = c;
          }
          t1 = m1;
          for (ii = m2 + 1; ii < t2; ii++) {
            c = ii * (i - r2[ii]);
            if (c > s) s = c;
          }
          t2 = m2;
          c = m1 * (i - r1[m1] + 1);
          if (c > s) s = c;
          c = m2 * (i - r2[m2] + 1);
          if (c > s) s = c;
        }
        for (ii = 1; ii < m1; ii++) {
          c = ii * (x - r1[ii] + 1);
          if (c > s) s = c;
        }
        for (ii = 1; ii < m2; ii++) {
          c = ii * (x - r2[ii] + 1);
          if (c > s) s = c;
        }
        printf("%d\n", s);
      }
    }
  }
  return 0;
}
