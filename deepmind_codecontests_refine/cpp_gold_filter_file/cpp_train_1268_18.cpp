#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> e;
vector<int> l, r;
vector<bool> vis;
stack<int> stk;
vector<int> dfn, low, be;
int tot = 0, cnt = 0;
void tarjan(int u) {
  dfn[u] = low[u] = ++tot;
  stk.push(u);
  vis[u] = true;
  for (auto &v : e[u]) {
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (vis[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    ++cnt;
    while (stk.top() != u) {
      int v = stk.top();
      stk.pop();
      be[v] = cnt;
      vis[v] = false;
    }
    stk.pop();
    be[u] = cnt;
    vis[u] = false;
  }
}
int main() {
  int n, p, M, m;
  cin >> n >> p >> M >> m;
  const int maxn = (p + M + 1) * 2 + 10;
  e.assign(maxn, vector<int>());
  l.assign(p, 0);
  r.assign(p, 0);
  int x, y;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    --x;
    --y;
    e[x << 1 | 1].emplace_back(y << 1);
    e[y << 1 | 1].emplace_back(x << 1);
  }
  for (int i = 0; i < p; ++i) {
    cin >> l[i] >> r[i];
    e[i << 1].emplace_back((l[i] + p) << 1);
    e[i << 1].emplace_back((r[i] + p + 1) << 1 | 1);
    e[(l[i] + p) << 1 | 1].emplace_back(i << 1 | 1);
    e[(r[i] + p + 1) << 1].emplace_back(i << 1 | 1);
  }
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    --x;
    --y;
    e[x << 1].emplace_back(y << 1 | 1);
    e[y << 1].emplace_back(x << 1 | 1);
  }
  for (int i = 0; i <= M; ++i) {
    e[(i + p + 1) << 1].emplace_back((i + p) << 1);
    e[(i + p) << 1 | 1].emplace_back((i + p + 1) << 1 | 1);
  }
  vis.assign(maxn, false);
  dfn.assign(maxn, 0);
  low.assign(maxn, 0);
  be.assign(maxn, 0);
  for (int i = 0, _i = 2 * (p + M + 1); i <= _i; ++i)
    if (!dfn[i]) tarjan(i);
  for (int i = 0, _i = p + M + 1; i <= _i; ++i) {
    if (be[i << 1] == be[i << 1 | 1]) {
      cout << -1 << endl;
      return 0;
    }
  }
  vector<int> ans;
  int val = 0;
  for (int i = 0; i < p; ++i) {
    if (be[i << 1] < be[i << 1 | 1]) {
      ans.emplace_back(i);
      val = max(val, l[i]);
    }
  }
  cout << ans.size() << " " << val << "\n";
  for (int i = 0, _i = ans.size(); i < _i; ++i) {
    if (i) cout << " ";
    cout << ans[i] + 1;
  }
  cout << endl;
  return 0;
}
