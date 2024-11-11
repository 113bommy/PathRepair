#include <bits/stdc++.h>
long f[25][25][15][15], a[5];
long findx(long a, long b, long c, long d, long x) {
  long tot;
  tot = a + b * 2 + c * 3 + d * 4;
  if ((tot < 3) || (tot == 5)) {
    return 1100000;
  }
  if (b > 6) {
    return 1100000;
  }
  if (a > 6) {
    return 1100000;
  }
  if (c > 10) {
    return 1100000;
  }
  if (d > 10) {
    return 1100000;
  }
  if (f[a][b][c][d] <= x) {
    return f[a][b][c][d];
  } else {
    f[a][b][c][d] = x;
    if (a > 0) {
      if (b > 0) {
        findx(a - 1, b - 1, c + 1, d, x + 1);
      }
      if (c > 0) {
        findx(a - 1, b, c - 1, d + 1, x + 1);
      }
    }
    if (a > 1) {
      findx(a - 2, b + 1, c, d, x + 1);
    }
    if (b > 0) {
      if (c > 0) {
        findx(a + 1, b - 1, c - 1, d + 1, x + 1);
      }
      findx(a + 2, b - 1, c, d, x + 1);
    }
    if (b > 1) {
      findx(a + 1, b - 2, c + 1, d, x + 1);
    }
    if (c > 0) {
      if (a > 0) {
        findx(a - 1, b + 2, c - 1, d, x + 1);
      }
      findx(a + 1, b + 1, c - 1, d, x + 1);
    }
    if (c > 1) {
      findx(a, b + 1, c - 2, d + 1, x + 1);
    }
    if (d > 0) {
      if (a > 0) {
        findx(a - 1, b + 1, c + 1, d - 1, x + 1);
      }
      if (b > 0) {
        findx(a, b - 1, c + 2, d - 1, x + 1);
      }
      findx(a + 1, b, c + 1, d - 1, x + 1);
    }
    return x;
  }
}
int main() {
  long i, j, k, l, tot, n, ans;
  scanf("%ld", &n);
  for (i = 0; i < 5; i++) {
    a[i] = 0;
  }
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 7; j++) {
      for (k = 0; k < 15; k++) {
        for (l = 0; l < 15; l++) {
          f[i][j][k][l] = 10000000;
        }
      }
    }
  }
  for (k = 0; k < 15; k++) {
    for (l = 0; l < 15; l++) {
      findx(0, 0, k, l, 0);
    }
  }
  for (i = 0, tot = 0; i < n; i++) {
    scanf("%ld", &j);
    a[j]++;
    tot += j;
  }
  if (tot < 3 || tot == 5) {
    printf("-1\n");
  } else {
    ans = 0;
    j = a[1];
    if (a[1] > a[2]) {
      j = a[2];
    }
    ans += j;
    a[3] += j;
    a[1] -= j;
    a[2] -= j;
    j = a[1] / 3;
    if (j > 1) {
      j--;
    }
    ans += j * 2;
    a[1] -= j * 3;
    a[3] += j;
    j = a[2] / 3;
    if (j > 1) {
      j--;
    }
    ans += j * 2;
    a[2] -= j * 3;
    a[3] += j * 2;
    if (a[3] > 9) {
      a[3] = 9;
    }
    if (a[4] > 9) {
      a[4] = 9;
    }
    ans += f[a[1]][a[2]][a[3]][a[4]];
    printf("%ld\n", ans);
  }
  return 0;
}
