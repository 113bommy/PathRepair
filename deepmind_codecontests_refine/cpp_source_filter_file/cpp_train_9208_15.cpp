#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int mod = 1000000007;
vector<int> ch[maxn];
int dp[maxn][2];
void dfs(int n) {
  for (int i = 0; i < ch[n].size(); i++) dfs(ch[n][i]);
  if (ch[n].size() == 0) {
    dp[n][0] = 0;
    dp[n][1] = 1;
    return;
  }
  int i, j;
  long long all0 = 1, all1[2];
  dp[n][0] = 1;
  all1[0] = 1, all1[0] = 0;
  for (i = 0; i < ch[n].size(); i++) {
    int v = ch[n][i];
    long long d0 = dp[n][0] * dp[v][0] + dp[n][1] * dp[v][1];
    long long d1 = dp[n][0] * dp[v][1] + dp[n][1] * dp[v][0];
    dp[n][0] = (dp[n][0] + d0) % mod;
    dp[n][1] = (dp[n][1] + d1) % mod;
    all0 = all0 * (dp[v][0] + 1) % mod;
    d0 = all1[1] * dp[v][1] % mod;
    d1 = all1[0] * dp[v][1] % mod;
    all1[0] = (d0 + all1[0]) % mod;
    all1[1] = (d1 + all1[1]) % mod;
  }
  long long dp0 = dp[n][0], dp1 = dp[n][1];
  dp[n][0] = 1, dp[n][1] = 0;
  dp[n][0] = 1;
  for (i = ch[n].size() - 1; i >= 0; i--) {
    int v = ch[n][i];
    long long d0 = dp[n][0] * dp[v][0] + dp[n][1] * dp[v][1];
    long long d1 = dp[n][0] * dp[v][1] + dp[n][1] * dp[v][0];
    dp[n][0] = (dp[n][0] + d0) % mod;
    dp[n][1] = (dp[n][1] + d1) % mod;
  }
  long long t0, t1;
  t0 = ((dp1 + dp[n][1] - all1[1]) % mod + mod) % mod;
  t1 = ((dp0 + dp[n][0] - all0) % mod + mod) % mod;
  dp[n][0] = t0, dp[n][1] = t1;
}
int main() {
  int n, i, j, k;
  scanf("%d", &n);
  for (i = 2; i <= n; i++) scanf("%d", &j), ch[j].push_back(i);
  for (i = 1; i <= n; i++)
    if (ch[i].size()) sort(ch[i].begin(), ch[i].end());
  dfs(1);
  cout << (dp[1][0] + dp[1][1]) % mod << endl;
}
