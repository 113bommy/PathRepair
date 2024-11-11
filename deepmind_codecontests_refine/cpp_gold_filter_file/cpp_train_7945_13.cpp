#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int ans = 0;
  vector<pair<int, int> > v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first >> v[i].second;
  }
  for (int i = 0; i < n; ++i) {
    int l = 0, r = 0, u = 0, d = 0;
    for (int j = 0; j < n; ++j) {
      int x1 = v[i].first;
      int x2 = v[j].first;
      int y1 = v[i].second;
      int y2 = v[j].second;
      if (1) {
        if (x1 == x2) {
          if (y1 > y2) ++l;
          if (y1 < y2) ++r;
        } else if (y1 == y2) {
          if (x1 > x2) ++u;
          if (x1 < x2) ++d;
        }
      }
    }
    if (l != 0 and r != 0 and u != 0 and d != 0) ++ans;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
