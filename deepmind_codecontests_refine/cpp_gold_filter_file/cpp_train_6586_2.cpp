#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInverse(long long a, long long p) { return power(a, p - 2, p); }
long long gcd(long long x, long long y) {
  if (x == 0 || y == 0) {
    return max(y, x);
  }
  return gcd(y % x, x);
}
vector<long long> a;
long long fun(long long l, long long r) {
  if (l > r) return 0;
  if (l == r) return a[l] != 0;
  long long p = l;
  for (long long i = l; i <= r; i++) {
    if (a[i] < a[p]) p = i;
  }
  long long mini = a[p];
  for (long long i = l; i <= r; i++) {
    a[i] -= mini;
  }
  return min(fun(l, p - 1) + fun(p + 1, r) + mini, r - l + 1);
}
int main() {
  long long n;
  scanf("%lld", &n);
  for (long long i = 0; i < n; i++) {
    long long x;
    scanf("%lld", &x);
    a.push_back(x);
  }
  cout << fun(0, n - 1) << endl;
}
