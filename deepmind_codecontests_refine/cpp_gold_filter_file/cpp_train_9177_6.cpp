#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  char ch = getchar();
  int pd = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') pd = -pd;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= pd;
}
inline void write(const int &x) {
  char ggg[10001];
  int s = 0;
  int tmp = x;
  if (tmp == 0) {
    putchar('0');
    return;
  }
  if (tmp < 0) {
    tmp = -tmp;
    putchar('-');
  }
  while (tmp > 0) {
    ggg[s++] = tmp % 10 + '0';
    tmp /= 10;
  }
  while (s > 0) {
    putchar(ggg[--s]);
  }
}
int n, a[100010];
int main() {
  read(n);
  for (register int i = 1; i <= n; ++i) read(a[i]);
  for (register int i = 1; i <= n; ++i) {
    if (a[i] >= 0) {
      a[i] = -a[i] - 1;
    }
  }
  if (n & 1) {
    int mx = -1e9;
    int now;
    for (register int i = 1; i <= n; ++i) {
      if (abs(a[i]) > mx) {
        mx = abs(a[i]);
        now = i;
      }
    }
    a[now] = -a[now] - 1;
  }
  for (register int i = 1; i <= n; ++i) {
    write(a[i]);
    putchar(' ');
  }
  return 0;
}
