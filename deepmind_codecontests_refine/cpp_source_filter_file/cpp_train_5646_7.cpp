#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int mxn = 1002;
int n, m, k, w;
string second;
pair<int, int> a[mxn * mxn];
long long first[mxn], dp[mxn];
int lp[mxn][mxn], it[mxn][mxn];
long long sol(int x) {
  for (int i = 0; i < n; i++) {
    first[i] = i, dp[i] = 0;
    while (first[i] < n && it[i][first[i]] < x) first[i]++;
  }
  dp[n] = 1;
  for (int i = 0; i < m; i++) {
    for (int j = n - 1; ~j; j--) dp[j] = min(inf, dp[j] + dp[j + 1]);
    for (int j = 0; j < n; j++) dp[j] = dp[first[j] + 1];
    dp[n] = 0;
  }
  return dp[0];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k >> second;
  for (int i = n - 1; ~i; i--)
    for (int j = n - 1; ~j; j--) {
      if (i <= j) a[w++] = {i, j};
      lp[i][j] = (second[i] == second[j]) * (lp[i + 1][j + 1] + 1);
    }
  sort(a, a + w, [&](pair<int, int> x, pair<int, int> y) {
    int p = x.first + lp[x.first][y.first], q = y.first + lp[x.first][y.first];
    return p > x.second || q > y.second
               ? x.second - x.first < y.second - y.first
               : second[p] < second[q];
  });
  for (int i = 0; i < w; i++) it[a[i].first][a[i].second] = i;
  int l = 0, r = w;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (sol(mid) >= k)
      l = mid;
    else
      r = mid;
  }
  for (int i = a[l].first; i <= a[l].second; i++) cout << second[i];
  cout << '\n';
  return 0;
}
