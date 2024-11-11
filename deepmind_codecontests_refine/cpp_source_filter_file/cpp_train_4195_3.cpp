#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
string no = "NO\n", yes = "YES\n";
string imp = "IMPOSSIBLE\n";
long long a, b, c, d;
long long f(long long mid) {
  long long damag = (mid + 1) * a;
  damag -= (mid * b * c);
  long long k = min(c / d, mid);
  damag += b * (c * (k)-d * (k + 1) * k / 2);
  return damag;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d;
    if (a > b * c) {
      cout << -1 << endl;
      continue;
    }
    if (d >= c) {
      cout << a << endl;
      continue;
    }
    long long l = -1, r = 1e12;
    while (r - l > 5) {
      long long m1 = l + (r - l) / 3;
      long long m2 = r - (r - l) / 3;
      if (f(m1) < f(m2))
        l = m1;
      else
        r = m2;
    }
    long long damag = 0;
    for (long long i = max((long long)0, l - 10); i < l + 10; i++) {
      if (damag < f(i)) {
        damag = f(i);
      }
    }
    cout << damag << endl;
  }
  return 0;
}
