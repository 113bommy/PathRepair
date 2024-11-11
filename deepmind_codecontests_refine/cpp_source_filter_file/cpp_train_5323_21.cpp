#include <bits/stdc++.h>
const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
using namespace std;
vector<int> v;
int dp[MAXN][3];
bool solve(int n, int flag) {
  if (n == 0) {
    return true;
  }
  if (n < 0) {
    return false;
  }
  if (dp[n][flag] != -1) {
    return dp[n][flag];
  }
  if (flag == 1) {
    v.push_back(4);
    if (solve(n - 4, 1)) {
      return dp[n][flag] = 1;
    }
    if (solve(n - 4, 2)) {
      return dp[n][flag] = 1;
    }
    v.pop_back();
    return dp[n][flag] = 0;
  } else if (flag == 2) {
    v.push_back(7);
    if (solve(n - 7, 1)) {
      return dp[n][flag] = 1;
    }
    if (solve(n - 7, 2)) {
      return dp[n][flag] = 1;
    }
    v.pop_back();
    return dp[n][flag] = 0;
  }
  return dp[n][flag] = 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  memset(dp, -1, sizeof(dp));
  int n;
  cin >> n;
  if (solve(n, 1) || solve(n, 2)) {
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
      cout << v[i];
    }
    cout << '\n';
  } else {
    cout << -1 << '\n';
  }
}
