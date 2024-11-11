#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int> > ans;
  for (int i = 1; i < n + 1; ++i) {
    ans.push_back(make_pair(i, 1));
  }
  for (int i = 2; i < m + 1; ++i) {
    ans.push_back(make_pair(1, i));
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
