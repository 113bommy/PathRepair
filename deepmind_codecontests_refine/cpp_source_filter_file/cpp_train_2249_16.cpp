#include <bits/stdc++.h>
using namespace std;
int read() {
  char s;
  int k = 0, base = 1;
  while ((s = getchar()) != '-' && s != EOF && !(s >= '0' && s <= '9'))
    ;
  if (s == EOF) exit(0);
  if (s == '-') base = -1, s = getchar();
  while (s >= '0' && s <= '9') {
    k = k * 10 + (s - '0');
    s = getchar();
  }
  return k * base;
}
void write(int x) {
  if (x < 0) {
    putchar('-');
    write(-x);
  } else {
    if (x / 10) write(x / 10);
    putchar(x % 10 + '0');
  }
}
int n, m;
int ax, ay, ix, iy;
int x, y, d;
int s;
char ch;
int main() {
  n = read();
  m = read();
  ix = 101;
  iy = 101;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      ch = getchar();
      while (ch != 'W' && ch != 'B') ch = getchar();
      if (ch == 'W') continue;
      ax = max(ax, i);
      ay = max(ay, j);
      ix = min(ix, i);
      iy = min(iy, j);
      s++;
    }
  if (s == 0) {
    printf("0");
    return 0;
  }
  x = ax - ix + 1;
  y = ay - iy + 1;
  d = max(x, y);
  if (d > n || d > m) {
    write(-1);
    return 0;
  }
  d = d * d - s;
  printf("%d", d);
  return 0;
}
