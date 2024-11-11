#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000 + 7;
const long long LL_INF = 1ll * INF * INF;
const int MAX_N = 3000 + 7;
const int mod = INF;
template <typename T>
inline void addmod(T& a, const long long& b, const int& MOD) {
  a = (a + b) % MOD;
  if (a < 0) a += MOD;
}
template <typename num_t>
inline void update_max(num_t& a, const num_t& b) {
  a = max(a, b);
}
struct Interpolation {
  static const int MOD = (int)1e9 + 7;
  static const int MAX_N = 5007;
  int a[MAX_N];
  int fact[MAX_N];
  int inv_fact[MAX_N];
  int prf[MAX_N];
  int suf[MAX_N];
  Interpolation() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
      fact[i] = (long long)fact[i - 1] * i % MOD;
      inv_fact[i] = this->pow(fact[i], MOD - 2);
    }
  }
  static int pow(int n, int k) {
    int r = 1;
    for (; k; k >>= 1) {
      if (k & 1) r = (long long)r * n % MOD;
      n = (long long)n * n % MOD;
    }
    return r;
  }
  void upd(int u, int v) { a[u] = v; }
  int calc(int x, int k) {
    prf[0] = suf[k + 1] = 1;
    for (int i = 1; i <= k; i++) {
      prf[i] = (long long)prf[i - 1] * (x - i + MOD) % MOD;
    }
    for (int i = k; i >= 1; i--) {
      suf[i] = (long long)suf[i + 1] * (x - i + MOD) % MOD;
    }
    int res = 0;
    for (int i = 1; i <= k; i++) {
      long long preCalc = 1ll * inv_fact[i - 1] * inv_fact[k - i] % MOD;
      long long temp =
          1ll * prf[i - 1] * suf[i + 1] % MOD * preCalc % MOD * a[i] % MOD;
      if ((k - i) & 1) {
        res = (res - temp + MOD) % MOD;
      } else {
        res = (res + temp) % MOD;
      }
    }
    return res;
  }
} interpolation;
int n, k;
int dp[MAX_N][MAX_N];
int sum[MAX_N][MAX_N];
vector<int> adj[MAX_N];
void dfs(int u) {
  for (int i = 1; i < MAX_N; ++i) dp[u][i] = 1;
  for (int v : adj[u]) {
    dfs(v);
    for (int i = 1; i < MAX_N; ++i) {
      dp[u][i] = dp[u][i] * 1ll * sum[v][i] % mod;
    }
  }
  for (int i = 1; i < MAX_N; ++i) {
    sum[u][i] = (dp[u][i] + sum[u][i - 1]) % mod;
  }
}
void solve() {
  cin >> n >> k;
  for (int i = 1; i < n; ++i) {
    int u;
    cin >> u;
    adj[u].push_back(i + 1);
  }
  dfs(1);
  if (k < MAX_N) {
    cout << sum[1][k] << '\n';
    return;
  }
  for (int i = 0; i < MAX_N; ++i) interpolation.upd(i, sum[1][i]);
  cout << interpolation.calc(k, MAX_N - 1) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  const bool multiple_test = false;
  int test = 1;
  if (multiple_test) cin >> test;
  for (int i = 0; i < test; ++i) {
    solve();
  }
}
