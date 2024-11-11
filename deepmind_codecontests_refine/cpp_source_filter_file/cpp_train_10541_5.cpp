#include <bits/stdc++.h>
using namespace std;
unsigned int dp[512][501];
unsigned int pcost[512][501];
int n, chgs;
string s;
static const unsigned int INF = 0x3f3f3f3f;
string toPalin(int l, int r) {
  string res = s.substr(l, r - l);
  int i = 0, j = res.size() - 1;
  while (i <= j) {
    if (s[l + i] != s[l + j]) res[j] = s[i];
    i++;
    j--;
  }
  return res;
}
int main() {
  cin >> s >> chgs;
  n = s.size();
  for (int i = 0; i < n; i++) {
    for (int j = i; j <= n; j++) {
      int l = i, r = j - 1;
      pcost[i][j] = 0;
      while (l < r) {
        if (s[l] != s[r]) {
          pcost[i][j]++;
        }
        l++;
        r--;
      }
    }
  }
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 0; i <= n; i++) {
    dp[i][1] = pcost[0][i];
  }
  for (int k = 2; k <= chgs; k++) {
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        if (dp[i][k] > dp[j][k - 1] + pcost[j][i]) {
          dp[i][k] = dp[j][k - 1] + pcost[j][i];
        }
      }
    }
  }
  unsigned int res = INF, c = -1;
  for (int i = 0; i <= chgs; i++) {
    if (res > dp[n][i]) {
      res = dp[n][i];
      c = i;
    }
  }
  cout << res << endl;
  string sres = "";
  int p = n;
  for (int i = n - 1; i > 0; i--) {
    if (dp[p][c] == dp[i][c - 1] + pcost[i][p]) {
      sres = toPalin(i, p) + sres;
      p = i;
      sres.insert(sres.begin(), '+');
      c--;
    }
  }
  sres = toPalin(0, p) + sres;
  cout << sres << endl;
  return 0;
}
