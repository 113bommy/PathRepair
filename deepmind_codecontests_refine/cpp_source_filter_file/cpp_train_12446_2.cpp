#include <bits/stdc++.h>
using namespace std;
long long a1, b1, a2, b2, L, R, x, y;
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  long long q = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return q;
}
int main() {
  cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
  long long d = exgcd(a1, a2, x, y);
  if (abs(b2 - b1) % d) {
    puts("1");
    return 0;
  }
  x *= (b2 - b1) / d;
  x = (x % abs(a2 / d) + abs(a2 / d)) % abs(a2 / d);
  long long fir = a1 * x + b1, add = a1 * a2 / d, ans = 0;
  L = max(L, max(b1, b2));
  if (L > R) return puts("0"), 0;
  if (fir <= R) ans += (R - fir) / add + 1;
  if (fir < L) ans -= (L - 1 - fir) / add + 1;
  cout << ans << endl;
}
