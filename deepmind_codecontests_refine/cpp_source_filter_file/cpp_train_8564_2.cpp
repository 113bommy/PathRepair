#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  if (p1 == p2) {
    p2 = (p1 = buf) + fread(buf, 1, 100000, stdin);
    if (p1 == p2) return EOF;
  }
  return *p1++;
}
inline void read(long long &x) {
  char c = nc(), b = 1;
  for (; !(c >= '0' && c <= '9'); c = nc())
    if (c == '-') b = -1;
  for (x = 0; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = nc())
    ;
  x *= b;
}
long long solve(long long n) {
  if (n & 1) {
    n = (n + 1) / 2;
  } else {
    n = n / 2 + 1;
  }
  long long ans = 0;
  if (n & 1) {
    long long n1 = n / 2;
    ans = 1 + (n1 + 1) % mod * (n1 % mod) % mod + n1;
    ans %= mod;
  } else {
    long long n1 = n / 2;
    ans = (n1 + 1) % mod * (n1 % mod) % mod;
  }
  return ans;
}
int main() {
  long long T;
  scanf("%lld", &T);
  while (T--) {
    long long n;
    scanf("%d", &n);
    long long ans = solve(n);
    printf("%lld\n", ans);
  }
}
