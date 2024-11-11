#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200001;
int l[MAXN], r[MAXN];
struct seg {
  int l, r, idx;
  bool operator<(const seg se) const {
    if (r != se.r) return r < se.r;
    return idx < se.idx;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  set<seg> st;
  vector<pair<int, int> > rr[MAXN];
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    rr[n - a + 1].push_back({b, i});
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < rr[i].size(); j++) {
      st.insert({i, rr[i][j].first, rr[i][j].second});
    }
    while (st.size() && st.begin()->r < i) st.erase(st.begin());
    if (st.size()) {
      ans.push_back(st.begin()->idx);
      st.erase(st.begin());
    }
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
  return 0;
}
