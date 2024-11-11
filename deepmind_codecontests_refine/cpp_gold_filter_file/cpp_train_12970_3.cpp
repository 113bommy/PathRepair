#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 239;
int getrev(int x) { return (3 - x % 3) % 3; }
int sub(int a, int b) {
  a -= b;
  if (a < 0) {
    return a + 3;
  } else {
    return a;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  vector<int> a(s.size());
  int n = (int)s.size();
  for (int i = 0; i < n; i++) {
    a[i] = s[i] - '0';
  }
  vector<vector<int>> dp(n + 1, vector<int>(3, inf));
  vector<vector<int>> tk(n + 1, vector<int>(3, -1));
  dp[n][0] = 0;
  for (int i = n; i > 0; i--) {
    for (int j = 0; j < 3; j++) {
      if (dp[i - 1][j] > dp[i][j] + 1) {
        dp[i - 1][j] = dp[i][j] + 1;
        tk[i - 1][j] = 0;
      }
      if (dp[i - 1][(j + a[i - 1]) % 3] > dp[i][j]) {
        dp[i - 1][(j + a[i - 1]) % 3] = dp[i][j];
        tk[i - 1][(j + a[i - 1]) % 3] = 1;
      }
    }
  }
  int ans = inf;
  int best = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] != 0) {
      if (ans > i + dp[i + 1][getrev(a[i])]) {
        best = i;
        ans = i + dp[i + 1][getrev(a[i])];
      }
    }
  }
  bool zr = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      if (ans > n - 1) {
        ans = n - 1;
        zr = 1;
      }
    }
  }
  if (ans == inf) {
    cout << -1 << '\n';
  } else if (zr) {
    cout << "0\n";
  } else {
    vector<int> res = {a[best]};
    int start_pos = best + 1;
    int start_mod = getrev(a[best]);
    for (; start_pos < n; start_pos++) {
      if (tk[start_pos][start_mod] == 1) {
        res.push_back(a[start_pos]);
        start_mod = sub(start_mod, a[start_pos] % 3);
      }
    }
    for (auto t : res) {
      cout << t;
    }
    cout << '\n';
  }
}
