#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ulli = unsigned long long int;
using ld = long double;
int n;
ld a[(int)(2e5 + 5)];
ld f(ld x) {
  ld ans = 0;
  ld temp = 0;
  for (int i = 0; i < n; ++i) {
    temp += a[i] - x;
    if (temp < 0) temp = 0;
    ans = max(ans, temp);
  }
  temp = 0;
  for (int i = 0; i < n; ++i) {
    temp += a[i] - x;
    if (temp > 0) temp = 0;
    ans = max(ans, -temp);
  }
  return ans;
}
int ts(ld l, ld r) {
  if (r - l <= (long double)(1e-11)) {
    cout << setprecision(12) << f(r);
    return 0;
  }
  ld m1 = l + (r - l) / 3;
  ld m2 = r - (r - l) / 3;
  ld f1 = f(m1), f2 = f(m2);
  if (f1 < f2) {
    ts(l, m2);
    return 0;
  }
  if (f2 < f1) {
    ts(m1, r);
    return 0;
  }
  ts(m1, m2);
  return 0;
}
int main() {
  cin >> n;
  ld lmax = -(long double)(10000), lmin = (long double)(10000);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    lmax = max(lmax, a[i]);
    lmin = min(lmin, a[i]);
  }
  ts(lmin, lmax);
  return 0;
}
