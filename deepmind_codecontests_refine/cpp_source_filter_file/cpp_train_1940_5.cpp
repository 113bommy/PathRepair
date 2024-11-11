#include <bits/stdc++.h>
using namespace std;
int n;
int adj[505][505];
const long long mod = 1e9 + 7;
long long dp[505][505][2][2];
inline int nxt(int u) { return (u + 1) % n; }
long long calc(long long be, long long en, bool flg1, bool flg2) {
  if (nxt(be) == en) return 1;
  if (dp[be][en][flg1][flg2] != -1) return dp[be][en][flg1][flg2];
  long long ret = 0;
  if (flg1) {
    for (int i = nxt(be); i != en; i = nxt(i)) {
      if (adj[i][en] == 0) continue;
      long long res = calc(be, i, 1, 1) * calc(i, en, 1, 1);
      res %= mod;
      ret = (ret + res) % mod;
    }
  }
  if (flg2) {
    for (int i = nxt(be); i != en; i = nxt(i)) {
      if (adj[i][en] == 0) continue;
      long long res = calc(be, i, 0, 1) * calc(i, en, 1, 1);
      res %= mod;
      ret = (ret + res) % mod;
    }
  }
  return dp[be][en][flg1][flg2] = ret;
}
int main() {
  memset(dp, -1, sizeof dp);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &adj[i][j]);
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    if (adj[0][i] == 0) continue;
    long long res = calc(0, i, 0, 1) * calc(i, 0, 1, 1);
    res %= mod;
    ans = (ans + res) % mod;
  }
  cout << ans << endl;
  return 0;
}
