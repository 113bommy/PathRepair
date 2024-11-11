#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
int k;
int deg[N], col[N], dis[N];
bool found;
int curlen = 2e5;
int st, en, n, m;
std::vector<int> g[N];
void dfs(int u, int p) {
  col[u] = 1;
  for (auto v : g[u]) {
    if (v == p) continue;
    if (col[v] == 2) continue;
    if (col[v] == 1) {
      if ((dis[u] - dis[v] + 1) < curlen) {
        curlen = dis[u] - dis[v] + 1;
        st = v, en = u;
      }
    } else {
      dis[v] = dis[u] + 1;
      dfs(v, u);
    }
  }
  col[u] = 2;
}
void solve() {
  queue<int> Q;
  Q.push(1);
  std::vector<int> vis(n + 1), par(n + 1);
  memset(col, 0, sizeof col);
  vis[1] = 1, par[1] = -1;
  int x = 1, y = 0;
  std::vector<int> fir, sec;
  col[1] = 1;
  fir.push_back(1);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (auto v : g[u]) {
      if (vis[v]) continue;
      if (col[u] == 2) {
        col[v] = 1;
        x++;
        fir.push_back(v);
      } else {
        col[v] = 2;
        y++;
        sec.push_back(v);
      }
      vis[v] = 1;
      Q.push(v);
    }
  }
  cout << 1 << endl;
  if (x >= (k + 1) / 2) {
    x = (k + 1) / 2;
    for (int i = 0; i < x; i++) cout << fir[i] << ' ';
  } else {
    y = (k + 1) / 2;
    for (int i = 0; i < y; i++) cout << sec[i] << ' ';
  }
}
int main() {
  int x, y;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  if (m == n - 1) {
    solve();
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (!col[i]) dfs(i, -1);
  }
  queue<int> Q;
  Q.push(st);
  std::vector<int> vis(n + 1), par(n + 1);
  vis[st] = 1, par[st] = -1;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (auto v : g[u]) {
      if (u == st and v == en) continue;
      if (vis[v]) continue;
      par[v] = u;
      vis[v] = 1;
      Q.push(v);
    }
  }
  std::vector<int> ans;
  while (en != -1) {
    ans.push_back(en);
    en = par[en];
  }
  if (ans.size() <= k) {
    cout << 2 << '\n';
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
    cout << '\n';
  } else {
    cout << 1 << endl;
    int now = (k + 1) / 2;
    for (int i = 0; i < ans.size(); i += 2) {
      cout << ans[i] << ' ';
      now--;
      if (now == 0) break;
    }
    cout << endl;
  }
  return 0;
}
