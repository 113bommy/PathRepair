#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a < b) {
    return gcd(b, a);
  }
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  std::ios_base::sync_with_stdio(false);
  long long n, m;
  cin >> n >> m;
  long long d;
  cin >> d;
  d -= 1;
  for (long long i = 1; i < n; i++) {
    long long a;
    cin >> a;
    a = a - 1;
    d = gcd(d, a);
  }
  long long ans = 0;
  for (long long i = 1; i * i <= d && i < m; i += 1) {
    if (d % i == 0) {
      long long base = i;
      if (i % 2 == 0) {
        while (base < m) {
          ans += m - base;
          base *= 2;
        }
      }
      if (i * i != d && d % 2 == 1 && d / i < m) {
        base = d / i;
        while (base < m) {
          ans += m - base;
          base *= 2;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
