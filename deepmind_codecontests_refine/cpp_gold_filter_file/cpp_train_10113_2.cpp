#include <bits/stdc++.h>
using namespace std;
int a, b, m;
vector<int> rep;
vector<int> d;
int dp(int n) {
  if (n < 0) return 0;
  int &v = d[n];
  if (v != -1) return v;
  int mx = rep[n];
  v = a + dp(n - 1);
  for (int i = 1; i <= mx; ++i) {
    v = min(v, dp(n - i) + b);
  }
  return v;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> a >> b;
  d = vector<int>(m, -1);
  string s;
  cin >> s;
  rep = vector<int>(m, 0);
  vector<vector<int>> lcs(m + 1, vector<int>(m + 1, 0));
  for (int i = 0; i <= m; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (i and j) {
        if (s[i - 1] == s[j - 1])
          lcs[i][j] = 1 + lcs[i - 1][j - 1];
        else
          lcs[i][j] = 0;
      }
    }
  }
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < j; ++i) {
      rep[j] = max(rep[j], min(lcs[i + 1][j + 1], j - i));
    }
  }
  cout << dp(m - 1) << '\n';
}
