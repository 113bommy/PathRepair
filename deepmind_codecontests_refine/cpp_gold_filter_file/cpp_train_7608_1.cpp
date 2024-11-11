#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 12), M = 1e3 + 9;
bool com(pair<int, int> a, pair<int, int> b) {
  if (a.first > b.first) return true;
  if (a.first == b.first) return a.second < b.second;
  return false;
}
int cnt_ar[N][N], wt_ar[N][N], dp[N][N];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  int lim = (1 << n);
  int w[n];
  for (int i = 0; i <= n - 1; i++) cin >> w[i];
  vector<int> cnt(lim + 5, 0);
  string s;
  for (int i = 0; i <= m - 1; i++) {
    cin >> s;
    int b = 0, k = lim;
    for (int j = 0; j <= n - 1; j++) {
      k >>= 1;
      if (s[j] == '1') b |= k;
    }
    cnt[b]++;
  }
  for (int i = 0; i <= lim - 1; i++) {
    for (int j = 0; j <= lim - 1; j++) {
      int wt = 0;
      for (int k = 0; k <= n - 1; k++) {
        if (!((i ^ j) & (1 << k))) wt += w[n - 1 - k];
      }
      dp[i][wt] += cnt[j];
    }
  }
  for (int i = 0; i <= lim - 1; i++) {
    for (int j = 1; j <= 100; j++) {
      dp[i][j] += dp[i][j - 1];
    }
  }
  int ser;
  while (q--) {
    cin >> s >> ser;
    int b = 0, k = lim;
    for (int j = 0; j <= n - 1; j++) {
      k >>= 1;
      if (s[j] == '1') b |= k;
    }
    cout << dp[b][ser] << "\n";
  }
  return 0;
}
