#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 2e5;
vector<int> g[N];
int a[N];
int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);
bool magic(int x) {
  while (x) {
    int a = x % 10;
    if (a != 4 and a != 7) return 0;
    x /= 10;
  }
  return 1;
}
int fac[N];
int C(int n, int r) {
  if (n * 1LL * r == 0) return 1;
  long long ans = fac[n];
  ans *= mpow(fac[r], mod - 2);
  ans %= mod;
  ans *= mpow(fac[n - r], mod - 2);
  ans %= mod;
  return ans;
}
int dp[1024][1024];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, n, k, x;
  cin >> n >> k;
  fac[0] = fac[1] = 1;
  for (i = 2; i < N; i++) fac[i] = (i * 1LL * fac[i - 1]) % mod;
  int N, second, j;
  N = second = 0;
  map<int, int> cnt;
  set<int> tot;
  for (i = 0; i < n; i++) {
    cin >> x;
    if (magic(x))
      cnt[x]++, tot.insert(x);
    else
      N++;
  }
  second = tot.size();
  vector<int> M;
  for (auto it = tot.begin(); it != tot.end(); it++) M.push_back(*it);
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (i = 0; i < 1024; i++) dp[i][0] = 1;
  for (i = 1; i < second + 1; i++)
    for (j = 1; j < i + 1; j++) {
      dp[i][j] = (dp[i - 1][j - 1] * cnt[M[i - 1]]) % mod + dp[i - 1][j];
      dp[i][j] %= mod;
    }
  long long ans = 0;
  for (i = 0; i < min(second, k) + 1; i++) {
    if (N < k - i) continue;
    long long tem = dp[second][i];
    tem %= mod;
    tem *= C(N, k - i);
    tem %= mod;
    ans += tem;
    if (ans >= mod) ans -= mod;
  }
  cout << ans << endl;
  return 0;
}
int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % mod;
    base = ((long long)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
void ipgraph(int n, int m) {
  int i, u, v;
  while (m--) {
    cin >> u >> v;
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
  }
}
void dfs(int u, int par) {
  for (int v : g[u]) {
    if (v == par) continue;
    dfs(v, u);
  }
}
