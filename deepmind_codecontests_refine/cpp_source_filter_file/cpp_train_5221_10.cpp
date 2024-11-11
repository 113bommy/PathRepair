#include <bits/stdc++.h>
const int maxn = 2250005;
using namespace std;
map<int, vector<pair<int, int> > > all;
int a[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while (cin >> n) {
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n; ++j) {
        int tmp = a[j] - a[i - 1];
        if (all[tmp].size() && all[tmp].back().second >= i) continue;
        all[tmp].push_back(pair<int, int>(i, j));
      }
    }
    vector<pair<int, int> > ans;
    for (auto it : all) {
      if (it.second.size() > ans.size()) ans = it.second;
    }
    cout << ans.size() << endl;
    for (auto it : ans) {
      cout << it.first << " " << it.second << endl;
    }
  }
  return 0;
}
