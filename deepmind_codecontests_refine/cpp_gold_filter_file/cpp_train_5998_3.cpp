#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
void read(long long &s) {
  s = 0;
  bool pd = false;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') pd = true;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = (s << 3) + (s << 1) + (c ^ 48);
    c = getchar();
  }
  if (pd) s = -s;
  return;
}
long long quickpow(long long x, long long y) {
  long long sum = 1;
  while (y) {
    if (y & 1) sum = (sum * x) % MOD;
    x = (x * x) % MOD;
    y >>= 1;
  }
  return sum;
}
int main() {
  long long n, m, ans1, ans2, ans3;
  read(n), read(m);
  ans1 = quickpow(2, m);
  ans2 = n - m + 1;
  ans3 = quickpow(n + 1, m - 1);
  printf("%lld", ans1 * ans2 % MOD * ans3 % MOD);
  return 0;
}
