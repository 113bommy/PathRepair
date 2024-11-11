#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0)
    return b;
  else if (b == 0)
    return a;
  else if (a >= b)
    return gcd(a % b, b);
  else
    return gcd(b % a, a);
}
int main() {
  long long n, m, q;
  cin >> n >> m >> q;
  long long g = gcd(n, m);
  long long nd = n / g;
  long long md = m / g;
  for (int i = 0; i < q; i++) {
    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d;
    b--;
    d--;
    if (a == 1)
      e = b / nd;
    else
      e = b / md;
    if (c == 1)
      f = d / nd;
    else
      f = d / md;
    if (e == f)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
