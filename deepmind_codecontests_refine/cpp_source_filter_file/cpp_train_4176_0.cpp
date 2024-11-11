#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return a == 0 ? b : gcd(b % a, a); }
signed main() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (2 * n * m % k != 0) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  bool bul = false;
  if (k % 2 == 0) {
    k /= 2;
    bul = true;
  }
  long long g = gcd(n, k);
  long long a = n / g;
  long long k1 = k / g;
  long long b = m / k1;
  if (!bul) {
    if (a < b)
      a *= 2;
    else
      b *= 2;
  }
  cout << "0 0\n"
       << a << " 0\n"
       << "0 " << b;
  return 0;
}
