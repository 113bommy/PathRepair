#include <bits/stdc++.h>
using namespace std;
const long long maxx = 1e5 + 20, maxlg = 21;
long long n, m, vis[maxx], di[maxx];
long long td[maxx], tu[maxx], sd[maxx], su[maxx];
vector<long long> adj[maxx];
vector<pair<long long, long long> > v[maxx];
pair<long long, long long> q[maxx];
long long dp[maxx][maxlg], h[maxx], isZir[maxx], rasZir[maxx];
queue<pair<long long, long long> > qu;
void dfs(long long root, long long dad, long long root_h = 0) {
  vis[root] = true;
  h[root] = root_h;
  dp[root][0] = dad;
  for (long long i = 1; i < maxlg; i++)
    dp[root][i] = dp[dp[root][i - 1]][i - 1];
  for (long long x : adj[root]) {
    if (!vis[x]) dfs(x, root, root_h + 1);
  }
}
long long lca(long long x, long long y) {
  if (h[x] > h[y]) swap(x, y);
  long long d = h[y] - h[x];
  for (long long i = 0; i < maxlg; i++)
    if (d & (1 << i)) y = dp[y][i];
  if (x == y) return d;
  for (long long i = maxlg - 1; i >= 0; i--) {
    if (dp[x][i] != dp[y][i]) x = dp[x][i], y = dp[y][i], d += (2 * (1 << i));
  }
  return d + 2;
}
void bfs(long long root) {
  qu.push(make_pair(root, 0));
  vis[root] = true;
  while (qu.size()) {
    auto r = qu.front();
    qu.pop();
    long long x = r.first, y = r.second;
    di[x] = y;
    for (long long u : adj[x]) {
      if (!vis[u]) {
        qu.push(make_pair(u, y + 1));
        vis[u] = true;
      }
    }
  }
}
void dfs_zero(long long root) {
  for (auto x : v[root]) {
    if (vis[x.first] != -1 && vis[x.first] != -2) {
      rasZir[x.second] = vis[x.first];
      if (root < x.first)
        isZir[x.second] = 1;
      else
        isZir[x.second] = 2;
    }
  }
  for (long long x : adj[root]) {
    if (vis[x] == -2) {
      vis[root] = x;
      dfs_zero(x);
    }
  }
  vis[root] = -1;
}
void dfs_down(long long root) {
  vis[root] = true;
  if (!adj[root].size())
    td[root] = 1, sd[root] = 0;
  else {
    for (long long x : adj[root]) {
      if (!vis[x]) {
        dfs_down(x);
        td[root] += td[x];
        sd[root] += sd[x] + td[x];
      }
    }
    td[root]++;
  }
}
void dfs_up(long long root) {
  vis[root] = true;
  if (!root) {
    tu[root] = 1, su[root] = 0;
  }
  long long sumt = 0, sumd = 0;
  vector<long long> w;
  for (long long x : adj[root]) {
    if (!vis[x]) {
      w.push_back(x);
      sumt += td[x];
      sumd += sd[x];
    }
  }
  for (long long x : w) {
    tu[x] = sumt + tu[root] - td[x] + 1;
    su[x] = su[root] + tu[root] + (sumd - sd[x]) + (2 * (sumt - td[x]));
    dfs_up(x);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(7) << fixed;
  cin >> n >> m;
  for (long long i = 0; i < n - 1; i++) {
    long long x, y;
    cin >> x >> y;
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (long long i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    x--, y--;
    q[i] = make_pair(x, y);
    v[x].push_back(make_pair(y, i));
    v[y].push_back(make_pair(x, i));
  }
  dfs(0, 0);
  fill(vis, vis + maxx, 0);
  bfs(0);
  fill(vis, vis + maxx, -2);
  dfs_zero(0);
  fill(vis, vis + maxx, 0);
  dfs_down(0);
  fill(vis, vis + maxx, 0);
  dfs_up(0);
  for (long long i = 0; i < m; i++) {
    long long x = q[i].first, y = q[i].second;
    if (y < x) swap(x, y);
    long long d1, d2, t1, t2, dis;
    if (isZir[i] == 0) {
      d1 = sd[x], d2 = sd[y], t1 = td[x], t2 = td[y], dis = di[x] + di[y];
    } else if (isZir[i] == 1) {
      long long z = rasZir[i];
      d1 = sd[x], d2 = su[y] + sd[y] - sd[z] - td[z], t1 = td[x],
      t2 = n - td[z], dis = di[x] - di[y];
    } else {
      long long z = rasZir[i];
      d1 = su[x] + sd[x] - sd[z] - td[z], d2 = sd[y], t1 = n - td[z],
      t2 = td[y], dis = di[y] - di[x];
    }
    long long soorat = d1 * t2 + d2 * t1;
    long long makhraj = t1 * t2;
    long double ans =
        (long double)(1.0 * (long double)soorat / (long double)makhraj);
    ans += (long double)(1.0 + lca(x, y));
    cout << ans << "\n";
  }
  return 0;
}
