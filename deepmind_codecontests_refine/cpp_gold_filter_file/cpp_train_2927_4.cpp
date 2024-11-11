#include <bits/stdc++.h>
const long long MAX_N = 1500 + 5;
const long long MOD = 1e9 + 7;
using namespace std;
int dp[MAX_N][MAX_N];
int a[MAX_N];
pair<int, int> seg[MAX_N];
vector<int> v1[MAX_N], v2[MAX_N];
int mn[MAX_N];
int d[MAX_N][MAX_N];
int n, s, m, k;
bool check(int x) {
  memset(dp, 0, sizeof dp);
  memset(d, 0, sizeof d);
  for (int i = 1; i <= n; ++i) d[1][i] = (a[i] <= x);
  for (int i = 2; i <= n; ++i)
    for (int j = 1; j <= n - i + 1; ++j)
      d[i][j] = d[i - 1][j] + (a[j + i - 1] <= x);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= s; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (mn[i] > 0)
        dp[i][j] =
            max(dp[i][j], dp[mn[i] - 1][j - 1] + d[i - mn[i] + 1][mn[i]]);
    }
  }
  if (dp[n][m] >= k) return true;
  return false;
}
int main() {
  cin >> n >> s >> m >> k;
  vector<int> v;
  for (int i = 1; i <= n; ++i) cin >> a[i], v.push_back(a[i]);
  sort(v.begin(), v.end());
  for (int i = 1; i <= s; ++i) {
    cin >> seg[i].first >> seg[i].second;
    v1[seg[i].first].push_back(i);
    v2[seg[i].second].push_back(i);
  }
  multiset<int> ms;
  for (int i = 1; i <= n; ++i) {
    for (auto x : v1[i]) ms.insert(i);
    if (!ms.size())
      mn[i] = -1;
    else
      mn[i] = *ms.begin();
    for (auto x : v2[i]) ms.erase(ms.find(seg[x].first));
  }
  int l = -1;
  int r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (check(v[mid]))
      r = mid;
    else
      l = mid;
  }
  if (r == n)
    cout << -1;
  else
    cout << v[r];
  return 0;
}
