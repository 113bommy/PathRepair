#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9 + 5;
const int MOD = 998244353;
const long long ooll = 1e18 + 5;
const int N = 1e6 + 5;
int v[N];
void solve() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int x3, y3, x4, y4;
  cin >> x3 >> y3 >> x4 >> y4;
  int x5, y5, x6, y6;
  cin >> x5 >> y5 >> x6 >> y6;
  for (int y = y1; y < y2; ++y) {
    int lx = x1, rx = x2;
    if (y3 <= y && y < y4) {
      if (x3 <= lx) lx = max(lx, x4);
      if (x4 >= rx) rx = min(rx, x3);
    }
    if (y5 <= y && y < y6) {
      if (x5 <= lx) lx = max(lx, x6);
      if (x6 >= rx) rx = min(rx, x5);
    }
    if (lx < rx) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  for (int tc = 1; tc <= t; ++tc) {
    solve();
  }
  return 0;
}
