#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
using namespace std;
const int N = 100000 + 10;
const int MOD = 1000000007;
const int LOG = 20;
const int INF = 1000000010;
const int delta = 11353;
vector<int> G[N << 2], num, num2;
int n, X[N], Y[N], cnt, ted, mark[N], tav[N], ans = 1;
void DFS(int v) {
  mark[v] = 1;
  ted++, cnt += (int)G[v].size();
  for (auto u : G[v])
    if (!mark[u]) DFS(u);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  tav[0] = 1;
  for (int i = 1; i < N; i++) tav[i] = tav[i - 1] * 2ll % MOD;
  for (int i = 1; i <= n; i++) {
    cin >> X[i] >> Y[i];
    num.push_back(X[i]), num2.push_back(Y[i]);
  }
  sort(num.begin(), num.end()),
      num.resize(unique(num.begin(), num.end()) - num.begin());
  sort(num2.begin(), num2.end()),
      num2.resize(unique(num2.begin(), num2.end()) - num2.begin());
  for (int i = 1; i <= n; i++) {
    int v = lower_bound(num.begin(), num.end(), X[i]) - num.begin() + 1,
        u = lower_bound(num2.begin(), num2.end(), Y[i]) - num2.begin() + 1;
    u += num2.size();
    G[v].push_back(u), G[u].push_back(v);
  }
  for (int i = 1; i <= num.size() + num2.size(); i++) {
    if (!mark[i]) {
      cnt = 0;
      ted = 0;
      DFS(i);
      if (cnt > 2 * (ted - 1))
        ans = ans * 1ll * tav[ted] % MOD;
      else
        ans = (ans * 1ll * (tav[ted] - 1)) % MOD;
      ans %= MOD;
      ans += MOD;
      ans %= MOD;
    }
  }
  cout << ans;
  return 0;
}
