#include <bits/stdc++.h>
using namespace std;
const long long P = 10000000000;
struct rec {
  long double x;
  long long v;
};
int T, lx, ly, rx, ry;
long long mul(long long x, long long y) {
  return (x * (y % 100000) + x * (y / 100000) % P * 100000 % P) % P;
}
rec operator-(rec a, rec b) {
  rec c;
  c.x = a.x - b.x;
  c.v = (a.v - b.v + P) % P;
  return c;
}
rec operator+(rec a, rec b) {
  rec c;
  c.x = a.x + b.x;
  c.v = (a.v + b.v) % P;
  return c;
}
rec operator*(rec a, int b) {
  a.x *= b;
  a.v = mul(a.v, (long long)b);
  return a;
}
rec sum(long long a) {
  long long b = a + 1;
  if (a % 2)
    b /= 2;
  else
    a /= 2;
  rec ret;
  ret.x = (double)a * b;
  ret.v = mul(a % P, b % P);
  return ret;
}
rec sqrsum(int x) {
  long long a = x, b = x + 1, c = 2 * x + 1;
  if (a % 2)
    b /= 2;
  else
    a /= 2;
  if (a % 3 == 0)
    a /= 3;
  else if (b % 3 == 0)
    b /= 3;
  else
    c /= 3;
  rec ret;
  ret.x = (double)a * b * c;
  ret.v = mul(mul(a, b), c);
  return ret;
}
rec calc(int x, int y) {
  rec ret;
  if ((!x) || (!y)) {
    ret.x = ret.v = 0;
    return ret;
  }
  long long a = (x < y) ? x : y, b = a * a;
  ret = sum(b);
  if (x == y) return ret;
  if (x > y)
    ret = ret + (sqrsum(x) - sqrsum(y)) * y - sum(y - 1) * (x - y);
  else
    ret = ret + (sqrsum(y - 1) - sqrsum(x - 1)) * x + sum(x) * (y - x);
  return ret;
}
void print(rec a) {
  if (a.x >= P)
    printf("...%.010I64d\n", a.v);
  else
    printf("%I64d\n", a.v);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
    print(calc(rx, ry) - calc(lx - 1, ry) - calc(rx, ly - 1) +
          calc(lx - 1, ly - 1));
  }
  return 0;
}
