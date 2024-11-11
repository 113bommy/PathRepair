#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N], n;
double poorness(double x) {
  double csp = 0, bs = 0, csn = 0;
  for (int i = 0; i < n; i++) {
    csp += (double)a[i] - x;
    csn += (double)a[i] - x;
    if (csp < 0) csp = 0;
    if (csn > 0) csn = 0;
    bs = max(bs, csp);
    bs = max(bs, -csn);
  }
  return bs;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  double l = 0, r = 10000.0, ans = 1e10;
  int t = 400;
  while (t--) {
    double m1 = l + (r - l) / 3.0, m2 = r - (r - l) / 3.0;
    double fm1 = poorness(m1), fm2 = poorness(m2);
    if (fm1 > fm2)
      l = m1;
    else
      r = m2;
    ans = min(ans, fm1);
    ans = min(ans, fm2);
  }
  cout << fixed << setprecision(10) << ans;
}
