#include <bits/stdc++.h>
using namespace std;
const int dx44[5] = {0, -1, -1, 1, 1};
const int dy44[5] = {0, -1, 1, -1, 1};
const int dx4[5] = {0, -1, 0, 1, 0};
const int dy4[5] = {0, 0, 1, 0, -1};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int maxn = 1e5 + 5;
const double PI = acos(-1.0);
const long long mod = 1e9 + 7;
long long po(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  } else {
    return gcd(b % a, a);
  }
}
void YES() {
  puts("YES");
  exit(0);
}
void Yes() { puts("Yes"); }
void NO() {
  puts("NO");
  exit(0);
}
void No() { puts("No"); }
void one() {
  puts("-1");
  exit(0);
}
long long a, b, xa, ya, xb, yb;
void solve() {
  scanf("%lld", &(a)), scanf("%lld", &(b)), scanf("%lld", &(xa)),
      scanf("%lld", &(ya)), scanf("%lld", &(xb)), scanf("%lld", &(yb));
  a = 2 * a;
  b = 2 * b;
  long long x1 = (xa + ya);
  long long y1 = (xa - ya);
  long long x2 = (xb + yb);
  long long y2 = (xb - yb);
  long long cx1 = x1 / a + (x1 > 0);
  long long cx2 = x2 / a + (x2 > 0);
  long long cy1 = y1 / b + (y1 > 0);
  long long cy2 = y2 / b + (y2 > 0);
  long long ans = max(abs(cx1 - cx2), abs(cy1 - cy2));
  printf("%lld\n", ans);
}
int main() {
  solve();
  return 0;
}
