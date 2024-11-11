#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int> > points;
bool inside(pair<int, int>& a, pair<int, int>& b, pair<int, int>& c) {
  if ((a.first == b.first || a.first == c.first) && a.second >= b.second &&
      a.second <= c.second)
    return true;
  if ((a.second == b.second || a.second == c.second) && a.first >= b.first &&
      a.first <= c.first)
    return true;
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int cntx[60] = {0}, cnty[60] = {0};
  cin >> n;
  int x, y;
  for (int i = int(0); i < int(4 * n + 1); i++) {
    cin >> x >> y;
    points.push_back(pair<int, int>(x, y));
    cntx[x]++;
    cnty[y]++;
  }
  pair<int, int> bl = pair<int, int>(100, 100), tr = pair<int, int>(0, 0);
  for (int i = int(0); i < int(60); i++) {
    if (cntx[i] > 2) {
      bl.first = min(bl.first, i);
      tr.first = max(tr.first, i);
    }
    if (cnty[i] > 2) {
      bl.second = min(bl.second, i);
      tr.second = max(tr.second, i);
    }
  }
  for (int i = int(0); i < int(4 * n + 1); i++) {
    if (!inside(points[i], bl, tr)) {
      cout << points[i].first << " " << points[i].second << endl;
      return 0;
    }
  }
  return 0;
}
