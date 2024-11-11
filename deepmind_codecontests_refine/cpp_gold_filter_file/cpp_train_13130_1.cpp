#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int tt;
  cin >> tt;
  for (int t = 0; t < tt; t++) {
    int n;
    cin >> n;
    vector<pair<int, int>> otr(n);
    vector<pair<pair<int, int>, int>> for_sort;
    vector<int> ans(n, 2);
    for (int i = 0; i < n; i++) {
      cin >> otr[i].first >> otr[i].second;
      for_sort.push_back({otr[i], i});
    }
    sort(for_sort.begin(), for_sort.end());
    int fn = for_sort[0].first.second;
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (fn >= for_sort[i].first.first) {
        fn = max(fn, for_sort[i].first.second);
        continue;
      }
      for (int j = i - 1; j >= 0; j--) {
        ans[for_sort[j].second] = 1;
      }
      flag = false;
      break;
    }
    if (flag) {
      cout << -1 << '\n';
      continue;
    }
    for (auto x : ans) cout << x << " ";
    cout << '\n';
  }
}
