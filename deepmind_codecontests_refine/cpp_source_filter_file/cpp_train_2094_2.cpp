#include <bits/stdc++.h>
using namespace std;
const long long pm = 10e9 + 7;
const long long inf = 400000000000000000;
long long gcd(long long a, long long b) {
  if (a < b) return gcd(b, a);
  long long c = a % b;
  if (c) {
    return gcd(b, c);
  } else
    return b;
}
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (2 * n * m % k != 0) {
    cout << "NO\n";
  } else {
    cout << "YES" << endl;
    long long g = gcd(2 * m, k);
    if (g == 1) {
      long long x = n;
      long long y = (2 * n) / (k);
      cout << "0 0\n";
      cout << x << " 0\n";
      cout << "0 " << y << endl;
    } else {
      long long x = 2 * n / g;
      long long y = (2 * n * m) / (x * k);
      if (x > n || y > m) {
        long long tmp = x;
        x = y;
        y = tmp;
      }
      cout << "0 0\n";
      cout << x << " 0\n";
      cout << "0 " << y << endl;
    }
  }
  return 0;
}
