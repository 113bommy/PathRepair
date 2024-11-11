#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, a, b;
  cin >> x >> y >> a >> b;
  vector<pair<int, int> > ans;
  for (int i = a; i <= x; i++) {
    for (int j = b; j <= y; j++) {
      if (j >= i) continue;
      ans.push_back(make_pair(i, j));
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].first << ' ' << ans[i].second << endl;
  return 0;
}
