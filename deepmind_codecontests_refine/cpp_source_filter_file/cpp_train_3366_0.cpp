#include <bits/stdc++.h>
using namespace std;
int atake[1 << 20], used[1 << 20];
int n, k;
double dist[1050][1050];
int x[1 << 20], y[1 << 20];
vector<int> g[1 << 20];
int found;
bool dfs(int v, int k) {
  if (v == n) {
    if (found == 0)
      for (int i = 0; i < n; i++) atake[i] = used[i];
    found = 1;
    return true;
  }
  if (used[v]) return dfs(v + 1, k);
  int nei = 0;
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    used[to]++;
    if (used[to] != 1) continue;
    nei++;
    --k;
  }
  if (k >= 0 && dfs(v + 1, k)) return true;
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (used[to] == 1) ++k;
    --used[to];
  }
  used[v]++;
  if (k > 0 && nei > 1 && dfs(v + 1, k - 1)) return true;
  used[v]--;
  return 0;
}
bool check(double bound) {
  found = 0;
  for (int i = 0; i < n; i++) {
    used[i] = 0;
    g[i].clear();
  }
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (dist[i][j] > bound + 1e-9) g[i].push_back(j), g[j].push_back(i);
  return dfs(0, k);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dist[i][j] =
          sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
  double l, r;
  l = 0;
  r = 1.2e9;
  for (int iter = 1; iter <= 77; iter++) {
    double mid = l + r;
    mid /= 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  check(l + 1e-8);
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (atake[i]) ans.push_back(i + 1);
  }
  for (int i = 0; i < n; i++)
    if (ans.size() < k && used[i] == 0) ans.push_back(i);
  for (int i = 0; i < ans.size(); i++) {
    if (i) cout << " ";
    cout << ans[i];
  }
  return 0;
}
