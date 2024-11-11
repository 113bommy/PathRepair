#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> edge[5001];
int u[5001], v[5001], g[5001];
vector<int> con[5001];
vector<int> son[5001];
bool vis[5001];
int father[5001];
int level[5001];
bool ok = true;
int ans[5001];
int ans2[5001];
void wk(int x, int y, int val) {
  if (x == y) {
    return;
  } else if (level[x] < level[y]) {
    ans[y] = max(ans[y], val);
    wk(x, father[y], val);
  } else {
    ans[x] = max(ans[x], val);
    wk(father[x], y, val);
  }
}
void ck(int x, int y, int val, bool fd) {
  if (x == y) {
    if (!fd) ok = false;
    return;
  } else if (level[x] < level[y]) {
    if (ans[y] < val) ok = false;
    if (ans[y] == val) fd = true;
    ck(x, father[y], val, fd);
  } else {
    if (ans[x] < val) ok = false;
    if (ans[x] == val) fd = true;
    ck(father[x], y, val, fd);
  }
}
void fd(int x) {
  int i;
  for (i = 1; i < n; i++) {
    if (edge[i] == pair<int, int>(x, father[x]) ||
        edge[i] == pair<int, int>(father[x], x)) {
      ans2[i] = ans[x];
      break;
    }
  }
}
void root(int x, int lev) {
  int i;
  vis[x] = true, level[x] = lev;
  for (i = 0; i < con[x].size(); i++) {
    int f = con[x][i];
    if (!vis[f])
      vis[f] = true, son[x].push_back(f), father[f] = x, root(f, lev + 1);
  }
}
int main() {
  int i;
  cin >> n;
  for (i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    edge[i] = pair<int, int>(x, y);
    con[x].push_back(y), con[y].push_back(x);
  }
  cin >> m;
  for (i = 1; i <= m; i++) cin >> u[i] >> v[i] >> g[i];
  root(1, 1);
  for (i = 1; i <= m; i++) wk(u[i], v[i], g[i]);
  for (i = 1; i <= m; i++) ck(u[i], v[i], g[i], false);
  for (i = 2; i <= n; i++) fd(i);
  for (i = 1; i <= n; i++)
    if (ans2[i] == 0) ans2[i] = 1000000;
  if (ok) {
    for (i = 1; i < n - 1; i++) cout << ans2[i] << " ";
    cout << ans2[n - 1] << endl;
  } else
    cout << -1 << endl;
  return 0;
}
