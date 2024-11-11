#include <bits/stdc++.h>
using namespace std;
int dp[16][16][1 << 16];
int di1[16][16];
int n, m;
int di2[16][16];
int find(int i, int j, int ma) {
  if (dp[i][j][ma] != 1000000001) return dp[i][j][ma];
  if (__builtin_popcountl(ma) == 2) {
    return di1[i][j];
  }
  vector<int> v;
  for (int k = 0; k < n; ++k) {
    if (((1 << k) & ma) != 0) {
      if (k != i && k != j) v.push_back(k);
    }
  }
  int ans = 0;
  for (int k = 0; k < v.size(); ++k) {
    ans = max(ans, min(find(v[k], j, ((1 << j) | (1 << v[k]))),
                       find(i, v[k], (ma ^ (1 << j)))));
  }
  dp[i][j][ma] = ans;
  return ans;
}
int main() {
  for (int i = 0; i < 16; ++i)
    for (int j = 0; j < 16; ++j)
      for (int k = 0; k < (1 << 16); ++k) dp[i][j][k] = 1000000001;
  cin >> n >> m;
  int a[n][m];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> a[i][j];
  if (n == 1) {
    int ans = 1000000001;
    for (int i = 1; i < n; ++i) {
      ans = min(ans, abs(a[0][i] - a[0][i - 1]));
    }
    cout << ans;
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        int mi = 1000000001;
        for (int k = 0; k < m; ++k) {
          mi = min(mi, abs(a[i][k] - a[j][k]));
        }
        di1[i][j] = mi;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        int mi = 1000000001;
        for (int k = 1; k < m; ++k) {
          mi = min(mi, abs(a[i][k] - a[j][k - 1]));
        }
        di2[i][j] = mi;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        ans = max(ans, min(di2[i][j], find(i, j, ((1 << n) - 1))));
      }
    }
  }
  cout << ans;
}
