#include <bits/stdc++.h>
using namespace std;
int n;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (!isdigit(c)) f = (c == 45 ? -f : f), c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return f * x;
}
inline void write(int x) {
  if (x < 0) putchar(45), x = -x;
  if (x < 10) {
    putchar(x | 48);
    return;
  }
  write(x / 10);
  putchar((x % 10) | 48);
}
inline void write3(int a, int b, int c) {
  write(3);
  putchar(32);
  write(a);
  putchar(32);
  write(b);
  putchar(32);
  write(c);
  putchar(10);
}
inline void write4(int a, int b, int c, int d) {
  write(3);
  putchar(32);
  write(a);
  putchar(32);
  write(b);
  putchar(32);
  write(c);
  putchar(32);
  write(d);
  putchar(10);
}
int main() {
  n = read();
  write(n * n / 4);
  putchar(10);
  if (n & 1) {
    for (int i = 3; i <= n; i += 2) {
      write3(1, i - 1, i);
      write3(1, i - 1, i);
      for (int j = 3; j < i; j += 2) {
        write4(i - 1, j - 1, i, j);
        write4(i - 1, j - 1, i, j);
      }
    }
  } else {
    write3(1, 2, 3);
    write3(1, 2, 4);
    write3(1, 3, 4);
    write3(2, 3, 4);
    for (int i = 6; i <= n; i += 2) {
      write3(1, i - 1, i);
      write3(2, i - 1, i);
      write4(1, i, 2, i - 1);
      for (int j = 4; j < i; j += 2) {
        write4(i, j, i - 1, j - 1);
        write4(i, j, i - 1, j - 1);
      }
    }
  }
}
