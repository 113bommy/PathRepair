#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
using namespace std;
template <typename T>
void uin(T &a, T b) {
  if (b < a) {
    a = b;
  }
}
template <typename T>
void uax(T &a, T b) {
  if (b > a) {
    a = b;
  }
}
const int N = 1000 * 1000 + 228;
const int INF = 1e9 + 228;
vector<pair<char, int>> g[N];
int dp[N], sz[N];
bool ok[N];
int a[N];
multiset<int> s;
int mod = 0;
void dfs(int v, int p) {
  if (p != -1) uin(dp[v], dp[p] + 1);
  if (!s.empty()) uin(dp[v], *s.begin() + mod + 1);
  sz[v] = ok[v];
  int y = 0;
  for (pair<char, int> go : g[v]) {
    int to = go.second;
    y = dp[v] - mod;
    s.insert(dp[v] - mod);
    mod += sz[v];
    dfs(to, v);
    mod -= sz[v];
    s.erase(s.find(y));
    sz[v] += sz[to];
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int p;
    cin >> p;
    char c;
    cin >> c;
    g[p].emplace_back(c, i);
  }
  int k;
  cin >> k;
  for (int i = 1; i <= k; ++i) {
    cin >> a[i];
    ok[a[i]] = 1;
  }
  for (int i = 0; i <= n; ++i) {
    if (!g[i].empty()) sort(g[i].begin(), g[i].end());
    dp[i] = INF;
  }
  dp[0] = 0;
  dfs(0, -1);
  for (int i = 1; i <= k; ++i) {
    cout << dp[a[i]] << ' ';
  }
  cout << '\n';
  return 0;
}
