#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
const int N = 2e5 + 1;
int n, m, a, b, ya[N], yb[N], lb[N];
ld dist(int x, int y, int x1, int ___y1) {
  return (ld)sqrt((ld)(x - x1) * (x - x1) + (ld)(y - ___y1) * (y - ___y1));
}
ld calf(int v, int x) { return dist(0, 0, a, x) + dist(a, x, b, v); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> a >> b;
  for (int i = (1); i <= (n); ++i) cin >> ya[i];
  for (int i = (1); i <= (m); ++i) cin >> yb[i];
  for (int i = (1); i <= (m); ++i) cin >> lb[i];
  ld ans = 1e13;
  int ansi, ansj;
  for (int i = (1); i <= (m); ++i) {
    int l = 1, r = n - 1;
    while (l <= r) {
      int mi = (l + r) >> 1;
      if (calf(yb[i], ya[mi]) > calf(yb[i], ya[mi + 1]))
        l = mi + 1;
      else
        r = mi - 1;
    }
    if (ans > lb[i] + calf(yb[i], ya[l])) {
      ans = lb[i] + calf(yb[i], ya[l]);
      ansi = l, ansj = i;
    }
  }
  cout << ansi << ' ' << ansj;
  return 0;
}
