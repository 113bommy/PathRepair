#include <bits/stdc++.h>
using namespace std;
string s;
int dp[110][27][110], a[27][27], n, inf = 1e9;
int fn(int i, int pch, int k) {
  if (k < 0) {
    return -inf;
  }
  if (i == n) {
    return 0;
  }
  int &res = dp[i][pch][k];
  if (res != -1) {
    return res;
  }
  res = 0;
  for (int ch = 1; ch < 27; ch++) {
    res = max(res, fn(i + 1, ch, k - (s[i] - 'a' + 1 != ch)) + a[pch][ch]);
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int t = 1, m, i, j, k, u, to, w;
  while (t--) {
    cin >> s >> k >> m;
    n = s.length();
    memset(dp, -1, sizeof(dp));
    memset(a, 0, sizeof(a));
    while (m--) {
      char c, cc;
      cin >> c >> cc >> w;
      u = c - 'a' + 1, to = cc - 'a' + 1;
      a[u][to] = w;
    }
    cout << fn(0, 0, k);
  }
}
