#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int> > ans;
  map<int, int> used1;
  for (int i = 0; i <= n; i++) {
    if (min(n, m) - i >= 0 && min(n, m) - i <= m)
      ans.push_back(make_pair(i, min(n, m) - i));
  }
  cout << ans.size() << "\n";
  for (auto it : ans) {
    cout << it.first << " " << it.second << "\n";
  }
}
