#include <bits/stdc++.h>
using namespace std;
long long bigmod(long long a, long long b, long long m) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b & 1) x = (x * y) % m;
    y = (y * y) % m;
    b >>= 1;
  }
  return x;
}
long long gcd(long long a, long long b) {
  long long rem = 0;
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
int main() {
  long long n, mn = 999999999999, mx = 0, i, res = 0, x, dis;
  cin >> n;
  map<long long, long long> make_pair;
  map<long long, long long>::iterator it;
  for (i = 1; i <= n; i++) {
    cin >> x;
    mx = max(mx, x);
    mn = min(mn, x);
    make_pair[x]++;
  }
  dis = mx - mn;
  if (dis)
    res = (make_pair[mx] * make_pair[mn]);
  else
    res = (n * (n + 1)) / 2;
  cout << dis << " " << res << endl;
}
