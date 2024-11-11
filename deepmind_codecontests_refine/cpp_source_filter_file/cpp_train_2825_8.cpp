#include <bits/stdc++.h>
using namespace std;
void prepare() {}
pair<int, int> mini(pair<int, int> a, pair<int, int> b) {
  if (a.first + a.second > b.first + b.second) return b;
  if (a.first + a.second < b.first + b.second) return a;
  if (a.first < b.first) return a;
  return b;
}
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int> > v(n + 1);
  if (4 < n + 1) v[4] = make_pair(1, 0);
  if (7 < n + 1) v[7] = make_pair(0, 1);
  for (int i = 8; i < n + 1; ++i) {
    pair<int, int> p1, p2;
    p1 = p2 = make_pair(0, 0);
    if (v[i - 4] != p1) {
      p1 = v[i - 4];
      p1.first++;
    }
    if (v[i - 7] != p1) {
      p2 = v[i - 7];
      p2.second++;
    }
    if (p1 != make_pair(0, 0) && p2 != make_pair(0, 0)) {
      v[i] = mini(p1, p2);
    } else if (p1 != make_pair(0, 0))
      v[i] = p1;
    else
      v[i] = p2;
  }
  if (v[n] == make_pair(0, 0))
    cout << -1;
  else {
    for (int i = 0; i < (v[n].first); ++i) cout << 4;
    for (int i = 0; i < (v[n].second); ++i) cout << 7;
  }
}
int main() {
  prepare();
  solve();
  return 0;
}
