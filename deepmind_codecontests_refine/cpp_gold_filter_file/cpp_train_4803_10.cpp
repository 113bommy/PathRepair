#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
vector<pair<int, int> > G[N];
vector<int> res, g[N];
pair<int, int> a[N];
int n, m, order[N], c[N], in[N];
bool test(int tar) {
  res.clear();
  for (int i = 1; i <= n; i++) in[i] = order[i] = 0, g[i].clear();
  queue<int> q;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (auto it : G[i]) {
      if (it.second > tar) {
        in[it.first]++;
        g[i].push_back(it.first);
      }
    }
  }
  for (int i = 1; i <= n; i++)
    if (!in[i]) q.push(i), order[i] = ++cnt;
  while (!q.empty()) {
    int tp = q.front();
    q.pop();
    for (auto it : g[tp]) {
      in[it]--;
      order[it] = ++cnt;
      if (!in[it]) q.push(it);
    }
  }
  for (int i = 1; i <= n; i++)
    if (in[i]) return 0;
  for (int i = 1; i <= m; i++)
    if (c[i] <= tar && order[a[i].first] > order[a[i].second]) res.push_back(i);
  return 1;
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int u, v, w;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v >> w;
    a[i].first = u;
    a[i].second = v;
    c[i] = w;
    G[u].push_back({v, w});
  }
  int l = 0, r = inf, ans;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (test(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  test(ans);
  cout << ans << ' ' << res.size() << '\n';
  for (auto it : res) cout << it << ' ';
  cout << '\n';
  return 0;
}
