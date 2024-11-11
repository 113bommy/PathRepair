#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, k, a, b;
  cin >> n >> k >> a >> b;
  long long x = 1e18;
  long long y = 0;
  for (long long i = 0; i <= n * (long long)3; i++) {
    long long l1 = k * i + b - a;
    long long l2 = k * i + (k - b) - a;
    long long l3 = k * i + b - (k - a);
    long long l4 = k * i + (k - b) - (k - a);
    if (l1 >= 0) {
      long long res = n * k / gcd(n * k, l1);
      x = min(x, res);
      y = max(y, res);
    }
    if (l2 >= 0) {
      long long res = n * k / gcd(n * k, l2);
      x = min(x, res);
      y = max(y, res);
    }
    if (l3 >= 0) {
      long long res = n * k / gcd(n * k, l3);
      x = min(x, res);
      y = max(y, res);
    }
    if (l4 >= 0) {
      long long res = n * k / gcd(n * k, l4);
      x = min(x, res);
      y = max(y, res);
    }
  }
  cout << x << ' ' << y;
  return 0;
}
