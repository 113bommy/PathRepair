#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int main() {
  int i, j, k;
  long long x1, x2, y1, y2, z1, z2, s, g, d, mmax, len1, len2;
  scanf("%I64d%I64d%I64d", &x1, &y1, &z1);
  scanf("%I64d%I64d%I64d", &x2, &y2, &z2);
  if (x1 > x2) {
    s = x1;
    x1 = x2;
    x2 = s;
    s = y1;
    y1 = y2;
    y2 = s;
    s = z1;
    z1 = z2;
    z2 = s;
  }
  len1 = y1 - x1 + 1;
  len2 = y2 - x2 + 1;
  g = gcd(z1, z2);
  d = x2 - x1;
  d = d % g;
  mmax = 0;
  mmax = max(mmax, min(len2, len1 - d));
  d = g - d;
  mmax = max(mmax, min(len1, len2 - d));
  printf("%I64d\n", mmax);
  return 0;
}
