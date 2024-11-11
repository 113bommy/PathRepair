#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 9;
const long long inf = 0x3f3f3f3f;
vector<int> x, y;
map<int, int> ma[N], mb[N], cntx, cnty;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    int xx;
    cin >> xx;
    x.push_back(xx);
  }
  for (int i = 1; i <= m; i++) {
    int yy;
    cin >> yy;
    y.push_back(yy);
  }
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    int xx, yy;
    cin >> xx >> yy;
    int pos1 = lower_bound(x.begin(), x.end(), xx) - x.begin();
    int pos2 = lower_bound(y.begin(), y.end(), yy) - y.begin();
    if (x[pos1] == xx && y[pos2] == yy) continue;
    if (x[pos1] == xx) {
      pos2--;
      ans += ++cnty[pos2] - ++ma[pos1][pos2];
    } else {
      pos1--;
      ans += ++cntx[pos1] - ++mb[pos2][pos1];
    }
  }
  for (int i = 0; i <= max(n, m) + 1; i++) {
    ma[i].clear();
    mb[i].clear();
  }
  cntx.clear();
  cnty.clear();
  x.clear();
  y.clear();
  cout << ans << endl;
}
signed main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
