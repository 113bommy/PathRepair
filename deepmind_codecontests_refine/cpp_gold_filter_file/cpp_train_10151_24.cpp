#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
int main() {
  long long t, a, b, ans, d, tem;
  while (cin >> t >> a >> b) {
    d = gcd(a, b);
    if (t / b < a / d)
      ans = min(t, min(a, b) - 1);
    else {
      d = a / d * b;
      ans = t / d * min(a, b);
      tem = t - (t / d * d - 1);
      ans += min(tem, min(a, b));
      ans--;
    }
    d = gcd(ans, t);
    ans /= d;
    t /= d;
    cout << ans << "/" << t << endl;
  }
  return 0;
}
