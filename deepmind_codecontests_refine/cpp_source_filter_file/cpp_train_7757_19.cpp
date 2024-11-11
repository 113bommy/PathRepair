#include <bits/stdc++.h>
using namespace std;
int n, m, cl, op;
int dp[2001][2001][2];
int rek(int cur, int o, int jp) {
  if (cur == n && jp == 1) return o == 0;
  if (cur > n || o > n - cur) return 0;
  if (dp[cur][o][jp] == -1) {
    int &r = dp[cur][o][jp];
    r = rek(cur + 1, o + 1, jp);
    if (o > 0) r = (r + rek(cur + 1, o - 1, jp)) % 1000000007;
    if (!jp && o >= cl) r = (r + rek(cur, o - cl + op, 1)) % 1000000007;
  }
  return dp[cur][o][jp];
}
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> n >> m;
  string a;
  cin >> a;
  n -= m;
  for (int ctr1 = 0; ctr1 < a.length(); ctr1++) {
    if (a[ctr1] == '(')
      op++;
    else if (op > 0)
      op--;
    else
      cl++;
  }
  cout << rek(0, 0, 0);
  return 0;
}
