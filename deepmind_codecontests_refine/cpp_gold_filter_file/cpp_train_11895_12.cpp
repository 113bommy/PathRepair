#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int dp[N][N];
vector<pair<int, int> > T[N];
int n, m;
int solve(int l, int r) {
  if (dp[l][r] != -1) return dp[l][r];
  if (l > r) {
    dp[l][r] = 0;
    return 0;
  }
  dp[l][r] = 0;
  vector<int> cnt(m + 1);
  for (int i = 1; i <= n; i++) {
    for (auto x : T[i]) {
      if (x.first >= l && x.second <= r) {
        for (int p = x.first; p <= x.second; p++) {
          cnt[p]++;
        }
      }
    }
  }
  int sol;
  for (int i = l; i <= r; i++) {
    sol = (cnt[i] * cnt[i]) + solve(l, i - 1) + solve(i + 1, r);
    dp[l][r] = max(dp[l][r], sol);
  }
  return dp[l][r];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  int k, li, ri;
  for (int i = 0; i <= m + 1; i++) {
    for (int j = 0; j <= m + 1; j++) {
      dp[i][j] = -1;
    }
  }
  for (int i = 1; i <= n; i++) {
    cin >> k;
    for (int j = 1; j <= k; j++) {
      cin >> li >> ri;
      T[i].push_back(make_pair(li, ri));
    }
  }
  cout << solve(1, m);
  return 0;
}
