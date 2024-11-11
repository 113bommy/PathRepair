#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  cin >> m;
  vector<pair<int, int> > a;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    a.push_back(make_pair(x, y));
  }
  int ret = 0;
  for (int i = 1; i < m; i++) {
    int h = abs(a[i].second - a[i - 1].second);
    int d = a[i].first - a[i - 1].first;
    if (h > d) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
    ret = max(ret, max(a[i].second, a[i - 1].second) + (d - h) / 2);
  }
  ret = max(ret, a[0].first + a[0].second);
  ret = max(ret, n - a[m - 1].first + a[m - 1].second);
  cout << ret << endl;
  return 0;
}
