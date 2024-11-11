#include <bits/stdc++.h>
using namespace std;
const int n_max = 1005;
int n, m, d[n_max], p[n_max];
bool chk[n_max];
vector<int> a[n_max];
void longest_path(int u, vector<int> &path, bool rep = true) {
  queue<int> q;
  fill(d + 1, d + n + 1, INT_MIN);
  q.push(u);
  d[u] = p[u] = 0;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    chk[u] = true;
    for (int v : a[u])
      if (d[v] == INT_MIN) {
        d[v] = d[u] + 1;
        p[v] = u;
        q.push(v);
      }
  }
  int t = u;
  for (int i = 1; i <= n; ++i)
    if (d[i] > d[t]) t = i;
  if (!rep) {
    path.clear();
    while (t) path.push_back(t), t = p[t];
  } else
    longest_path(t, path, false);
}
void solve() {
  int dmt = -1;
  vector<int> path;
  vector<pair<int, int>> vt;
  for (int i = 1; i <= n; ++i)
    if (!chk[i]) {
      longest_path(i, path);
      dmt = (int)path.size() - 1;
      int x = ((int)path.size() + 1) / 2 - 1, t = path[x];
      vt.push_back({max(x, (int)path.size() - x - 1), t});
    }
  if ((int)vt.size() < 2) {
    printf("%d\n", dmt);
    return;
  }
  sort(vt.begin(), vt.end(), greater<pair<int, int>>());
  for (int i = 1; i < (int)vt.size(); ++i) {
    a[vt[0].second].push_back(vt[i].second);
    a[vt[i].second].push_back(vt[0].second);
  }
  longest_path(1, path);
  printf("%d\n", (int)path.size() - 1);
  for (int i = 1; i < (int)vt.size(); ++i)
    printf("%d %d\n", vt[0].second, vt[1].second);
}
int main() {
  ios::sync_with_stdio(false);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  if (m)
    solve();
  else {
    printf("%d\n", n == 1 ? 0 : n == 2 ? 1 : 2);
    for (int i = 2; i <= n; ++i) printf("1 %d\n", i);
  }
  return 0;
}
