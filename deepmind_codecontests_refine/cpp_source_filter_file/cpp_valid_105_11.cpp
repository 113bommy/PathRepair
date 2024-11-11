#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 3003;
int n;
int a[N];
vector<int> v[N];
int dp[N][N];
void solv() {
  cin >> n;
  for (int i = 1; i <= n; ++i) v[i].clear();
  for (int i = 1; i <= n; ++i) cin >> a[i];
  vector<int> aa;
  for (int i = 1; i <= n; ++i) {
    if (a[i] != a[i - 1]) aa.push_back(a[i]);
  }
  n = ((int)(aa).size());
  for (int i = 1; i <= n; ++i) a[i] = aa[i - 1];
  for (int i = 1; i <= n; ++i) v[a[i]].push_back(i);
  for (int d = 1; d <= n; ++d) {
    for (int l = 1; l <= n - d + 1; ++l) {
      int r = l + d - 1;
      dp[l][r] = max(dp[l][r - 1], dp[l + 1][r]);
      for (int i = 0; i < v[a[l]].size(); ++i) {
        int u = v[a[l]][i];
        if (l < u && u <= r) {
          dp[l][r] = max(dp[l][r], dp[l + 1][u - 1] + dp[u + 1][r] + 1);
        }
      }
      for (int i = 0; i < v[a[r]].size(); ++i) {
        int u = v[a[r]][i];
        if (l <= u && u < r) {
          dp[l][r] = max(dp[l][r], dp[l][u - 1] + dp[u + 1][r - 1] + 1);
        }
      }
    }
  }
  cout << n - 1 - dp[1][n] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solv();
  }
  return 0;
}
