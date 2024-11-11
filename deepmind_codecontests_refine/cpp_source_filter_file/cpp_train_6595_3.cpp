#include <bits/stdc++.h>
long a, i, j, k, n, r, m, x, y, z, o, p;
char c[1000002];
int main() {
  scanf("%ld %ld", &n, &r);
  m = 2000000;
  for (i = 1; i < r; i++) {
    x = r;
    y = i;
    k = 0 + x / y;
    j = k - 1;
    z = x % y;
    while (z) {
      x = y;
      y = z;
      o = x / y;
      k = k + o;
      j = j + o - 1;
      z = x % y;
    }
    if (y == 1 && k == n && j < m) {
      m = j;
      a = i;
    }
  }
  if (m < 2000000) {
    x = r;
    y = a;
    p = n - 1;
    j = 1;
    z = x % y;
    o = x / y;
    for (i = 0; i < o; i++) {
      c[p] = 'T';
      p--;
    }
    while (z) {
      j++;
      x = y;
      y = z;
      o = x / y;
      z = x % y;
      if (j % 2) {
        for (i = 1; i < o; i++) {
          c[p] = 'T';
          p--;
        }
        if (z) {
          c[p] = 'T';
          p--;
        } else {
          c[p] = 'B';
        }
      } else {
        for (i = 1; i < o; i++) {
          c[p] = 'B';
          p--;
        }
        if (z) {
          c[p] = 'B';
          p--;
        } else {
          c[p] = 'T';
        }
      }
      k = k + o;
    }
    printf("%ld\n", m - 1);
    if (c[0] == 'T') {
      printf("%s\n", c);
    } else {
      for (i = 0; i < n; i++) {
        if (c[i] == 'T')
          printf("B");
        else
          printf("T");
      }
      printf("\n");
    }
  } else {
    if (r > 1 || (r == 1 && n > 1)) {
      printf("IMPOSSIBLE\n");
    } else {
      printf("1\nT\n");
    }
  }
}
