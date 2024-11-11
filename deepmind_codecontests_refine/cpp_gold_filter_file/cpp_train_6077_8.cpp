#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int dp[MAXN], a[MAXN];
vector<int> v[MAXN];
int main() {
  int m, n, i, j, k;
  for (i = 2; i <= 100000; i++) {
    if (v[i].size() == 0) {
      for (j = 1; j * i <= 100000; j++) v[i * j].push_back(i);
    }
  }
  ios::sync_with_stdio(false);
  ;
  cin >> m;
  for (i = 1; i <= m; i++) {
    cin >> a[i];
  }
  for (i = 1; i <= m; i++) {
    int ans = 1;
    for (j = 0; j < v[a[i]].size(); j++) {
      ans = max(ans, dp[v[a[i]][j]] + 1);
    }
    for (j = 0; j < v[a[i]].size(); j++) {
      dp[v[a[i]][j]] = ans;
    }
  }
  int ans = 1;
  for (i = 1; i <= 100000; i++) ans = max(ans, dp[i]);
  cout << ans << endl;
}
