#include <bits/stdc++.h>
using namespace std;
long long n, m, k, x, y, Time, Max, Min, Sergei;
inline int gcd(int x, int y) {
  if (!y) return x;
  return gcd(y, x % y);
}
inline void read(long long &x) {
  char ch;
  int N = 1;
  while ((ch = getchar()) && (!((ch >= '0') && (ch <= '9'))) && (!(ch == '-')))
    ;
  if ((ch == '-')) {
    N = -1;
    while ((ch = getchar()) && (!((ch >= '0') && (ch <= '9'))))
      ;
  }
  x = ch - 48;
  while ((ch = getchar()) && (((ch >= '0') && (ch <= '9'))))
    x = x * 10 + ch - 48;
  x *= N;
}
int main() {
  read(n);
  read(m);
  read(k);
  read(x);
  read(y);
  if ((n == 1) || (n == 2)) {
    Time = k / (n * m);
    k -= Time * n * m;
    Max = Min = Sergei = Time;
    Max += (k > 0), Sergei += ((x - 1) * m + y <= k);
  } else {
    Time = k / (m * (n - 1) << 1);
    k -= (Time * m * (n - 1) << 1);
    Max = Time << 1;
    Min = Time;
    if ((x == 1) || (x == n))
      Sergei = Min;
    else
      Sergei = Max + (((n << 1) - x - 1) * m + y <= k);
    if ((x - 1) * m + y <= k) Sergei++;
    if (!Time) {
      if (k < n * m)
        Max = 1, Min = 0;
      else if (k == n * m)
        Max = Min = 1;
      else
        Max = 2, Min = 1;
    } else
      Max += (k > m) + (k > n * m), Min += (k > 0);
  }
  printf("%lld %lld %lld\n", Max, Min, Sergei);
}
