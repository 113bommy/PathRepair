#include <bits/stdc++.h>
using namespace std;
long long int modpow(long long int a, long long int n, long long int temp) {
  long long int res = 1, y = a;
  while (n > 0) {
    if (n & 1) res = (res * y) % temp;
    y = (y * y) % temp;
    n /= 2;
  }
  return res % temp;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0)
    return (b);
  else
    return (gcd(b % a, a));
}
int main() {
  int m, x, y, c[1000], tot = 0;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> c[i];
    tot += c[i];
  }
  cin >> x >> y;
  bool fnd = 0;
  int res = -1;
  int l = 0;
  for (int i = 0; i <= m; i++) {
    if (l >= x && l <= y && tot - l >= x && tot - l <= y) {
      fnd = 1;
      res = i + 1;
    }
    l += c[i];
  }
  if (fnd == 0)
    cout << 0 << endl;
  else
    cout << res << endl;
  return 0;
}
