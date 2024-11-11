#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int main() {
  long long a1, b1, c1, a2, b2, c2;
  cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
  if (b1 - a1 > b2 - a2) swap(a1, a2), swap(b1, b2), swap(c1, c2);
  long long d2 = b2 - a2, d1 = b1 - a1;
  if (a2 < a1) a2 = a1 + c2 - (a2 - a1) % c2, b2 = a2 + d2;
  long long t = gcd(c1, c2);
  a1 = a2 + c1 - (a2 - a1) % c1;
  if (a1 > a2 + t - 1) a2 = a1 - (a1 - a2) % c2, b2 = a2 + d2;
  long long Min = a2 + (a1 - a2) % t;
  printf("%lld", max(0ll, max(min(b2, Min + d1 - c1) - max(a2, Min - c1) + 1,
                              min(b2, Min + d1) - max(a2, Min) + 1)));
  return 0;
}
