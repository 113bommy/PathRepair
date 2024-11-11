#include <bits/stdc++.h>
using namespace std;
const int MOD = 100000000;
vector<vector<vector<int> > > memo(101,
                                   vector<vector<int> >(101,
                                                        vector<int>(2, -1)));
int n1, n2, k1, k2;
int DP(int cur1, int cur2, bool same) {
  if (memo[cur1][cur2][same] != -1) return memo[cur1][cur2][same];
  int ans = 0, lim1 = 0;
  if (same)
    lim1 = min(cur1, k1);
  else
    lim1 = min(cur1, k2);
  for (int i = 1; i <= lim1; i++) ans = (ans + DP(cur2, cur1 - i, !same)) % MOD;
  return memo[cur1][cur2][same] = ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n1 >> n2 >> k1 >> k2;
  memo[0][0][0] = 1;
  memo[0][0][1] = 1;
  for (int i = 1; i <= 100; i++) {
    memo[0][i][0] = 0;
    memo[0][i][1] = 0;
  }
  cout << (DP(n1, n2, true) + DP(n2, n1, false));
  return 0;
}
