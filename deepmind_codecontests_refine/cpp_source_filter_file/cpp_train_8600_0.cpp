#include <bits/stdc++.h>
using namespace std;
long long binpow(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long binpowmod(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long mod_inverse(long long n, long long p) {
  return binpowmod(n, p - 2, p);
}
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
bool comp(int x, int y) { return x > y; }
bool isPowerOfTwo(long long x) { return x && (!(x & (x - 1))); }
void solve() {
  long long n;
  cin >> n;
  if (n % 4 == 0)
    cout << n / 4;
  else if (n % 4 == 1) {
    if (n >= 9)
      cout << (n - 9) / 4 + 1;
    else
      cout << -1;
  } else if (n % 4 == 2) {
    if (n >= 6)
      cout << (n - 6) / 2 + 1;
    else
      cout << -1;
  } else {
    if (n < 15)
      cout << -1;
    else
      cout << (n - 15) / 4 + 2;
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  while (q--) solve();
}
