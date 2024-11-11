#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  char ch;
  bool flag = false;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') flag = true;
  for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  x = flag ? -x : x;
}
inline void write(int x) {
  static char s[100];
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (!x) {
    putchar('0');
    return;
  }
  int len = 0;
  for (; x; x /= 10) s[len++] = x % 10 + '0';
  for (int i = len - 1; i >= 0; --i) putchar(s[i]);
}
int n;
char ans[1000100];
char s[1000100];
int main() {
  read(n);
  int x, y;
  x = 1, y = 1;
  for (int i = 1; i <= n - 1; i++) {
    if (y + 1 <= n) {
      printf("? %d %d %d %d\n", x, y + 1, n, n);
      fflush(stdout);
      scanf("%s", s);
      if (s[0] == 'Y') {
        ans[i] = 'R';
        y = y + 1;
        continue;
      }
    }
    if (x + 1 <= n) {
      printf("? %d %d %d %d\n", x + 1, y, n, n);
      fflush(stdout);
      scanf("%s", s);
      if (s[0] == 'Y') {
        ans[i] = 'D';
        x = x + 1;
        continue;
      }
    }
  }
  x = n, y = n;
  for (int i = 1; i <= n - 1; i++) {
    if (x - 1 > 0) {
      printf("? %d %d %d %d\n", 1, 1, x - 1, y);
      fflush(stdout);
      scanf("%s", s);
      if (s[0] == 'Y') {
        ans[2 * n - 1 - i] = 'D';
        x = x + 1;
        continue;
      }
    }
    if (y - 1 > 0) {
      printf("? %d %d %d %d\n", 1, 1, x, y - 1);
      fflush(stdout);
      scanf("%s", s);
      if (s[0] == 'Y') {
        ans[2 * n - 1 - i] = 'R';
        y = y + 1;
        continue;
      }
    }
  }
  printf("! ");
  for (int i = 1; i <= 2 * n - 2; i++) printf("%c", ans[i]);
  puts("");
  return 0;
}
