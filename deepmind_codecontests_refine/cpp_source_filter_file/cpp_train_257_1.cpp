#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  long long r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = 2 * acos(0);
const int maxn = 1000010;
int n, c, d;
long double angle[maxn];
long double getangle(long double x, long double y) {
  if (x == 0) {
    if (y > 0) return PI / 2;
    return 3 * PI / 2;
  }
  if (y == 0) {
    if (x > 0) return 0;
    return PI;
  }
  long double res = atan(y / x);
  if (x < 0) return res + PI;
  if (y < 0) return res + 2 * PI;
  return res;
}
void solve() {
  scanf("%d%d%d", &n, &c, &d);
  for (int i = (0); i < (n); i++) {
    long long x, y;
    scanf("%I64d%I64d", &x, &y);
    angle[i] = getangle(x - c, y - d);
  }
  sort(angle, angle + n);
  for (int i = (0); i < (n); i++) angle[i + n] = angle[i] + 2 * PI;
  long long tot = 0;
  for (int i = (0); i < (n); i++) {
    int l = i, r = i + n;
    while (l < r) {
      int m = (l + r + 1) >> 1;
      if (angle[m] - angle[i] < PI - 1e-12)
        l = m;
      else
        r = m - 1;
    }
    int p = l;
    l = i;
    r = i + n;
    while (l < r) {
      int m = (l + r) >> 1;
      if (angle[m] - angle[i] < PI + 1e-12)
        l = m + 1;
      else
        r = m;
    }
    int q = l;
    long long u = p - i;
    long long v = n - (q - i);
    long long w = q - p - 1;
    tot += u * (u - 1) / 2 + v * (v - 1) / 2 + w * (u + v);
  }
  printf("%I64d", 1LL * n * (n - 1) * (n - 2) / 6 - tot / 2);
}
int main() {
  solve();
  return 0;
}
