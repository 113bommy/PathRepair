#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int> > a;
int ans = 0;
int lft(int i, int u) {
  int l = 0, r = a[i].size() - 1, x;
  while (l < r) {
    x = (l + r + 1) >> 1;
    if (a[i][x] > u)
      r = x - 1;
    else
      l = x;
  }
  if (a[i][r] > u) return 0;
  return r + 1;
}
int rght(int i, int u) {
  int l = 0, r = a[i].size() - 1, x;
  while (l < r) {
    x = (l + r) >> 1;
    if (a[i][x] < u)
      l = x + 1;
    else
      r = x;
  }
  if (a[i][r] < u) return 0;
  return a[i].size() - r;
}
int main() {
  cin >> n;
  a.resize(n + 2);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    a[i + 1].resize(k);
    for (int j = 0; j < k; ++j) cin >> a[i + 1][j];
    sort(a[i + 1].begin(), a[i + 1].end());
  }
  for (int i = 0; i < a[n - 1].size(); ++i) a[0].push_back(a[n][i]);
  for (int i = 0; i < a[1].size(); ++i) a[n + 1].push_back(a[1][i]);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < a[i].size() - 1; ++j) {
      int u = a[i][j], v = a[i][j + 1];
      int prev = a[i - 1].size() - lft(i - 1, u) - rght(i - 1, v);
      int nxt = a[i + 1].size() - lft(i + 1, u) - rght(i + 1, v);
      ans += prev != nxt;
    }
  }
  cout << ans << endl;
  return 0;
}
