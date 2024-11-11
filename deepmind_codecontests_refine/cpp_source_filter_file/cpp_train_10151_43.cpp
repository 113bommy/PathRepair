#include <bits/stdc++.h>
using namespace std;
long long t, a, b;
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
int main() {
  cin >> t >> a >> b;
  if (a > b) swap(a, b);
  long long ans;
  if (t / a * gcd(a, b) / b > 0) {
    long long lcm = a / gcd(a, b) * b;
    ans = t / lcm * a + min(t % lcm, a - 1);
  } else {
    ans = min(a - 1, t - 1);
  }
  long long d = gcd(ans, t);
  ans /= d;
  t /= d;
  cout << ans << "/" << t << endl;
  return 0;
}
