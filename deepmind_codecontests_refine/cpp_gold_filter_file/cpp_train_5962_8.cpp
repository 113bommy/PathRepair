#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
void solve() {
  int m, d, w;
  long long int ans = 0, lim, g, x, y;
  scanf("%d%d%d", &m, &d, &w);
  lim = min(m, d);
  if (d == 1)
    ans = lim * lim;
  else {
    g = gcd(d - 1, w);
    w /= g;
    x = lim / w;
    y = lim % w;
    ans = y * (x + 1) * (x + 1) + (w - y) * x * x;
  }
  ans -= lim;
  ans >>= 1;
  printf("%lld\n", ans);
  return;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
