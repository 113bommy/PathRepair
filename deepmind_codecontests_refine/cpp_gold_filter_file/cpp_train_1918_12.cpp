#include <bits/stdc++.h>
using namespace std;
long long i, j, k, m, n;
long long a[223456], b[223456], c, d, e, s, t, l, r, ll, rr;
string p[1111], q, w;
map<long long, long long> x, y;
int main() {
  cin >> n >> m >> c >> d >> l >> r;
  n--;
  m--;
  c--;
  d--;
  s = 111111111;
  t = s;
  if (n + 1 <= l) e++;
  if (m + 1 <= r) e++;
  if (e == 1) {
    if ((n != c && c != 0) || (m != d && d != 0)) {
      cout << "Poor Inna and pony!";
      return 0;
    }
  }
  if (c % l == 0 && d % r == 0) {
    if ((c / l + d / r) % 2 == 0) s = max(c / l, d / r);
  }
  c = n - c;
  if (c % l == 0 && d % r == 0) {
    if ((c / l + d / r) % 2 == 0) s = min(s, max(c / l, d / r));
  }
  d = m - d;
  if (c % l == 0 && d % r == 0) {
    if ((c / l + d / r) % 2 == 0) s = min(s, max(c / l, d / r));
  }
  c = n - c;
  if (c % l == 0 && d % r == 0) {
    if ((c / l + d / r) % 2 == 0) s = min(s, max(c / l, d / r));
  }
  if (s < t)
    cout << s;
  else
    cout << "Poor Inna and pony!";
  return 0;
}
