#include <bits/stdc++.h>
using namespace std;
int a[510], b[1100];
int c[510][510], cc[510][510];
int lef[510][510], lcnt[510][510];
int rig[510][510], rcnt[510][510];
bool ok(int i, int j, int r) {
  int i1 = i / 2, i2 = i - i1;
  int j1 = j / 2, j2 = j - j1;
  if (i1 * i1 + j1 * j1 <= r * r && i2 * i2 + j2 * j2 <= r * r) return false;
  ;
  if (i1 * i1 + j2 * j2 <= r * r && i2 * i2 + j1 * j1 <= r * r) return false;
  ;
  for (int ii = max(i1 - 5, 0); ii <= min(i1 + 5, i); ++ii)
    for (int jj = max(j1 - 5, 0); jj <= min(j1 + 5, j); ++jj)
      if (ii * ii + jj * jj <= r * r &&
          (i - ii) * (i - ii) + (j - jj) * (j - jj) <= r * r)
        return false;
  return true;
}
int main() {
  int n, m, r;
  scanf("%d %d %d", &n, &m, &r);
  int rr = r * 2;
  for (int i = 0; i <= r; ++i) {
    for (int j = 0; j <= r + 1; ++j)
      if (i * i + j * j > r * r) {
        a[i] = j - 1;
        break;
      }
  }
  for (int i = 0; i <= rr; ++i) {
    for (int j = 0; j <= rr + 1; ++j)
      if (!ok(i, j, r)) {
        b[i] = j;
        break;
      }
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      scanf("%d", &cc[i][j]), cc[i][j] += cc[i][j - 1];
  for (int i = 1 + r; i + r <= n; ++i) {
    for (int j = 1 + r; j + r <= m; ++j) {
      for (int k = i - r; k <= i + r; ++k) {
        int dy = abs(i - k), x1 = j - a[dy], x2 = j + a[dy];
        c[i][j] += cc[k][x2] - cc[k][x1 - 1];
      }
    }
    for (int j = 1 + r; j + r <= m; ++j) {
      lef[i][j] = c[i][j];
      lcnt[i][j] = 1;
      if (lef[i][j] == lef[i][j - 1])
        lcnt[i][j] += lcnt[i][j - 1];
      else if (lef[i][j] < lef[i][j - 1])
        lef[i][j] = lef[i][j - 1], lcnt[i][j] = lcnt[i][j - 1];
    }
    for (int j = m - r; j >= 1 + r; --j) {
      rig[i][j] = c[i][j];
      rcnt[i][j] = 1;
      if (rig[i][j] == rig[i][j + 1])
        rcnt[i][j] += rcnt[i][j + 1];
      else if (rig[i][j] < rig[i][j + 1])
        rig[i][j] = rig[i][j + 1], rcnt[i][j] = rcnt[i][j + 1];
    }
  }
  int res = 0;
  long long cnt = 0;
  for (int i = r + 1; i + r <= n; ++i) {
    for (int j = r + 1; j + r <= m; ++j) {
      int t1 = 0, t2 = 0;
      for (int k = r + 1; k + r <= n; ++k) {
        int dy = abs(i - k), x1 = r + 1, x2 = m - r;
        if (dy <= rr) x1 = j + b[dy], x2 = j - b[dy];
        if (x1 + r <= m) {
          if (t1 == rig[k][x1])
            t2 += rcnt[k][x1];
          else if (t1 < rig[k][x1])
            t1 = rig[k][x1], t2 = rcnt[k][x1];
        }
        if (dy > rr) continue;
        if (x2 > r) {
          if (t1 == lef[k][x2])
            t2 += lcnt[k][x2];
          else if (t1 < lef[k][x2])
            t1 = lef[k][x2], t2 = lcnt[k][x2];
        }
      }
      if (t1 == 0) continue;
      t1 += c[i][j];
      if (res == t1)
        cnt += t2;
      else if (res < t1)
        res = t1, cnt = t2;
    }
  }
  cout << res << " " << cnt / 2 << endl;
  return 0;
}
