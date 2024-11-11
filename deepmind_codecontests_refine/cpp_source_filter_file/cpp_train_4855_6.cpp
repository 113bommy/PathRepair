#include <bits/stdc++.h>
using namespace std;
int n;
long long ans = 1;
long long binpow(long long a, long long n) {
  if (n == 0) return 1;
  if (n % 2 == 1)
    return binpow(a, n - 1) * a;
  else {
    int b = binpow(a, n / 2);
    return b * b;
  }
}
int main() {
  cin >> n;
  long long a = 2;
  long long d = 1;
  a++;
  while (d <= n) {
    if (n % d == 0) ans = d;
    d = (binpow(2, a) - 1) * binpow(2, a - 1);
    a++;
  }
  cout << ans;
  return 0;
}
