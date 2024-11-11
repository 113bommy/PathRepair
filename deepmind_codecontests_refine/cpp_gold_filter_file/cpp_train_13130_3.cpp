#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
      events.emplace_back(l[i], -i);
      events.emplace_back(r[i], 1);
    }
    sort(events.begin(), events.end());
    int active = 0;
    vector<int> res(n);
    int cur = 0;
    for (auto& [x, y] : events) {
      if (y == 1)
        --active;
      else {
        if (active == 0)
          res[-y] = ++cur;
        else
          res[-y] = cur;
        ++active;
      }
    }
    if (cur < 2)
      cout << "-1\n";
    else {
      for (int p : res) cout << (p == 1 ? 1 : 2) << ' ';
      cout << '\n';
    }
  }
  return 0;
}
