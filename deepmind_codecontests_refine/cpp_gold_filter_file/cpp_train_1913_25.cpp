#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:300000000")
const long double eps = 1e-20;
const long double pi = acos(-1.0);
const long long inf = 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const long long base = 1000 * 1000 * 1000 + 7;
using namespace std;
long long n, x, y, k;
long long f(long long t) {
  long long res, tmp, lenx, leny;
  res = t * t + (t + 1ll) * (t + 1ll);
  if (x <= t) {
    tmp = t - x + 1ll;
    res -= tmp * tmp;
  }
  if (y <= t) {
    tmp = t - y + 1ll;
    res -= tmp * tmp;
  }
  if (n - x + 1ll <= t) {
    tmp = (t - (n - x + 1ll)) + 1ll;
    res -= tmp * tmp;
  }
  if (n - y + 1ll <= t) {
    tmp = (t - (n - y + 1ll)) + 1ll;
    res -= tmp * tmp;
  }
  if (x < t) {
    lenx = t - x;
    lenx = lenx - y + 1ll;
    if (lenx > 0ll) res += ((lenx) * (lenx + 1ll)) / 2;
  }
  if (n - x + 1ll < t) {
    lenx = t - (n - x + 1ll);
    lenx = lenx - y + 1ll;
    if (lenx > 0ll) res += ((lenx) * (lenx + 1ll)) / 2;
  }
  if (n - y + 1ll < t) {
    lenx = t - (n - y + 1ll);
    lenx = lenx - x + 1ll;
    if (lenx > 0ll) res += ((lenx) * (lenx + 1ll)) / 2;
  }
  if (n - y + 1ll < t) {
    lenx = t - (n - y + 1ll);
    lenx = lenx - (n - x + 1ll) + 1ll;
    if (lenx > 0ll) res += ((lenx) * (lenx + 1ll)) / 2;
  }
  return res;
}
int main() {
  cin >> n >> x >> y >> k;
  long long l = 0, r = n + n, c;
  while (r - l > 1) {
    c = (r + l) / 2;
    if (f(c) >= k)
      r = c;
    else
      l = c;
  }
  if (f(l) >= k)
    cout << l;
  else
    cout << r;
  return 0;
}
