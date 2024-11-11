#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > arr, pre;
vector<int> l;
int n, m;
void gen(int loc) {
  if (loc > n) return;
  arr[loc].push_back(0);
  pre[loc].push_back(0);
  int lc = 2 * loc, rc = 2 * loc + 1, l1, r1;
  if (lc <= n) gen(lc);
  if (rc <= n) gen(rc);
  int i = 0, j = 0;
  while (i < arr[lc].size() && j < arr[rc].size()) {
    if ((arr[lc][i] + l[lc]) < (arr[rc][j] + l[rc])) {
      arr[loc].push_back(arr[lc][i] + l[lc]);
      pre[loc].push_back(arr[lc][i] + l[lc]);
      pre[loc][pre[loc].size() - 1] += pre[loc][pre[loc].size() - 2];
      i++;
    } else {
      arr[loc].push_back(arr[rc][j] + l[rc]);
      pre[loc].push_back(arr[rc][j] + l[rc]);
      pre[loc][pre[loc].size() - 1] += pre[loc][pre[loc].size() - 2];
      j++;
    }
  }
  while (i < arr[lc].size()) {
    arr[loc].push_back(arr[lc][i] + l[lc]);
    pre[loc].push_back(arr[lc][i] + l[lc]);
    pre[loc][pre[loc].size() - 1] += pre[loc][pre[loc].size() - 2];
    i++;
  }
  while (j < arr[rc].size()) {
    arr[loc].push_back(arr[rc][j] + l[rc]);
    pre[loc].push_back(arr[rc][j] + l[rc]);
    pre[loc][pre[loc].size() - 1] += pre[loc][pre[loc].size() - 2];
    j++;
  }
}
long long solve(long long idx, long long h) {
  long long ans = 0, len = upper_bound(arr[idx].begin(), arr[idx].end(), h) -
                           arr[idx].begin();
  ans += h * len - pre[idx][len - 1];
  h -= l[idx];
  int prev = idx;
  idx /= 2;
  while ((idx) && h > 0) {
    ans += h;
    if (2 * idx == prev) {
      int ch = 2 * idx + 1;
      if (ch <= n && h > l[ch]) {
        len = upper_bound(arr[idx].begin(), arr[ch].end(), h - l[ch]) -
              arr[ch].begin();
        ans += (h - l[ch]) * len - pre[ch][len - 1];
      }
    } else {
      int ch = 2 * idx;
      if (ch <= n && h > l[ch]) {
        len = upper_bound(arr[idx].begin(), arr[ch].end(), h - l[ch]) -
              arr[ch].begin();
        ans += (h - l[ch]) * len - pre[ch][len - 1];
      }
    }
    h -= l[idx];
    prev = idx;
    idx /= 2;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  l.resize(2 * n + 10);
  arr.resize(2 * n + 10);
  pre.resize(2 * n + 10);
  for (int i = 2; i <= n; i++) {
    cin >> l[i];
  }
  gen(1);
  int x, h;
  for (int i = 0; i < m; i++) {
    cin >> x >> h;
    cout << solve(x, h) << '\n';
  }
  return 0;
}
