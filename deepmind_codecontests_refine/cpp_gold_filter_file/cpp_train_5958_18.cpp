#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 314;
const int INF = 1e9;
const double PI = acos(-1);
const int MOD = 1e9 + 7;
const double eps = 1e-9;
void solve() {
  long long n, g, b;
  cin >> n >> g >> b;
  long long nd = (n + 1) / 2;
  long long l = 1, r = 1e18, f = -1, mnb, mng;
  while (l <= r) {
    long long md = l + (r - l) / 2;
    long long pl = md / (g + b);
    long long sg = pl * g;
    long long sb = pl * b;
    pl = md % (g + b);
    sg += min(g, pl);
    pl -= min(g, pl);
    sb += pl;
    if (sg >= nd) {
      f = md;
      r = md - 1;
      mnb = sb;
      mng = sg;
    } else {
      l = md + 1;
    }
  }
  cout << f + max(0ll, n - mng - mnb) << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
