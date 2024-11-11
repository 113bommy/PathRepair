#include <bits/stdc++.h>
using namespace std;
long long mod;
map<long long, long long> first;
long long fib(long long x) {
  if (x <= 1) return 1;
  if (first.find(x) != first.end()) return first[x];
  long long p = x / 2;
  long long r;
  if (x % 2 == 0)
    r = (fib(p) * fib(p) + fib(p - 1) * fib(p - 1)) % mod;
  else
    r = (fib(p) * fib(p + 1) + fib(p - 1) * fib(p)) % mod;
  first[x] = r;
  return r;
}
long long m, l, r, k;
long long check(long long a) {
  long long x = r / a;
  long long y = (l - 1) / a;
  if (x - y >= k)
    return 1;
  else
    return 0;
}
signed main() {
  cin >> m >> l >> r >> k;
  mod = m;
  long long ans = -1;
  for (long long i = 1; i <= sqrt(r); i++) {
    long long y = r / i;
    if (check(i) == 1) ans = max(ans, i);
    if (check(y) == 1) ans = max(ans, y);
  }
  cout << fib(ans - 1) << endl;
}
