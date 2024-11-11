#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> ans;
    vector<vector<int>> af(a.size());
    auto lis = [&](vector<int> a) {
      vector<int> pre(a.size(), -1);
      af.clear();
      vector<pair<int, int>> st(1, {-1345567, -1});
      int p = 0;
      for (int i = 0; i < a.size(); i++) {
        if (a[i] > st.back().first) {
          pre[i] = st.back().second;
          st.emplace_back(a[i], i);
          af.push_back(vector<int>(1, i));
          p = i;
        } else {
          auto it = lower_bound(st.begin(), st.end(), make_pair(a[i], i));
          af[it - st.begin() - 1].push_back(i);
          *it = {a[i], i};
          pre[i] = (it - 1)->second;
        }
      }
      vector<int> ret;
      for (; p != -1; p = pre[p]) {
        ret.push_back(p);
      }
      reverse(ret.begin(), ret.end());
      return ret;
    };
    for (; !a.empty();) {
      auto v1 = lis(a);
      int k = 0;
      while (a.size() >= k * (k + 1) / 2) k++;
      if (v1.size() >= k) {
        ans.push_back(vector<int>());
        vector<bool> vis(a.size());
        for (auto x : v1) {
          ans.back().push_back(a[x]);
          vis[x] = true;
        }
        vector<int> b;
        for (int i = 0; i < a.size(); i++) {
          if (!vis[i]) b.push_back(a[i]);
        }
        a = b;
      } else {
        for (auto vec : af) {
          ans.push_back(vector<int>());
          for (auto x : vec) {
            ans.back().push_back(a[x]);
          }
        }
        break;
      }
    }
    cout << ans.size() << endl;
    for (auto vec : ans) {
      cout << vec.size();
      for (auto x : vec) {
        cout << " " << x;
      }
      cout << endl;
    }
  }
  return 0;
}
