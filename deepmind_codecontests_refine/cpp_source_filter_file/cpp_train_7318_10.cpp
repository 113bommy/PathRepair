#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,tune=native")
using namespace std;
const int inf = -2e9 + 100;
const int N = 555;
int n, m;
vector<vector<int>> A;
int mx[N][N], pref[N][N];
int dp[101][10001];
int solve(int idx, int cnt) {
  if (cnt > m) {
    return -inf;
  }
  if (idx == n) {
    return (cnt == m) ? 0 : -inf;
  }
  int &ans = dp[idx][cnt];
  if (ans != -1) {
    return ans;
  }
  ans = 0;
  int sz = (int)(A[idx].size());
  for (int taken = 0; taken <= sz; ++taken) {
    ans = max(ans, mx[idx][taken] + solve(idx + 1, cnt + taken));
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    vector<int> v;
    for (int j = 0; j < x; ++j) {
      int y;
      cin >> y;
      v.push_back(y);
    }
    A.push_back(v);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (int)(A[i].size()); ++j) {
      pref[i][j + 1] = pref[i][j];
      pref[i][j + 1] += A[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    int sz = (int)(A[i].size());
    for (int taken = 0; taken <= sz; ++taken) {
      int maximum = 0;
      for (int left = 0; left <= taken; ++left) {
        int right = taken - left;
        int left_sum = pref[i][left];
        int right_sum =
            pref[i][sz] - ((sz - right < 0) ? 0 : pref[i][sz - right]);
        maximum = max(maximum, left_sum + right_sum);
      }
      mx[i][taken] = maximum;
    }
  }
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0);
  return 0;
}
