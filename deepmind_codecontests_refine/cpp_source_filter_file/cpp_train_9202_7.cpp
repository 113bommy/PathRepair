#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:134217728")
using namespace std;
const int MOD = (int)1e9 + 7;
int n, x, y;
char a[3][1 << 14];
int b[1 << 14];
int dp[1 << 14][7][7][3];
int can[4];
int go(int col, int m1, int m2, int r) {
  if (col == n) return m1 == 0;
  if (r == 3) {
    if (m1 == 7)
      return go(col + 1, m2, b[col + 2], 0);
    else
      return 0;
  }
  int& res = dp[col][m1][m2][r];
  if (res != -1) return res;
  res = 0;
  if (!(m1 & (1 << r)) && !(m2 & (1 << r))) {
    res += go(col, m1 | (1 << r), m2 | (1 << r), r + 1);
    if (res >= MOD) res -= MOD;
  }
  if (r < 2 && !(m1 & (3 << r))) {
    res += go(col, m1 | (3 << r), m2, r + 1);
    if (res >= MOD) res -= MOD;
  }
  if (m1 & (1 << r)) {
    res += go(col, m1, m2, r + 1);
    if (res >= MOD) res -= MOD;
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 3; ++i) scanf("%s", a[i]);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] == 'O') x = i, y = j;
      if (a[i][j] != '.') b[j] |= 1 << i;
    }
  }
  can[0] = y >= 2 && !(b[y - 1] & (1 << x)) && !(b[y - 2] & (1 << x));
  can[1] = x == 2 && !(b[y] & 3);
  can[2] = y < n - 2 && !(b[y + 1] & (1 << x)) && !(b[y + 2] & (1 << x));
  can[3] = x == 0 && !(b[y] & 6);
  int res = 0;
  for (int i = 1; i < 1 << 4; ++i) {
    int bad = 0;
    int cc = 0;
    for (int j = 0; j < 4; ++j) {
      if (i & (1 << j)) {
        bad |= !can[j];
        cc++;
      }
    }
    if (bad) continue;
    if (i & 1) {
      b[y - 1] ^= 1 << x;
      b[y - 2] ^= 1 << x;
    }
    if (i & 2) b[y] ^= 3;
    if (i & 4) {
      b[y + 1] ^= 1 << x;
      b[y + 2] ^= 1 << x;
    }
    if (i & 8) b[y] ^= 6;
    memset(dp, -1, sizeof(dp));
    if (cc & 1) {
      res += go(0, b[0], b[1], 0);
      if (res >= MOD) res -= MOD;
    } else {
      res -= go(0, b[0], b[1], 0);
      if (res < 0) res += MOD;
    }
    if (i & 1) {
      b[y - 1] ^= 1 << x;
      b[y - 2] ^= 1 << x;
    }
    if (i & 2) b[y] ^= 3;
    if (i & 4) {
      b[y + 1] ^= 1 << x;
      b[y + 2] ^= 1 << x;
    }
    if (i & 8) b[y] ^= 6;
  }
  printf("%d\n", res);
  return 0;
}
