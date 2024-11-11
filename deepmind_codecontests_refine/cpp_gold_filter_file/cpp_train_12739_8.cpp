#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int n, vis[N], pos1[N], pos2[N];
vector<int> g[N], q[N];
vector<int> ord;
int sz[N], ans[N];
int dfs(int x) {
  sz[x] = true;
  pos1[x] = ((int)ord.size());
  for (auto i : g[x])
    if (!sz[i]) sz[x] += dfs(i);
  ord.push_back(x);
  pos2[x] = ((int)ord.size());
  return sz[x];
}
int cnt[N], val[N];
void calc(int l, int r, int pl, int sum = 0, int tag = 1, int s = 0,
          int e = n) {
  if (s >= r || e <= l) return;
  if (s >= l && e <= r) {
    val[tag] += pl;
    if (val[tag] == 0 && pl == -1) cnt[tag] = cnt[2 * tag] + cnt[2 * tag + 1];
    if (val[tag] == 1 && pl == 1) cnt[tag] = e - s;
    return;
  }
  int mid = (s + e) / 2;
  calc(l, r, pl, sum, tag * 2 + 0, s, mid);
  calc(l, r, pl, sum, tag * 2 + 1, mid, e);
  if (val[tag] == 0) cnt[tag] = cnt[tag * 2] + cnt[tag * 2 + 1];
}
void solve(int x) {
  vis[x] = true;
  for (auto i : q[x]) calc(pos1[i], pos2[i], 1);
  ans[x] = max(0, cnt[1] - 1);
  for (auto i : g[x])
    if (!vis[i]) solve(i);
  for (auto i : q[x]) calc(pos1[i], pos2[i], -1);
}
int32_t main() {
  ios::sync_with_stdio(0);
  int Q;
  cin >> n >> Q;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  while (Q--) {
    int x, y;
    cin >> x >> y;
    q[x].push_back(y);
    q[y].push_back(x);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
    if (((int)q[i].size())) q[i].push_back(i);
  }
  solve(1);
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}
