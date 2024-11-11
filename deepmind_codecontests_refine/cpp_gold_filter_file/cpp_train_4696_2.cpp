#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  t = 1;
  while (t--) {
    long long a, b, x, y;
    cin >> a >> b >> x >> y;
    long long q = 0;
    q = gcd(x, y);
    x = x / q;
    y = y / q;
    long long ans = 0;
    ans = min(a / x, b / y);
    cout << ans << endl;
  }
  return 0;
}
