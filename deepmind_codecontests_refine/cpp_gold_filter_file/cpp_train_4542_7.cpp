#include <bits/stdc++.h>
using namespace std;
const int N = 55, Inf = 1e9;
int n, s, m, ev[N * 2], ew[N * 2], cnt[N], deg[N];
vector<int> G[N];
int f[N][N * 2][N];
void solve(int, int);
int dp(int i, int j, int k) {
  if (!f[i][j][k]) solve(i, j);
  return f[i][j][k];
}
struct node {
  int i, e, c;
  int val() const { return c < i ? dp(i, e, c + 1) : 0; }
  bool operator<(const node& b) const { return val() < b.val(); }
};
void solve(int i, int j) {
  f[i][j][0] = Inf;
  if (deg[ev[j]] == 1) {
    for (int k = (1); k <= (i); k++)
      f[i][j][k] = k < i ? dp(i - k, j ^ 1, i - k) + ew[j] : ew[j];
  } else {
    priority_queue<node> q;
    for (int e : G[ev[j]])
      if (e ^ j ^ 1) q.push({i, e, 0});
    for (int k = (1); k <= (i); k++) {
      node x = q.top();
      q.pop();
      f[i][j][k] = min(f[i][j][k - 1], x.val() + ew[j]);
      x.c++, q.push(x);
    }
  }
}
int dfs(int u, int fa) {
  int res = cnt[u];
  for (int e : G[u])
    if (ev[e] ^ fa) res += dfs(ev[e], u);
  return res;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  int u, v, w;
  for (int i = (2); i <= (n); i++) {
    int a = i * 2, b = a + 1;
    cin >> u >> v >> w, deg[ev[a] = v]++, deg[ev[b] = u]++, ew[a] = ew[b] = w;
    G[u].push_back(a), G[v].push_back(b);
  }
  cin >> s >> m;
  for (int i = (1); i <= (m); i++) cin >> u, cnt[u]++;
  int ans = 1e9;
  for (int e : G[s]) ans = min(ans, dp(m, e, dfs(ev[e], s)));
  cout << ans;
  return 0;
}
