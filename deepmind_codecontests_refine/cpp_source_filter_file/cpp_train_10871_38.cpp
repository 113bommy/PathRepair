#include <bits/stdc++.h>
using namespace std;
template <class T>
bool setmax(T& _a, T _b) {
  if (_b > _a) {
    _a = _b;
    return true;
  }
  return false;
}
template <class T>
bool setmin(T& _a, T _b) {
  if (_b < _a) {
    _a = _b;
    return true;
  }
  return false;
}
template <class T>
T gcd(T _a, T _b) {
  return _b == 0 ? _a : gcd(_b, _a % _b);
}
int n, a[1010];
bool good(int limit, int* first, int* delta) {
  for (int d = int(0); d <= int(10000); ++d) {
    int l = -1 << 30, r = 1 << 30;
    for (int i = int(1); i <= int(n); ++i) {
      int zl = a[i] - d * i - limit, zr = a[i] - d * i + limit;
      setmax(l, zl);
      setmin(r, zr);
      if (l > r) break;
    }
    if (l <= r) {
      *first = l + d, *delta = d;
      return true;
    }
  }
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = int(1); i <= int(n); ++i) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  int le = 0, ri = 10000, first = 0, delta = 0;
  while (le < ri) {
    int mid = (le + ri) / 2;
    if (good(mid, &first, &delta))
      ri = mid;
    else
      le = mid + 1;
  }
  assert(good(le, &first, &delta));
  printf("%d\n%d %d\n", le, first, delta);
  return 0;
}
