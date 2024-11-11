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
    auto lis = [](vector<int> a) {
      vector<int> pre(a.size(), -1);
      vector<pair<int, int>> st(1, {-1345567, -1});
      int p = 0;
      for (int i = 0; i < a.size(); i++) {
        if (a[i] > st.back().first) {
          pre[i] = st.back().second;
          st.emplace_back(a[i], i);
          p = i;
        } else {
          auto it = lower_bound(st.begin(), st.end(), make_pair(a[i], i));
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
        vector<vector<int>> vec;
        for (auto x : a) {
          bool ok = false;
          for (int i = 0; i < vec.size(); i++) {
            if (vec[i].back() > x) {
              vec[i].push_back(x);
              ok = true;
              break;
            }
          }
          if (!ok) {
            vec.push_back(vector<int>(1, x));
          }
        }
        sort(vec.begin(), vec.end(),
             [](const vector<int>& v1, const vector<int>& v2) {
               return v1.back() < v2.back();
             });
        for (auto v : vec) {
          ans.push_back(v);
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
