#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long MOD = 998244353;
const long long INF = 0x7f7f7f7f7f7f7f7f;
const int INFi = 0x7f7f7f7f;
const long long MAXN = 1e+5 + 7;
vector<long long> adj[MAXN];
long long visit[MAXN] = {};
int dx8[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy8[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dx4[] = {0, 1, 0, -1}, dy4[] = {1, 0, -1, 0};
int q = 1;
long long n, k;
long long dp[2005][2005] = {};
vector<vector<long long>> div1;
long long add(long long a, long long b) { return (a + b) % MOD; }
long long mult(long long a, long long b) { return (a * b) % MOD; }
void MAIN() {
  cin >> n >> k;
  div1.resize(n + 1);
  for (long long i = 1; i <= n; i++)
    for (long long j = i; j <= n; j += i) div1[j].push_back(i);
  for (long long i = 1; i <= k; i++) {
    for (long long j = 1; j <= n; j++) {
      if (i == 1) {
        dp[i][j] = 1;
        continue;
      }
      long long len = div1[j].size();
      for (long long h = 0; h < len; h++)
        dp[i][j] = add(dp[i][j], dp[i - 1][div1[j][h]]);
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) ans = add(ans, dp[k][i]);
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(10);
  ;
  mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
  ;
  while (q--) {
    MAIN();
  }
}
