#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
struct st {
  int n;
  vector<int> t;
  st(int sz) {
    n = sz;
    t = vector<int>(2 * n, -1);
  }
  void upd(int pos, int val) {
    for (t[pos += n] = val; pos > 1; pos >>= 1) {
      t[pos >> 1] = min(t[pos], t[pos ^ 1]);
    }
  }
  int qry(int l, int r) {
    int res = n;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = min(res, t[l++]);
      if (r & 1) res = min(res, t[--r]);
    }
    return res;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int a[n];
  bool all_one = true;
  vector<vector<int>> at(n, vector<int>(1, -1));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    if (a[i] > 0) all_one = false;
    at[a[i]].push_back(i);
  }
  if (all_one) {
    cout << 1 << '\n';
    return 0;
  }
  vector<pair<int, int>> qry;
  for (int i = 0; i < n; i++) {
    at[i].push_back(n);
    if (at.size() == 2) continue;
    for (int j = 1; j < at[i].size(); j++) {
      qry.push_back({at[i][j - 1], at[i][j]});
    }
  }
  sort(qry.begin(), qry.end(), cmp);
  vector<bool> vis(n + 2);
  vis[0] = 1;
  st rmq(n);
  for (int q = 0; q < qry.size(); q++) {
    int l = qry[q].first;
    int r = qry[q].second;
    int cur;
    if (0 <= l && l < n) cur = a[l];
    if (0 <= r && r < n) cur = a[r];
    if (cur) {
      int small = rmq.qry(0, cur);
      if (l < small) vis[cur] = 1;
    }
    if (r < n) rmq.upd(a[r], r);
  }
  vector<bool> avail(n + 1);
  for (int i = 0; i < n; i++) avail[a[i]] = 1;
  for (int i = 0; i <= n; i++) {
    if (!avail[i]) {
      vis[i] = 1;
      break;
    }
  }
  for (int i = 0; i < n + 2; i++) {
    if (!vis[i]) {
      cout << i + 1 << '\n';
      break;
    }
  }
}
