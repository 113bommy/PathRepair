#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
int cur = 0, n, m;
bool cmp(int i, int j) {
  return a[i][cur] - a[i][n - 1] > a[j][cur] - a[j][n - 1];
}
void init() {}
void solve() {
  cin >> n >> m;
  a.resize(m, vector<int>(n));
  for (__typeof(m) i = (0) - ((0) > (m)); i != (m) - ((0) > (m));
       i += 1 - 2 * ((0) > (m)))
    for (auto &it : a[i]) cin >> it;
  vector<int> ans, temp, order(m);
  for (__typeof(m) i = (0) - ((0) > (m)); i != (m) - ((0) > (m));
       i += 1 - 2 * ((0) > (m)))
    ans.push_back(i + 1);
  while (cur < n - 1) {
    for (__typeof(m) i = (0) - ((0) > (m)); i != (m) - ((0) > (m));
         i += 1 - 2 * ((0) > (m)))
      order[i] = i;
    sort((order).begin(), (order).end(), cmp);
    temp.clear();
    int sum = 0;
    for (auto it : order) {
      if (sum + a[it][cur] - a[it][n - 1] >= 0)
        sum += a[it][cur] - a[it][n - 1];
      else
        temp.push_back(it + 1);
    }
    if (temp.size() < ans.size()) ans = temp;
    cur++;
  }
  cout << ans.size() << endl;
  {
    for (auto it : ans) cout << it << " ";
    cout << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  init();
  while (t--) {
    solve();
  }
  return 0;
}
