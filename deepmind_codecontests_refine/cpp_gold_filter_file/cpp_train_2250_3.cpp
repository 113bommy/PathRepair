#include <bits/stdc++.h>
using namespace std;
bool check(int h, int k, int r, int x, int y) {
  if ((x - h) * (x - h) + (y - k) * (y - k) - (r * r) <= 0)
    return (true);
  else
    return (false);
}
void print_vector(vector<int> v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
}
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> c;
  map<pair<int, int>, int> mp;
  for (int i = 0; i < n; i++) {
    int cen, rad;
    cin >> cen >> rad;
    c.push_back({cen - rad, cen + rad});
    mp[{cen - rad, cen + rad}] = i;
  }
  sort(c.begin(), c.end());
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) {
    l[i] = c[i].first;
    r[i] = c[i].second;
  }
  vector<int> ans(n, -1);
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    int idx = lower_bound(r.begin(), r.end(), x) - r.begin();
    if (idx == n || x < l[idx]) continue;
    int orig_idx = 0;
    if (check((l[idx] + r[idx]) / 2, 0, (r[idx] - l[idx]) / 2, x, y) == true) {
      orig_idx = mp[{l[idx], r[idx]}];
      if (ans[orig_idx] == -1) ans[orig_idx] = i;
    }
    if (x == r[idx] && r[idx] == l[idx + 1] && (idx + 1) <= (n - 1) && y == 0) {
      orig_idx = mp[{l[idx + 1], r[idx + 1]}];
      if (ans[orig_idx] == -1) ans[orig_idx] = i;
    }
  }
  int cnt = 0;
  for (int i = 0; i < ans.size(); i++)
    if (ans[i] != -1) cnt++;
  cout << cnt << '\n';
  print_vector(ans);
  return;
}
int main() {
  int t = 1;
  while (t--) solve();
  return (0);
}
