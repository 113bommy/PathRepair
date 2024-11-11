#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, x;
  cin >> n >> x;
  vector<pair<int, pair<int, int> > > saveX, saveY;
  int xx, y, cost;
  for (int i = 0; i < n; i++) {
    cin >> xx >> y >> cost;
    saveX.push_back(make_pair(xx, pair<int, int>(y - xx + 1, cost)));
    saveY.push_back(make_pair(y, pair<int, int>(y - xx + 1, cost)));
  }
  sort(saveX.begin(), saveX.end());
  sort(saveY.begin(), saveY.end());
  int ind1 = 0;
  map<int, int> m1;
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    while (ind1 < n) {
      if (saveY[ind1].first < saveX[i].first) {
        if (m1.find(saveY[ind1].second.first) == m1.end()) {
          m1[saveY[ind1].second.first] = saveY[ind1].second.second;
        } else {
          m1[saveY[ind1].second.first] =
              min(m1[saveY[ind1].second.first], saveY[ind1].second.second);
        }
        ind1++;
      } else
        break;
    }
    int dist = saveX[i].second.first;
    int sDist = x - dist;
    if (m1.find(sDist) != m1.end()) {
      ans = min(ans, m1[sDist] + saveX[i].second.second);
    }
  }
  if (ans == INT_MAX) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
