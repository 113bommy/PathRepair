#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long mpow(long long a, long long b) {
  long long r = 1;
  a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) r = r * a % 1000000007;
    a = a * a % 1000000007;
  }
  return r;
}
void fastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long long N = 3e5;
int32_t main() {
  fastIO();
  long long n, s;
  cin >> n >> s;
  if (n == 1 && s != 1) {
    cout << "YES"
         << "\n";
    cout << s << "\n";
    cout << s - 1 << "\n";
  } else if ((n == 1 && s == 1) || n >= s || 2 * n > s)
    cout << "NO"
         << "\n";
  else {
    cout << "YES"
         << "\n";
    cout << s - (n - 1) << " ";
    for (__typeof(n - 1) i = (0) - ((0) > (n - 1));
         i != (n - 1) - ((0) > (n - 1)); i += 1 - 2 * ((0) > (n - 1)))
      cout << 1 << " ";
    cout << "\n";
    cout << n << "\n";
  }
  return 0;
}
