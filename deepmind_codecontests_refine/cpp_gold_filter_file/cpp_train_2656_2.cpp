#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int> > tr, v;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    if (b) {
      tr.push_back(make_pair(a, i));
    } else {
      v.push_back(make_pair(a, i));
    }
  }
  sort(v.begin(), v.end());
  sort(tr.begin(), tr.end());
  int ptr = 0;
  int cnt = 1;
  vector<pair<int, int> > ans(m);
  for (int i = 0; i < tr.size(); ++i) {
    ans[tr[i].second] = make_pair(0, cnt);
    cnt++;
  }
  int q = v.size();
  for (int i = 1; i < tr.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      if (ptr == v.size()) break;
      if (max(tr[i].first, tr[j].first) <= v[ptr].first) {
        int ind = v[ptr].second;
        ans[ind] =
            make_pair(ans[tr[i].second].second, ans[tr[j].second].second);
        ptr++;
      } else {
        cout << -1;
        return 0;
      }
    }
    if (ptr == v.size()) break;
  }
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
  }
  return 0;
}
