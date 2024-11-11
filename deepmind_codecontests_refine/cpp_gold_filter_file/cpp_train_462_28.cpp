#include <bits/stdc++.h>
using namespace std;
const long long inf = 2147383647;
const double pi = 2 * acos(0.0);
const double eps = 1e-12;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
inline long long gcd(long long a, long long b) {
  a = ((a) < 0 ? -(a) : (a));
  b = ((b) < 0 ? -(b) : (b));
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
int ext_gcd(int a, int b, int& x, int& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  int x1, y1;
  int d = ext_gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
inline long long modInv(int a, int m) {
  int x, y;
  ext_gcd(a, m, x, y);
  if (x < 0) x += m;
  return x;
}
inline long long power(long long a, long long p) {
  long long res = 1, x = a;
  while (p) {
    if (p & 1) res = (res * x);
    x = (x * x);
    p >>= 1;
  }
  return res;
}
inline long long bigmod(long long a, long long p, long long m) {
  long long res = 1, x = a % m;
  while (p) {
    if (p & 1) res = (res * x) % m;
    x = (x * x) % m;
    p >>= 1;
  }
  return res;
}
int main() {
  long long r, x, y, p, q;
  scanf("%I64d %I64d %I64d %I64d %I64d", &r, &x, &y, &p, &q);
  if (x == p && y == q) {
    printf("0\n");
    return 0;
  }
  double d = sqrt(((x - p) * (x - p)) + ((y - q) * (y - q)));
  long long res = d / (2 * r) - eps;
  res++;
  printf("%I64d\n", res);
  return 0;
}
