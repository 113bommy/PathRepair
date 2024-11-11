#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (b != 0) {
    long long r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main() {
  long long n, k, a, b, mi = 2e9, ma = -2e9;
  cin >> n >> k >> a >> b;
  for (int i = -1; i < 2; i += 2) {
    for (int j = -1; j < 2; j += 2) {
      for (long long x = n; x < 2 * n; x++) {
        long long l = k * x + a * i + b * j;
        if (k * n / gcd(k * n, l) < mi) {
          mi = k * n / gcd(k * n, l);
        }
        if (k * n / gcd(k * n, l) > ma) {
          ma = k * n / gcd(k * n, l);
        }
      }
    }
  }
  cout << mi << ' ' << ma;
  return 0;
}
