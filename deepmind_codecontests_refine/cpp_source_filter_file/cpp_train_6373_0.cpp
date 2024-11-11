#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    long long a, m;
    cin >> a >> m;
    long long d = gcd(a, m);
    m /= d;
    long long ans = 1;
    for (long long i = 2; i * i <= m; i++) {
      if (m % i != 0) continue;
      m /= i;
      ans *= (i - 1);
      while (m % i == 0) {
        ans *= m;
        m /= i;
      }
    }
    if (m > 1) ans *= (m - 1);
    cout << ans << endl;
  }
  return 0;
}
