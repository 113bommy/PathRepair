#include <bits/stdc++.h>
using namespace std;
long long inline read() {
  long long x = 0, f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') f ^= (ch == '-'), ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
bool check(long long x, long long y) {
  if (x < y) swap(x, y);
  if (!y) return false;
  long long z = x / y;
  bool w = check(y, x % y);
  if (!w) return true;
  if (y & 1) return (z & 1) ^ 1;
  return z % (y + 1) & 1 ^ 1;
}
signed main() {
  long long t = read();
  while (t--) {
    long long n = read(), m = read();
    puts(check(n, m) ? "First" : "Second");
  }
}
