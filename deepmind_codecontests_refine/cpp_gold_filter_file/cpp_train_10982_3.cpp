#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  bool dum = 1;
  vector<int> ans, res;
  int n;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int k = i;
    for (int j = 0; j < ans.size(); ++j) {
      if (k % ans[j] == 0) k /= ans[j];
    }
    if (k != 1) {
      ans.push_back(k);
      res.push_back(i);
    }
  }
  cout << ans.size() << "\n";
  if (ans.size() >= 1) {
    for (int i = 0; i < ans.size(); ++i) cout << res[i] << " ";
    cout << "\n";
  }
  return 0;
}
