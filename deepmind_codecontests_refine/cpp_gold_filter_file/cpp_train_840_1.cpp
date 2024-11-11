#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 100005;
const double PI = 4 * atan(1);
const double eps = 1e-7;
const long long oo = 1e10;
const int K = 205;
long long gcd(long long u, long long v) {
  if (v == 0) return u;
  return gcd(v, u % v);
}
int n;
long long a[705];
bool vis[705][705][2];
bool dp[705][705][2];
vector<int> adj[N];
bool dfs(int l, int r, int dir) {
  if (l > r) return true;
  if (vis[l][r][dir]) return dp[l][r][dir];
  vis[l][r][dir] = 1;
  long long bef = (dir == 1 ? r + 1 : l - 1);
  for (auto i : adj[bef]) {
    if (i < l) continue;
    if (i > r) break;
    bool flag = (dfs(l, i - 1, 1) && dfs(i + 1, r, 0));
    if (flag) return dp[l][r][dir] = 1;
  }
  return dp[l][r][dir] = 0;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < n; j++) {
      if (gcd(a[i], a[j]) >= 2) adj[i].push_back(j);
    }
  }
  bool ans = dfs(0, n - 1, 1);
  if (ans) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}
