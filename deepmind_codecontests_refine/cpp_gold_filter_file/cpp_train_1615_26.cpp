#include <bits/stdc++.h>
using namespace std;
inline void Input_Output() {}
const double eps = 0.000001;
const long double pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const long long MOD = 1e18 + 9;
const long long INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 6e5 + 123;
const int M = 22;
const int pri = 997;
const int Magic = 2101;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n, m, k;
vector<int> g[N];
int u[N];
int f[N];
int sub[N];
int dp[N][2];
void dfs(int v, int pr = 0) {
  dp[v][0] = dp[v][1] = -inf;
  sub[v] = u[v];
  if (u[v]) {
    dp[v][0] = 0;
  }
  for (auto to : g[v])
    if (to != pr) {
      dfs(to, v);
      sub[v] += sub[to];
      f[v] += f[to] + 2 * (sub[to] > 0);
      if (dp[to][0] + 1 > dp[v][0]) {
        dp[v][1] = dp[v][0];
        dp[v][0] = dp[to][0] + 1;
      } else {
        dp[v][1] = max(dp[v][1], dp[to][0] + 1);
      }
    }
}
pair<int, int> ans = make_pair(inf, inf);
void calc(int v, int pr = 0, int sum = 0, int up = 0, int mx = -inf) {
  pair<int, int> cur = {up + f[v] - max(mx, dp[v][0]), v};
  cerr << cur.first << ' ' << cur.second << '\n';
  if (cur < ans) ans = cur;
  for (auto to : g[v])
    if (to != pr) {
      if (!sub[to]) continue;
      if (sum + sub[v] - sub[to] < 1) {
        calc(to, v);
        return;
      } else {
        int nxt = mx;
        if (dp[to][0] + 1 == dp[v][0])
          nxt = max(nxt, dp[v][1]);
        else
          nxt = max(nxt, dp[v][0]);
        ++nxt;
        calc(to, v, sum + sub[v] - sub[to], up + f[v] - f[to], nxt);
      }
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    g[l].push_back(r);
    g[r].push_back(l);
  }
  for (int i = 1, x; i <= m; ++i) {
    scanf("%d", &x);
    u[x] = 1;
  }
  dfs(1);
  calc(1);
  cout << ans.second << '\n' << ans.first << '\n';
  return 0;
}
