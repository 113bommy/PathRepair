#include <bits/stdc++.h>
const int mx = 100009;
using namespace std;
long long t;
long long n, r, l, q1, q2, a[mx], s[mx], h, mi;
long long mini(long long a, long long b) {
  if (a > b)
    return b;
  else
    return a;
}
long long ab(long long x) {
  if (x > 0)
    return x;
  else
    return -x;
}
int main() {
  cin >> n >> l >> r >> q1 >> q2;
  cin >> a[0];
  s[0] = a[0];
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
  }
  mi = s[n - 1] * r + q2 * (n - 1);
  for (int i = 0; i < n; i++) {
    if (i < n / 2)
      h = q2;
    else
      h = q1;
    t = 0;
    if (ab(n - 2 * (i + 1)) > 0) t = ab(n - 2 * (i + 1)) - 1;
    mi = mini(mi, l * s[i] + (s[n - 1] - s[i]) * r + h * t);
  }
  cout << mi << endl;
  return 0;
}
