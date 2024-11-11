#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, up, low, lef, rig, p1, p2;
  cin >> n;
  vector<pair<int, int>> vs;
  for (int i = 1; i <= n; i++) {
    cin >> p1 >> p2;
    vs.push_back(make_pair(p1, p2));
  }
  p1 = 0;
  for (int i = 0; i < n; i++) {
    up = 0, low = 0, lef = 0, rig = 0, rig = 0;
    for (int j = 0; j < n; j++) {
      if ((vs[i].first > vs[j].first) && (vs[i].second == vs[j].second)) {
        rig++;
      } else if ((vs[i].first < vs[j].first) &&
                 (vs[i].second == vs[j].second)) {
        lef++;
      } else if ((vs[i].first == vs[j].first) &&
                 (vs[i].second < vs[j].second)) {
        low++;
      } else if ((vs[i].first == vs[j].first) &&
                 (vs[i].second > vs[j].second)) {
        up++;
      }
    }
    if (low >= 1 && up >= 1 && rig >= 1 && rig >= 1) {
      p1++;
    }
  }
  cout << p1;
}
