#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
inline int read() {
  register int x;
  register char c(getchar());
  register bool k;
  while ((c < '0' || c > '9') && c ^ '-')
    if ((c = getchar()) == EOF) exit(0);
  if (c ^ '-')
    x = c & 15, k = 1;
  else
    x = 0, k = 0;
  while (c = getchar(), c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c & 15);
  return k ? x : -x;
}
void write(register int a) {
  if (a < 0) putchar('-'), a = -a;
  if (a <= 9)
    putchar(a | '0');
  else
    write(a / 10), putchar((a % 10) | '0');
}
void read_s(char *s) {
  char ch = getchar();
  while (ch == '\n') ch = getchar();
  int p = 0;
  while (ch != '\n') {
    s[p++] = ch;
    ch = getchar();
  }
  s[p] = 0;
}
int main() {
  int t = read();
  while (t--) {
    int a = read(), b = read(), x = read();
    if (x == a)
      cout << 1 << '\n';
    else if (x * 2 <= a + b)
      cout << 2 << '\n';
    else {
      int n = (a - x) / (2 * x - a - b);
      double tmp1 =
          fabs(((double)a * (n + 1) + (double)b * n) / (2 * n + 1) - x);
      double tmp2 =
          fabs(((double)a * (n + 2) + (double)b * (n + 1)) / (2 * n + 3) - x);
      if (tmp1 <= tmp2)
        cout << 2 * n + 1 << '\n';
      else
        cout << 2 * n + 3 << '\n';
    }
  }
  return 0;
}
