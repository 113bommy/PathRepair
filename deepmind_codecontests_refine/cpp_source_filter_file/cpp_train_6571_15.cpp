#include <bits/stdc++.h>
using namespace std;
const long long MAX = 5e2 + 5;
const long long INF = 1e18;
const long long mod = 1e8;
int main() {
  vector<pair<int, int>> st, st1, st2;
  int x0, y0, x1, y1, x2, y2, i, j, k, l, p, q;
  cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
  st1.push_back({x0, y0});
  st1.push_back({x1, y1});
  st1.push_back({x2, y2});
  st2.push_back({y0, x0});
  st2.push_back({y1, x1});
  st2.push_back({y2, x2});
  if ((x0 == x1 and x1 == x2) or (y0 == y1 and y1 == y2)) {
    if (x0 == x1 and x1 == x2) {
      p = min(y0, min(y1, y2));
      q = max(y0, max(y1, y2));
      for (i = p; i <= q; i++) st.push_back({x0, i});
    }
    if (y0 == y1 and y1 == y2) {
      p = min(x0, min(x1, x2));
      q = max(x0, max(x1, x2));
      for (i = p; i <= q; i++) st.push_back({x0, i});
    }
    cout << st.size() << "\n";
    for (auto z : st) cout << z.first << " " << z.second << "\n";
    return 0;
  }
  sort(st1.begin(), st1.end());
  sort(st2.begin(), st2.end());
  p = st1[0].first;
  q = st1[2].first;
  for (i = p; i <= q; i++) st.push_back({i, st2[1].first});
  p = st2[0].first;
  q = st2[1].first;
  for (i = p; i < q; i++) st.push_back({st2[0].second, i});
  p = st2[1].first;
  q = st2[2].first;
  for (i = q; i > p; i--) st.push_back({st2[2].second, i});
  cout << st.size() << "\n";
  for (auto z : st) cout << z.first << " " << z.second << "\n";
}
