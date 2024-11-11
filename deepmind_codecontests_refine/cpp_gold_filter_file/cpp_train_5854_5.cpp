#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int f[2 * 233333][21];
int dep[2 * 233333];
int grf[2 * 233333];
int vis[2 * 233333];
vector<int> e[2 * 233333];
int gf(int x) {
  if (grf[x] == x) return x;
  return grf[x] = gf(grf[x]);
}
int move(int x, int val) {
  for (register int i = 20; (20 < 0) ? (i <= 0) : (i >= 0);
       i += (20 < 0) ? 1 : (-1)) {
    if ((1 << i) <= val) {
      val -= (1 << i);
      x = f[x][i];
    }
  }
  return x;
}
int lca(int x, int y) {
  int xx, yy;
  if (dep[x] < dep[y]) swap(x, y);
  x = move(x, dep[x] - dep[y]);
  if (x == y) return x;
  for (register int i = 20; (20 < 0) ? (i <= 0) : (i >= 0);
       i += (20 < 0) ? 1 : (-1)) {
    xx = f[x][i];
    yy = f[y][i];
    if (xx != yy) {
      x = xx;
      y = yy;
    }
  }
  return f[x][0];
}
void dfs(int rt, int fa) {
  dep[rt] = dep[fa] + 1;
  f[rt][0] = fa;
  for (register int i = 1; (1 < 20) ? (i <= 20) : (i >= 20);
       i += (1 < 20) ? 1 : (-1))
    f[rt][i] = f[f[rt][i - 1]][i - 1];
  for (int i : e[rt]) {
    if (i == fa) continue;
    dfs(i, rt);
  }
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  int x, y, z;
  for (register int i = 1; (1 < n - 1) ? (i <= n - 1) : (i >= n - 1);
       i += (1 < n - 1) ? 1 : (-1)) {
    cin >> x >> y;
    e[x].push_back(n + i);
    e[y].push_back(n + i);
    e[n + i].push_back(x);
    e[n + i].push_back(y);
  }
  dfs(1, 0);
  for (register int i = 1; (1 < n * 2) ? (i <= n * 2) : (i >= n * 2);
       i += (1 < n * 2) ? 1 : (-1))
    grf[i] = i;
  queue<int> q;
  memset(vis, -1, sizeof vis);
  for (register int i = 1; (1 < k) ? (i <= k) : (i >= k);
       i += (1 < k) ? 1 : (-1)) {
    cin >> x;
    q.push(x);
    vis[x] = 0;
  }
  while (!q.empty()) {
    int tmp = q.front();
    q.pop();
    if (vis[tmp] == m) break;
    for (int i : e[tmp]) {
      grf[gf(i)] = gf(tmp);
      if (vis[i] == -1) {
        vis[i] = vis[tmp] + 1;
        q.push(i);
      }
    }
  }
  int qu, ans1, ans2;
  cin >> qu;
  for (register int i = 1; (1 < qu) ? (i <= qu) : (i >= qu);
       i += (1 < qu) ? 1 : (-1)) {
    cin >> x >> y;
    z = lca(x, y);
    int len = dep[x] + dep[y] - 2 * dep[z];
    if (len <= 2 * m)
      cout << "YES" << endl;
    else {
      ans1 = (m <= dep[x] - dep[z]) ? gf(move(x, m)) : gf(move(y, len - m));
      ans2 = (m <= dep[y] - dep[z]) ? gf(move(y, m)) : gf(move(x, len - m));
      cout << (ans1 == ans2 ? "YES" : "NO") << endl;
    }
  }
  return 0;
}
