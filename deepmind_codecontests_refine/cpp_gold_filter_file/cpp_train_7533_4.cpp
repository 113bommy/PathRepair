#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c, nn, mm;
char s[111][111];
int main() {
  scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);
  if ((n & 1) && (m & 1)) {
    puts("IMPOSSIBLE");
    return 0;
  }
  nn = n, mm = m;
  if (n & 1) {
    nn--;
    if (a < m / 2) {
      puts("IMPOSSIBLE");
      return 0;
    }
    a -= m / 2;
    if (a & 1) a--;
    if (b & 1) b--;
    if (a * 2 + b * 2 + c * 4 < (n - 1) * m) {
      puts("IMPOSSIBLE");
      return 0;
    }
    for (int j = 0; j < m; j++) {
      if (j % 4 < 2)
        s[n - 1][j] = 'y';
      else
        s[n - 1][j] = 'z';
    }
  } else if (m & 1) {
    mm--;
    if (b < n / 2) {
      puts("IMPOSSIBLE");
      return 0;
    }
    b -= n / 2;
    if (a & 1) a--;
    if (b & 1) b--;
    if (a * 2 + b * 2 + c * 4 < n * (m - 1)) {
      puts("IMPOSSIBLE");
      return 0;
    }
    for (int i = 0; i < n; i++) {
      if (i % 4 < 2)
        s[i][m - 1] = 'y';
      else
        s[i][m - 1] = 'z';
    }
  } else {
    if (a & 1) a--;
    if (b & 1) b--;
    if (a * 2 + b * 2 + c * 4 < n * m) {
      puts("IMPOSSIBLE");
      return 0;
    }
  }
  for (int i = 0; i < nn; i += 2) {
    for (int j = 0; j < mm; j += 2) {
      int x = i / 2, y = j / 2, color;
      if (x % 2 == 0 && y % 2 == 0)
        color = 0;
      else if (x % 2 == 0)
        color = 1;
      else if (y % 2 == 0)
        color = 2;
      else
        color = 3;
      if (c) {
        s[i][j] = s[i + 1][j] = s[i][j + 1] = s[i + 1][j + 1] = 'a' + color;
        c--;
      } else if (a) {
        s[i][j] = s[i][j + 1] = 'a' + 4 + color * 2;
        s[i + 1][j] = s[i + 1][j + 1] = s[i][j] + 1;
        a -= 2;
      } else if (b) {
        s[i][j] = s[i + 1][j] = 'a' + 12 + color * 2;
        s[i][j + 1] = s[i + 1][j + 1] = s[i][j] + 1;
        b -= 2;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) printf("%c", s[i][j]);
    puts("");
  }
  return 0;
}
