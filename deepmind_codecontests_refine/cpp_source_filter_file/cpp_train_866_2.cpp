#include <bits/stdc++.h>
long long gi() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f ^= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? x : -x;
}
int n, ans[101][101][101];
void output(bool o = 0) {
  int xl = 1000, xr = 0, yl = 1000, yr = 0, zl = 1000, zr = 0, L = 1e9, R = 0;
  for (int i = 0; i <= 100; ++i)
    for (int j = 0; j <= 100; ++j)
      for (int k = 0; k <= 100; ++k)
        if (ans[i][j][k]) {
          if (ans[i][j][k] < L) L = ans[i][j][k];
          if (ans[i][j][k] > R) R = ans[i][j][k];
          if (i < xl) xl = i;
          if (i > xr) xr = i;
          if (j < yl) yl = j;
          if (j > yr) yr = j;
          if (k < zl) zl = k;
          if (k > zr) zr = k;
        }
  if (o) {
    assert(n == xr - xl + 1);
    assert(n == yr - yl + 1);
    assert(n == zr - zl + 1);
    assert(n * n * n == R - L + 1);
  }
  for (int i = xl; i <= xr; ++i) {
    for (int j = yl; j <= yr; ++j) {
      for (int k = zl; k <= zr; ++k) printf("%d ", ans[i][j][k] - L + 1);
      puts("");
    }
    puts("");
  }
  fflush(stdout);
}
int main() {
  n = gi();
  if (n == 1) {
    puts("1");
    return 0;
  }
  if (n == 2) {
    puts("1 2\n4 3\n\n5 6\n8 7");
    return 0;
  }
  int hx = 50, hy = 50, hz = 50, h = 100000000, t = 100000000, tx = 50, ty = 50,
      tz = 50;
  ans[hx][hy][hz] = h;
  (assert(!ans[tx][ty][tz + 1]), ans[tx][ty][++tz] = ++t);
  (assert(!ans[tx - 1][ty][tz]), ans[--tx][ty][tz] = ++t);
  (assert(!ans[tx][ty][tz - 1]), ans[tx][ty][--tz] = ++t);
  (assert(!ans[tx][ty + 1][tz]), ans[tx][++ty][tz] = ++t);
  (assert(!ans[tx][ty][tz + 1]), ans[tx][ty][++tz] = ++t);
  (assert(!ans[tx + 1][ty][tz]), ans[++tx][ty][tz] = ++t);
  (assert(!ans[tx][ty][tz - 1]), ans[tx][ty][--tz] = ++t);
  (assert(!ans[tx][ty + 1][tz]), ans[tx][++ty][tz] = ++t);
  (assert(!ans[tx][ty][tz + 1]), ans[tx][ty][++tz] = ++t);
  (assert(!ans[tx - 1][ty][tz]), ans[--tx][ty][tz] = ++t);
  (assert(!ans[tx][ty][tz - 1]), ans[tx][ty][--tz] = ++t);
  for (int s = 2; s < n; ++s)
    if (s & 1) {
      (assert(!ans[hx][hy][hz - 1]), ans[hx][hy][--hz] = --h),
          (assert(!ans[tx][ty][tz - 1]), ans[tx][ty][--tz] = ++t);
      for (int j = 1; j <= s; ++j)
        (assert(!ans[hx - 1][hy][hz]), ans[--hx][hy][hz] = --h);
      for (int j = 1; j * 2 <= s + 1; ++j) {
        for (int k = 1; k < s - 1; ++k)
          (assert(!ans[tx][ty - 1][tz]), ans[tx][--ty][tz] = ++t);
        (assert(!ans[tx + 1][ty][tz]), ans[++tx][ty][tz] = ++t);
        for (int k = 1; k < s - 1; ++k)
          (assert(!ans[tx][ty + 1][tz]), ans[tx][++ty][tz] = ++t);
        if (j * 2 < s + 1)
          (assert(!ans[tx + 1][ty][tz]), ans[++tx][ty][tz] = ++t);
      }
      (assert(!ans[hx][hy - 1][hz]), ans[hx][--hy][hz] = --h);
      for (int j = 1; j * 2 <= s + 1; ++j) {
        for (int k = 1; k <= s; ++k)
          (assert(!ans[hx][hy][hz + 1]), ans[hx][hy][++hz] = --h);
        (assert(!ans[hx + 1][hy][hz]), ans[++hx][hy][hz] = --h);
        for (int k = 1; k <= s; ++k)
          (assert(!ans[hx][hy][hz - 1]), ans[hx][hy][--hz] = --h);
        if (j * 2 < s + 1)
          (assert(!ans[hx + 1][hy][hz]), ans[++hx][hy][hz] = --h);
      }
      if (s + 1 < n) {
        (assert(!ans[tx][ty + 1][tz]), ans[tx][++ty][tz] = ++t);
        for (int j = 1; j * 2 <= s + 1; ++j) {
          for (int k = 1; k <= s; ++k)
            (assert(!ans[tx][ty][tz + 1]), ans[tx][ty][++tz] = ++t);
          (assert(!ans[tx - 1][ty][tz]), ans[--tx][ty][tz] = ++t);
          for (int k = 1; k <= s; ++k)
            (assert(!ans[tx][ty][tz - 1]), ans[tx][ty][--tz] = ++t);
          if (j * 2 < s + 1)
            (assert(!ans[tx - 1][ty][tz]), ans[--tx][ty][tz] = ++t);
        }
      }
    } else {
      (assert(!ans[hx][hy][hz - 1]), ans[hx][hy][--hz] = --h),
          (assert(!ans[tx][ty][tz - 1]), ans[tx][ty][--tz] = ++t);
      for (int j = 1; j <= s; ++j)
        (assert(!ans[hx][hy + 1][hz]), ans[hx][++hy][hz] = --h);
      for (int j = 1; j < s - 1; ++j)
        (assert(!ans[tx + 1][ty][tz]), ans[++tx][ty][tz] = ++t);
      for (int j = 1; j <= s; ++j)
        (assert(!ans[tx][ty - 1][tz]), ans[tx][--ty][tz] = ++t);
      for (int j = 1; j * 2 < s; ++j) {
        (assert(!ans[tx - 1][ty][tz]), ans[--tx][ty][tz] = ++t);
        for (int k = 1; k < s; ++k)
          (assert(!ans[tx][ty + 1][tz]), ans[tx][++ty][tz] = ++t);
        (assert(!ans[tx - 1][ty][tz]), ans[--tx][ty][tz] = ++t);
        for (int k = 1; k < s; ++k)
          (assert(!ans[tx][ty - 1][tz]), ans[tx][--ty][tz] = ++t);
      }
      (assert(!ans[hx + 1][hy][hz]), ans[++hx][hy][hz] = --h);
      for (int k = 1; k <= s; ++k)
        (assert(!ans[hx][hy][hz + 1]), ans[hx][hy][++hz] = --h);
      for (int k = 1; k <= s; ++k)
        (assert(!ans[hx][hy - 1][hz]), ans[hx][--hy][hz] = --h);
      for (int j = 1; j * 2 <= s; ++j) {
        (assert(!ans[hx][hy][hz - 1]), ans[hx][hy][--hz] = --h);
        for (int k = 1; k < s; ++k)
          (assert(!ans[hx][hy + 1][hz]), ans[hx][++hy][hz] = --h);
        (assert(!ans[hx][hy][hz - 1]), ans[hx][hy][--hz] = --h);
        for (int k = 1; k < s; ++k)
          (assert(!ans[hx][hy - 1][hz]), ans[hx][--hy][hz] = --h);
      }
      if (s + 1 < n) {
        (assert(!ans[tx - 1][ty][tz]), ans[--tx][ty][tz] = ++t);
        for (int k = 1; k <= s; ++k)
          (assert(!ans[tx][ty][tz + 1]), ans[tx][ty][++tz] = ++t);
        for (int k = 1; k <= s; ++k)
          (assert(!ans[tx][ty + 1][tz]), ans[tx][++ty][tz] = ++t);
        for (int j = 1; j * 2 <= s; ++j) {
          (assert(!ans[tx][ty][tz - 1]), ans[tx][ty][--tz] = ++t);
          for (int k = 1; k < s; ++k)
            (assert(!ans[tx][ty - 1][tz]), ans[tx][--ty][tz] = ++t);
          (assert(!ans[tx][ty][tz - 1]), ans[tx][ty][--tz] = ++t);
          for (int k = 1; k < s; ++k)
            (assert(!ans[tx][ty + 1][tz]), ans[tx][++ty][tz] = ++t);
        }
      }
    }
  output(1);
  return 0;
}
