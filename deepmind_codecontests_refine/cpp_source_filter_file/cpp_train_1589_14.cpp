#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int read() {
  char c;
  int num, f = 1;
  while (c = (char)getchar(), !isdigit(c))
    if (c == '-') f = -1;
  num = (int)(c - '0');
  while (c = (char)getchar(), isdigit(c)) num = num * 10 + (int)(c - '0');
  return num * f;
}
void prt(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) prt(x / 10);
  putchar(x % 10 + '0');
}
int x, y, n;
void work() {
  x = read();
  y = read();
  n = read();
  int xx = n / x;
  int c = 0;
  for (int i = xx; i >= 1; i--) {
    if (i * x + y <= n) {
      c++;
      printf("%d\n", i * x + y);
      break;
    }
  }
  if (c == 0) printf("0\n");
  return;
}
signed main() {
  int T = read();
  for (int Case = 1; Case <= T; Case++) {
    work();
  }
  return 0;
}
