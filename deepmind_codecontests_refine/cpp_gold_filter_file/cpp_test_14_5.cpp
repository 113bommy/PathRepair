#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
      int id_max = (int)v.size() - 1;
      int mx = INT_MIN;
      for (int j = (int)v.size() - 1; j >= 0; j--) {
        if (mx < v[j]) {
          mx = v[j];
          id_max = j;
        }
      }
      if (id_max + 1 < (int)v.size()) {
        vector<int> res;
        res.emplace_back(id_max + 1);
        res.emplace_back((int)v.size());
        ans.emplace_back(res);
        v.erase(v.begin() + id_max);
      } else if (id_max + 1 == (int)v.size()) {
        v.erase(v.begin() + id_max);
      }
    }
    cout << (int)ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); i++) {
      cout << ans[i][0] << " " << ans[i][1] << " " << 1 << "\n";
    }
  }
  return 0;
}
