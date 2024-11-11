#include <bits/stdc++.h>
using namespace std;
int n, len, valid = -1;
string s;
long long val[65][65];
long long dp[65][65][65];
long long pown[65];
long long mx = 1e18;
long long go(int i, int prev, int pw) {
  if (i == 0) {
    return 0;
  }
  long long &ret = dp[i][prev][pw];
  ret = 1e18 + 50;
  for (int j = i - 1; j >= 0; j--) {
    if (val[j + 1][i] != -1) {
      if (pw + 1 <= valid && (!val[j + 1][i] || mx / val[j + 1][i] >= pown[pw]))
        ret = min(ret, go(j, i, pw + 1) + pown[pw] * val[j + 1][i]);
    }
  }
  return ret;
}
void solve() {
  cin >> n >> s;
  len = s.size();
  s = '#' + s;
  pown[0] = 1;
  for (int i = 1;; i++) {
    long long k = mx / pown[i - 1];
    if (n > k) {
      valid = i;
      break;
    }
    pown[i] = pown[i - 1] * (1ll) * n;
  }
  for (int i = 1; i <= len; i++) {
    for (int j = 1; j <= i; j++) {
      long long net = 0;
      if (s[j] == '0' && i - j + 1 > 1) {
        val[j][i] = -1;
        continue;
      }
      for (int k = j; k <= i; k++) {
        net = net * 10 + (s[k] - '0');
        if (net >= n) {
          val[j][i] = -1;
          break;
        }
      }
      if (val[j][i] != -1) val[j][i] = net;
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << go(len, len, 0);
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
