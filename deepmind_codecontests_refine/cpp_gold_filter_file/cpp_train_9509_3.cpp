#include <bits/stdc++.h>
using namespace std;
int dp[2][1010 + 1];
bool match(string str, string strx, int x) {
  int i = 0, n;
  n = str.size();
  for (int i = 0; i < n; i++) {
    if (strx[i] != str[x]) return false;
    x++;
    x %= n;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string str, strx;
  int n, sol = 0, x, pref, p, s;
  cin >> str;
  cin >> strx;
  cin >> x;
  n = str.size();
  dp[0][0] = 1;
  pref = 1;
  p = 0;
  for (int i = 1; i <= x; i++) {
    s = 0;
    p = 1 - p;
    for (int j = 0; j < n; j++) {
      dp[p][j] = pref - dp[1 - p][j];
      if (dp[p][j] < 0)
        dp[p][j] += 1000000007;
      else
        dp[p][j] %= 1000000007;
      s += dp[p][j];
      s %= 1000000007;
    }
    pref = s;
  }
  sol = 0;
  for (int i = 0; i < n; i++)
    if (match(str, strx, i)) {
      sol += dp[p][i];
      sol %= 1000000007;
    }
  cout << sol << "\n";
  return 0;
}
