#include <bits/stdc++.h>
using namespace std;
int k;
long long maxans = 0;
vector<vector<int>> allv;
vector<long long> sum;
void solve(vector<long long> &dp, int l, int r) {
  if (l == r) {
    int a = 0;
    for (int i = 0; i <= min((int)allv[l].size(), k); i++) {
      maxans = max(maxans, dp[k - i] + a);
      if (i < min((int)allv[l].size(), k)) a += allv[l][i];
    }
    return;
  }
  vector<long long> dp2 = dp;
  int m = (l + r) / 2;
  int l1 = l, r1 = m, l2 = m + 1, r2 = r;
  for (int i = l1; i <= r1; i++) {
    for (int j = k; j >= allv[i].size(); j--)
      dp2[j] = max(dp2[j], dp2[j - allv[i].size()] + sum[i]);
  }
  vector<long long> dp1 = dp;
  solve(dp2, l2, r2);
  vector<long long>().swap(dp2);
  for (int i = l2; i <= r2; i++) {
    for (int j = k; j >= allv[i].size(); j--)
      dp1[j] = max(dp1[j], dp1[j - allv[i].size()] + sum[i]);
  }
  solve(dp1, l1, r1);
  vector<long long>().swap(dp1);
}
signed main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int t;
    long long s = 0;
    cin >> t;
    allv.push_back(vector<int>(t));
    for (int j = 0; j < t; j++) cin >> allv[i][j], s += allv[i][j];
    sum.push_back(s);
  }
  vector<long long> dp(k + 1);
  solve(dp, 0, n - 1);
  cout << maxans << endl;
}
