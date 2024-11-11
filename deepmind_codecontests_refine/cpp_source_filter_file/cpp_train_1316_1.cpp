#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, nl, ne, v;
  cin >> n >> m >> nl >> ne >> v;
  vector<int> stairs(nl), elevators(ne);
  for (auto& x : stairs) cin >> x;
  for (auto& x : elevators) cin >> x;
  int t;
  cin >> t;
  for (int i = 0, x1, y1, x2, y2; i < t; ++i) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2)
      cout << abs(x1 - x2) << '\n';
    else {
      int rez = 1e9;
      auto it1 = lower_bound(begin(stairs), end(stairs), y1);
      auto it2 =
          lower_bound(stairs.rbegin(), stairs.rend(), y1, greater<int>());
      auto it3 = lower_bound(begin(elevators), end(elevators), y1);
      auto it4 =
          lower_bound(elevators.rbegin(), elevators.rend(), y1, greater<int>());
      if (it1 != end(stairs)) {
        rez = min(rez, abs(x1 - x2) + abs(y1 - *it1) + abs(*it1 - y2));
      }
      if (it2 != stairs.rend()) {
        rez = min(rez, abs(x1 - x2) + abs(y1 - *it2) + abs(*it2 - y2));
      }
      if (it3 != end(elevators)) {
        rez = min(rez, (abs(x1 - x2) + v - 1) / (v) + abs(y1 - *it3) +
                           abs(*it3 - y2));
      }
      if (it4 != elevators.rend()) {
        rez = min(rez, (abs(x1 - x2) + v - 1) / (v) + abs(y1 - *it4) +
                           abs(*it4 - y2));
      }
      cout << rez << '\n';
    }
  }
  return 0;
}
