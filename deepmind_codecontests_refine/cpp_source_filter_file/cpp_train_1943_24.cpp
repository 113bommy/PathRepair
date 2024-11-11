#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 5e5 + 50;
const long long inf = 1e16;
int k;
char st[2000], ed[2000];
long long dp[2000][2000][2];
int num[2000];
long long dfs(int pos, int ok, bool limit, int yes) {
  if (pos == -1) return yes;
  if (!limit && dp[pos][ok][yes] != -1) return dp[pos][ok][yes];
  int up = limit ? num[pos] : 9;
  long long ans = 0;
  for (int i = 0; i <= up; i++) {
    int dis = ok + 1;
    if (i == 4 || i == 7) {
      if (ok <= k)
        dis = 0;
      else
        dis = 1;
    }
    ans += dfs(pos - 1, dis, limit && i == up, dis == 0 || yes);
    ans %= mod;
  }
  if (!limit) dp[pos][ok][yes] = ans;
  return ans;
}
long long acc(char x[]) {
  int len = strlen(x);
  for (int i = 0; i < len; i++) num[i] = x[len - 1 - i] - '0';
  return dfs(len - 1, k + 5, true, false);
}
int main() {
  int t;
  memset(dp, -1, sizeof(dp));
  ios::sync_with_stdio(false);
  cin >> t >> k;
  while (t--) {
    cin >> st >> ed;
    int lena = strlen(st), p = lena - 1;
    while (st[p] == '0') st[p--] = '9';
    st[p] = st[p] - 1;
    cout << (acc(ed) - acc(st) + mod) % mod << endl;
  }
  return 0;
}
