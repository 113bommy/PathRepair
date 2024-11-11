#include <bits/stdc++.h>
using namespace std;
long long int power(long long x, long long int y) {
  int res = 1;
  x = x % 1000000009;
  ;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000009;
    ;
    y = y >> 1;
    x = (x * x) % 1000000009;
    ;
  }
  return res % 1000000009;
  ;
}
int main() {
  long long int n, m, k, t, cnt = 0, b, sum = 0, is = 0, c, mo = 1000000009, v;
  cin >> n >> m >> k;
  c = m;
  t = n - (n / k);
  if (m <= t) {
    cout << m << endl;
  } else {
    c = m - t;
    v = (2 * (power(2, c) - 1) * k) % mo + t % mo - (c * (k - 1)) % mo;
    cout << v % mo << endl;
  }
}
