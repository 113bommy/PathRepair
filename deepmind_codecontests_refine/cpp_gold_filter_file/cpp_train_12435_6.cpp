#include <bits/stdc++.h>
using namespace std;
string s;
int dp[500][500];
int dfs(int p, char c) {
  if (dp[p][c] != -1) return dp[p][c];
  if (p == s.size()) return dp[p][c] = 1;
  int ret = 0;
  int x = c + s[p];
  if (x % 2 == 0)
    ret = dfs(p + 1, char(x / 2));
  else
    ret = dfs(p + 1, char(x / 2)) + dfs(p + 1, char(x / 2 + 1));
  return dp[p][c] = ret;
}
bool check() {
  string a = s;
  for (int(i) = (1); (i) < (s.size()); (i)++) {
    int x;
    bool f = 0;
    x = a[i - 1] + s[i];
    if (x % 2 == 0) {
      x /= 2;
      if (x == a[i]) f = 1;
    } else {
      x /= 2;
      if (x == a[i])
        f = 1;
      else if (x + 1 == a[i])
        f = 1;
    }
    if (!f) return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  memset(dp, -1, sizeof(dp));
  long long ans = 0;
  for (int(i) = (0); (i) < (10); (i)++) {
    ans += dfs(1, char(i + '0'));
  }
  if (check()) ans--;
  cout << ans << endl;
  return 0;
}
