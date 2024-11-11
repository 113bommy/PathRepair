#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T& num) {
  char CH;
  bool F = false;
  for (CH = getchar(); CH < '0' || CH > '9'; F = CH == '-', CH = getchar())
    ;
  for (num = 0; CH >= '0' && CH <= '9';
       num = num * 10 + CH - '0', CH = getchar())
    ;
  F && (num = -num);
}
int stk[70], tp;
template <class T>
inline void print(T p) {
  if (!p) {
    puts("0");
    return;
  }
  while (p) stk[++tp] = p % 10, p /= 10;
  while (tp) putchar(stk[tp--] + '0');
  putchar('\n');
}
const long long mod = 1e9 + 7;
const double PI = acos(-1.0);
const long long inf = 1e18;
const int N = (1 << 20) + 10;
const int maxn = 1e6 + 10;
const double eps = 1e-12;
long long ax, ay, bx, by, cx, cy;
int solve(long long x, long long y) {
  x = bx - x;
  y = by - y;
  if (cx == 0 && cy == 0) {
    if (x == 0 && y == 0) return 1;
    return 0;
  } else if (cx == 0) {
    long long g = x / cy, h = y / cy;
    if (g * cy == x && h * cy == y) return 1;
    return 0;
  } else if (cy == 0) {
    long long g = x / cx, h = y / cx;
    if (g * cx == x && h * cx == y) return 1;
    return 0;
  } else {
    long long tx = x * cy, ty = y * cx;
    long long b = (tx - ty) / (cy * cy + cx * cx);
    if (b * (cx * cx + cy * cy) != (tx - ty))
      return 0;
    else {
      long long a = (x - b * cy) / cx;
      if (a * cx + b * cy == x) return 1;
      return 0;
    }
  }
}
int main() {
  read(ax);
  read(ay);
  read(bx);
  read(by);
  read(cx);
  read(cy);
  int f = 0;
  if (solve(ax, ay)) f = 1;
  if (solve(-ax, -ay)) f = 1;
  if (solve(ay, -ax)) f = 1;
  if (solve(-ay, ax)) f = 1;
  if (f)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
