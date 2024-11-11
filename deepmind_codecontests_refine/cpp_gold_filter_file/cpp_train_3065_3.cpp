#include <bits/stdc++.h>
using namespace std;
int n, m, s, e;
const int l = 1000005;
int a[l], b[l];
vector<int> v[l];
int dp[305];
int main() {
  scanf("%d %d %d %d", &n, &m, &s, &e);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < m; i++) scanf("%d", b + i), v[b[i]].push_back(i);
  int t = min(s / e, min(n, m));
  int ans = -1;
  memset(dp, 0x7f, sizeof dp);
  dp[0] = -1;
  for (int i = 0; i < n; i++) {
    if (v[a[i]].size() == 0) continue;
    for (int j = t; j >= 0; j--) {
      int idx =
          upper_bound(v[a[i]].begin(), v[a[i]].end(), dp[j]) - v[a[i]].begin();
      if (idx == v[a[i]].size()) continue;
      dp[j + 1] = min(dp[j + 1], v[a[i]][idx]);
      if ((j + 1) * e + i + v[a[i]][idx] + 2 <= s) ans = max(ans, j + 1);
    }
  }
  cout << max(ans, 0) << endl;
  return 0;
}
