#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long func(long long l, long long lcm, long long a, long long b) {
  long long ans = 0;
  long long d = max(a, b), c = min(a, b);
  for (long long i = 1; i < min(l, d); i++)
    if ((i % a) % b == (i % b) % a) ans++;
  long long div = (l - 1) / lcm;
  if (div >= 1) ans += (div - 1) * d;
  if (div >= (long long)1) ans += min(((l - 1) % lcm) + 1, d);
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, q;
    cin >> a >> b >> q;
    while (q--) {
      long long l, r;
      cin >> l >> r;
      long long lcm = a * b / gcd(a, b);
      long long left = func(l, lcm, a, b);
      long long right = func(r + 1, lcm, a, b);
      long long ans = r - l + 1 - right + left;
      cout << ans << " ";
    }
    cout << endl;
  }
}
