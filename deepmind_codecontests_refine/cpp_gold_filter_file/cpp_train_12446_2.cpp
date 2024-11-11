#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 10;
long long rd() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long gcd(long long a, long long b) { return a == 0 ? b : gcd(b % a, a); }
long long a1, b1, a2, b2, l, r;
long long ans = 0;
int main() {
  a1 = rd(), b1 = rd();
  a2 = rd(), b2 = rd();
  l = rd(), r = rd();
  long long k = a1 * a2 / gcd(a1, a2);
  while (b1 + 100000 * a1 < l) b1 += 100000 * a1;
  while (b2 + 100000 * a2 < l) b2 += 100000 * a2;
  while (b1 + 10000 * a1 < l) b1 += 10000 * a1;
  while (b2 + 10000 * a2 < l) b2 += 10000 * a2;
  while (b1 + 100 * a1 < l) b1 += 100 * a1;
  while (b2 + 100 * a2 < l) b2 += 100 * a2;
  while (b1 + a1 < l) b1 += a1;
  while (b2 + a2 < l) b2 += a2;
  if (b1 > b2) {
    swap(b1, b2);
    swap(a1, a2);
  }
  while (b1 + 100000 * a1 < b2) b1 += 100000 * a1;
  while (b1 + 1000 * a1 < b2) b1 += 1000 * a1;
  while (b1 + 10 * a1 < b2) b1 += 10 * a1;
  int t = 0;
  while (1) {
    t++;
    if (t > 156000000 || b1 > r || b2 > r) {
      printf("0\n");
      return 0;
    }
    if (b1 == b2) {
      if (b1 <= r)
        ;
      break;
    }
    if (b1 < b2) b1 += a1;
    if (b2 < b1) b2 += a2;
  }
  if (b1 >= l && b1 <= r) ans++;
  while (b1 + k < l) b1 += k;
  if (b1 + k < l) b1 += k;
  if (k < 1e13) {
    while (b1 + 100000 * k <= r) {
      b1 += 100000 * k;
      ans += 100000;
    }
    while (b1 + 1000 * k <= r) {
      b1 += 1000 * k;
      ans += 1000;
    }
  }
  while (b1 + k <= r) {
    b1 += k;
    ans++;
  }
  printf("%lld\n", ans);
}
