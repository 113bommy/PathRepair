#include <bits/stdc++.h>
using namespace std;
char buf[1 << 15], *p1 = buf, *p2 = buf;
inline long long read() {
  char ch;
  bool flag = 0;
  long long res;
  while (!isdigit(
      ch = (p1 == p2 &&
                    (p2 = (p1 = buf) + fread(buf, 1, 1 << 15, stdin), p1 == p2)
                ? EOF
                : *p1++)))
    (ch == '-') && (flag = true);
  for (res = ch - '0'; isdigit(
           ch = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 15, stdin),
                             p1 == p2)
                     ? EOF
                     : *p1++));
       res = res * 10ll + ch - '0')
    ;
  (flag) && (res = -res);
  return res;
}
inline void write(long long x) {
  if (x < 0) x = ~x + 1ll, putchar('-');
  if (x > 9) write(x / 10ll);
  putchar(x % 10ll + '0');
}
void solve() {
  int n = read(), w = read(), v = read(), u = read();
  double k = u * 1.0 / v, l = (double)(1 << 29) - 1, r = 0;
  for (register int i = (1); i <= (n); i++) {
    int x = read(), y = read();
    l = min(l, x - y / k);
    r = max(r, x - y / k);
  }
  printf("%.10lf\n", l > 0 ? w * 1.0 / u : r / v + w * 1.0 / u);
}
int main() { solve(); }
