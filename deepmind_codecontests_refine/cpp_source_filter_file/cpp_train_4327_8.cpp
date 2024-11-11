#include <bits/stdc++.h>
using namespace std;
const int MODA = 1000003;
inline void print(char pt) { printf("%c\n", pt); }
inline void print(int pt) { printf("%d\n", pt); }
inline void print(long long pt) { printf("%I64d\n", pt); }
inline void print(double pt) { printf("%.20f\n", pt); }
inline void print(char pt[]) { printf("%s\n", pt); }
inline void print() { printf("\n"); }
inline void scan(int &pt) { scanf("%d", &pt); }
inline void scan(char &pt) { scanf("%c", &pt); }
inline void scan(long long &pt) { scanf("%I64d", &pt); }
inline void scan(double &pt) { scanf("%lf", &pt); }
inline void scan(char pt[]) { scanf("%s", pt); }
long long qpow(long long x, long long y) {
  x %= MODA;
  long long res = 1;
  while (y) {
    if (y % 2 == 1) {
      res *= x;
      res %= MODA;
    }
    x = x * x;
    x %= MODA;
    y /= 2;
  }
  return res;
}
long long extend_gcd(long long a, long long b, long long &x, long long &y) {
  if (a == 0 && b == 0) return -1;
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = extend_gcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
long long mod_reverse(long long a, long long MOD) {
  long long x, y;
  long long d = extend_gcd(a, MOD, x, y);
  if (d == 1)
    return (x % MOD + MOD) % MOD;
  else
    return -1;
}
void fail() {
  print("-1");
  exit(0);
}
int x, y;
int n;
char stra[100008];
int a[10];
int main() {
  scan(x);
  scan(y);
  a[0] = y;
  a[1] = y;
  a[2] = y;
  for (int i = 1;; i++) {
    a[0] = a[1] + a[2] - 1;
    sort(a, a + 3);
    if (a[2] >= x) {
      print(i);
      return 0;
    }
  }
  return 0;
}
