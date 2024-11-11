#include <bits/stdc++.h>
using namespace std;
const long long p = 1000003LL;
long long n, c;
long long power(long long x, long long n) {
  long long ret = 1LL;
  while (n > 0LL) {
    if (n & 1LL) ret = ret * x % p;
    x = x * x % p;
    n >>= 1LL;
  }
  return ret;
}
long long ans;
int main() {
  cin >> n >> c;
  ans = 1LL;
  for (long long i = n + 1LL; i <= n + c; i++) {
    ans = (ans * i) % p;
  }
  for (long long i = 2; i <= c; i++) {
    ans = (ans * power(i, p - 2)) % p;
  }
  cout << ans << endl;
}
