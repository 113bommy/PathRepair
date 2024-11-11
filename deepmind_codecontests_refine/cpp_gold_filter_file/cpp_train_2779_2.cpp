#include <bits/stdc++.h>
using namespace std;
long long ncr[100][100];
int frq[10];
long long dp[11][20];
long long rec(int dd, int ll, int jj) {
  long long ret = 0;
  if (dd == 10) return ll == 0;
  if (frq[dd] == 0) return rec(dd + 1, ll, jj);
  if (dd == jj) ret += rec(dd + 1, ll, jj);
  if (jj != dd && frq[dd] > 0 && ll == 0) return 0;
  if (ll < 0) return 0;
  if (dp[dd][ll] != -1) return dp[dd][ll];
  for (int i = 1; i <= ll && i <= frq[dd]; i++) {
    ret += ncr[ll][i] * rec(dd + 1, ll - i, jj);
  }
  return dp[dd][ll] = ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        ncr[i][j] = 1;
      else
        ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
    }
  }
  string s;
  cin >> s;
  int mn = 0, mx = s.size();
  for (int i = 0; i < (int)s.size(); i++) {
    if (frq[s[i] - '0'] == 0) mn++;
    frq[s[i] - '0']++;
  }
  long long ans = 0;
  for (int i = mn; i <= mx; i++) {
    for (int j = 1; j < 10; j++) {
      if (frq[j] == 0) continue;
      memset(dp, -1, sizeof(dp));
      frq[j]--;
      ans += rec(0, i - 1, j);
      frq[j]++;
    }
  }
  cout << ans << "\n";
  return 0;
}
