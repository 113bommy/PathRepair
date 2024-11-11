#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  vector<vector<pair<int, int> > > ml(200010);
  vector<int> d;
  for (int i = 0; i < n; i++) {
    int l, r, c;
    scanf("%d %d %d", &l, &r, &c);
    ml[r - l + 1].push_back({l, c});
  }
  for (int i = 0; i <= x; i++) {
    sort(ml[i].begin(), ml[i].end());
  }
  int ans = 0x7fffffff;
  for (int i = 1; i < x; i++) {
    int j = 0, mn = 0x7fffffff;
    for (int k = 0; k < ml[i].size(); k++) {
      for (; j < ml[x - i].size(); j++) {
        if (ml[x - i][j].first + x - i - 1 < ml[i][k].first) {
          if (mn > ml[x - i][j].second) {
            mn = ml[x - i][j].second;
          }
        } else {
          break;
        }
      }
      if (mn != 0x7fffffff && ans > mn + ml[i][k].second) {
        ans = mn + ml[i][k].second;
      }
    }
  }
  cout << (ans == 0x7fffffff ? -1 : ans) << endl;
}
