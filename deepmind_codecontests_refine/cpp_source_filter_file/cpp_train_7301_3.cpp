#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, k, n, s;
  cin >> m >> k >> n >> s;
  vector<int> a(m);
  vector<int> need(500005);
  for (auto &el : a) cin >> el;
  for (int i = 0, j; i < s; i++) cin >> j, need[j]++;
  vector<int> curr(500005);
  int cnt = 0;
  int need_cnt = 0;
  for (int i = 0; i < 500005; i++)
    if (need[i]) need_cnt++;
  int l = 0, r = -1, min_l = -1, min_r = -1, min_v = m + 1;
  while (l < m) {
    while (r + 1 < m && cnt < need_cnt) {
      r++;
      curr[a[r]]++;
      if (curr[a[r]] == need[a[r]]) cnt++;
    }
    if (cnt >= need_cnt && min_v > r - l + 1)
      min_l = l, min_r = r, min_v = r - l + 1;
    for (int i = 0; l < m && i < k; i++) {
      if (curr[a[r]] == need[a[r]]) cnt--;
      curr[a[l]]--;
      l++;
    }
  }
  if (min_l == -1) {
    cout << -1;
    return 0;
  }
  curr.assign(500005, 0);
  vector<int> ans;
  cnt = 0;
  for (int i = min_l; i <= min_r; i++) curr[a[i]]++, cnt++;
  for (int i = min_l; i <= min_r && cnt > k; i++) {
    if (curr[a[i]] > need[a[i]]) ans.push_back(i + 1), curr[a[i]]--, cnt--;
  }
  if (cnt > k || n * k > m - (min_r - min_l + 1 - cnt)) {
    cout << -1;
    return 0;
  }
  cout << ans.size() << '\n';
  for (auto &el : ans) cout << el << ' ';
  return 0;
}
