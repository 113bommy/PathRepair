#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > v(n, vector<int>(m));
  for (int i = 0; i < m; ++i) {
    for (int j = n - 1; j > -1; --j) {
      cin >> v[j][i];
    }
  }
  int mn = 100, sum = 0;
  for (int i = 0; i < m; ++i) sum += v[0][i];
  vector<int> ans(m);
  for (int i = 0; i < m; ++i) ans[i] = i + 1;
  for (int i = 1; i < n; ++i) {
    int k = 0, sumi = 0, summ = sum;
    vector<pair<int, int> > a(m);
    vector<int> el;
    for (int j = 0; j < m; ++j)
      a[j].first = v[0][j] - v[i][j], a[j].second = j, sumi += v[i][j];
    if (sumi >= sum) {
      mn = 0, ans.clear();
      break;
    }
    sort(a.rbegin(), a.rend());
    for (int j = 0; j < m; ++j) {
      el.push_back(a[j].second);
      sumi -= v[i][a[j].second], summ -= v[0][a[j].second];
      if (sumi >= summ) break;
    }
    if (el.size() < mn) mn = el.size(), ans = el;
  }
  cout << mn << '\n';
  for (auto i : ans) cout << i + 1 << ' ';
  return 0;
}
