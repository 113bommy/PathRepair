#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<set<int>> seg;
    for (int i = 0; i < n - 1; i++) {
      int k;
      cin >> k;
      set<int> tmp;
      for (int j = 0; j < k; j++) {
        int cur;
        cin >> cur;
        tmp.insert(cur);
      }
      seg.push_back(tmp);
    }
    for (int st = 1; st <= n; st++) {
      vector<set<int>> p = seg;
      vector<int> ans;
      for (auto &x : p) {
        if (x.count(st)) {
          x.erase(st);
        }
      }
      ans.push_back(st);
      bool flag = true;
      for (int i = 0; i < n - 1; i++) {
        vector<int> tmp;
        for (auto &x : p) {
          if (x.size() == 1) {
            tmp.push_back(*x.begin());
          }
        }
        if (tmp.size() != 1) {
          flag = false;
          break;
        }
        ans.push_back(tmp[0]);
        for (auto &x : p) {
          if (x.count(tmp[0])) {
            x.erase(tmp[0]);
          }
        }
      }
      set<set<int>> all;
      for (auto x : seg) all.insert(x);
      if (flag) {
        for (int l = 0; l < n - 1; l++) {
          set<int> tmp;
          tmp.insert(ans[l]);
          for (int r = l + 1; r < n; r++) {
            tmp.insert(ans[r]);
            if (all.count(tmp)) all.erase(tmp);
          }
        }
      }
      if (all.size() == 0) {
        for (auto x : ans) cout << x << " ";
        cout << '\n';
        break;
      }
    }
  }
  return 0;
}
