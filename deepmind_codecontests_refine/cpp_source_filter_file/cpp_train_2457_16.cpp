#include <bits/stdc++.h>
using namespace std;
const int N = 5001;
int a[N];
int dp[N][N];
vector<int> nx[N];
int ok(int i, int j) {
  if (i == 0 || j == 0) return 1;
  int x = a[i - 1];
  int y = a[j] - 1;
  return abs(x - y) == 1 || (x - y) % 7 == 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int v = a[i - 1];
    {
      vector<int> fminus;
      vector<int> fplus;
      vector<int> fmod;
      for (int j = i; j < n; j++) {
        if (v - 1 == a[j] && (int)fminus.size() < 2) fminus.push_back(j + 1);
        if (v + 1 == a[j] && (int)fplus.size() < 2) fplus.push_back(j + 1);
        if ((v - a[j]) % 7 == 0 && (int)fmod.size() < 2) fmod.push_back(j + 1);
      }
      for (auto j : fminus) nx[i].push_back(j);
      for (auto j : fplus) nx[i].push_back(j);
      for (auto j : fmod) nx[i].push_back(j);
    }
    nx[0].push_back(i);
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      ans = max(ans, dp[i][j]);
      {
        for (auto t : nx[i]) {
          if (t > max(i, j)) {
            dp[t][j] = max(dp[t][j], dp[i][j] + 1);
          }
        }
      }
      {
        for (auto t : nx[j]) {
          if (t > max(i, j)) {
            dp[i][t] = max(dp[i][t], dp[i][j] + 1);
          }
        }
      }
    }
  }
  cout << ans << endl;
}
