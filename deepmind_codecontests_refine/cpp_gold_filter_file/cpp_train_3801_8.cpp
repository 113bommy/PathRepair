#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &a) {
  static char c;
  static int fh;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  if (c == '-')
    fh = -1, a = 0;
  else
    fh = 1, a = c - '0';
  while ((c = getchar()) <= '9' && c >= '0') a = (a << 3) + (a << 1) + c - '0';
  a = a * fh;
}
template <class T>
void write(T a) {
  if (a == 0)
    putchar('0');
  else {
    if (a < 0) putchar('-'), a = -a;
    static char c[30];
    static int c0;
    c0 = 0;
    while (a) c[++c0] = a % 10 + '0', a /= 10;
    while (c0) putchar(c[c0--]);
  }
}
long long x, a[2000005][2] = {{0}}, _end, i0;
int tot = 0;
int main() {
  read(x);
  _end = (long long)pow((double)x * 6, 1.0 / 3);
  while (_end * _end * _end < x * 2) _end++;
  for (long long i = 1; i <= _end; i++) {
    i0 = 2 * x + (i * i * i - i) / 3;
    if (i0 % (i * i + i) == 0) {
      i0 /= (i * i + i);
      if (i0 < i) break;
      a[++tot][0] = i;
      a[tot][1] = i0;
    }
  }
  write(tot * 2 - (a[tot][0] == a[tot][1]));
  putchar('\n');
  for (int i = 1; i <= tot; i++)
    write(a[i][0]), putchar(' '), write(a[i][1]), putchar('\n');
  for (int i = (a[tot][0] == a[tot][1]) ? tot - 1 : tot; i >= 1; i--)
    write(a[i][1]), putchar(' '), write(a[i][0]), putchar('\n');
  return 0;
}
