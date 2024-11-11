#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test--) {
    long long int a, b, c, d, e, f, res = 0;
    cin >> a >> b >> c >> d >> e >> f;
    long long int p, q, r, s;
    p = min(c, e);
    c -= p;
    e -= p;
    q = min(c, f);
    c -= q;
    f -= q;
    r = min(b, e);
    b -= r;
    e -= r;
    q = min(d, c);
    d -= q;
    c -= q;
    q = min(a, f);
    a -= q;
    f -= q;
    q = min(d, b);
    d -= q;
    b -= q;
    q = min(a, e);
    a -= q;
    e -= q;
    res = p * 2;
    res += min(b, f) * (-2);
    cout << res << "\n";
  }
  return 0;
}
