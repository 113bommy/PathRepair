#include <bits/stdc++.h>
using namespace std;
int fail[100005], cal[100005][207], n, m;
string s, p;
vector<int> dp[100005];
void build_failure() {
  int k = 0;
  fail[0] = 0, fail[1] = 0;
  for (int i = 2; i <= m; ++i) {
    while (k > 0 && p[i - 1] != p[k]) k = fail[k];
    if (p[i - 1] == p[k]) k++;
    fail[i] = k;
  }
}
int kmp(int i, int j) {
  if (i >= n) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  int ans = 0;
  if (s[i] != '?') {
    int i1 = cal[j][s[i] - 'a'];
    if (i1 == m) {
      ans = max(ans, 1 + kmp(i + 1, i1));
    } else
      ans = max(ans, kmp(i + 1, i1));
  } else {
    for (int x = 0; x < 26; x++) {
      int i1 = cal[j][x];
      if (i1 == m) {
        ans = max(ans, 1 + kmp(i + 1, i1));
      } else
        ans = max(ans, kmp(i + 1, i1));
    }
  }
  return dp[i][j] = ans;
}
int main() {
  int i, j, k, x = 0, y, t;
  cin >> s >> p;
  n = s.size(), m = p.size();
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= m; j++) dp[i].push_back(-1);
  }
  if (n < m) {
    cout << 0 << endl;
    return 0;
  }
  build_failure();
  for (i = 0; i <= m; i++) {
    for (char c = 'a'; c <= 'z'; c++) {
      k = i;
      if (k == m) k = fail[m];
      while (k > 0 && c != p[k]) k = fail[k];
      if (c == p[k]) k++;
      cal[i][c - 'a'] = k;
    }
  }
  x = kmp(0, 0);
  cout << x << endl;
}
