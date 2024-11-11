#include <bits/stdc++.h>
using namespace std;
struct Lem {
  int m, v, id;
  bool operator<(Lem b) const { return m < b.m || (m == b.m && v < b.v); }
};
int n, k, h;
Lem a[(100000 + 10)];
bool can(double t) {
  int j = k;
  for (int i(n - 1), _l(0); i >= _l; --i) {
    if (j > 0 && (double)j * h / a[i].v - t <= -1e-7) j--;
  }
  return j == 0;
}
void putAns(double t) {
  int ans[(100000 + 10)];
  int j = k;
  for (int i(n - 1), _l(0); i >= _l; --i) {
    if (j > 0 && (double)j * h / a[i].v - t <= -1e-7) ans[--j] = a[i].id;
  }
  for (int i(0), _n(k - 1); i < _n; ++i) printf("%d ", ans[i]);
  printf("%d\n", (ans[k - 1]));
}
int main() {
  scanf("%d", &(n)), scanf("%d", &(k)), scanf("%d", &(h));
  for (int i(0), _n(n); i < _n; ++i) scanf("%d", &(a[i].m)), a[i].id = i + 1;
  for (int i(0), _n(n); i < _n; ++i) scanf("%d", &(a[i].v));
  sort(a, a + n);
  double l = 0, r = 1e10;
  int cnt = 90;
  while (cnt--) {
    double mid = (l + r) / 2.0;
    if (can(mid))
      r = mid;
    else
      l = mid;
  }
  putAns(r);
  return 0;
}
