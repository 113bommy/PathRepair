#include <bits/stdc++.h>
using namespace std;
long long pot(long long b, int p, int m) {
  long long res = 1;
  b %= m;
  while (p) {
    if (p & 1) {
      res *= b;
      res %= m;
    }
    b *= b;
    b %= m;
    p /= 2;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long a, b, x, n, m = 1e9 + 7;
  cin >> a >> b >> n >> x;
  if (a == 1) {
    cout << ((pot(a, n, m) * x) % m + (b * (n % m)) % m) % m << '\n';
    return 0;
  }
  cout << ((pot(a, n, m) * x) % m +
           (b * ((((((pot(a, n, m) - 1) % (m)) + (m)) % (m)) *
                  pot(((((a - 1) % (m)) + (m)) % (m)), m - 2, m)) %
                 m)) %
               m) %
              m
       << '\n';
  return 0;
}
