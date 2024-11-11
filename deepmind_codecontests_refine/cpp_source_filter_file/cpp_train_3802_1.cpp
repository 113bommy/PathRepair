#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const int mod = 1e9 + 7;
map<int, set<int> > p;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    p[a[i]].insert(i);
  }
  set<int> st;
  int l = -1, r = 0;
  vector<pair<int, int> > ans;
  for (int i = 0; i < n; i++) {
    int cur = *p[a[i]].begin();
    p[a[i]].erase(p[a[i]].begin());
    if (st.find(a[i]) != st.end()) {
      r = cur;
      int f = 0;
      for (int j = i + 1; j < n; j++) {
        if (p[a[i]].size() > 1) {
          f = 1;
          break;
        }
      }
      if (f == 0) r = n - 1;
      ans.push_back({l, r});
      l = -1;
      r = 0;
      while (st.size()) st.erase(st.begin());
      continue;
    }
    if (l == -1) l = cur;
    st.insert(a[i]);
  }
  if (!ans.size()) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
  }
}
