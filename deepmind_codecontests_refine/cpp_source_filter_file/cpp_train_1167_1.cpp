#include <bits/stdc++.h>
using namespace std;
bool sortorder(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first != b.first) return a.first < b.first;
  return a.second < b.second;
}
void solve() {
  vector<pair<int, int> > v;
  int n, i, x, y;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  sort(v.begin(), v.end(), sortorder);
  string res = "";
  x = v[0].first;
  y = v[0].second;
  res.append(x, 'R');
  res.append(y, 'U');
  for (i = 1; i < n; i++) {
    x = v[i].first - v[i - 1].first;
    y = v[i].second - v[i - 1].second;
    if (x > 0 && y > 0) {
      res.append(x, 'R');
      res.append(y, 'U');
    } else {
      cout << "NO";
      return;
    }
  }
  cout << "YES" << endl;
  cout << res;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
