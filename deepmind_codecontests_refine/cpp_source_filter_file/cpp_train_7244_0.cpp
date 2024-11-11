#include <bits/stdc++.h>
using namespace std;
char buffer[2000020], *p1, *p2;
template <class T>
void read(T& x) {
  char ch = ((p1 == p2 &&
              (p2 = (p1 = buffer) + fread(buffer, 1, 2000020, stdin), p1 == p2))
                 ? EOF
                 : *p1++);
  x = 0;
  bool f = 1;
  while (!('0' <= ch && ch <= '9') && ch != '-')
    ch = ((p1 == p2 &&
           (p2 = (p1 = buffer) + fread(buffer, 1, 2000020, stdin), p1 == p2))
              ? EOF
              : *p1++);
  if (ch == '-')
    f = 0,
    ch = ((p1 == p2 &&
           (p2 = (p1 = buffer) + fread(buffer, 1, 2000020, stdin), p1 == p2))
              ? EOF
              : *p1++);
  while ('0' <= ch && ch <= '9')
    x = (x << 1) + (x << 3) + ch - '0',
    ch = ((p1 == p2 &&
           (p2 = (p1 = buffer) + fread(buffer, 1, 2000020, stdin), p1 == p2))
              ? EOF
              : *p1++);
  x = (f) ? x : -x;
}
int _num[20];
template <class T>
void write(T x, char sep = '\n') {
  if (!x) {
    putchar('0'), putchar(sep);
    return;
  }
  if (x < 0) putchar('-'), x = -x;
  int c = 0;
  while (x) _num[++c] = x % 10, x /= 10;
  while (c) putchar('0' + _num[c--]);
  putchar(sep);
}
int a[320];
int main() {
  int T, x;
  read(T);
  while (T--) {
    long double r = 0, aver = 0;
    int mx = -200000;
    for (register int i = 1; i <= 250; i++)
      read(a[i]), aver += a[i], mx = max(mx, a[i]);
    aver /= 250.0;
    for (register int i = 1; i <= 250; i++) r += (a[i] - aver) * (a[i] - aver);
    r /= 250.0, r = sqrt(r), r = (mx - aver) / r;
    if (r > 1.9)
      printf("poisson\n");
    else
      printf("uniform\n");
  }
  return 0;
}
