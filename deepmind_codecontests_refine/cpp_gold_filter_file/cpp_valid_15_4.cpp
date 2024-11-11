#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
  if (y < x) x = y;
}
template <typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
  if (x < y) x = y;
}
mt19937 rnd(time(0));
const int MAXN = 10e3 + 228;
vector<int> g[MAXN];
int d[MAXN];
int mod = 1000000007;
int mul(int a, int b) { return 1ll * a * b % mod; }
int add(int a, int b) {
  if (a + b >= mod) return a + b - mod;
  return a + b;
}
int sub(int a, int b) {
  if (a - b < 0) return a - b + mod;
  return a - b;
}
int binpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
int inv(int x) { return binpow(x, mod - 2); }
int fact[MAXN];
int rfact[MAXN];
int cnk(int n, int k) {
  if (n < 0 || k > n) return 0;
  return mul(fact[n], mul(rfact[k], rfact[n - k]));
}
int tpc[MAXN];
void dfs(int v, int p, int tp) {
  d[v] = d[p] + 1;
  tpc[v] = tp;
  for (int i : g[v]) {
    if (i != p) {
      int ntp = tp;
      if (v == p) ntp = i;
      dfs(i, v, ntp);
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout.precision(20), cout.setf(ios::fixed);
  fact[0] = 1;
  for (int i = 1; i < MAXN; ++i) fact[i] = mul(fact[i - 1], i);
  rfact[MAXN - 1] = inv(fact[MAXN - 1]);
  for (int i = MAXN - 2; i >= 0; --i) rfact[i] = mul(rfact[i + 1], i + 1);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) g[i].clear();
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    if (k == 2) {
      cout << n * (n - 1) / 2 << '\n';
      continue;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      fill(d, d + n + 1, 0);
      dfs(i, i, -1);
      for (int dd = 2; dd <= n; ++dd) {
        vector<int> cnts(n + 1);
        for (int j = 1; j <= n; ++j) {
          if (d[j] == dd) {
            cnts[tpc[j]]++;
          }
        }
        vector<int> itms;
        for (int i : cnts) {
          if (i) itms.push_back(i);
        }
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int j : itms) {
          vector<int> ndp = dp;
          for (int x = 1; x <= 1; ++x) {
            for (int gg = 0; gg + x <= n; ++gg) {
              ndp[gg + x] = add(ndp[gg + x], mul(dp[gg], cnk(j, x)));
            }
          }
          swap(dp, ndp);
        }
        ans = add(ans, dp[k]);
      }
    }
    cout << ans << '\n';
  }
}
