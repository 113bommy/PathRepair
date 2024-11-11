#include <bits/stdc++.h>
long long gcd(long long a, long long b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}
long long sod(long long x) {
  long long r, sum = 0;
  while (x > 0) {
    r = x % 10;
    x /= 10;
    sum += r;
  }
  return sum;
}
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, j;
  cin >> t;
  for (j = 0; j < t; j++) {
    long long l, r, m, i, a, b, c, n, d;
    cin >> l >> r >> m;
    for (i = l; i <= r; i++) {
      if ((m % i) <= abs(l - r) && (m - (m % i)) / i > 0) {
        a = i;
        n = (m - (m % i)) / i;
        break;
      } else if (i - (m % i) <= abs(l - r) && (m + (i - (m % i)) / i) > 0) {
        a = i;
        n = (m + (i - (m % i)) / i);
        break;
      }
    }
    d = m - n * a;
    if (d >= 0) {
      b = r;
      c = r - d;
    } else if (d < 0) {
      b = l;
      c = r - l;
    }
    cout << a << " " << b << " " << c << endl;
  }
}
