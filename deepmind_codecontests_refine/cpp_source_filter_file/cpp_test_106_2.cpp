#include <bits/stdc++.h>
using namespace std;
inline void wrt(int x, const char endc = 10) {
  static char buf[21], *nw;
  nw = buf;
  if (!x) {
    putchar(48);
    goto end;
  }
  if (x < 0) putchar(45), x = -x;
  while (x) *(nw++) = x % 10 + 48, x /= 10;
  while (nw != buf) putchar(*(--nw));
end:
  putchar(endc);
}
inline int _isdigit(const char x) { return x > 47 and x < 58; }
inline int rd() {
  static int f, x;
  static char c;
  f = x = 0;
  do
    if ((c = getchar()) == 45) f = 1;
  while (!_isdigit(c));
  do x = (x << 1) + (x << 3) + c - 48;
  while (_isdigit(c = getchar()));
  return f ? -x : x;
}
void work() {
  for (int i = 1, iend = rd(); i <= iend; i++) wrt(i, 32);
  puts("");
}
int main() {
  for (int T = 1, Tend = rd(); T <= Tend; T++) work();
}
