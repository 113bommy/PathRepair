#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int count(int x) {
  int ans = 0;
  for (int i = 1; i * i <= x; i++)
    if (x % i == 0) {
      ++ans;
      if (i * i != x) ++ans;
    }
  return ans;
}
int main() {
  int t;
  scanf("%d", &t);
  do {
    long long a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    long long x = count(gcd(a, b)), y = count(gcd(a, c)), z = count(gcd(c, b)),
              zz = count(gcd(gcd(a, b), c));
    a = count(a), b = count(b), c = count(c);
    long long ans = a * b * c -
                    (a * (x - 1) * x + b * (y - 1) * y + c * (z - 1) * z) / 2 +
                    (zz - 2) * (zz - 1) * zz / 3 * 2;
    ans += (zz - 1) * zz * (x + y + z - 3 * zz + 2) / 2 -
           (x - zz) * (y - zz) * (z - zz);
    printf("%lld\n", ans);
    --t;
  } while (t > 0);
}
