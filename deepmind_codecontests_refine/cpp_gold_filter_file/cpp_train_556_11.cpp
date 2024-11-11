#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long mod_inv(long long a, long long m) {
  a = a % m;
  return power(a, m - 2, m) % 1000000007;
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
bool mod(double a, double b) { return a / b - floor(a / b); }
long long logb(long long base, long long x) { return (log(x) / log(base)); }
char ToLower(char c) {
  if ((c >= 'A') && (c <= 'Z'))
    return (char)((long long)c - 'A' + 'a');
  else
    return c;
}
long long Vowel(char c) {
  c = ToLower(c);
  return (c == 'a') || (c == 'o') || (c == 'i') || (c == 'y') || (c == 'u') ||
         (c == 'e');
}
bool cmp(pair<long long, long long> &a, pair<long long, long long> &b) {
  if (a.first != b.first) return a.first < b.first;
  return a.second > b.second;
}
long long countSetBits(long long x) {
  if (x == 0)
    return 0;
  else
    return 1 + countSetBits(x & (x - 1));
}
long long fact(long long n);
long long nCr(long long n, long long r) {
  return fact(n) / (fact(r) * fact(n - r));
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; i++) res = res * i;
  return res;
}
long long n;
bool in_range(long long x, long long y) {
  if (x >= 0 && x <= n - 1 && y >= 0 && y <= n - 1) return true;
  return false;
}
signed main() {
  long long g[3][3];
  for (long long i = 0; i < 3; i++) {
    for (long long j = 0; j < 3; j++) {
      cin >> g[i][j];
    }
  }
  g[1][1] = (g[0][2] + g[0][1] + g[2][1] + g[2][0]) / 4;
  for (long long i = 0; i <= 100000; i++) {
    if (g[1][0] + g[1][2] + g[1][1] == g[0][1] + g[0][2] + i) g[0][0] = i;
  }
  for (long long i = 0; i <= 100000; i++) {
    if (g[1][0] + g[1][2] + g[1][1] == g[2][0] + g[2][1] + i) g[2][2] = i;
  }
  for (long long i = 0; i < 3; i++) {
    for (long long j = 0; j < 3; j++) {
      cout << g[i][j] << " ";
    }
    cout << '\n';
  }
}
