#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int ch = getchar(), f = 1, ans = 0;
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = 0;
  for (; ch >= '0' && ch <= '9'; ch = getchar())
    ans = (((ans << 2) + ans) << 1) + (ch ^ '0');
  return f ? ans : -ans;
}
const int maxn = 200050;
int n, m, k;
vector<pair<int, int> > e[maxn];
int dep[maxn];
vector<int> s;
vector<vector<int> > ans;
vector<int> vis;
int cnt;
void dfs(int u) {
  if (cnt >= k) return;
  if (u == n + 1) {
    ans.push_back(vis);
    ++cnt;
    return;
  }
  for (int i = 0; i < e[u].size(); ++i) {
    int v = e[u][i].first;
    if (dep[v] != dep[u] - 1) continue;
    vis[e[u][i].second] = 1;
    dfs(u + 1);
    vis[e[u][i].second] = 0;
  }
}
int main() {
  n = read(), m = read(), k = read();
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read();
    e[u].push_back(make_pair(v, i));
    e[v].push_back(make_pair(u, i));
  }
  queue<int> q;
  q.push(1);
  dep[1] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < e[u].size(); ++i) {
      int v = e[u][i].first;
      if (dep[v]) continue;
      dep[v] = dep[u] + 1;
      q.push(v);
    }
  }
  vis.resize(m + 5, 0);
  dfs(2);
  cout << cnt << endl;
  for (int i = 0; i < cnt; ++i) {
    for (int j = 1; j <= m; ++j) cout << (int)ans[i][j];
    cout << endl;
  }
  return 0;
}
