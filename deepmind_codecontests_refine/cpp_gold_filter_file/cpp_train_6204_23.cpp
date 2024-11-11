#include <bits/stdc++.h>
using namespace std;
struct _cert {
  template <typename T>
  _cert& operator<<(T) {
    return *this;
  }
};
_cert _cer;
template <typename T>
void dprint(T begin, T end) {
  for (auto i = begin; i != end; i++) {
    _cer << (*i) << " ";
  }
  _cer << "\n";
}
long double mnt, mxt;
void slv(long double l, long double x, long double v) {
  if (v == 0) {
    if (x > 0 && x < l) return;
    mnt = 1e7;
    return;
  }
  if (v < 0) {
    x = l - x;
    v = -v;
  }
  mnt = max(mnt, (0 - x) / v);
  mxt = min(mxt, (l - x) / v);
}
int n;
const long double eps = 1e-12;
int main() {
  long long x1, y1, x2, y2;
  scanf("%d", &n);
  scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
  long long w = x2 - x1;
  long long h = y2 - y1;
  mnt = 0;
  mxt = 1e6;
  for (int i = 0; i < n; ++i) {
    long long x, y, vx, vy;
    scanf("%lld%lld%lld%lld", &x, &y, &vx, &vy);
    x -= x1;
    y -= y1;
    slv(w, x, vx);
    slv(h, y, vy);
  }
  if (mnt + eps >= mxt) {
    cout << -1 << "\n";
  } else {
    cout.setf(ios::fixed);
    cout.precision(20);
    cout << mnt << "\n";
  }
  return 0;
}
