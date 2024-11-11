#include <bits/stdc++.h>
using namespace std;
const int maxc = 15, d = 16;
const long long inf = 2e9 + 79;
long long p[maxc][maxc];
long long ways(long long n, vector<long long> x, bool zero) {
  vector<vector<long long> > dp(d + 1, vector<long long>(n + 1, 0));
  dp[0][0] = 1;
  for (long long di = 1; di <= d; di++) {
    for (long long cnt = 0; cnt <= n; cnt++) {
      for (long long mycnt = 0; mycnt + cnt <= n && mycnt <= x[di - 1];
           mycnt++) {
        dp[di][cnt + mycnt] += min(inf, dp[di - 1][cnt] * p[mycnt + cnt][cnt]);
        dp[di][cnt + mycnt] = min(dp[di][cnt + mycnt], inf);
      }
    }
  }
  if (!zero) {
    x[0]--;
    dp[d][n] -= ways(n - 1, x, true);
  }
  return dp[d][n];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < maxc; i++) {
    fill(p[i], p[i] + maxc, 0);
    p[i][0] = p[i][i] = 1;
    for (int j = 1; j < i; j++) {
      p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
    }
  }
  long long k, t;
  cin >> k >> t;
  long long c = 1;
  vector<long long> x(d, t);
  while (true) {
    long long nw = ways(c, x, false);
    if (nw <= k)
      k -= nw;
    else
      break;
    c++;
  }
  vector<int> ans;
  for (int i = 0; i < c; i++) {
    ans.push_back(0);
    if (!i) {
      ans.back()++;
    }
    while (k && ans.back() < 15) {
      if (!x[ans.back()]) {
        ans.back()++;
        continue;
      }
      x[ans.back()]--;
      long long w = ways(c - i - 1, x, true);
      x[ans.back()]++;
      if (w < k) {
        k -= w;
        ans.back()++;
      } else
        break;
    }
    x[ans.back()]--;
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << "0123456789abcdef"[ans[i]];
  }
  cout << "\n";
  return 0;
}
