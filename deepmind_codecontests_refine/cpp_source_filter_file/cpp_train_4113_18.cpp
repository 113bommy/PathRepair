#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, pair<int, int>>> v;
  for (int i = 1; i < 2 * n; ++i)
    for (int j = 0; j < i; ++j) {
      int a;
      cin >> a;
      v.push_back({a, {i, j}});
    }
  static int ans[400];
  fill_n(ans, 400, -1);
  sort(v.begin(), v.end(), greater<pair<int, pair<int, int>>>());
  for (int i = 0; i < v.size(); ++i)
    if (ans[v[i].second.first] == -1 && ans[v[i].second.second] == -1) {
      ans[v[i].second.first] = v[i].second.second;
      ans[v[i].second.second] = v[i].second.first;
    }
  for (int i = 0; i < 2 * n; ++i) cout << ans[i] + 1 << ' ';
  cout << '\n';
  return 0;
}
