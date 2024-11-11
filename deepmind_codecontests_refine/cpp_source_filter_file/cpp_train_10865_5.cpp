#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 9;
vector<int> idx[MAXN];
vector<bool> vis(MAXN);
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    idx[a[i]].push_back(i);
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (vis[a[i]]) continue;
    vis[a[i]] = true;
    for (int j = i + 1; j < n; j++) {
      int ind = i, cur = 1;
      for (int k = 1;; k++) {
        if (k & 1) {
          auto it = upper_bound(idx[a[j]].begin(), idx[a[j]].end(), ind);
          if (it == idx[a[j]].end()) break;
          ind = *it;
          ++cur;
        } else {
          auto it = upper_bound(idx[a[i]].begin(), idx[a[i]].end(), ind);
          if (it == idx[a[i]].end()) break;
          ind = *it;
          ++cur;
        }
      }
      res = max(res, cur);
    }
  }
  cout << res << '\n';
  return 0;
}
