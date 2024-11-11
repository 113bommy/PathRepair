#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int x, y;
  char s[4];
  scanf("%d%d%s", &x, &y, s);
  int d;
  int row[2][100010], line[2][100010];
  if (s[0] == 'D' && s[1] == 'R') d = 0;
  if (s[0] == 'D' && s[1] == 'L') d = 1;
  if (s[0] == 'U' && s[1] == 'R') d = 2;
  if (s[0] == 'U' && s[1] == 'L') d = 3;
  int need = 0;
  memset(row, 0, sizeof(row));
  memset(line, 0, sizeof(line));
  for (int i = 1; i <= m; i++) {
    if ((i + 1) % 2 == (x + y) % 2) need++;
    if ((i + n) % 2 == (x + y) % 2) need++;
  }
  for (int i = 1; i <= n; i++) {
    if ((i + 1) % 2 == (x + y) % 2) need++;
    if ((i + m) % 2 == (x + y) % 2) need++;
  }
  if ((1 + 1) % 2 == (x + y) % 2) need--;
  if ((1 + m) % 2 == (x + y) % 2) need--;
  if ((n + 1) % 2 == (x + y) % 2) need--;
  if ((n + m) % 2 == (x + y) % 2) need--;
  int now = 0;
  long long ans = 1;
  if (x == 1 || x == n || y == 1 || y == m) {
    now += 1;
    if (d == 0) {
      if (x == n) {
        if (y == m)
          d = 3;
        else
          d = 2;
      } else if (y == m)
        d = 1;
    }
    if (d == 1) {
      if (x == n) {
        if (y == 1)
          d = 2;
        else
          d = 3;
      } else if (y == 1)
        d = 0;
    }
    if (d == 2) {
      if (x == 1) {
        if (y == m)
          d = 1;
        else
          d = 0;
      } else if (y == m)
        d = 3;
    }
    if (d == 3) {
      if (x == 1) {
        if (y == 1)
          d = 0;
        else
          d = 1;
      } else if (y == 1)
        d = 2;
    }
  }
  if (x == 1) row[0][y] = 1;
  if (x == n) row[1][y] = 1;
  if (y == 1) line[0][x] = 1;
  if (y == m) line[1][x] = 1;
  bool flag = true;
  while (now < need) {
    int dn;
    if (d == 0) dn = ((n - x) < (m - y) ? (n - x) : (m - y));
    if (d == 1) dn = ((n - x) < (y - 1) ? (n - x) : (y - 1));
    if (d == 2) dn = ((x - 1) < (m - y) ? (x - 1) : (m - y));
    if (d == 3) dn = ((x - 1) < (y - 1) ? (x - 1) : (y - 1));
    ans += dn;
    int nx = x + dn * dx[d];
    int ny = y + dn * dy[d];
    int nd;
    if (d == 0) {
      if (nx == n) {
        if (row[1][ny] == 0) now++;
        row[1][ny]++;
        if (row[1][ny] > 2) flag = false;
        if (ny == m)
          nd = 3;
        else
          nd = 2;
      } else if (ny == m) {
        if (line[1][nx] == 0) now++;
        line[1][nx]++;
        if (line[1][nx] > 2) flag = false;
        nd = 1;
      }
    }
    if (d == 1) {
      if (nx == n) {
        if (row[1][ny] == 0) now++;
        row[1][ny]++;
        if (row[1][ny] > 2) flag = false;
        if (ny == 1)
          nd = 2;
        else
          nd = 3;
      } else if (ny == 1) {
        if (line[0][nx] == 0) now++;
        line[0][nx]++;
        if (line[0][nx] > 2) flag = false;
        nd = 0;
      }
    }
    if (d == 2) {
      if (nx == 1) {
        if (row[0][ny] == 0) now++;
        row[0][ny]++;
        if (row[0][ny] > 2) flag = false;
        if (ny == m)
          nd = 1;
        else
          nd = 0;
      } else if (ny == m) {
        if (line[1][nx] == 0) now++;
        line[1][nx]++;
        if (line[1][nx] > 2) flag = false;
        nd = 3;
      }
    }
    if (d == 3) {
      if (nx == 1) {
        if (row[0][ny] == 0) now++;
        row[0][ny]++;
        if (row[0][ny] > 2) flag = false;
        if (ny == 1)
          nd = 0;
        else
          nd = 1;
      } else if (ny == 1) {
        if (line[0][nx] == 0) now++;
        line[0][nx]++;
        if (line[0][nx] > 2) flag = false;
        nd = 2;
      }
    }
    x = nx;
    y = ny;
    d = nd;
    if (!flag) break;
  }
  if (!flag) ans = -1;
  printf("%I64d\n", ans);
  return 0;
}
