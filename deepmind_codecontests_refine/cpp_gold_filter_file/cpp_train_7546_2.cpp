#include <bits/stdc++.h>
using namespace std;
int n;
long long p = 1000000007;
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long d, x1, y1;
  d = exgcd(b % a, a, x1, y1);
  x = y1 - (b / a) * (x1);
  y = x1;
  return d;
}
long long powmod(long long a, long long k, long long m) {
  long long res = 1;
  while (k) {
    if (k & 1) res = (res * a) % m;
    a = (a * a) % m;
    k >>= 1;
  }
  return res;
}
long long rev(long long a) { return powmod(a, p - 2, p); }
int main() {
  int n;
  cin >> n;
  long long res = 1;
  for (long long i = n; i, i <= 2 * n - 1; i++) {
    long long x = rev(i - n + 1);
    res = (((res * i) % p) * x) % p;
  }
  cout << (res * 2) % p - n;
  return 0;
}
