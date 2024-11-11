#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, i;
  cin >> n;
  vector<long long> ans;
  vector<pair<pair<long long, long long>, long long> > v(n + 1);
  for (i = 1; i <= n; i++) {
    cin >> v[i].first.first;
    v[i].second = i;
  }
  for (i = 1; i <= n; i++) {
    cin >> v[i].first.second;
  }
  sort(v.begin() + 1, v.end());
  ans.push_back(v[n].second);
  if (n % 2 == 0) {
    ans.push_back(v[1].second);
  }
  if (n % 2 == 0)
    for (i = 2; i <= n - 2; i += 2) {
      if (v[i].first.second > v[i + 1].first.second) {
        ans.push_back(v[i].second);
      } else {
        ans.push_back(v[i + 1].second);
      }
    }
  else
    for (i = 1; i <= n - 2; i += 2) {
      if (v[i].first.second > v[i + 1].first.second) {
        ans.push_back(v[i].second);
      } else {
        ans.push_back(v[i + 1].second);
      }
    }
  cout << ans.size() << '\n';
  for (i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
