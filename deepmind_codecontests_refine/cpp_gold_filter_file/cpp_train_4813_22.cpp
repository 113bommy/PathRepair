#include <bits/stdc++.h>
using namespace std;
const int64_t N = 1e6 + 7;
const int64_t INF = 1e16;
int64_t t;
int64_t a, b, c;
int64_t factor(int64_t n, int64_t c) {
  int64_t ret = 1, mdist = c - 1;
  for (int64_t i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      int64_t dist = abs(c - i);
      if (dist < mdist) mdist = dist, ret = i;
      dist = abs(c - n / i);
      if (dist < mdist) mdist = dist, ret = n / i;
    }
  }
  return ret;
}
int64_t multiple(int64_t n, int64_t c) {
  int64_t ret = n, mdist = abs(c - n);
  for (int64_t i = n; i <= 20000; i += n) {
    int64_t dist = abs(c - i);
    if (dist < mdist) mdist = dist, ret = i;
  }
  return ret;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    int64_t mincost = INF, mina, minb, minc;
    for (int64_t i = 1; i <= 20000; i++) {
      int64_t cb = i;
      int64_t ca = factor(i, a);
      int64_t cc = multiple(i, c);
      int64_t cost = abs(b - cb) + abs(c - cc) + abs(a - ca);
      if (cost < mincost) mincost = cost, mina = ca, minb = cb, minc = cc;
    }
    cout << mincost << "\n";
    cout << mina << " " << minb << " " << minc << "\n";
  }
  return 0;
}
