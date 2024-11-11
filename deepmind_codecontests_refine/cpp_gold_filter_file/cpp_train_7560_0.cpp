#include <bits/stdc++.h>
using namespace std;
int n, m, dp[100100], dp2[100010], cntq[100100], cnta[100100], cntb[100010];
string str;
int solve(int pos) {
  if (pos >= str.size() || pos + m > str.size()) return 0;
  if (dp[pos] != -1) return dp[pos];
  int a = cnta[pos] - cnta[pos + m + (m & 1)];
  int b = cntb[pos + 1] - cntb[pos + m + 1 - (m & 1)];
  int op = 0;
  if (a == (m + 1) / 2 && b == m / 2) op = max(op, 1 + solve(pos + m));
  op = max(op, solve(pos + 1));
  return dp[pos] = op;
}
int sol2(int pos) {
  if (pos >= str.size() || pos + m > str.size()) return 0;
  if (dp2[pos] != -1) return dp2[pos];
  int a = cnta[pos] - cnta[pos + m + (m & 1)];
  int b = cntb[pos + 1] - cntb[pos + m + 1 - (m & 1)];
  int c = cntq[pos] - cntq[pos + m];
  int get0 = solve(pos + 1), get1 = 0, ok = 0;
  if (a == (m + 1) / 2 && b == m / 2) ok = 1;
  if (ok && 1 + solve(pos + m) > solve(pos + 1)) {
    return dp2[pos] = c + sol2(pos + m);
  } else {
    dp2[pos] = sol2(pos + 1);
    if (ok) dp2[pos] = min(dp2[pos], c + sol2(pos + m));
    return dp2[pos];
  }
}
int main() {
  cin >> n >> str >> m;
  str = "0" + str;
  for (int i = n; i >= 1; i--) {
    if (str[i] == '?') {
      cntq[i] = cntq[i + 1] + 1;
      cnta[i] = cnta[i + 2] + 1, cntb[i] = cntb[i + 2] + 1;
    } else {
      cntq[i] = cntq[i + 1];
      if (str[i] == 'a')
        cnta[i] = cnta[i + 2] + 1, cntb[i] = cntb[i + 2];
      else
        cntb[i] = cntb[i + 2] + 1, cnta[i] = cnta[i + 2];
    }
  }
  memset(dp, -1, sizeof(dp));
  memset(dp2, -1, sizeof(dp2));
  cout << sol2(1) << endl;
}
