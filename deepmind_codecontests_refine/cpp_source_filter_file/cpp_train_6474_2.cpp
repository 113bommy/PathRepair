#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y) {
  long long p = 1000000007;
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1 & p;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  long long n, m;
  cin >> n >> m;
  long long ans = 0, per = 0;
  per = pow(2, m);
  ans = pow(per - 1, n);
  cout << ans;
}
