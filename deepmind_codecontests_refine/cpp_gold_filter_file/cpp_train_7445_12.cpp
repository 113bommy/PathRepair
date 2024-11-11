#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int N, K, a[maxn], b[maxn];
vector<int> adj[maxn];
int sum[maxn], sz[maxn];
bool vis[maxn];
int ans;
int root;
int dp(int u, int p = -1) {
  int res = 1;
  int big1 = 0, big2 = 0;
  sz[u] = 1;
  for (int v : adj[u])
    if (v != p) {
      int f = dp(v, u);
      sz[u] += sz[v];
      if (sz[v] == f) {
        res += f;
      } else {
        if (f > big1) {
          big2 = big1;
          big1 = f;
        } else if (f > big2)
          big2 = f;
      }
    }
  if (!b[u]) return 0;
  ans = max(ans, res + big1 + big2);
  return res + big1;
}
bool check(int val) {
  for (int i = 1; i <= N; ++i)
    if (a[i] >= val)
      b[i] = 1;
    else
      b[i] = 0;
  ans = 0;
  dp(root);
  return ans >= K;
}
signed main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> K;
  for (int i = 1; i <= N; ++i) cin >> a[i];
  for (int i = 1; i < N; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  root = min_element(a + 1, a + 1 + N) - a;
  int lo = 1, hi = 1e6, mid;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (check(mid))
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  while (check(hi + 1)) ++hi;
  cout << hi;
}
