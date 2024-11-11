#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 9, N4 = N * 4, p = 1000000007;
void scan(int &x) {
  int ty = 1;
  x = 0;
  char ch = getchar();
  while (!(ch >= '0' && ch <= '9') && ch != '-') ch = getchar();
  if (ch == '-') {
    ty = -1;
    ch = getchar();
  }
  while ((ch >= '0' && ch <= '9')) {
    x *= 10;
    x += (ch - '0');
    ch = getchar();
  }
  x *= ty;
}
char s[20];
void print(int x) {
  int len = 0;
  for (; x; x /= 10) s[len++] = (x % 10) + '0';
  for (int i = len - 1; i >= 0; i--) putchar(s[i]);
}
int main() {
  int n, m, k;
  scan(n);
  scan(m);
  scan(k);
  char a = '0', b = '1';
  if (n < m) {
    swap(n, m);
    swap(a, b);
  }
  if (k % 2 == 0) {
    for (int j = 1; j <= n - k / 2; j++) putchar(a);
    for (int j = 1; j <= m - k / 2 + 1; j++) putchar(b);
    for (int j = 3; j <= k; j++) {
      putchar(a);
      putchar(b);
    }
    putchar(a);
  } else {
    for (int j = 1; j <= n - k / 2; j++) putchar(a);
    for (int j = 1; j <= m - k / 2; j++) putchar(b);
    for (int j = 3; j <= k; j++) {
      putchar(a);
      putchar(b);
    }
  }
  return 0;
}
