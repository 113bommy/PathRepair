#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using cd = complex<double>;
const int MA = 6007;
int ma[(ll)(2e5 + 7)];
vector<int> ar[(ll)(2e5 + 7)];
int dp[MA][MA];
bool ch[MA][MA];
int solve(int l, int r) {
  if (l > r) {
    return (0);
  }
  if (dp[l][r] != -1) {
    return dp[l][r];
  }
  dp[l][r] = 0;
  dp[l][r] = solve(l + 1, r);
  for (int i = 0; i < ar[l].size(); i++) {
    if (ar[l][i] < r) {
      dp[l][r] = max(dp[l][r], solve(l, ar[l][i]) + solve(ar[l][i] + 1, r));
    }
  }
  dp[l][r] += ch[l][r];
  return dp[l][r];
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, cc = 0;
    cin >> n;
    vector<pair<int, int>> vp(n);
    set<int> mm;
    for (int i = 0; i < n; i++) {
      cin >> vp[i].first >> vp[i].second;
      mm.insert(vp[i].first);
      mm.insert(vp[i].second);
    }
    for (int x : mm) {
      ma[x] = ++cc;
    }
    for (int i = 0; i <= cc; i++) {
      for (int j = 0; j <= cc; j++) {
        ch[i][j] = 0;
        dp[i][j] = -1;
      }
    }
    for (int i = 0; i < n; i++) {
      vp[i].first = ma[vp[i].first];
      vp[i].second = ma[vp[i].second];
      ar[vp[i].first].push_back(vp[i].second);
      ch[vp[i].first][vp[i].second] = 1;
    }
    cout << solve(1, cc) << "\n";
    for (int i = 1; i <= cc; i++) {
      ar[i].clear();
    }
  }
}
