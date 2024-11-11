#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int64_t, int>> a(n);
    for (auto& pair : a) {
      cin >> pair.second;
      pair.first = 0;
      for (int i = 0; i < pair.second; i++) {
        int j;
        cin >> j;
        pair.first = max(pair.first, static_cast<int64_t>(j + 1 - i));
      }
    }
    sort(begin(a), end(a));
    int64_t min_power = a[0].first;
    int64_t power = min_power;
    int64_t beaten = 0;
    for (auto& pair : a) {
      if (pair.first >= power) {
        min_power = pair.first - beaten;
        power = pair.first - beaten;
      }
      power += pair.second;
      beaten += pair.second;
    }
    cout << min_power << endl;
  }
  return 0;
}
