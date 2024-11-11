#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long int INF = 9e18 + 2e17;
const int inf = 2e9;
const double eps = 1e-10;
const int MX_V = 301;
pair<vector<vector<int> >, vector<vector<int> > > calc(vector<int>& a) {
  int n = (int)(a).size();
  vector<vector<int> > dp(2 * n * n, vector<int>(MX_V, 0));
  vector<vector<int> > dp2(2 * n * n, vector<int>(MX_V, 0));
  dp[0][a[0]] = 1;
  for (int i = (int)1; i < (int)2 * n * n; i++) {
    int mx = 0;
    for (int j = (int)1; j < (int)MX_V; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j <= a[i % n]) mx = max(mx, dp[i][j]);
    }
    dp[i][a[i % n]] = mx + 1;
  }
  dp2[2 * n * n - 1][a[n - 1]] = 1;
  for (int i = (int)2 * n * n - 2; i >= (int)0; i--) {
    int mx = 0;
    for (int j = (int)1; j < (int)MX_V; j++) {
      dp2[i][j] = dp2[i + 1][j];
      if (j >= a[i % n]) mx = max(mx, dp2[i][j]);
    }
    dp2[i][a[i % n]] = mx + 1;
  }
  return {dp, dp2};
}
int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, T;
  cin >> n >> T;
  vector<int> a(n);
  vector<int> cnt(MX_V, 0);
  for (int i = (int)0; i < (int)n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  auto ret = calc(a);
  if (T <= 2 * n) {
    int mx = 0;
    for (int z = (int)0; z < (int)MX_V; z++)
      mx = max(mx, ret.first[n * T - 1][z]);
    cout << mx << endl;
    return 0;
  }
  int mx = 0;
  for (int j = (int)0; j < (int)MX_V; j++) {
    int len = ret.first[n * n - 1][j] + ret.second[n * n][j];
    len += (T - 2 * n) * cnt[j];
    mx = max(len, mx);
  }
  cout << mx << endl;
  return 0;
}
