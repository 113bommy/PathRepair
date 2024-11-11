#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n;
char s[N];
inline int read() {
  int ret = 0, ff = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    ret = ret * 10 + (ch ^ 48);
    ch = getchar();
  }
  return ret * ff;
}
void write(int x) {
  if (x < 0) {
    x = -x, putchar('-');
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + 48);
}
void writeln(int x) { write(x), puts(""); }
void writesp(int x) { write(x), putchar(' '); }
signed main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  writeln(4);
  printf("L %d\n", n - 1);
  printf("R %d\n", 2);
  printf("L %d\n", 2 * n - 2);
  printf("L %d\n", n - 2);
  return 0;
}
