#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
long long int dp[2][2][1005ll][1005ll];
long long int num[1005ll];
long long int n, k;
long long int recur(long long int full, long long int ok, long long int pos,
                    long long int before) {
  if (pos == -1) return (ok) ? 1 : 0;
  long long int &res = dp[full][ok][pos][(full) ? 0 : before];
  if (res != -1) return res;
  res = 0;
  for (long long int i = 0; i < 10; i++) {
    if (full && num[pos] < i) continue;
    bool fulled = full & (i == num[pos]);
    if (i != 4 && i != 7)
      res =
          (res + recur(fulled, ok, pos - 1, min(1005ll - 1, before + 1))) % mod;
    else
      res = (res + recur(fulled, ok | (before < k), pos - 1, 0)) % mod;
  }
  return res;
}
long long int check(string str) {
  long long int bef = -(1ll << (long long int)(60));
  for (long long int i = 0; i < ((long long int)(((long long int)str.size())));
       i++)
    if (str[i] == '4' || str[i] == '7') {
      if (i - bef <= k) return 1;
      bef = i;
    }
  return 0;
}
long long int cal(string str) {
  for (long long int i = 0; i < ((long long int)(1005ll)); i++) num[i] = 0;
  for (long long int i = 0; i < ((long long int)(((long long int)str.size())));
       i++)
    num[i] = str[((long long int)str.size()) - i - 1] - '0';
  for (long long int i = 0; i < ((long long int)(2)); i++)
    for (long long int j = 0; j < ((long long int)(1005ll)); j++)
      dp[1][i][j][0] = -1;
  return recur(1, 0, ((long long int)str.size()), 1005ll - 1);
}
int main() {
  cin >> n >> k;
  memset(dp, -1, sizeof(dp));
  for (long long int i = 0; i < ((long long int)(n)); i++) {
    string s0, s1;
    cin >> s0 >> s1;
    cout << (cal(s1) - cal(s0) + check(s0) + mod) % mod << endl;
  }
}
