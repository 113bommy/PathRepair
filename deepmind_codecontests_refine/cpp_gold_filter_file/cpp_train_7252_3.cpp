#include <bits/stdc++.h>
using namespace std;
struct Square1 {
  vector<pair<int, int>> p;
  void read() {
    for (int i = 0; i < 4; i++) {
      int x, y;
      cin >> x >> y;
      p.emplace_back(x, y);
    }
    sort(p.begin(), p.end());
  }
  bool inside(int x, int y) {
    int c1 = p[0].first + p[0].second;
    int c2 = p[3].first + p[3].second;
    int sign1 = x + y - c1;
    int sign2 = x + y - c2;
    if (sign1 * sign2 > 0) return false;
    c1 = p[0].second - p[0].first;
    c2 = p[3].second - p[3].first;
    sign1 = x - y + c1;
    sign2 = x - y + c2;
    if (sign1 * sign2 > 0) return false;
    return true;
  }
};
struct Square2 {
  vector<pair<int, int>> p;
  void read() {
    for (int i = 0; i < 4; i++) {
      int x, y;
      cin >> x >> y;
      p.emplace_back(x, y);
    }
    sort(p.begin(), p.end());
  }
  bool inside(int x, int y) {
    if (x >= p[0].first && x <= p[3].first && y >= p[0].second &&
        y <= p[1].second)
      return true;
    else
      return false;
  }
};
void solve() {
  Square2 s2;
  s2.read();
  Square1 s1;
  s1.read();
  for (int i = -100; i <= 100; i++) {
    for (int j = -100; j <= 100; j++) {
      if (s1.inside(i, j) && s2.inside(i, j)) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  for (int tt = 1; tt <= t; tt++) {
    solve();
  }
}
