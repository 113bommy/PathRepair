#include <bits/stdc++.h>
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b) * b); }
unsigned long long power(unsigned long long a, unsigned long long b) {
  a %= 1000000007;
  unsigned long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
    b >>= 1;
  }
  return res % 1000000007;
}
long long modmul(long long x, long long y) { return (x * y) % 1000000007; }
long long modadd(long long x, long long y) { return (x + y) % 1000000007; }
long long modsub(long long x, long long y) {
  return (x - y + 1000000007) % 1000000007;
}
long long fact[1000007] = {0};
void facto() {
  fact[0] = 1;
  fact[1] = 1;
  for (long long i = 2; i < 100007; i++)
    fact[i] = (fact[i - 1] * i) % 1000000007;
}
long long ncr(long long n, long long r) {
  long long res = 1;
  res = fact[n];
  res = (res * (power(fact[r], 1000000007 - 2))) % 1000000007;
  res = (res * (power(fact[n - r], 1000000007 - 2))) % 1000000007;
  return res;
}
long long npr(long long n, long long r) {
  long long res = 1;
  res = fact[n];
  res = (res * (power(fact[n - r], 1000000007 - 2))) % 1000000007;
  return res;
}
bool prime[1000005];
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  double x1, y1, x2, y2, r1, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  double dist = hypot((x1 - x2), (y1 - y2));
  double ans;
  double max1 = r1 >= r2 ? r2 : r2;
  if (dist < r1 + r2)
    ans = (abs(r1 - r2) - dist) / 2;
  else if (dist > r1 + r2)
    ans = (dist - r1 - r2) / 2;
  else
    ans = 0;
  cout << fixed << setprecision(10) << ans << endl;
}
