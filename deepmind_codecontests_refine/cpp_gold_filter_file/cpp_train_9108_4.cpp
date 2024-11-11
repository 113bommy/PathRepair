#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  vector<pair<int, int> > v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  if (n == 1) {
    cout << -1 << endl;
  } else if (n == 2) {
    if (v[0].first == v[1].first || v[0].second == v[1].second) {
      cout << "-1" << endl;
    } else {
      cout << abs((v[0].first - v[1].first) * (v[0].second - v[1].second))
           << endl;
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (abs(v[i].first - v[j].first) > 0) {
          x = abs(v[i].first - v[j].first);
        }
        if (abs(v[i].second - v[j].second) > 0) {
          y = abs(v[i].second - v[j].second);
        }
      }
    }
    cout << x * y << endl;
  }
  return 0;
}
