#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > d;
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int day, hd;
    cin >> day >> hd;
    d.push_back(make_pair(day, hd));
  }
  int ma = 0;
  for (int i = 0; i < m - 1; i++) {
    int diff_day = d[i + 1].first - d[i].first;
    int diff = d[i + 1].second - d[i].second;
    if (diff_day < abs(diff)) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
    if (diff_day > 1) {
      if (diff >= 0) {
        ma = max(ma, d[i].second + diff + ((diff_day - diff) / 2));
      } else {
        ma = max(ma, d[i].second + ((diff_day - abs(diff)) / 2));
      }
    }
    ma = max(ma, d[i].second);
  }
  ma = max(ma, n - d[m - 1].first + d[m - 1].second);
  ma = max(ma, d[0].first + d[0].second - 1);
  cout << ma;
}
