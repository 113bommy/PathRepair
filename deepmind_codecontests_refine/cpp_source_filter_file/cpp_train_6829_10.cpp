#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
long long add(long long x, long long y) {
  long long res = x + y;
  return (res >= 1000000007 ? res - 1000000007 : res);
}
long long mul(long long x, long long y) {
  long long res = x * y;
  return (res >= 1000000007 ? res % 1000000007 : res);
}
long long sub(long long x, long long y) {
  long long res = x - y;
  return (res < 0 ? res + 1000000007 : res);
}
long long power(long long x, long long y) {
  long long res = 1;
  x %= 1000000007;
  while (y) {
    if (y & 1) res = mul(res, x);
    y >>= 1;
    x = mul(x, x);
  }
  return res;
}
long long mod_inv(long long x) { return power(x, 1000000007 - 2); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, k, x;
  cin >> n >> k >> x;
  long long z = n / 2;
  long long a = z / (x + 1);
  cout << a << " " << x * a << " " << n - (x + 1) * a << endl;
}
