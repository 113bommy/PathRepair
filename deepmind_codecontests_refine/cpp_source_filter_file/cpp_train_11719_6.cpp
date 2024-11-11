#include <bits/stdc++.h>
using namespace std;
string s;
int dp[110][27][110], a[27][27], inf = 1e9;
int fn(int i, int pch, int k) {
  if (i == s.length()) {
    return 0;
  }
  int &res = dp[i][pch][k];
  if (res != -1) {
    return res;
  }
  res = 0;
  for (int ch = 0; ch < 26; ch++) {
    if (s[i] - 'a' == ch) {
      res = max(res, fn(i + 1, ch, k) + a[pch][ch]);
    } else if (k > 0) {
      res = max(res, fn(i + 1, ch, k - 1) + a[pch][ch]);
    }
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int t = 1, m, i, j, k, u, to, w;
  while (t--) {
    cin >> s >> k >> m;
    memset(dp, -1, sizeof(dp));
    memset(a, 0, sizeof(a));
    while (m--) {
      char c, cc;
      cin >> c >> cc >> w;
      u = c - 'a', to = cc - 'a';
      a[u][to] = w;
    }
    cout << fn(0, 26, k);
  }
}
