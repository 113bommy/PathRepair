#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
int flag = 0;
long long multi(long long x, long long y) {
  if (y == 0) return 0ll;
  long long t = multi(x, y / 2);
  t = t + t;
  if ((t < 0) || (t > a)) flag = 1;
  if (y % 2 == 1) t = t + x;
  if ((t < 0) || (t > a)) flag = 1;
  return t;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  cin >> a >> b >> c;
  long long t = multi(b / gcd(b, c), c);
  if (flag == 1) t = a;
  long long ans = a / t * min(b, c);
  ans += min(min(b, c) - 1, a % t);
  long long temp = gcd(ans, a);
  cout << ans / temp << "/" << a / temp << endl;
  return 0;
}
