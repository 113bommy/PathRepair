#include <bits/stdc++.h>
const int MOD = 1000000007;
using namespace std;
long long gcd(long long x, long long y) { return (x == 0) ? y : gcd(y % x, x); }
bool isprime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return true;
}
int main() {
  long long a[4];
  for (int i = 0; i < 4; i++) {
    cin >> a[i];
  }
  long long p, q;
  cin >> p >> q;
  sort(a, a + 4);
  long long x = a[0];
  if (x < p)
    cout << 0 << "\n";
  else {
    if (x < q)
      cout << x - p << "\n";
    else {
      cout << q - p + 1 << "\n";
    }
  }
}
