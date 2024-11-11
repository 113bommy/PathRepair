#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
template <class I>
inline void sp(I& p, I& q) {
  I x = p;
  p = q, q = x;
}
struct ky {
  int x, y;
} a[N];
inline long long cross(const ky a, const ky b) {
  return (0ll + a.x) * b.y - (0ll + a.y) * b.x;
}
int n, x[N], y[N];
inline int C3(const int n) { return (0ll + n) * (n - 1) * (n - 2) / 6; }
int main() {
  scanf("%d", &n);
  register int i, j, cn, k;
  register long long tot = 0;
  for (i = 1; i <= n; ++i) scanf("%d%d", &x[i], &y[i]);
  for (i = 1; i <= n; ++i) {
    for (j = 1, cn = 0; j <= n; ++j)
      j ^ i ? a[++cn] = (ky){x[j] - x[i], y[j] - y[i]}, 0 : 0;
    std::sort(a + 1, a + 1 + cn, [](const ky a, const ky b) {
      const bool f1 = (a.y < 0 || ((!a.y) && (a.x > 0))),
                 f2 = (b.y < 0 || ((!b.y) && (b.x > 0)));
      return f1 ^ f2 ? f1 < f2 : (cross(a, b) > 0);
    });
    for (j = 1; j <= cn; ++j) a[j + cn] = a[j];
    for (k = 1, j = cn + 1; j <= cn + cn; ++j) {
      while (k + cn <= j || (cross(a[j], a[k]) > 0)) ++k;
      tot += C3(j - k);
    }
  }
  printf(
      "%lld\n",
      (0ll + n) * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 2 * (n - 4) / 2 - tot);
  return 0;
}
