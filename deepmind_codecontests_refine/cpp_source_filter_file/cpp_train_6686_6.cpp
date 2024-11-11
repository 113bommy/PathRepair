#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, N = 57, M = 2e4 + 7, INF = INT_MAX / 10;
long long powe(long long x, long long y) {
  x = x % mod, y = y % (mod - 1);
  long long ans = 1;
  while (y > 0) {
    if (y & 1) {
      ans = (1ll * x * ans) % mod;
    }
    y >>= 1;
    x = (1ll * x * x) % mod;
  }
  return ans;
}
int inp[N][M], pre[N][M];
int dp[M];
int stree[4 * M], ltree[4 * M];
int n, m, k;
int getmax() { return stree[0]; }
void rupdate(int ss, int se, int spos, int l, int r, int val) {
  if (ss > se || l > se || r < ss) return;
  if (l <= ss && se <= r) {
    ltree[spos] += val;
    stree[spos] += val;
    return;
  }
  ltree[spos * 2 + 1] += ltree[spos];
  stree[spos * 2 + 1] += ltree[spos];
  ltree[spos * 2 + 2] += ltree[spos];
  stree[spos * 2 + 2] += ltree[spos];
  ltree[spos] = 0;
  int mid = (ss + se) / 2;
  rupdate(ss, mid, 2 * spos + 1, l, r, val);
  rupdate(mid + 1, se, 2 * spos + 2, l, r, val);
  stree[spos] = max(stree[2 * spos + 1], stree[2 * spos + 2]);
}
void rupdate(int l, int r, int val) { rupdate(1, n, 0, l, r, val); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> inp[i][j];
      pre[i][j] += inp[i][j] + pre[i][j - 1];
    }
  }
  for (int i = 1; i <= m - k + 1; i++) {
    dp[i] = pre[n][i + k - 1] - pre[n][i - 1];
  }
  for (int i = n - 1; i >= 1; i--) {
    memset(stree, 0, sizeof(stree));
    memset(ltree, 0, sizeof(ltree));
    for (int j = 1; j <= k; j++) {
      rupdate(j, j, dp[j] - (pre[i + 1][k] - pre[i + 1][j - 1]));
    }
    for (int j = k + 1; j <= m - k + 1; j++) {
      rupdate(j, j, dp[j]);
    }
    for (int j = 1; j <= m - k + 1; j++) {
      dp[j] = pre[i][j + k - 1] - pre[i][j - 1] + pre[i + 1][j + k - 1] -
              pre[i + 1][j - 1] + getmax();
      rupdate(max(1, j - k + 1), j, inp[i + 1][j]);
      rupdate(j + 1, j + k, -inp[i + 1][j + k]);
    }
  }
  int maxi = -1;
  for (int i = 1; i <= m - k + 1; i++) maxi = max(maxi, dp[i]);
  cout << maxi;
  return 0;
}
