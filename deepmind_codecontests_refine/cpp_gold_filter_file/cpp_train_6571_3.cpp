#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<pair<int, int>> a(3), ans;
  for (int i = 0; i < 3; i++) {
    int x, y;
    cin >> x >> y;
    a[i] = {x, y};
  }
  sort(a.begin(), a.end());
  if ((a[0].second - a[1].second) * (a[2].second - a[1].second) > 0) {
    int ind = a[1].second;
    for (int i = a[1].second; i != a[2].second && i != a[0].second;
         a[1].second > a[0].second ? i-- : i++) {
      ans.push_back({a[1].first, i});
      ind = i;
    }
    int lst = a[0].second;
    for (int j = a[0].second; j != ind; a[0].second < a[1].second ? j++ : j--) {
      ans.push_back({a[0].first, j});
      lst = j;
    }
    for (int j = a[2].second; j != ind; a[2].second < a[1].second ? j++ : j--) {
      ans.push_back({a[2].first, j});
    }
    for (int i = a[0].first + 1; i < a[2].first; i++) {
      ans.push_back({i, lst});
    }
  } else {
    int ind = a[1].second;
    for (int j = a[0].second; j != ind; a[0].second < a[1].second ? j++ : j--) {
      ans.push_back({a[0].first, j});
    }
    for (int j = a[2].second; j != ind; a[2].second < a[1].second ? j++ : j--) {
      ans.push_back({a[2].first, j});
    }
    for (int i = a[0].first; i <= a[2].first; i++) {
      ans.push_back({i, ind});
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << ' ' << ans[i].second << endl;
  }
}
